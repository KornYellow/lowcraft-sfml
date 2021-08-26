#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "include/Music.h"

class MusicLibrary {

    private :
        
        //Music Library
        std::vector <Music*> musics;

    public :

        //Constructor and Destructor
        MusicLibrary();
        virtual ~MusicLibrary();

        //Music
        void addMusic(std::string music_name, std::string music_author, int music_bpm, double music_offset, std::string music_path);
        Music* getMusic(std::string music_name);
};