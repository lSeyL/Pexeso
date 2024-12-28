//
// Created by seil0 on 28. 12. 2024.
//

#include "Rules.h"

Rules::Rules() {
    isPaired = false;
    difficulty = 1;
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

int Rules::getDifficulty() {
    return difficulty;
}

