/**
 * @file JsonComHelper.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __JSONCOMHELPER__H__
#define __JSONCOMHELPER__H__

#define writeVariable(x) writeVariable(#x, &x)      
#define readVariable(x) readVariable(#x, &x)  

#define JSONCOM_READ_VARIABLE(json, var) if(json.containsKey(#var)) var = json[#var]
#define JSONCOM_WRITE_VARIABLE(json, var) json[#var] = var


#endif  //!__JSONCOMHELPER__H__