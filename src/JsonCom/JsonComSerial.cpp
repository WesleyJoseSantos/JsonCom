/**
 * @file JsonComSerial.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "JsonComSerial.h"

JsonComSerial::JsonComSerial()
{
}

void JsonComSerial::init(){

}

void JsonComSerial::task(){
    if(serial->available()){
        status = ST_RECEIVED;
    }

    switch (status)
    {
    case ST_WAITING_DATA:
        
        break;
    case ST_RECEIVED:
        deserializeJson(jsonRx, serial->readStringUntil('\n'));
        status = ST_READ;
        break;
    case ST_READ:
        sendData();
        break;
    case ST_WRITTEN:
        
        break;
    default:
        break;
    }
}

void JsonComSerial::sendData(){
    serializeJson(jsonTx, *serial);
        serial->println();
        status = ST_WAITING_DATA;
}

void JsonComSerial::setSerial(Stream *serial){
    this->serial = serial;
}