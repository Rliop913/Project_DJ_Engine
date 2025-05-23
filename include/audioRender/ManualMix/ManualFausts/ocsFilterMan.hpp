#pragma once
#include "DeckData.hpp"

class OcsFilterMan{
public:
    int ocsFilterHighLowSW;
    int middleFreq;
    int rangeFreqHalf;
    float bps;
    float OCSFilterDryWet;
    ARGSETTER
    makeArgSetter(){
        return {
            {"ocsFilterHighLowSW", [this](double value) {
                this->ocsFilterHighLowSW = static_cast<int>(value);
            }},
            {"middleFreq", [this](double value) {
                this->middleFreq = static_cast<int>(value);
            }},
            {"rangeFreqHalf", [this](double value) {
                this->rangeFreqHalf = static_cast<int>(value);
            }},
            {"bps", [this](double value) {
                this->bps = static_cast<float>(value);
            }},
            {"OCSFilterDryWet", [this](double value) {
                this->OCSFilterDryWet = static_cast<float>(value);
            }}
        };
    }
};