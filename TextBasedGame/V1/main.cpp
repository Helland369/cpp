//
// Credits to code Bot; https://www.youtube.com/watch?v=KgqCic2ERiM&list=PLoAoZw952_FQnNB0BMCTD5YJyFKMT13RQ&index=1
//

//#include "header.h"
#include "charecter.h"
#include "charecter.cpp"
#include "header.h"

// Shortening the line for the sleep function
/*void Sleep500() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Sleep200() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
*/

//(void Sleeps(int milliseconds) {
//    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
//}

// Declaring functions
void HUD();
void CombatHUD();
void combat();
void moving();
void createMonster();
void LevelUp();

// Globale variables
//:std::string name = " ", race = " ", sex = " ";
//int level = 0, EXP = 0, health = 0, totalHP = 0, maxHP = 0, nextlvl = 0, heal = 0;

int monsterHP = 0;
int monsterEXP = 0;
int monsterLevel = 0;

std::string monsterName[] = {"Goblin", "Dwarf", "Orc", "Ogre", "Deamon", "Troll"};
int currentMonsterName = 5;
std::string currentMonster = " ";

int counter = 0;

Charecter charecter;

int main() {

    charecter.charecterCreation();

    HUD();
    moving();

    return 0;
}

void HUD() {
    Sleeps(500);
    std::system("clear");
    std::cout << "Name: " << charecter.name << "\t\tHealth: " << charecter.totalHP << "\nRace: " << charecter.race
        << "\nSex: " << charecter.sex << "\nLevel: " << charecter.level << "\nEXP: " << charecter.current_EXP << "\nEXP to lvl: " << charecter.EXP_to_level << std::endl;

    moving();
}

void CombatHUD() {
    Sleeps(500);
    std::system("clear");
    std::cout << "Name: " << charecter.name << "\t\t|\t\tMonster Name: " <<  currentMonster << "\nHealth: " << charecter.totalHP <<"\t\t|\t\tMonster Health: "
        << monsterHP << "\nLevlel: " << charecter.level << "\t\t|\t\tMonster Level: " << monsterLevel << std::endl;
}

void combat() {
    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * charecter.level / 2;
    int monsterAttack = 6 * monsterLevel / 2;

    if (charecter.totalHP >= 1 && monsterHP >= 1) {
        std::cout << "\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Block\n";
        std::cout << "3. RUN!!\n";
        std::cout << "\n";
        std::cin >> playerAttack;

        if (playerAttack == 1) {
            // Attack
            std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
            monsterHP = monsterHP - playerDamage;
            Sleeps(1000);
            CombatHUD();
            if (monsterHP >= 1) {
                std::cout << "\n";
                std::cout << "Monster is Attcking...\n";
                charecter.totalHP = charecter.totalHP - monsterAttack;
                std::cout << "You suffered " << monsterAttack << "hp " << charecter.totalHP << std::endl;
                // Change to function.
                if (charecter.totalHP <= 0) {
                    charecter.totalHP = 0;
                    std::system("clear");
                    std::cout << "You Died! \nYou were level: " << charecter.level << " you got killed by " << currentMonster << std::endl;
                    Sleeps(2000);
                    exit(0);
                }
            }
            else if (monsterHP <= 0) {
                monsterHP = 0;
                std::cout << "\n";
                std::cout << "You Defeated " << currentMonster <<  " you are rewarded with " << monsterEXP << "Exp.\nWell done!\n";

                if (charecter.level != charecter.maxlevel) {
                    charecter.current_EXP = charecter.current_EXP + monsterEXP;
                    LevelUp();
                }

                Sleeps(1000);
                HUD();
            }
            Sleeps(1000);
            combat();
        }
        else if (playerAttack == 2) {
            // Block
            std::cout << "Blocking\n";
            int i = rand() % 100 + 1;
            if (i >= 50) {  // 50/50 chanse to block.
                std::cout << "You Blocked the incoming attack\n";
                charecter.heal = charecter.level * 10 / 2;
                std::cout << "You have been healed for " << charecter.heal << std::endl;
                charecter.totalHP += charecter.heal;
                Sleeps(1000);
                combat();
            }
            else {
                std::cout << "You failed to block the savage attack\n";
                charecter.totalHP -= monsterAttack;
                std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << charecter.totalHP << std::endl;
                Sleeps(1000);
                combat();
            }
        }
        else if (playerAttack == 3) {
            // Run
            std::cout << "You try to run\n";
            int x = rand() % 100 + 1;
            if (x >= 50) {
                std::cout << "You run away!\n";
                HUD();
            }
            else {
                std::cout << "You failed to run away\n";
                std::cout << "Monster does a savage attack on you!\n";
                charecter.totalHP -= monsterAttack + 10;
                std::cout << "You suffered " << monsterAttack + 10<< "Your current Health is " << charecter.totalHP << std::endl;
                Sleeps(1000);
                combat();
            }

        }
        else {
            std::cout << "Invalid choise\n";
            Sleeps(500);
            combat();
        }
    }
//    if (totalHP <= 1) {
//        std::system("clear");
//        std::cout << "You Died! \nYou were level: " << level << " you got killed by " << currentMonster << std::endl;
//        Sleeps(2000);
//        exit(0);
//    }
}

void moving() {

    int choice;

    std::cout << "\n\n";
    std::cout << "1. Move Forward\n";
    std::cout << "2. Relax\n";
    std::cout << "3. Move Backwards\n";
    std::cout << "\n";

    std::cin >> choice;

    if (choice == 1) {
        int temp = rand() % 100 + 1;    // temp value with a random value.
        std::cout << "You begin moving forward...\n";
        if (temp >= 50) {   // if temp value is greater than 50 we create a monster.
            // Emcounter a monster
            createMonster();
            std::string tempName = monsterName[rand() % currentMonsterName];
            std::cout << "A " << tempName << "| Prepare to fight\n";
            currentMonster = tempName;
            Sleeps(1000);
            combat();
        }
        std::cout << "You find nothing of interest\n"; // if there is no monster.
        Sleeps(1000);
        HUD();
    }
    else if (choice == 2) {
        std::cout << "You want to set up camp for the evening\n";
        if (charecter.totalHP <= 99) {
            charecter.totalHP += 10 * charecter.level;
        }
        std::cout << "You heald by resting. Healt is now: " << charecter.totalHP << std::endl;
        Sleeps(1000);
        HUD();
    }
    else if (choice == 3) {
        int temp = rand() % 100 + 1;    // temp value with a random value.
        std::cout << "You begin moving backwards...\n";
        if (temp >= 50) {   // if temp value is greater than 50 we create a monster.
            // Emcounter a monster
            createMonster();
            std::string tempName = monsterName[rand() % currentMonsterName];
            std::cout << "A " << tempName << "| Prepare to fight\n";
            currentMonster = tempName;
            Sleeps(1000);
            combat();
        }
        std::cout << "You find nothing of interest\n"; // if there is no monster.
        Sleeps(1000);
        HUD();
    }
    else {
        std::cout << "Invalid choise\n";
        Sleeps(500);
        moving(); // If choise is wrong call moving again, so that player may try again.
    }

}

void LevelUp() {

    if (charecter.current_EXP >= charecter.EXP_to_level) {
        charecter.EXP_to_level += floor(charecter.level + 25 * pow(2, charecter.level / 7));
        charecter.totalHP = floor(charecter.totalHP + 13 * pow(2, charecter.level / 8));
        if (charecter.level >= charecter.minlevel && charecter.level <= charecter.maxlevel) {
            charecter.level++;
        }
        else {
            charecter.level = 60;
        }

        charecter.maxHP = charecter.totalHP;
        std::cout << "Wait what this is a level up! you are now level " << charecter.level << std::endl;
        std::cout << "Your total healt increased now your total health is " << charecter.totalHP << std::endl;
        std::cout << "\n";
        Sleeps(1000);
        LevelUp();
    }

    Sleeps(2000);
    HUD();
}

void createMonster() {
    monsterHP = 30;
    monsterLevel = (rand() % 3) + charecter.level;

    //if (monsterLevel == 0) {
    //    monsterLevel = (rand() % 3) + level;
    //}

    monsterHP = (rand() % 30) * monsterLevel;

    //if (monsterHP == 0) {
    //    monsterHP = (rand() % 30) * totalHP;
    //}

    monsterEXP = monsterHP;

    if (monsterHP == 0)
        createMonster();
    if (monsterLevel == 0)
        createMonster();
}
