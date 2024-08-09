#include "charecter.h"
//#include <cstdlib>

Charecter::Charecter() {

    name = " ";
    race = " ";
    sex = " ";

    playerRace = { "elf", "dwarf", "orc", "goblin", "human" };

    level = 0, health = 0, totalHP = 0, maxHP = 2, heal = 0;

    level = 1, current_EXP = 0, base_EXP = 83, EXP_to_level = base_EXP, minlevel = 1, maxlevel = 60;
}

void Charecter::charecterCreation() {

        int counter = 0;

        // Charecter creation
        std::cout << "Enter charecter name: ";
        std::cin >> name;

        std::cout << "Enter charecter race\n";
        std::cout << "Elf\n";
        std::cout << "Dwarf\n";
        std::cout << "Orc\n";
        std::cout << "Goblin\n";
        std::cout << "Human\n";
        std::cout << "Type below your race: \n\n";
        std::cin >> race;

        std::for_each(race.begin(), race.end(), [](char & c) {      // Make input charecters in lowercase to match playerRace array.
            c = ::tolower(c);
        });

        for (int i = 0; i < sizeof(playerRace); i++) {
            if (race == "elf") {
                health = 85;
                break;
            }
            if (race == "dwarf") {
                health = 120;
                break;
            }
            if (race == "orc") {
                health = 150;
                break;
            }
            if (race == "goblin") {
                health = 70;
                break;
            }
            if (race == "human") {
                health = 100;
                break;
            }
            else {
                health = 100;
                break;
            }
        }

        std::cout << "\n";
        std::cout << "Enter charecter sex: ";
        std::cin >> sex;
        std::system("clear");

        // "Loading screen"
        for (int i = 0; i <= counter; i++) {
            if (i == 0)
                std::cout << "Creating Charecter.\n";
            if (i == 1)
                std::cout << "Creating charecter..\n";
            if (i == 2)
                std::cout << "Creating charecter...\n";
            break;
            Sleeps(400);
            std::system("clear");
            counter++;
        }

        name[0] = toupper(name[0]);
        race[0] = toupper(race[0]);
        sex[0] = toupper(sex[0]);

       // health = 100;
        totalHP = health;
        maxHP = totalHP;
}
