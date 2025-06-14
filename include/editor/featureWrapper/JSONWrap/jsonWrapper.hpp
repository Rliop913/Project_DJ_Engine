#pragma once

#include <filesystem>
#include <string>
#include <fstream>
#include <functional>
#include <ranges>
#include <memory>

#include <nlohmann/json.hpp>

#include "MixTranslator.hpp"
#include "PDJE_EXPORT_SETTER.hpp"

#define PDJEARR "PDJE_MIX"
#define PDJENOTE "PDJE_NOTE"
#define PDJEMUSICBPM "PDJE_MUSIC_BPM"
using nj = nlohmann::json;
namespace fs = std::filesystem;
namespace vs = std::views;

struct PDJE_API MixArgs{
    TypeEnum type       = TypeEnum::EQ      ;
    DetailEnum details  = DetailEnum::HIGH  ;
    int ID              = -1                ;
    std::string first   = ""                ;
    std::string second  = ""                ;
    std::string third   = ""                ;
    long long bar       = -1                ;
    long long beat      = -1                ;
    long long separate  = -1                ;
    long long Ebar      = -1                ;
    long long Ebeat     = -1                ;
    long long Eseparate = -1                ;
};

struct PDJE_API NoteArgs{
    std::string Note_Type   = "";
    std::string Note_Detail = "";
    std::string first       = "";
    std::string second      = "";
    std::string third       = "";
    long long bar           = -1;
    long long beat          = -1;
    long long separate      = -1;
    long long Ebar          = -1;
    long long Ebeat         = -1;
    long long Eseparate     = -1;
};

struct PDJE_API MusicArgs{
    std::string bpm     = ""                ;
    long long bar       = -1                ;
    long long beat      = -1                ;
    long long separate  = -1                ;
};

using MIX_W = CapWriter<MixBinaryCapnpData>;
using NOTE_W = CapWriter<NoteBinaryCapnpData>;
using MUSIC_W = CapWriter<MusicBinaryCapnpData>;

using KEY = std::string;
using KEY_VALUE = std::pair<std::string, std::string>;
using KV_W = std::vector<KEY_VALUE>;

template<typename CapnpWriterType>
class PDJE_API PDJE_JSONHandler{
private:
    nj ROOT;
public:

    std::unique_ptr<CapnpWriterType> render();

    template<typename Target> 
    int deleteLine(
        const Target& args,
        bool skipType, 
        bool skipDetail);

    template<typename Target> 
    int deleteLine(const Target& args);

    template<typename Target> 
    bool add(const Target& args);

    template<typename Target> 
    void getAll(std::function<void(const Target& args)> jsonCallback);
        
    bool load(const std::string& path);





    inline nj& operator[](const std::string& key){
        return ROOT[key];
    }

    bool save(const std::string& path){
        std::ofstream jfile(path);
        if(jfile.is_open()){
            jfile << std::setw(4) << ROOT;
            return true;
        }
        else{
            return false;
        }
    }
    

    bool deleteFile(const std::string& path){
        try{ return fs::remove_all(path) > 0; }
        catch(...) { return false; }
    }


    PDJE_JSONHandler() = default;
    ~PDJE_JSONHandler() = default;
};
