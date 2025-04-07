#pragma once

#include "audioPlayer.hpp"
#include "dbRoot.hpp"
#include "NoteTranslator.hpp"

enum PLAY_MODE{
    FULL_PRE_RENDER,
    HYBRID_RENDER,
    FULL_MANUAL_RENDER
};

class PDJE{
private:
    std::optional<litedb> DBROOT;
public:
    PDJE(const std::string& rootPath);
    ~PDJE() = default;

    std::optional<audioPlayer> player;

    bool
    InitPlayer(
        PLAY_MODE mode, 
        trackdata& td, 
        const unsigned int FrameBufferSize);

    bool
    GetNoteObjects(
        trackdata& td,
        OBJ_SETTER_CALLBACK& ObjectSetCallback
    );

    MUS_VEC 
    SearchMusic(
        const std::string& Title, 
        const std::string& composer, 
        const double bpm = -1);
    
    TRACK_VEC SearchTrack(const std::string& Title);

    audioPlayer* GetPlayer();

    
};

class ARGSETTER_WRAPPER{
private:
    FXControlPannel* fxp;
public:
    ARGSETTER_WRAPPER(FXControlPannel* pointer): fxp(pointer){};
    ~ARGSETTER_WRAPPER() = default;
    std::vector<std::string> GetFXArgKeys(FXList fx);
    
    void
    SetFXArg(
        FXList fx, 
        const std::string& key, 
        double arg);

};