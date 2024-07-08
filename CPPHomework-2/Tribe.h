#pragma once
#include "Survivor.h"
#include "algorithm"
#include "cstring"
class Tribe
{
private:
    string _tribeName;
    int _maxSurvivors;
    int _numSurvivors;
    Survivor** _survivorsArray;
    static bool compareSurvivorNames(Survivor* a, Survivor* b) {
        return a->getName().std::string::compare(b->getName()) < 0;
    }
public:
    void findYoungest();
    Tribe(string n="Tzofim",int max=10);
    void setTribe(string n = "Tzofim", int max = 10);
    ~Tribe();
    void printTribe() const;
    void addSurivovrToTribe();
    void removeSurivorFromTribe();
    int findSurvivorByName(string n);
    void MENU();
    void sortTribe();
};

