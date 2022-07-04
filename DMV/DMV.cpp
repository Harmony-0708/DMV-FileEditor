// DMV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Race.h"
#include "harmonylib.h"


void GenerateMenu();
Race EditRaceInfo(std::string Name = "", std::string OptionPack = "", std::string Description = "", SizeEnum::Size Size = SizeEnum::small, std::string SizeChoice = "", std::string Speed = "", std::string FlyingSpd = "", std::string SwimmingSpd = "", std::string DarkVision = "", std::string SkillOptionsCount = "", std::string LanguageOptionsCount = "", std::string WeaponOptionsCount = "", bool LizFolkAC = false, bool TortAC = false);

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
            std::cout << std::endl << std::endl;

            TestRace = EditRaceInfo();

            system("pause");
            break;
        }
        case 'C':
        case 'c':
        {
            std::string input{};
            std::cout << "Test function: Input check" << std::endl << "Enter input: " << std::endl;
            std::cin >> input;
            input = InputCheck(input, "Enter input: ", false, true, std::vector<std::string>{"0", "1"});
            system("pause");
            break;
        }
        default:
            break;
        }

        
    } while (selection != 'Q' && selection != 'q');



    system("cls");
}

Race EditRaceInfo(std::string Name, std::string OptionPack, std::string Description, SizeEnum::Size Size, std::string SizeChoice, std::string Speed, std::string FlyingSpd, std::string SwimmingSpd, std::string DarkVision, std::string SkillOptionsCount, std::string LanguageOptionsCount, std::string WeaponOptionsCount, bool LizFolkAC, bool TortAC) {
    Race NewRace{};

    std::string selection{};
    /*std::string Name{};
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
    bool TortAC{};*/
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
    getline(std::cin, Name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Name = InputCheck(Name,"Enter name for race: ");
    NewRace.set_name(Name);

    std::cout << "\nDo you want to save it to a custon pack? (y/n) ";
    getline(std::cin, selection);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    selection = InputCheck(selection, "\nDo you want to save it to a custon pack? (y/n) ", true, false, std::vector<std::string>{"y", "n"});
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
    getline(std::cin,Description);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    NewRace.set_description(Description);
    std::cout << "\nWhat size is the race: Small (0), Medium (1), Large (2)\n";
    getline(std::cin, SizeChoice);
    int SizeChoiceSelection{ std::stoi(InputCheck(SizeChoice,"\nWhat size is the race: Small (0), Medium (1), Large (2)\n",false, true, std::vector<std::string>{"0","1","2"}))};
    switch (SizeChoiceSelection)
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
    getline(std::cin,Speed);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Speed = InputCheck(Speed, "\nEnter Speed: ",false, true);
    NewRace.set_speed(std::stoi(Speed));

    std::cout << "\nEnter Flying Speed: ";
    getline(std::cin,FlyingSpd);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    FlyingSpd = InputCheck(FlyingSpd, "\nEnter Flying Speed: ", false, true);
    NewRace.set_flySpeed(std::stoi(FlyingSpd));

    std::cout << "\nEnter Swimming Speed: ";
    getline(std::cin,SwimmingSpd);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    SwimmingSpd = InputCheck(SwimmingSpd, "\nEnter Swimming Speed: ", false, true);
    NewRace.set_swimSpeed(std::stoi(SwimmingSpd));

    std::cout << "\nEnter Dark vision distance: ";
    getline(std::cin,DarkVision);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    DarkVision = InputCheck(DarkVision, "\nEnter Dark vision distance: ", false, true);
    NewRace.set_darkVision(std::stoi(DarkVision));

    std::cout << "\nEnter amount of Skill proficencies: ";
    getline(std::cin,SkillOptionsCount);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    SkillOptionsCount = InputCheck(SkillOptionsCount, "\nEnter amount of Skill proficencies: ", false, true);
    NewRace.set_skillOptionsCount(std::stoi(SkillOptionsCount));

    std::cout << "\nEnter amount of Language proficencies: ";
    getline(std::cin,LanguageOptionsCount);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    LanguageOptionsCount = InputCheck(LanguageOptionsCount, "\nEnter amount of Language proficencies: ", false, true);
    NewRace.set_languageOptionsCount(std::stoi(LanguageOptionsCount));

    std::cout << "\nEnter amount of Weapon proficencies: ";
    getline(std::cin,WeaponOptionsCount);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    WeaponOptionsCount = InputCheck(WeaponOptionsCount, "\nEnter amount of Weapon proficencies: ", false, true);
    NewRace.set_weaponOptionsCount(std::stoi(WeaponOptionsCount));

    std::cout << "\nDo they have Lizard folk AC? (y/n) ";
    selection.clear();
    getline(std::cin,selection);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    selection = InputCheck(selection, "\nDo they have Lizard folk AC? (y/n) ", true, false, std::vector<std::string>{"y", "n"});
    if (selection[0] == 'y') {
        NewRace.set_lizFolkAC(true);
    }
    else {
        NewRace.set_lizFolkAC(false);
    }

    std::cout << "\nDo they have Tortle AC? (y/n) ";
    selection.clear();
    getline(std::cin,selection);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    selection = InputCheck(selection, "\nDo they have Tortle AC? (y/n) ", true, false, std::vector<std::string>{"y", "n"});
    if (selection[0] == 'y') {
        NewRace.set_tortAC(true);
    }
    else {
        NewRace.set_tortAC(false);
    }

    return NewRace;
}

