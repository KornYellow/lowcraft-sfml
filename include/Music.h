#pragma once

#include <iostream>
#include <string>

class Music {

    private :
        
        //Music
        std::string music_path;
        std::string music_name;
        std::string music_author;
        int music_bpm;
        double music_offset;

    public :

        //Constructor and Destructor
        Music(std::string music_name, std::string music_author, int music_bpm, double music_offset, std::string music_path);
        virtual ~Music();

        //Music
        void setMusicPath(std::string music_path);
        std::string getMusicPath();
        void setMusicName(std::string music_name);
        std::string getMusicName();
        void setMusicAuthor(std::string music_author);
        std::string getMusicAuthor();
        void setMusicBPM(int music_bpm);
        int getMusicBPM();
        void setMusicOffset(double music_offset);
        double getMusicOffset();
};