//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_RULES_H
#define PEXESO_RULES_H


class Rules {
private:
    bool isPaired;
    int difficulty;
public:
    Rules();
    bool checkPair(int rows, int columns);
    bool getPairedStatus();
    int getDifficulty();
};


#endif //PEXESO_RULES_H
