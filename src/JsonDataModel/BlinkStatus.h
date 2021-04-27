/**
 * @file BlinkStatus.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __BLINKSTATUS__H__
#define __BLINKSTATUS__H__

#include "JsonDataModel.h"

class BlinkStatus : JsonDataModel
{
private:
    
public:
    int blinkCount;
    bool ledStatus;
    BlinkStatus();
    StaticJsonDocument<MODEL_SIZE> toJson() override;
    void fromJson(StaticJsonDocument<MODEL_SIZE> json) override;
};

BlinkStatus::BlinkStatus()
{

}

StaticJsonDocument<MODEL_SIZE> BlinkStatus::toJson(){
    StaticJsonDocument<MODEL_SIZE> json;
    JSONCOM_WRITE_VARIABLE(json, blinkCount);
    JSONCOM_WRITE_VARIABLE(json, ledStatus);
}

void BlinkStatus::fromJson(StaticJsonDocument<MODEL_SIZE> json){
    JSONCOM_READ_VARIABLE(json, blinkCount);
    JSONCOM_READ_VARIABLE(json, ledStatus);
}

#endif  //!__BLINKSTATUS__H__