#include <filesystem>

#include "git2/repository.h"
#include "gitWrapper.hpp"


namespace fs = std::filesystem;



PDJE_GitHandler::PDJE_GitHandler(const DONT_SANITIZE& auth_name, const DONT_SANITIZE& auth_email)
{
    git_signature_now(&sign, auth_name.c_str(), auth_email.c_str());

}

PDJE_GitHandler::~PDJE_GitHandler()
{
    try
    {
        git_signature_free(sign);
    }
    catch(...)
    {
        
    }
}


bool
PDJE_GitHandler::Open(const fs::path& path)
{
    return gw.open(path);
}

bool
PDJE_GitHandler::DeleteGIT(const fs::path& path)
{

    if( !fs::exists(path) ||
        !fs::is_directory(path) ||
        !Close())
    {
        return false;
    }
    fs::remove_all(path);
    return true;
}


bool
PDJE_GitHandler::Close()
{
    return gw.close();
}


bool
PDJE_GitHandler::Save(const DONT_SANITIZE& tracingFile, const DONT_SANITIZE& timeStamp)
{
    if(gw.handleBranch->FLAG_TEMP_CHECKOUT.has_value()){
        gitwrap::commit tempcommit(gw.handleBranch->FLAG_TEMP_CHECKOUT.value(), gw.repo);
        if(!gw.handleBranch->MakeNewFromCommit(tempcommit, gw.GenTimeStamp())){
            return false;
        }
        gw.handleBranch->FLAG_TEMP_CHECKOUT.reset();
    }
    if(!gw.add(tracingFile)) return false;
    if(!gw.commit(sign, timeStamp)) return false;
    return true;
}

bool
PDJE_GitHandler::Undo()
{
    if(UpdateLog(gw.handleBranch->branchName)){
        gitwrap::commit before_commit;
        if(gw.handleBranch->FLAG_TEMP_CHECKOUT.has_value()){

            git_oid_cpy(
                &before_commit.commitID,
                &(gw.log_hdl->logs[gw.handleBranch->FLAG_TEMP_CHECKOUT.value()].parentID));
        } 
        else {
            auto head = std::move(gw.handleBranch->GetHEAD());
            if(head.has_value()){
                git_oid_cpy(
                    &before_commit.commitID,
                    &head->commitID
                );
            }
            else{
                return false;
            }
        }

        if(gw.handleBranch->CheckoutCommitTemp(before_commit)){
            return true;
        } 
        else{
            return false;
        } 
    }
    else{
        return false;
    }
}

bool
PDJE_GitHandler::Redo()
{
    if(gw.handleBranch->FLAG_TEMP_CHECKOUT.has_value()){
        try
        {
            for(auto& i : gw.log_hdl->logs){
                if(git_oid_equal(
                &i.second.parentID, 
                &gw.handleBranch->FLAG_TEMP_CHECKOUT.value())){

                    if(gw.handleBranch->CheckoutCommitTemp(i.second.now)){
                        return true;
                    } 
                    else{
                        return false;
                    } 
                }
                
            }
           
        }
        catch(const std::exception& e)
        {
            RecentERR = e.what();
            return false;
        }
    }
    else{
        return false;
    }
    return false;
}

DiffResult
PDJE_GitHandler::GetDiff(const gitwrap::commit& oldTimeStamp, const gitwrap::commit& newTimeStamp)
{
    return gw.diff(oldTimeStamp, newTimeStamp);
}

struct BranchJSON{
    DONT_SANITIZE branchname;
    DONT_SANITIZE oid;
};

DONT_SANITIZE
PDJE_GitHandler::GetLogWithJSONGraph()
{
    using nj = nlohmann::json;
    nj GraphRoot;
    for(auto& i : gw.log_hdl->heads){
        nj b;
        b["NAME"] = i.BranchName;
        b["OID"] = DONT_SANITIZE(git_oid_tostr_s(&i.head));
        GraphRoot["BRANCH"].push_back(b);
    }
    for(auto& i : gw.log_hdl->logs){
        nj c;
        c["OID"] = DONT_SANITIZE(git_oid_tostr_s(&i.first));
        c["EMAIL"] = i.second.authEmail;
        c["NAME"] = i.second.authName;
        c["PARENTID"] = DONT_SANITIZE(git_oid_tostr_s(&i.second.parentID));
        GraphRoot["COMMIT"].push_back(c);
    }
    return GraphRoot.dump();
}

bool
PDJE_GitHandler::Go(const DONT_SANITIZE& branchName, git_oid* commitID)
{
    if(!gw.handleBranch->SetBranch(branchName)){
        return false;
    }
    auto headbranch = std::move(gw.handleBranch->GetHEAD());
    if(headbranch.has_value()){
        
        if(git_oid_equal(&headbranch->commitID, commitID)){
            if(gw.handleBranch->CheckoutThisHEAD()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            auto tempcommit = gitwrap::commit(*commitID, gw.repo);
            if(gw.handleBranch->CheckoutCommitTemp(tempcommit)){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
    return false;
}