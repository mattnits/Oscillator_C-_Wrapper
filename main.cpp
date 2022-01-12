#include "Oscillator_Wrapper.h"


int main() {
    std::vector<Song> songResults;
    // testConnection();
    songResults = querySong("", "Seven Lions");

    for (int i = 0; i < songResults.size(); i++)
    {
        songResults.at(i).printSongData();
    }
    

    return 1;
}