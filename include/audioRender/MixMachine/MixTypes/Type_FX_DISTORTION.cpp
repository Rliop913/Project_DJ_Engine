#include "MixMachine.hpp"

template<>
bool
MixMachine::TypeWorks<TypeEnum::DISTORTION, FaustEffects>
(MixStruct& ms, FaustEffects& data, std::vector<float>* Vec)
{
    if(!InterpolateInit(data.distortionData, Vec, ms)){
        return false;
    }
    return true;
}