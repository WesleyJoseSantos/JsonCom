/**
 * @file JsonComSerial.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __JSONCOMSERIAL__H__
#define __JSONCOMSERIAL__H__

#include "JsonCom.h"
#include "Stream.h"

class JsonComSerial : public JsonCom
{
private:
    Stream *serial;
public:
    JsonComSerial();
    void init() override;
    void task() override;
    void sendData() override;
    void setSerial(Stream *serial);
};

#endif  //!__JSONCOMSERIAL__H__