#include "song.h"


Song::Song() {

}

Song::Song(std::vector<std::string> songDataList) {
    if (songDataList.size() < 9) {
        throw "Error creating Song. Missing values!";
    }
    _errorState = 0;
    fileName = songDataList.at(0);
    songName = songDataList.at(1);
    artistNames.push_back(songDataList.at(2));
    setSongLength(songDataList.at(3));
    fileSize = songDataList.at(4);
    bitRate = songDataList.at(5);
    setSongBpm(songDataList.at(7));
    sampleRate = songDataList.at(6);
    key = songDataList.at(8);

}

Song::Song(std::string songName, std::string songID, std::vector<std::string> artistNames, std::vector<std::string> artistIDs,
                std::string songBpm, std::string songLength, std::string songKey, std::string songMode,  std::string albumImage) {
    setSongName(songName);
    setSongID(songID);
    setArtistNames(artistNames);
    setArtistIDs(artistIDs);
    setSongBpm(songBpm);
    setSongLength(stoi(songLength));
    setSongKey(songKey);
    setSongMode(songMode);
    setAlbumImage(albumImage);
    setFileSize("");
    setBitRate("");
    setSampleRate("");
    setFileName("Oscillator API Query");

}

void Song::setSongName(std::string newSongName) {
    songName = newSongName;
}

void Song::setArtistNames(std::vector<std::string> newArtistName) {
    artistNames = newArtistName;
}

void Song::setSongBpm(std::string newBpm) {
    try {
        float value = (int)(stof(newBpm) * 10 + .5);
        bpm = (float)value / 10;
    } catch (...) {
        std::cout << "Error occured getting BPM\n";
        _errorState = 1;
        bpm = -1;
    }

}

void Song::setSongLength(std::string newSongLength) {
    int secs = songLengthToSeconds(newSongLength);
    length = secs;
}

void Song::setSongLength(int newSongLength) {
    length = newSongLength;
}

int Song::songLengthToSeconds(std::string songLength) {
    int songLen = 0;
    int start = 0;
    int end = songLength.find(":");

    try {
        songLen += 60 * stoi(songLength.substr(start, end - start));
        start = end + 1;
        end = songLength.find(":", start);
        songLen += stoi(songLength.substr(start, end - start));
    } catch (...) {
        std::cout << "Error occured converting song length to seconds\n";
        _errorState = 1;
        songLen = -1;
    }

    return songLen;
}

void Song::setFileSize(std::string newFileSize) {
    fileSize = newFileSize;
}

void Song::setBitRate(std::string newBitRate) {
    bitRate = newBitRate;
}

void Song::setSampleRate(std::string newSampleRate) {
    sampleRate = newSampleRate;
}

void Song::setSongKey(std::string newSongKey) {
    key = newSongKey;
}

void Song::setSongID(std::string newSongID) {
    songID = newSongID;
}

void Song::setArtistIDs(std::vector<std::string> newArtistIDs) {
    artistIDs = newArtistIDs;
}

void Song::setSongMode(std::string newSongMode) {
    songMode = newSongMode;
}

void Song::setAlbumImage(std::string newAlbumImage) {
    albumImage = newAlbumImage;
}

void Song::setFileName(std::string newFileName) {
    fileName = newFileName;
}
std::string Song::getArtistNames() {
    std::string artistString;

    for (int i=0; i < artistNames.size(); i++) {
        if (i < artistNames.size() - 1) {
            artistString += artistNames.at(i) + ", ";
        } else {
            artistString += artistNames.at(i);
        }

    }

    return artistString;
}

std::string Song::printVector(std::vector<std::string> vec) {

    std::string results;
    for (int i = 0; i < vec.size(); i++) {
        if (i < vec.size()-1) {
            results += vec.at(i) + ", ";
        } else {
            results += vec.at(i);
        }
    }

    return results;

}

void Song::printSongData() {
    std::cout << "File:\t\t" << fileName << "\nSong:\t\t" << songName
        << "\nArtist:\t\t" << printVector(artistNames) << "\nLength:\t\t" << length
        << "s\nBPM:\t\t" << bpm << "\nSize:\t\t" << fileSize << "\nBit Rate:\t" << bitRate
        << "\nSample Rate:\t" << sampleRate << "\nKey:\t\t" << key << " " << songMode
        << "\nArtistIDs:\t" << printVector(artistIDs) << "\nsongID:\t\t" << songID
        << "\n---------------------------------------------\n";
}

void Song::_printDataList(std::vector<std::string> songDataList) {
    std::cout << "Data List: \n";
    for (int i = 0; i < (int)songDataList.size(); i++) {
        std::cout << songDataList.at(i) << "\n";
    }

}
