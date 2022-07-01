// DMV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Race.h"
#include "harmonylib.h"

void GenerateMenu();
Race EditRaceInfo();

int main()
{
    std::cout << "Hello World!\n";
    GenerateMenu();
    return 0;
}

void GenerateMenu() {
    
    char selection{};
    
    Race TestRace{ "Test" };
    //TestRace.set_optionPack("TestOptionPack");
    //TestRace.set_description("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

    do {
        system("cls");


        std::cout << "A - Display" << std::endl
                  << "B - Edit Info" << std::endl
                  << "C - Option C" << std::endl
                  << "Q - Quit"     << std::endl;
        std::cout << "==========================" << std::endl << std::endl;
        std::cin >> selection;

        switch (selection)
        {
        case 'A':
        case 'a':
        {
            std::cout << std::endl << std::endl;
            TestRace.display_info();
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 'B':
        case 'b':
        {
            std::cout << "B was entered" << std::endl << std::endl;

            TestRace = EditRaceInfo();

            system("pause");
            break;
        }
        case 'C':
        case 'c':
        {
            std::cout << "C was entered" << std::endl << std::endl;
            system("pause");
            break;
        }
        default:
            break;
        }

        
    } while (selection != 'Q' && selection != 'q');



    system("cls");
}

Race EditRaceInfo() {
    Race NewRace{};

    std::string selection{};
    std::string Name{};
    std::string OptionPack{};
    std::string Description{};
    SizeEnum::Size Size{};
    int SizeChoice{};
    int Speed{};
    int FlyingSpd{};
    int SwimmingSpd{};
    int DarkVision{};
    int SkillOptionsCount{};
    int LanguageOptionsCount{};
    int WeaponOptionsCount{};
    bool LizFolkAC{};
    bool TortAC{};
    /*std::vector<std::string> Languages{};
    std::vector<std::string> Tools{};
    std::vector<std::string> SkillOptions{};
    std::vector<std::string> SkillProf{};
    std::vector<std::string> LanguageOptions{};
    std::vector<std::string> WeaponOptions{};
    std::vector<std::string> WeaponProf{};
    std::vector<std::string> ArmorProf{};
    std::vector<std::string> DamageRes{};
    std::vector<std::string> DamageImmun{};*/
    bool check{};

    std::cout << "Enter name for race: ";
    std::cin >> Name;
    NewRace.set_name(Name);
    do {
        std::cout << "\nDo you want to save it to a custon pack? (y/n) ";
        std::cin >> selection;
        for (char i : selection) {
            if (!isalpha(i) && i != 'y' && i != 'n') {
                check = false;
                break;
            }
            else {
                check = true;
            }
        }
        if (!check) {
            std::cout << "\nPlease enter a valid choice.";
        }
    } while (!check);
    if (selection[0] == 'y') {
        std::string pack{};
        std::cout << "Please enter Pack name: ";
        std::cin >> pack;
        NewRace.set_optionPack(pack);
    }
    else {
        NewRace.set_optionPack("Default");
    }
    std::cout << "\nEnter description: ";
    std::cin.ignore();
    getline(std::cin,Description);
    NewRace.set_description(Description);

    std::cout << "\nWhat size is the race: Small (0), Medium (1), Large (2)\n";
    std::cin >> SizeChoice;
    switch (SizeChoice)
    {
    case 0:
        NewRace.set_size(SizeEnum::small);
        break;
    case 1:
        NewRace.set_size(SizeEnum::medium);
        break;
    case 2:
        NewRace.set_size(SizeEnum::large);
        break;
    }
    std::cout << "\nEnter Speed: ";
    std::cin >> Speed;
    NewRace.set_speed(Speed);
    std::cout << "\nEnter Flying Speed: ";
    std::cin >> FlyingSpd;
    NewRace.set_flySpeed(FlyingSpd);
    std::cout << "\nEnter Swimming Speed: ";
    std::cin >> SwimmingSpd;
    NewRace.set_swimSpeed(SwimmingSpd);
    std::cout << "\nEnter Dark vision distance: ";
    std::cin >> DarkVision;
    NewRace.set_darkVision(DarkVision);
    std::cout << "\nEnter amount of Skill proficencies: ";
    std::cin >> SkillOptionsCount;
    NewRace.set_skillOptionsCount(SkillOptionsCount);
    std::cout << "\nEnter amount of Language proficencies: ";
    std::cin >> LanguageOptionsCount;
    NewRace.set_languageOptionsCount(LanguageOptionsCount);
    std::cout << "\nEnter amount of Weapon proficencies: ";
    std::cin >> WeaponOptionsCount;
    NewRace.set_weaponOptionsCount(WeaponOptionsCount);
    std::cout << "\nDo they have Lizard folk AC? (y/n) ";
    selection.clear();
    std::cin >> selection;
    if (selection[0] == 'y') {
        NewRace.set_lizFolkAC(true);
    }
    else {
        NewRace.set_lizFolkAC(false);
    }
    std::cout << "\nDo they have Tortle AC? (y/n) ";
    selection.clear();
    std::cin >> selection;
    if (selection[0] == 'y') {
        NewRace.set_tortAC(true);
    }
    else {
        NewRace.set_tortAC(false);
    }

    return NewRace;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
