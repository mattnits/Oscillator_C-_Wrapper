#ifndef OSCILLATOR_WRAPPER_H
#define OSCILLATOR_WRAPPER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <curl/curl.h>
#include "song.h"
#include "json.hpp"

// Main Functions
int testConnection();
std::vector<Song> querySong(std::string songName, std::string artistName);
nlohmann::json querySongJson(std::string songName, std::string artistName);
const char * querySongString(std::string songName, std::string artistName);

// Helper Functions
std::string eraseChars(std::string str);
Song parseQueryData(auto array);



#endif