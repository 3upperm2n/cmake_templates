#ifndef _HELLO_H
#define _HELLO_H

#include <iostream>                                                             
#include <string>     

#ifdef __cplusplus
extern "C" {
#endif

void hello(const std::string &input);

#ifdef __cplusplus
}
#endif

#endif
