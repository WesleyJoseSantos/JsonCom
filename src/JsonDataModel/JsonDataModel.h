/**
 * @file JsonDataModel.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __JSONDATAMODEL__H__
#define __JSONDATAMODEL__H__

#include "JsonCom.h"

class JsonDataModel
{
private:
public:
    JsonDataModel();
    virtual StaticJsonDocument<MODEL_SIZE> toJson();
    virtual void fromJson(StaticJsonDocument<MODEL_SIZE> json);
};

#endif  //!__JSONDATAMODEL__H__