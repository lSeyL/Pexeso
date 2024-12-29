//
// Created by seil0 on 28. 12. 2024.
//

#include "Rules.h"

Rules::Rules() {
    isPaired = false;
    difficulty = 1;
    mode = 0; // 0 - neobmedzeny, 1 - casovo obmedzeny
}

bool Rules::checkPair(int rows, int columns) {
    if(rows * columns % 2 != 0)
    {
        return isPaired = false;
    } else {
        return isPaired = true;
    }
}

bool Rules::getPairedStatus() {
    return isPaired;
}

void Rules::setDifficulty(int dif) {
    difficulty = dif;
}

void Rules::setMode(int mod) {
    mode = mod;
}

int Rules::getDifficulty() {
    return difficulty;
}

int Rules::getMode() {
    return mode;
}


