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
        0.08,
        "../resource/Music/just-shapes-and-beats--creatures-ov-deception.ogg"
    );
    this->music_library->addMusic(
        "La Danse Macabre",
        "Just Shovels and Knights",
        128,
        0.04,
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
    this->music.setVolume(1);
    this->calculateBeat();
}
void Conductor::displayMusicStatus() {

    if(this->music.getStatus() == sf::Music::Playing) {

        std::cout << "* ================================================================= *" << std::endl;
        std::cout << "| > Now playing : " << this->music_author << " - " << this->music_name << std::endl;
        std::cout << "| > BPM : " << this->music_bpm << " (" << this->music_offset << ")" << std::endl;
        std::cout << "| > Music position : " << this->music.getPlayingOffset().asSeconds() << std::endl;
        std::cout << "| > Second per Beat : " << this->second_per_beat << std::endl;
        std::cout << "| > Beat 1/4 Now : " << this->beat_1_4 << std::endl;

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
    
    int window_width = this->player->getRenderWindow()->getSize().x;

    if(beat % 4 == 0 && beat < 512) {

        int random_x = Randomize::randomIntRange(0, window_width);
        this->player->createBulletEnemy(random_x, 28, 7, 90, "Rectangle");

        this->player->createBulletEnemyCircle(window_width/2, 64, 7, 10, "Rectangle");
    }
    if(beat == 512) {

        int enemy_size = 44;
        int enemy_count_column = 12;
        int enemy_count_row = 4;
        int wave_gap = 25;

        this->player->createEnemyWave(0, -((enemy_size + wave_gap) * enemy_count_row), enemy_count_column, enemy_count_row, wave_gap);
        this->player->moveEnemyWave(0, (enemy_size + wave_gap) * enemy_count_row + enemy_size);
        
        this->player->createBulletEnemyCircle(window_width/2, 64, 7, 10, "Rectangle");
        this->player->createBulletEnemyCircle(window_width/2, 64, 8, 10, "Rectangle");
        this->player->createBulletEnemyCircle(window_width/2, 64, 9, 10, "Rectangle");
    }
    if(beat % 8 == 0 && beat > 512) {

        this->player->moveEnemyWave();
    }
    if(beat % 4 == 0 && beat >= 768) {

        int random_x = Randomize::randomIntRange(0, window_width);
        this->player->createBulletEnemy(random_x, 28, 7, 90, "Rectangle");

        random_x = Randomize::randomIntRange(0, window_width);
        this->player->createBulletEnemy(random_x, 28, 7, 90, "Rectangle");

        if(beat % 16 == 0) {
            this->player->createBulletEnemyCircle(window_width/2, 64, 7, 5, "Rectangle");

            this->player->createParticleCircle(window_width / 2, -8, 255, 255, 255, 255, 255, 85, 85);
        }
        else if(beat % 16 == 8) {
            this->player->createBulletEnemyCircle(window_width, 64, 7, 5, "Rectangle");
            this->player->createBulletEnemyCircle(0, 64, 7, 5, "Rectangle");

            this->player->createParticleCircle(window_width, -8, 255, 255, 255, 255, 255, 85, 85);
            this->player->createParticleCircle(0, -8, 255, 255, 255, 255, 255, 85, 85);
        }
    }
    
}