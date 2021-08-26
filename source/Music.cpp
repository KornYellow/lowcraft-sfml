#include "include/Music.h"

//Constructor and Destructor
Music::Music(std::string music_name, std::string music_author, int music_bpm, double music_offset, std::string music_path) {

    this->music_name = music_name;
    this->music_author = music_author;
    this->music_bpm = music_bpm;
    this->music_offset = music_offset;
    this->music_path = music_path;
}
Music::~Music() {

}

//Music
void Music::setMusicPath(std::string music_path) {
    
    this->music_path = music_path;
}
std::string Music::getMusicPath() {
    
    return this->music_path;
}
void Music::setMusicName(std::string music_name) {

    this->music_name = music_name;
}
std::string Music::getMusicName() {

    return this->music_name;
}
void Music::setMusicAuthor(std::string music_author) {

    this->music_author;
}
std::string Music::getMusicAuthor() {

    return this->music_author;
}
void Music::setMusicBPM(int music_bpm) {

    this->music_bpm = music_bpm;
}   
int Music::getMusicBPM() {

    return this->music_bpm;
}
void Music::setMusicOffset(double music_offset) {

    this->music_offset = music_offset;
}
double Music::getMusicOffset() {

    return this->music_offset;
}