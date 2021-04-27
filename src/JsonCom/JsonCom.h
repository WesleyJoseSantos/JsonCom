/**
 * @file JsonCom.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __JSONCOM__H__
#define __JSONCOM__H__

#include "JsonDef.h"
#include "ArduinoJson.h"
#include "JsonDataModel/JsonDataModel.h"

enum JconComStatus
{
    ST_WAITING_DATA,
    ST_RECEIVED,
    ST_READ,
    ST_WRITTEN,
};

class JsonCom
{
protected:
    StaticJsonDocument<SIZE_RX> jsonRx;
    StaticJsonDocument<SIZE_TX> jsonTx;
    JconComStatus status;
public:
    JsonCom();
    virtual void init();
    virtual void task();
    virtual void sendData();

    void writeJsonData(JsonDataModel json){
        deserializeJson(jsonTx, json.toJson());
    }

    void readJsonData(JsonDataModel json){
        String data;
        serializeJson(jsonRx, data);
        json.fromJson(data);
    }

    template< typename T> 
    void writeVariable(String path, T *variable){
        if(status == ST_READ || status == ST_WRITTEN){
            jsonTx[path] = *variable;
            status = ST_WRITTEN;
        }
    }

    template< typename T> 
    void readVariable(String path, T *variable){
        if(jsonRx.containsKey(path)) *variable = json[path];
    }
}; 

#endif  //!__JSONCOM__H__