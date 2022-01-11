#include "Oscillator_Wrapper.h"
#include "Http_Request.h"
#include "json.hpp"

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


void querySong(std::string songName, std::string artistName) {
    std::string query = "https://api-oscillator.herokuapp.com/search?song=" + songName + "&artist=" + artistName;
    struct memory results;

    query = urlify(query);
    const char *url = query.c_str();
    results = createSocket(url);

    // for (int i = 0; i < results.size; i++){
    //     std::cout << results.memory[i];
    // }
    // std::cout << std::endl;

    nlohmann::json jsonSongInfo = nlohmann::json::parse(results.memory);
    std::cout << std::setw(4) << jsonSongInfo << std::endl;

    cleanMemory(results);

    return ;
}

