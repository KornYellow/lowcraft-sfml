#include "include/Randomize.h"

//Functions
int Randomize::randomInt(int a) {

    return rand() % a;
}
int Randomize::randomIntRange(int a, int b) {

    return rand() % b + a;
}