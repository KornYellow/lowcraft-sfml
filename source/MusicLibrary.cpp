#include "include/MusicLibrary.h"

//Constructor and Destructor
MusicLibrary::MusicLibrary() {

}
MusicLibrary::~MusicLibrary() {

}

//Music
void MusicLibrary::addMusic(std::string music_name, std::string music_author, int music_bpm, double music_offset, std::string music_path) {

    Music* music = new Music(music_name, music_author, music_bpm, music_offset, music_path);
    this->musics.push_back(music);
}
Music* MusicLibrary::getMusic(std::string music_name) {

    int is_found = -1;
    for(int i = 0; i < this->musics.size(); i++) {

        if(this->musics.at(i)->getMusicName() == music_name) {

            is_found = i;
        }
    }
    
    if(is_found == -1) {

        std::cout << "error: cannot find music \'" << music_name << "\' in the library." << std::endl;
        abort();
    }
    return this->musics.at(is_found);
}