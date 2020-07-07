#include"MAP2D.h"

template <typename T>
uint8_t MAP2D_::INIT_MAP(T TOKEN){
    UTILITY *funcs = new UTILITY;
    uint8_t ID = funcs -> GENERATE_ID();
    if(TOKEN == INIT){
        ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][0] = ID;
        ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][0] = IACD_count;
        IACD_count++;
        delete funcs;
        return ID;
    } else {
       //Add check function 
    }
}

template <typename T>
uint8_t MAP2D_::UPDATE_2D(T ID,T bearing, T value){
    if(searchTable(ID,bearing) != (-1)){
        ADD_ON_TO_TABLE(ID,searchTable(ID,bearing),value);
    }else{

    }
}

template <typename T>
uint8_t  MAP2D_::ADD_ON_TO_TABLE(T ID,uint8_t index,T value){
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    MAP[mapLocationIndex][index][1] = value;
    //ATTACH_TO_JSON();
    return 1;
}

template <typename T>
uint8_t  MAP2D_::searchTable(T ID,T bearing){
    //Get 
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    signed int finalIndex = -1;
    for(size_t i = 0; i < mapSize;++i){
        if(MAP[mapLocationIndex][i][0] != bearing){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    return finalIndex;
}

uint8_t MAP2D_::ATTACH_TO_JSON(){

}

uint8_t MAP2D_::GET_ID_INDEX_CORRELATION(uint8_t ID){
    signed int finalIndex = -1;
    for(size_t i = 0; i < mapSize;++i){
        if(ID_ARRAYINDEX_CORRELATION_DATA[i][0] != ID){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    return finalIndex;
}

 