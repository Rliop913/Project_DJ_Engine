#include "editorObject.hpp"



trackdata
editorObject::makeTrackData(
    const std::string& trackTitle, 
    std::unordered_map<std::string, std::string>& titles)
{
    trackdata td;
    auto mixRendered = E_obj->mixHandle.second.render();
    auto mixData = mixRendered->Wp->getDatas();
    
    for(unsigned long long i=0; i < mixData.size();++i){
        if(mixData[i].getType() == TypeEnum::LOAD){
            titles.insert(std::pair(mixData[i].getFirst().cStr(), mixData[i].getSecond().cStr()));
        }
    }
    
    td.trackTitle = trackTitle;
    td.mixBinary = mixRendered->out();
    td.noteBinary = E_obj->noteHandle.second.render()->out();
    for(auto& i : titles){
        td.cachedMixList+= (i.first + ",");
    }
    if(!titles.empty()){
        td.cachedMixList.pop_back();
    }
    return std::move(td);
}

void 
editorObject::demoPlayInit(
    std::optional<audioPlayer>& player, 
    unsigned int frameBufferSize, const std::string& trackTitle)
{
    if(player.has_value()){
        player.reset();
    }
    trackdata tdtemp(trackTitle);
    auto searchedTd = projectLocalDB->GetBuildedProject() << tdtemp;
    if(!searchedTd.has_value()) return;
    if(searchedTd->empty()) return;
    player.emplace(
        projectLocalDB->GetBuildedProject(),
        searchedTd->front(),
        frameBufferSize,
        true
    );
}

std::string 
editorObject::DESTROY_PROJECT()
{
    try
    {
        E_obj.reset();
        projectLocalDB.reset();
        auto deletedAmount = fs::remove_all(projectRoot);
        if(deletedAmount < 1){
            return "DELETED NOTHING";
        }
        else{
            return "COMPLETE";
        }
    }
    catch(const std::exception& e)
    {
        return e.what();
    }
}

bool
editorObject::ConfigNewMusic(
    const std::string& NewMusicName, 
    const std::string& composer,
    const std::string& musicPath,
    const std::string& firstBar)
{
    if( E_obj->AddMusicConfig(NewMusicName)){

        E_obj->musicHandle.back().jsonh["TITLE"] = NewMusicName;
        E_obj->musicHandle.back().jsonh["COMPOSER"] = composer;
        E_obj->musicHandle.back().jsonh["PATH"] = 
        fs::relative(
            fs::path(musicPath),
            projectRoot
        );
        E_obj->musicHandle.back().jsonh["FIRST_BAR"] = firstBar;
        return true;
    }
    else{
        return false;
    }
}

bool 
editorObject::Open(const std::string& projectPath)
{
    projectRoot = fs::path(projectPath);
    
    mixFilePath = projectRoot / "Mixes" / "mixmetadata.PDJE";
    noteFilePath = projectRoot / "Notes" / "notemetadata.PDJE";
    kvFilePath = projectRoot / "KeyValues" / "keyvaluemetadata.PDJE";
    musicFileRootPath = projectRoot / "Musics";
    projectLocalDB.emplace();
    
    return E_obj->openProject(projectPath) && projectLocalDB->Open(projectRoot);
}

bool
editorObject::pushToRootDB(litedb& ROOTDB, const std::string& trackTitleToPush)
{
    TITLE_COMPOSER tcData;
    auto td = makeTrackData(trackTitleToPush, tcData);
    if(!(ROOTDB <= td)){
        return false;
    }
    for(auto& tcTemp : tcData){
        if(!pushToRootDB(ROOTDB, tcTemp.first, tcTemp.second)) continue;
    }
    return true;
}


bool 
editorObject::pushToRootDB(
    litedb& ROOTDB, 
    const std::string& musicTitle, 
    const std::string& musicComposer)
{
    auto fromProjectSearchQuery = musdata(musicTitle, musicComposer);
    auto searched =
    projectLocalDB->GetBuildedProject() << fromProjectSearchQuery;
    if(!searched.has_value())           return false;
    if(searched->empty())               return false;
    auto checkRoot = ROOTDB << searched->front();
    if(checkRoot.has_value()){
        if(!checkRoot->empty())         return false;
    }
    else return false;
    auto resultToInsert = searched->front();
    resultToInsert.musicPath =
    fs::relative(
        (projectRoot / fs::path(resultToInsert.musicPath)).lexically_normal(),
        fs::path(ROOTDB.getRoot()).parent_path()
    ).generic_string();
    if(!(ROOTDB <= resultToInsert))  return false;

    return true;
}