#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>


struct memory {
    char *memory;
    size_t size;
};


memory createSocket(const char *url);
size_t writeCallback(char *ptr, size_t size, size_t nmemb, void *userdata);
void cleanMemory(memory mem);
std::string urlify(std::string& s);


#endif