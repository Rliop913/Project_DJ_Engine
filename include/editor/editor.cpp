#include "editor.hpp"
#include <filesystem>

namespace fs = std::filesystem;

bool
PDJE_Editor::openProject(const fs::path& projectPath)
{
    pt = projectPath;
    mixp = pt / "Mixes";
    notep = pt / "Notes";
    musicp = pt / "Musics";
    kvp = pt / "KeyValues";
    
    if(!fs::exists(pt) || !fs::is_directory(pt)){
        fs::create_directory(pt);
        fs::create_directory(mixp);
        fs::create_directory(notep);
        fs::create_directory(musicp);
        fs::create_directory(kvp);
        if(
            !fs::exists(pt)     || !fs::is_directory(pt)    ||
            !fs::exists(mixp)   || !fs::is_directory(mixp)  ||
            !fs::exists(notep)  || !fs::is_directory(notep) ||
            !fs::exists(kvp)    || !fs::is_directory(kvp)   ||
            !fs::exists(musicp) || !fs::is_directory(musicp)
        ){ return false; }
    }
    if( !mixHandle.first->Open(mixp)    || !mixHandle.second.load(mixp) ||
        !KVHandler.first->Open(kvp)     || !KVHandler.second.load(kvp)  ||
        !noteHandle.first->Open(notep)  || !noteHandle.second.load(notep))
        { return false; }

    for(const auto& musicSubpath : fs::directory_iterator(musicp)){
        if(fs::is_directory(musicSubpath)){
            
            musicHandle.emplace_back(name, email);
            musicHandle.back().musicName = musicSubpath.path().filename().string();
            if( !musicHandle.back().gith->Open(musicSubpath.path()) ||
                !musicHandle.back().jsonh.load(musicSubpath.path()) ){
                    return false;
                }
        }
    }
    return true;
    
}
#include <random>
bool
PDJE_Editor::AddMusicConfig(const SANITIZED& NewMusicName, fs::path& DataPath)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> randomFilename(
        std::numeric_limits<unsigned int>::min(),
        std::numeric_limits<unsigned int>::max());
    std::optional<DONT_SANITIZE> mfilename;
    for(int TRY_COUNT=0; TRY_COUNT<50; ++TRY_COUNT){
        DONT_SANITIZE tempFilename = std::to_string(randomFilename(gen));
        if(!fs::exists(musicp / fs::path(tempFilename))){
            mfilename = tempFilename;
            break;
        }
    }
    if(!mfilename.has_value()) return false;
    DataPath = musicp / fs::path(mfilename.value());
    // if(fs::exists(newpath)){
    //     return false;
    // }
    try
    {
        if(fs::create_directory(DataPath)){
            musicHandle.emplace_back(name, email);
            musicHandle.back().musicName = NewMusicName;
            if( !musicHandle.back().gith->Open(DataPath) ||
            !musicHandle.back().jsonh.load(DataPath) ){
                fs::remove_all(DataPath);
                EDITOR_ERR += "Failed to init git or json\n";
                return false;
            }
            else return true;
        }
    }
    catch(const std::exception& e)
    {
        EDITOR_ERR += e.what();
        EDITOR_ERR += "\n";
        return false;
    }
    
    return false;
}