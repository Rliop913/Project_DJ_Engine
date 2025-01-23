#include "MixMachine.hpp"


MixMachine::MixMachine()
{
}



bool
MixMachine::IDsort(const MixTranslator& tr)
{
    try
    {    
        for(auto i : tr.mixs.value().mixVec){
            long id = i.RP.getId();
            
            if(Memorized.find(id) == Memorized.end()){
                Memorized[id] = std::vector<MixStruct>();
            }
            Memorized[id].push_back(i);
        }
        
        return true;
    }
    catch(...)
    {
        
        return false;
    }
}


bool
MixMachine::mix(litedb& db, const BPM& bpms)
{
    auto num_threads = Memorized.size();
    for(auto i : Memorized){// todo - impl this to threads
        auto MC = MUSIC_CTR();
        auto DJ = BattleDj();
        auto Filter = FilterFAUST();
        Filter.init(SAMPLERATE);

        DJ.GetDataFrom(MC);
        for(auto j : i.second){
            switch (j.RP.getType()){

            case TypeEnum::BATTLE_DJ: 
                if(TypeWorks<TypeEnum::BATTLE_DJ>(j, DJ)) break;
                else continue;

            case TypeEnum::LOAD: 
                if(TypeWorks<TypeEnum::LOAD>(j, MC, db)
                    && TypeWorks<TypeEnum::LOAD>(j, DJ)) break;
                else continue;
                
            case TypeEnum::CONTROL:
                if(TypeWorks<TypeEnum::CONTROL>(j, MC)) break;
                else continue;

            case TypeEnum::UNLOAD:
                if(TypeWorks<TypeEnum::UNLOAD>(j, MC)) break;
                else continue;


            default:
                break;
            }
        }

        //임시 믹싱 코드 더 효율적 구현 필요 -> HIGHWAY 사용 예정
        std::vector<float> tempVec;
        auto result = DJ << MC.Execute(bpms, &tempVec);
        if(!result.has_value()){
            return false;
        }
        if(rendered_out.size() < (MC.FullPos.value() * CHANNEL)){
            rendered_out.resize((MC.FullPos.value() * CHANNEL));
        }
        auto Rptr = rendered_out.data() + (MC.StartPos.value() * CHANNEL);
        auto Tptr = tempVec.data();
        for(unsigned long i = MC.StartPos.value(); i < (MC.FullPos.value() - MC.StartPos.value()) * CHANNEL; ++i){
            (*Rptr) += (*Tptr);
            ++Rptr;
            ++Tptr;
        }
        // memcpy(Rptr, tempVec.data(), (MC.FullPos.value() - MC.StartPos.value()) * CHANNEL);
        
    }

    //todo - implement mix
    return true;
}

MixMachine::~MixMachine()
{
    
}