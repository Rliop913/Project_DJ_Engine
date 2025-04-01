#include "MixMachine.hpp"


template<>
bool
MixMachine::TypeWorks<TypeEnum::EQ, FaustEffects>
(MixStruct& ms, FaustEffects& data, SIMD_FLOAT* Vec)
{
    if(!InterpolateInit(data.eqData, Vec, ms)){
        return false;
    }
    switch (ms.RP.getDetails())
    {
    case DetailEnum::HIGH:
        data.eqData.back().EQSelect = 0;
        break;
    case DetailEnum::MID:
        data.eqData.back().EQSelect = 1;
        break;
    case DetailEnum::LOW:
        data.eqData.back().EQSelect = 2;
        break;
    default:
        break;
    }
    return true;
}