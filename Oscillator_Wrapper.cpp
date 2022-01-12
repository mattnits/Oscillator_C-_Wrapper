#include "Oscillator_Wrapper.h"
#include "Http_Request.h"

using nlohmann::json;

int testConnection() {
    char *url;
    url = "https://api-oscillator.herokuapp.com/";
    struct memory results;
    results = createSocket(url);

    for (int i = 0; i < results.size; i++) {
        std::cout << results.memory[i];
    }
    std::cout << std::endl;

    cleanMemory(results);

    return 1;
}


std::vector<Song> querySong(std::string songName, std::string artistName) {
    std::string query = "https://api-oscillator.herokuapp.com/search?song=" + songName + "&artist=" + artistName;
    struct memory results;
    std::vector<Song> songResults;
    
    query = urlify(query);
    const char *url = query.c_str();
    results = createSocket(url);

    json j = json::parse(results.memory);
    
    for (auto &array : j["results"]) {
        Song song = parseQueryData(array);
        songResults.push_back(song);
    }

    cleanMemory(results);

    return songResults;
}

json querySongJson(std::string songName, std::string artistName) {
    std::string query = "https://api-oscillator.herokuapp.com/search?song=" + songName + "&artist=" + artistName;
    struct memory results;
    std::vector<Song> songResults;
    
    query = urlify(query);
    const char *url = query.c_str();
    results = createSocket(url);

    json j = json::parse(results.memory);

    return j;
}

const char * querySongString(std::string songName, std::string artistName) {
    std::string query = "https://api-oscillator.herokuapp.com/search?song=" + songName + "&artist=" + artistName;
    struct memory results;
    std::vector<Song> songResults;
    
    query = urlify(query);
    const char *url = query.c_str();
    results = createSocket(url);

    json j = json::parse(results.memory);

    return j.dump().c_str();
}


std::string eraseChars(std::string str) {
    str.erase(remove(str.begin(), str.end(), '"'), str.end());
    return str;
}

Song parseQueryData(auto array) {
    std::string sName, sID, sBpm, sLength, sKey, sMode, sImage, aName, aID;
    std::vector<std::string> aNames, aIDs;


    sName = array["songName"].dump().c_str();
    sID = array["songID"].dump().c_str();
    sBpm = array["tempo"].dump().c_str();
    sLength = array["duration"].dump().c_str();
    sKey = array["key"].dump().c_str();
    sMode = array["mode"].dump().c_str();
    sImage = array["albumImage"].dump().c_str();
    sName = eraseChars(sName);
    sID = eraseChars(sID);
    sKey = eraseChars(sKey);
    sMode = eraseChars(sMode);
    sImage = eraseChars(sImage);

    for (int i = 0; i < array["artists"].size(); i++) {
        // std::cout << array["artists"][i] << std::endl;
        aName = array["artists"][i].dump().c_str();
        aID = array["artistID"][i].dump().c_str();
        aName = eraseChars(aName);
        aID = eraseChars(aID);
        aNames.push_back(aName);
        aIDs.push_back(aID);            
    }

    Song song(sName, sID, aNames, aIDs, sBpm, sLength, sKey, sMode, sImage);

    aNames.clear();
    aIDs.clear();
    return song;
}

