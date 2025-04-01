#pragma once
#include <string>
#include <vector>
#include <optional>
#include <sqlite3.h>

#include "musicDB.hpp"
#include "trackDB.hpp"


using MUS_VEC = std::vector<musdata>;
using MAYBE_MUS_VEC = std::optional<MUS_VEC>;

using TRACK_VEC = std::vector<trackdata>;
using MAYBE_TRACK_VEC = std::optional<TRACK_VEC>;

class litedb{
private:
    sqlite3* db = nullptr;
    bool CheckTables();
public:
    template<typename DBType>
    std::optional<std::vector<DBType>>
    operator<<(DBType& searchClue);

    template<typename DBType>
    bool
    operator<=(DBType& insertObject);

    bool openDB(const std::string& dbPath);
    
    litedb();
    ~litedb();
};

template<typename DBType>
std::optional<std::vector<DBType>>
litedb::operator<<(DBType& searchClue)
{
    stmt dbstate = stmt();
    if(searchClue.GenSearchSTMT(dbstate, db)){
        std::vector<DBType> data;
        while(sqlite3_step(dbstate.S) == SQLITE_ROW){
            data.emplace_back(&dbstate);
        }
        return std::move(data);
    }
    else{
        return std::nullopt;
    }
}

template<typename DBType>
bool
litedb::operator<=(DBType& insertObject)
{
    stmt dbstate = stmt();
    if(insertObject.GenInsertSTMT(dbstate, db)){
        auto insertRes = sqlite3_step(dbstate.S);
        if(insertRes != SQLITE_DONE){
            return false;
        }
        return true;
    }
    return false;
}