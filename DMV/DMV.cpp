#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include "TraitType.h"
#include "SizeEnum.h"
#include "Spell.h"
#include "Trait.h"
#include "Race.h"
#include "GUI.h"
#include "harmonylib.h"


void GenerateMenu();
Race EditRaceInfo(std::string Name = "", std::string OptionPack = "", std::string Description = "", SizeEnum::Size Size = SizeEnum::small, std::string Str = "", std::string Dex = "", std::string Con = "", std::string Int = "", std::string Wis = "", std::string Cha = "", std::string SizeChoice = "", std::string Speed = "", std::string FlyingSpd = "", std::string SwimmingSpd = "", std::string DarkVision = "", std::string SkillOptionsCount = "", std::string LanguageOptionsCount = "", std::string WeaponOptionsCount = "", bool LizFolkAC = false, bool TortAC = false, std::string selection = {}, std::vector<std::string> Languages = {}, std::vector<std::string> Tools = {}, std::vector<std::string> SkillOptions = {}, std::vector<std::string> SkillProf = {}, std::vector<std::string> LanguageOptions = {}, std::vector<std::string> WeaponOptions = {}, std::vector<std::string> WeaponProf = {}, std::vector<std::string> ArmorProf = {}, std::vector<std::string> DamageRes = {}, std::vector<std::string> DamageImmun = {});
std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno = false);
std::vector<std::string> GetInputVector(std::string prompt, std::vector<std::string> globalVector, std::vector<std::string> inputVar = {});
std::vector<Trait> InsertTraitsPrompt(std::vector<Trait> defaultVector = {});
std::vector<Spell> remove(std::vector<Spell> input, int index);
std::vector<Trait> remove(std::vector<Trait> input, int index);
int index(std::string input, std::vector<std::string> inputVector);


//Globals
std::vector<std::string> GlobalLanguages{"Giant", "Common", "Celestial", "Undercommon", "Goblin", "Dwarvish", "Abyssal", "Sylvan", "Orc", "Deep Speech", "Primordial", "Draconic", "Gnomish", "Elvish", "Halfling", "Infernal" };
std::vector<std::string> GlobalWeapons{"battleaxe", "halberd", "longsword", "dagger", "blowgun", "sickle", "handaxe", "war-pick", "flail", "greatsword", "whip", "rapier", "spear", "net", "shortbow", "warhammer", "mace", "crossbow-heavy", "glaive", "greataxe", "quarterstaff", "crossbow-light", "sling", "javelin", "light-hammer", "longbow", "greatclub", "club", "morningstar", "trident", "maul", "pike", "lance", "shortsword", "crossbow-hand", "scimitar", "dart"};
std::vector<std::string> GlobalSkills{"religion", "persuasion", "investigation", "acrobatics", "performance", "perception", "sleight-of-hand", "survival", "history", "animal-handling", "nature", "deception", "intimidation", "arcana", "athletics", "insight", "medicine", "stealth"};
std::vector<std::string> GlobalTools{"cartographers-tools", "painters-supplies", "poisoners-kit", "navigators-tools", "glassblowers-tools", "flute", "dice-set", "horn", "herbalism-kit", "dulcimer", "disguise-kit", "masons-tools", "land-vehicles", "viol", "thieves-tools", "jewelers-tools", "leatherworkers-tools", "smiths-tools", "drum", "cobblers-tools", "potters-tools", "dragonchess-set", "playing-card-set", "brewers-supplies", "three-dragon-ante-set", "forgery-kit", "pan-flute", "bagpipes", "woodcarvers-tools", "carpenters-tools", "tinkers-tools", "alchemists-supplies", "water-vehicles", "weavers-tools", "shawm", "cooks-utensils", "lute", "calligraphers-supplies", "lyre"};
std::vector<std::string> GlobalArmorType{"light","medium", "heavy", "shield"};
std::vector<std::string> GlobalDamageType{"fire", "acid", "psychic", "force", "bludgeoning", "radiant", "lightning", "slashing", "piercing", "thunder", "cold", "traps", "poison", "necrotic"};


void UnicodeTest() {
    int val{ 175 };
    for (int i{ 175 }; i < 224; i++) {
        std::cout << " " << (char)val << " - " << val << std::endl;
        val = i;
    }
}

int main()
{
    //UnicodeTest();
    GenerateMenu();
    return 0;
}


void GenerateMenu() {
    GUI menuGUI{};
    std::string selection{};
    Race TestRace{ "" };
    do {
        system("cls");
        menuGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);
        std::cout << std::endl;
        menuGUI.GenerateMenu("Menu Options", std::vector<std::string>{"D - Display", "E - Edit Info", "T - Testing", "Q - Quit"});
        std::cout << "Enter choice: ";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, selection);
        if (selection == "") {
            std::getline(std::cin, selection);
        }
        selection = HLib::InputCheck(selection,"Enter choice: ", true, false, std::vector<std::string>{"D","d","E","e","T","t","Q","q"});

        switch (selection[0])
        {
        case 'D':
        case 'd':
        {
            std::cout << std::endl << std::endl;
            TestRace.display_info();
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 'E':
        case 'e':
        {
            std::cout << std::endl << std::endl;
            TestRace = EditRaceInfo();
            break;
        }
        case 'T':
        case 't':
        {
            std::string input{};
            std::cout << "Test function: Box testing" << std::endl << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, input);
            menuGUI.GenerateMenu("Menu Options", std::vector<std::string>{"D - Display", "E - Edit Info", "T - Testing", "Q - Quit"});
            system("pause");
            break;
        }
        default:
            break;
        }

        
    } while (selection[0] != 'Q' && selection[0] != 'q');
    system("cls");
}

Race EditRaceInfo(std::string Name, std::string OptionPack, std::string Description, SizeEnum::Size Size, std::string Str, std::string Dex, std::string Con, std::string Int, std::string Wis, std::string Cha, std::string SizeChoice, std::string Speed, std::string FlyingSpd, std::string SwimmingSpd, std::string DarkVision, std::string SkillOptionsCount, std::string LanguageOptionsCount, std::string WeaponOptionsCount, bool LizFolkAC, bool TortAC, std::string selection, std::vector<std::string> Languages, std::vector<std::string> Tools, std::vector<std::string> SkillOptions, std::vector<std::string> SkillProf, std::vector<std::string> LanguageOptions, std::vector<std::string> WeaponOptions, std::vector<std::string> WeaponProf, std::vector<std::string> ArmorProf, std::vector<std::string> DamageRes, std::vector<std::string> DamageImmun) {
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
    selection = HLib::InputCheck(selection, "\nDo you want to save it to a custon pack? (y/n) ", true,  false, std::vector<std::string>{"y", "n"});
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

    NewRace.set_str(std::stoi(GetInputSingle("Enter Str Mod: ", Str)));

    NewRace.set_dex(std::stoi(GetInputSingle("Enter Dex Mod: ", Dex)));

    NewRace.set_con(std::stoi(GetInputSingle("Enter Con Mod: ", Con)));

    NewRace.set_int(std::stoi(GetInputSingle("Enter Int Mod: ", Int)));

    NewRace.set_wis(std::stoi(GetInputSingle("Enter Wis Mod: ", Wis)));

    NewRace.set_cha(std::stoi(GetInputSingle("Enter Cha Mod: ", Cha)));

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

    NewRace.insert_skillOption(GetInputVector("skills", GlobalSkills));

    NewRace.insert_skillProf(GetInputVector("skill profs", GlobalSkills));

    NewRace.insert_weaponOption(GetInputVector("weapon options", GlobalWeapons));

    NewRace.insert_weaponProf(GetInputVector("weapon profs", GlobalWeapons));

    NewRace.insert_armorProf(GetInputVector("armor profs", GlobalArmorType));

    NewRace.insert_damageRes(GetInputVector("damage resistance", GlobalDamageType));

    NewRace.insert_damageImmun(GetInputVector("damage immunities", GlobalDamageType));

    NewRace.insert_trait(InsertTraitsPrompt());

    std::cout << "\n\nRace has been finished\n";

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
        inputVar = HLib::InputCheck(inputVar, prompt,true, false, std::vector<std::string>{"y", "n"});
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

std::vector<Trait> remove(std::vector<Trait> input, int index) {
    std::vector<Trait> newVector{};
    int counter{};
    for (Trait i : input) {
        if (counter != index) {
            newVector.push_back(i);
        }
        counter++;
    }
    return newVector;
}
std::vector<Spell> remove(std::vector<Spell> input, int index) {
    std::vector<Spell> newVector{};
    int counter{};
    for (Spell i : input) {
        if (counter != index) {
            newVector.push_back(i);
        }
        counter++;
    }
    return newVector;
}
int index(std::string input, std::vector<std::string> inputVector) {
    return (std::distance(inputVector.begin(), std::find(inputVector.begin(), inputVector.end(), input)));
}

std::vector<Trait> InsertTraitsPrompt(std::vector<Trait> defaultVector) {
    if (defaultVector.empty()){
        std::string selection{};
        do {
            system("CLS");
            std::cout << "Enter traits/feats for race\n\n";
            std::vector<std::string> displayVector{};
            if (!defaultVector.empty()) {
                std::cout << "Current Traits: ";
                for (Trait i : defaultVector) {
                    displayVector.push_back(i.get_name());
                }
                HLib::DisplayVector(100, displayVector);
            }
            std::cout << "\nType command then the tool you want to add. Commands: add, edit, remove, clear, done\n";
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

            if (cmd != "done") {
                if (cmd != "clear") {
					if (cmd == "add") {
						Trait newTrait{};
						newTrait = newTrait.create_trait();
                        if (std::find(displayVector.begin(), displayVector.end(), newTrait.get_name()) != displayVector.end()) {
                            std::cout << "\nItem already in list. To remove an element use 'remove'\n";
                            system("pause");
                        }
                        else {
                            defaultVector.push_back(newTrait);
                        }
					}
					else if (cmd == "edit") {
                        if (std::find(displayVector.begin(), displayVector.end(), selection) != displayVector.end()) {
                            Trait newTrait{ defaultVector[index(selection,displayVector)] };
                            std::string choice{};
                            std::cout << "\nWhat would you like to edit (name, description, type): ";
                            std::getline(std::cin, choice);
                            HLib::InputCheck(choice, "\nWhat would you like to edit (name, description, type): ", true, false, std::vector<std::string>{"name", "description", "type"});
                            if (choice == "name") {
                                defaultVector[index(selection, displayVector)] = newTrait.create_trait("", newTrait.get_description(), newTrait.get_typename());
                            }
                            else if (choice == "description") {
                                defaultVector[index(selection, displayVector)] = newTrait.create_trait(newTrait.get_name(), "", newTrait.get_typename());
                            }
                            else {
                                defaultVector[index(selection, displayVector)] = newTrait.create_trait(newTrait.get_name(), newTrait.get_description(), "");
                            }
                        }
                        else {
                            std::cout << "\nItem not in list.\n";
                            system("pause");
                        }
                    }
                    else if (cmd == "remove") {
                        if (std::find(displayVector.begin(), displayVector.end(), selection) != displayVector.end()) {
                            defaultVector = remove(defaultVector, index(selection, displayVector));
                        }
                        else {
                            std::cout << "\nItem not in list.\n";
                            system("pause");
                        }
                    }
                    else {
                        std::cout << "\n\nCommand not found";
                        system("pause");
                    }
                }
                else {
                    std::string choice{};
                    std::cout << "\nAre you sure? (y/n) ";
                    std::getline(std::cin, choice);
                    if (std::stoi(GetInputSingle("\nAre you sure? (y/n) ", choice, true))) {
                        defaultVector.clear();
                    }
                }
            }
            else {
                selection = "done";
                std::cout << "Items inserted\n";
                system("pause");
            }

        } while (selection != "done");

        return defaultVector;

    }
    else {
        return defaultVector;
    }
}

