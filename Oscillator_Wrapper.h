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
std::vector<Song> recommendSong(std::string songID, std::string artistID, std::string key = "", std::string bpm = "");
nlohmann::json recommendSongJson(std::string songID, std::string artistID, std::string key = "", std::string bpm = "");
const char * recommendSongString(std::string songID, std::string artistID, std::string key = "", std::string bpm = "");

// Helper Functions
std::string eraseChars(std::string str);
Song parseQueryData(auto array);



#endif