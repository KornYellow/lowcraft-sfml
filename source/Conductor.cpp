#include "include/Conductor.h"

//Music Library
void Conductor::initMusicLibrary() {

    this->music_library = new MusicLibrary();
}

//Constructor and Destructor
Conductor::Conductor() {

    this->initMusicLibrary();

    this->music_library->addMusic(
        "Creatures Ov Deception", "Just Shapes and Beats",
        190,
        0.04,
        "../resource/Music/just-shapes-and-beats--creatures-ov-deception.ogg"
    );
    this->music_library->addMusic(
        "La Danse Macabre",
        "Just Shovels and Knights",
        128,
        -0.02,
        "../resource/Music/just-shovels-and-knights--la-danse-macabre.ogg"
    );
}
Conductor::~Conductor() {

    delete this->music_library;
}

//Music
void Conductor::playMusic(std::string music_name) {

    this->music_name = this->music_library->getMusic(music_name)->getMusicName();
    this->music_author = this->music_library->getMusic(music_name)->getMusicAuthor();
    this->music_bpm = this->music_library->getMusic(music_name)->getMusicBPM();
    this->music_offset = this->music_library->getMusic(music_name)->getMusicOffset();
    this->music_path = this->music_library->getMusic(music_name)->getMusicPath();
    
    if(!this->music.openFromFile(this->music_path)) abort();
    this->music.play();
    this->calculateBeat();
}
void Conductor::displayMusicStatus() {

    if(this->music.getStatus() == sf::Music::Playing) {

        std::cout << "* ================================================================= *" << std::endl;
        std::cout << "| > Now playing : " << this->music_author << " - " << this->music_name << std::endl;
        std::cout << "| > BPM : " << this->music_bpm << std::endl;
        std::cout << "| > Music position : " << this->music.getPlayingOffset().asSeconds() << std::endl;
        std::cout << "| > Second per Beat : " << this->second_per_beat << std::endl;

        int beat_show = ((this->beat_1_4 - 1) % 4);
        std::cout << "| > 1/4  ";
        for(int i = 0; i < 4; i++) {
            if(i <= beat_show) std::cout << " ⊠⊠⊠⊠⊠⊠⊠";
        }
        std::cout << std::endl;

        beat_show = ((this->beat_1_8 - 1) % 8);
        std::cout << "| > 1/8  ";
        for(int i = 0; i < 8; i++) {
            if(i <= beat_show) std::cout << " ⊠⊠⊠";
        }
        std::cout << std::endl;

        beat_show = ((this->beat_1_16 - 1) % 16);
        std::cout << "| > 1/16 ";
        for(int i = 0; i < 16; i++) {
            if(i <= beat_show) std::cout << " ⊠";
        }
        std::cout << std::endl;
        
        std::cout << "* ================================================================= *" << std::endl;
    }
}

//Conductor
void Conductor::calculateBeat() {

    this->beat_1 = 0;
    this->beat_1_2 = 0;
    this->beat_1_4 = 0;
    this->beat_1_8 = 0;
    this->beat_1_16 = 0;
    this->beat_1_32 = 0;
    this->beat_next_treshold = this->music_offset;

    this->second_per_beat = (60 / (float)this->music_bpm) / 8;
}
void Conductor::manageBeat() {

    if(this->music.getPlayingOffset().asSeconds() > this->beat_next_treshold) {

        this->beat_next_treshold += this->second_per_beat;

        this->beat_1_32 ++;
        if((this->beat_1_32 + 1) % 2 == 0) {
            this->beat_1_16 ++;
            if((this->beat_1_16 + 1) % 2 == 0) {
                this->beat_1_8 ++;
                if((this->beat_1_8 + 1) % 2 == 0) {
                    this->beat_1_4 ++;
                    if((this->beat_1_4 + 1) % 2 == 0) {
                        this->beat_1_2 ++;
                        if((this->beat_1_2 + 1) % 2 == 0) {
                            this->beat_1 ++;
                        }
                    }
                }
            }
        }
        this->beatActionCreaturesOvDeception(this->beat_1_32);
    }
}

//Player
void Conductor::setPlayer(Player* player) {

    this->player = player;
}
Player* Conductor::getPlayer() {

    return this->player;
}

//Functions
void Conductor::update() {
    
    this->manageBeat();
    //this->displayMusicStatus();
}

//Beat Action
void Conductor::beatActionCreaturesOvDeception(int beat) {

    if(beat % 4 == 0) {

        int window_width = this->player->getRenderWindow()->getSize().x;
        int random_x = Randomize::randomIntRange(0, window_width);
        this->player->createBulletEnemy(random_x, 28, 4, 90, "Rectangle");
    }
}