#pragma once

#include <miniaudio.h>

#include <map>

#include "ManualMix.hpp"



using TITLE         = std::string;

using LOADED_LIST   = std::vector<TITLE>;

struct MusicOnDeck{
    bool play = false;
    ma_decoder dec;
    FXControlPannel* fxP;
    MusicOnDeck() : fxP(new FXControlPannel(48000)) {};
    ~MusicOnDeck(){
        ma_decoder_uninit(&dec);
        delete fxP;
    }

};


using LOADS         = std::map<TITLE, MusicOnDeck>;



class MusicControlPannel{
private:

    LOADS deck; 
    unsigned long fsize;
    std::vector<float> L;
    std::vector<float> R;
    float* FaustStyle[2] = {L.data(), R.data()};
    SIMD_FLOAT tempFrames;

public:
    int LoadMusic(const musdata& Mus);
    bool CueMusic(const TITLE& title, const unsigned long long newPos);
    bool SetMusic(const TITLE& title, const bool onOff);
    LOADED_LIST GetLoadedMusicList();
    bool UnloadMusic(const TITLE& title);

    bool GetPCMFrames(SIMD_FLOAT* array, const unsigned long FrameSize);
    FXControlPannel* getFXHandle(const TITLE& title);
    MusicControlPannel(const unsigned long FrameSize): fsize(FrameSize){}
    ~MusicControlPannel();

};