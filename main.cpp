#include "Oscillator_Wrapper.h"


int main() {
    std::vector<Song> songResults;
    // testConnection();
    // songResults = querySong("", "Seven Lions");
    songResults = recommendSong("2U0pVx4m1Kdm1Gsjjm6iq8", "6fcTRFpz0yH79qSKfof7lp", "0", "130");

    for (int i = 0; i < songResults.size(); i++)
    {
        songResults.at(i).printSongData();
    }
    

    return 1;
}