#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/MusicLibrary.h"

class Conductor {

    private :
        
        //Music
        sf::Music music;
        std::string music_name;
        std::string music_author;
        int music_bpm;
        double music_offset;
        std::string music_path;

        void displayMusicStatus();

        //Music Library
        MusicLibrary* music_library;
        
        //Initialize
        void initMusicLibrary();

        //Conductor
        double second_per_beat;

        int beat_1;
        int beat_1_2;
        int beat_1_4;
        int beat_1_8;
        int beat_1_16;
        int beat_1_32;
        double beat_next_treshold;

        void calculateBeat();
        void manageBeat();

    public :

        //Constructor and Destructor
        Conductor();
        virtual ~Conductor();

        //Music
        void playMusic(std::string music_name);

        //Functions
        void update();
};