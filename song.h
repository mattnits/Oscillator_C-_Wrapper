#ifndef Song_H
#define Song_H
#include <iostream>
#include <string>
#include <vector>

class Song {
    private:
        std::string fileName;
        std::string songName;
        std::vector<std::string> artistNames;
        std::vector<std::string> artistIDs;
        std::string songID;
        std::string songMode;
        std::string albumImage;
        int length;
        std::string fileSize;
        std::string bitRate;
        std::string sampleRate;
        float bpm;
        std::string key;

        int _errorState;

        int songLengthToSeconds(std::string songLength);

        // Debug Methods
        void _printDataList(std::vector<std::string> songDataList);

    public:
        // Constructors
        Song();
        Song(std::vector<std::string> songDataList);
        Song(std::string songName, std::string songID, std::vector<std::string> artistNames, std::vector<std::string> artistIDs,
                std::string songBpm, std::string songLength, std::string songKey, std::string songMode,  std::string albumImage);

        // Setters
        void setSongName(std::string newSongName);
        void setArtistNames(std::vector<std::string> newArtistName);
        void setSongBpm(std::string newBpm);
        void setSongLength(std::string newSongLength);
        void setSongLength(int newSongLength);
        void setFileSize(std::string newFileSize);
        void setBitRate(std::string newBitRate);
        void setSampleRate(std::string newSampleRate);
        void setSongKey(std::string newSongKey);
        void setSongID(std::string newSongID);
        void setArtistIDs(std::vector<std::string> newArtistIDs);
        void setSongMode(std::string newSongMode);
        void setAlbumImage(std::string newAlbumImage);
        void setFileName(std::string newFileName);

        // Getters
        std::string getFileName() {return fileName;}
        std::string getSongName() {return songName;}
        std::vector<std::string> getArtistList() {return artistNames;}
        std::string getArtistNames();
        float getSongBpm() {return bpm;}
        int getSongLength() {return length;}
        std::string getFileSize() {return fileSize;}
        std::string getBitRate() {return bitRate;}
        std::string getSampleRate() {return sampleRate;}
        std::string getSongKey() {return key;}
        std::string getSongID() {return songID;}
        std::vector<std::string> getArtistIDs() {return artistIDs;}
        std::string getSongMode() {return songMode;}
        std::string getAlbumImage() {return albumImage;}

        // Methods
        void printSongData();
        std::string printVector(std::vector<std::string> vec);
        int inErrorState() {return _errorState;}
};

#endif
