#pragma once

#include "header.h"
//#include <string>
//#include <vector>

class Charecter {
    public:
    Charecter();

    std::string name, race, sex;
    std::vector<std::string> playerRace; // { "elf", "dwarf", "orc", "goblin", "human" };
    int health, totalHP, maxHP, heal;

    int level, current_EXP, base_EXP, EXP_to_level, minlevel, maxlevel;

    void charecterCreation();
};
