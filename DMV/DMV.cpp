// DMV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include "Race.h"
#include "harmonylib.h"


void GenerateMenu();
Race EditRaceInfo(std::string Name = "", std::string OptionPack = "", std::string Description = "", SizeEnum::Size Size = SizeEnum::small, std::string SizeChoice = "", std::string Speed = "", std::string FlyingSpd = "", std::string SwimmingSpd = "", std::string DarkVision = "", std::string SkillOptionsCount = "", std::string LanguageOptionsCount = "", std::string WeaponOptionsCount = "", bool LizFolkAC = false, bool TortAC = false, std::string selection = {}, std::vector<std::string> Languages = {}, std::vector<std::string> Tools = {}, std::vector<std::string> SkillOptions = {}, std::vector<std::string> SkillProf = {}, std::vector<std::string> LanguageOptions = {}, std::vector<std::string> WeaponOptions = {}, std::vector<std::string> WeaponProf = {}, std::vector<std::string> ArmorProf = {}, std::vector<std::string> DamageRes = {}, std::vector<std::string> DamageImmun = {});
std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno = false);
std::vector<std::string> GetInputVector(std::string prompt, std::vector<std::string> globalVector, std::vector<std::string> inputVar = {});
std::vector<std::string> GlobalLanguages{"Giant", "Common", "Celestial", "Undercommon", "Goblin", "Dwarvish", "Abyssal", "Sylvan", "Orc", "Deep Speech", "Primordial", "Draconic", "Gnomish", "Elvish", "Halfling", "Infernal" };
std::vector<std::string> GlobalWeapons{"battleaxe", "halberd", "longsword", "dagger", "blowgun", "sickle", "handaxe", "war-pick", "flail", "greatsword", "whip", "rapier", "spear", "net", "shortbow", "warhammer", "mace", "crossbow-heavy", "glaive", "greataxe", "quarterstaff", "crossbow-light", "sling", "javelin", "light-hammer", "longbow", "greatclub", "club", "morningstar", "trident", "maul", "pike", "lance", "shortsword", "crossbow-hand", "scimitar", "dart"};
std::vector<std::string> GlobalSkills{"religion", "persuasion", "investigation", "acrobatics", "performance", "perception", "sleight-of-hand", "survival", "history", "animal-handling", "nature", "deception", "intimidation", "arcana", "athletics", "insight", "medicine", "stealth"};
std::vector<std::string> GlobalTools{"cartographers-tools", "painters-supplies", "poisoners-kit", "navigators-tools", "glassblowers-tools", "flute", " : dice-set", "horn", "herbalism-kit", "dulcimer", "disguise-kit", "masons-tools", "land-vehicles", "viol", "thieves-tools", "jewelers-tools", "leatherworkers-tools", "smiths-tools", "drum", "cobblers-tools", "potters-tools", "dragonchess-set", "playing-card-set", "brewers-supplies", "three-dragon-ante-set", "forgery-kit", "pan-flute", "bagpipes", "woodcarvers-tools", "carpenters-tools", "tinkers-tools", "alchemists-supplies", "water-vehicles", "weavers-tools", "shawm", "cooks-utensils", "lute", "calligraphers-supplies", "lyre"};
    

int main()
{
    GenerateMenu();
    return 0;
}

void GenerateMenu() {
    
    char selection{};
    Race TestRace{ "Test" };
    //TestRace.set_optionPack("TestOptionPack");
    //TestRace.set_description("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    //TestRace.set_description("Giff are tall, broad-shouldered folk with hippo-like features. Some have smooth skin, while others have short bristles on their faces and the tops of their heads. As beings of impressive size and unforgettable appearance, giff are noticed wherever they go.");

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
            std::vector<std::string> input{};
            std::cout << "Test function: Vector input" << std::endl << std::endl;
            input = GetInputVector("tool profs", input, GlobalTools);
            system("pause");
            break;
        }
        default:
            break;
        }

        
    } while (selection != 'Q' && selection != 'q');
    system("cls");
}

Race EditRaceInfo(std::string Name, std::string OptionPack, std::string Description, SizeEnum::Size Size, std::string SizeChoice, std::string Speed, std::string FlyingSpd, std::string SwimmingSpd, std::string DarkVision, std::string SkillOptionsCount, std::string LanguageOptionsCount, std::string WeaponOptionsCount, bool LizFolkAC, bool TortAC, std::string selection, std::vector<std::string> Languages, std::vector<std::string> Tools, std::vector<std::string> SkillOptions, std::vector<std::string> SkillProf, std::vector<std::string> LanguageOptions, std::vector<std::string> WeaponOptions, std::vector<std::string> WeaponProf, std::vector<std::string> ArmorProf, std::vector<std::string> DamageRes, std::vector<std::string> DamageImmun) {
    Race NewRace{};
    bool check{};

    std::cout << "Enter name for race: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, Name);
    if (Name == "") {
        std::getline(std::cin, Name);
    }
    Name = HLib::InputCheck(Name,"Enter name for race: ");
    NewRace.set_name(Name);

    std::cout << "\nDo you want to save it to a custon pack? (y/n) ";
    std::getline(std::cin, selection);
    selection = HLib::InputCheck(selection, "\nDo you want to save it to a custon pack? (y/n) ", true, false, std::vector<std::string>{"y", "n"});
    if (selection[0] == 'y') {
        std::string pack{};
        std::cout << "Please enter Pack name: ";
        std::getline(std::cin,pack);
        NewRace.set_optionPack(pack);
    }
    else {
        NewRace.set_optionPack("Default");
    }

    std::cout << "\nEnter description: ";
    std::getline(std::cin,Description);
    NewRace.set_description(Description);

    std::cout << "\nWhat size is the race: Small (0), Medium (1), Large (2)\n";
    std::getline(std::cin, SizeChoice);
    int SizeChoiceSelection{ std::stoi(HLib::InputCheck(SizeChoice,"\nWhat size is the race: Small (0), Medium (1), Large (2)\n",false, true, std::vector<std::string>{"0","1","2"}))};
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

    NewRace.set_speed(std::stoi(GetInputSingle("\nEnter Speed: ", Speed)));

    NewRace.set_flySpeed(std::stoi(GetInputSingle("\nEnter Flying Speed: ", FlyingSpd)));

    NewRace.set_swimSpeed(std::stoi(GetInputSingle("\nEnter Swimming Speed: ", SwimmingSpd)));

    NewRace.set_darkVision(std::stoi(GetInputSingle("\nEnter Dark vision distance: ", DarkVision)));

    NewRace.set_skillOptionsCount(std::stoi(GetInputSingle("\nEnter amount of Skill proficencies: ", SkillOptionsCount)));

    NewRace.set_languageOptionsCount(std::stoi(GetInputSingle("\nEnter amount of Language proficencies: ", LanguageOptionsCount)));

    NewRace.set_weaponOptionsCount(std::stoi(GetInputSingle("\nEnter amount of Weapon proficencies: ", WeaponOptionsCount)));

    selection.clear();
    NewRace.set_lizFolkAC(std::stoi(GetInputSingle("\nDo they have Lizard folk AC? (y/n) ", selection, true)));

    selection.clear();
    NewRace.set_tortAC(std::stoi(GetInputSingle("\nDo they have Tortle AC? (y/n) ", selection, true)));
    
    system("pause");

    NewRace.insert_tool(GetInputVector("tool profs", GlobalTools));

    NewRace.insert_languageOption(GetInputVector("language options", GlobalLanguages));

    NewRace.insert_language(GetInputVector("languages", GlobalLanguages));

    NewRace.insert_weaponOption(GetInputVector("weapon options", GlobalWeapons));

    NewRace.insert_weaponProf(GetInputVector("weapon profs", GlobalWeapons));

    std::cout << "\nRace has been finished\n";

    system("pause");
    return NewRace;
}

std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno) {
    if (!yesno) {
        std::cout << prompt;
        std::getline(std::cin, inputVar);
        inputVar = HLib::InputCheck(inputVar, prompt, false, true);
        return inputVar;
    }
    else {
        std::cout << prompt;
        std::getline(std::cin, inputVar);
        inputVar = HLib::InputCheck(inputVar, prompt, true, false, std::vector<std::string>{"y", "n"});
        if (inputVar[0] == 'y') {
            return "1";
        }
        else {
            return "0";
        }
    }
}

std::vector<std::string> GetInputVector(std::string prompt, std::vector<std::string> globalVector, std::vector<std::string> inputVar) {
	std::string selection{};
	do {
		system("CLS");
		std::cout << "Please choose " << prompt << ": ";
		HLib::DisplayVector(100, globalVector);
		if (inputVar.empty() != true) {
			std::cout << "\nAlready chosen " << prompt << ": ";
			HLib::DisplayVector(100, inputVar);
		}
		std::cout << "\nType command then the tool you want to add. Commands: add, remove, clear, done\n";
		std::cin.clear();
		std::cin.sync();
		std::getline(std::cin, selection);
		if (selection == "") {
			std::getline(std::cin, selection);
		}
		selection = HLib::InputCheck(selection, "\nType command then the tool you want to add. Commands: add, remove, clear, done\n");

		std::string safeSelection{ selection };
		std::string cmd{};
		for (char i : safeSelection) {
			if (i != ' ') {
				cmd += i;
				selection.erase(0, 1);
			}
			else {
				selection.erase(0, 1);
				break;
			}
		}
		if (std::find(globalVector.begin(), globalVector.end(), selection) != globalVector.end()) {
			if (cmd == "add") {
				if (std::find(inputVar.begin(), inputVar.end(), selection) == inputVar.end()) {
                    inputVar.push_back(selection);
				}
				else {
					std::cout << "\nItem already in list. To remove use 'remove'\n";
					system("pause");
				}
			}
			else if (cmd == "remove") {
				if (std::find(inputVar.begin(), inputVar.end(), selection) != inputVar.end()) {
                    inputVar.at(std::distance(inputVar.begin(), std::find(inputVar.begin(), inputVar.end(), selection))).erase();
				}
				else {
					std::cout << "\nItem not in list.\n";
					system("pause");
				}
			}
			else {
				std::cout << "\nInvalid command.\n";
				system("pause");
			}
		}
		else if (cmd == "clear") {
            inputVar.clear();
		}
		else if (cmd == "done") {
            selection = "done";
			std::cout << "Items inserted\n";
			system("pause");
		}
		else {
			std::cout << "\nItem not found. Try again.\n";
			system("pause");
		}

    } while (selection != "done");
	return inputVar;

}