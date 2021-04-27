/**
 * @file BlinkParameters.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __BLINKPARAMETERS__H__
#define __BLINKPARAMETERS__H__

#include "JsonCom.h"

class BlinkParameters : JsonDataModel
{
public:
    int time;
    bool start;
    BlinkParameters();
    StaticJsonDocument<MODEL_SIZE> toJson() override;
    void fromJson(StaticJsonDocument<MODEL_SIZE> json) override;
};

BlinkParameters::BlinkParameters()
{

}

StaticJsonDocument<MODEL_SIZE> BlinkParameters::toJson(){
    StaticJsonDocument<MODEL_SIZE> json;
    JSONCOM_WRITE_VARIABLE(json, time);
    JSONCOM_WRITE_VARIABLE(json, start);
}

void BlinkParameters::fromJson(StaticJsonDocument<MODEL_SIZE> json){
    JSONCOM_READ_VARIABLE(json, time);
    JSONCOM_READ_VARIABLE(json, start);
}

#endif  //!__BLINKPARAMETERS__H__