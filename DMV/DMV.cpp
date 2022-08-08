#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
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
#include "Pack.h"
#include "HPack.h"
#include "Orcbrew.h"


void GenerateMenu();
Race EditRaceInfo(std::string Name = "", std::string OptionPack = "", std::string Description = "", std::string Str = "", std::string Dex = "", std::string Con = "", std::string Int = "", std::string Wis = "", std::string Cha = "", std::string SizeChoice = "", std::string Speed = "", std::string FlyingSpd = "", std::string SwimmingSpd = "", std::string DarkVision = "", std::string SkillOptionsCount = "", std::string LanguageOptionsCount = "", std::string WeaponOptionsCount = "", std::string LizFolkAC = "", std::string TortAC = "", std::vector<std::string> Languages = {"empty"}, std::vector<std::string> Tools = {"empty"}, std::vector<std::string> SkillOptions = {"empty"}, std::vector<std::string> SkillProf = {"empty"}, std::vector<std::string> LanguageOptions = {"empty"}, std::vector<std::string> WeaponOptions = {"empty"}, std::vector<std::string> WeaponProf = {"empty"}, std::vector<std::string> ArmorProf = {"empty"}, std::vector<std::string> DamageRes = {"empty"}, std::vector<std::string> DamageImmun = {"empty"}, std::vector<Trait> Traits = {});
std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno = false);
std::vector<std::string> GetInputVector(std::string prompt, std::vector<std::string> globalVector, std::vector<std::string> inputVar = {});
std::vector<Trait> InsertTraitsPrompt(std::vector<Trait> defaultVector = {});
std::vector<std::string> RaceOptions{ "Name", "OptionPack", "Description", "Str", "Dex", "Con", "Int", "Wis", "Cha", "SizeChoice", "Speed", "FlyingSpd", "SwimmingSpd", "DarkVision", "SkillOptionsCount", "LanguageOptionsCount", "WeaponOptionsCount", "LizFolkAC", "TortAC", "Languages", "Tools", "SkillOptions", "SkillProf", "LanguageOptions", "WeaponOptions", "WeaponProf", "ArmorProf", "DamageRes", "DamageImmun", "Traits"};
Race FindRace(std::string raceName, std::vector<Pack> packSet, std::string packName = "");
std::vector<Spell> remove(std::vector<Spell> input, int index);
std::vector<Trait> remove(std::vector<Trait> input, int index);
int index(std::string input, std::vector<std::string> inputVector);
int CommandCode(std::string command);
HPack ExecuteCommand(int cmdCode, HPack currentHPack, std::vector<std::string> parameters = {}, std::string context = {});
void Console(std::vector<std::string> currentCommands = {}, std::vector<std::string> currentCmdDef = {}, HPack currentHPack = {});
std::vector<std::string> split(std::string input);
std::vector<std::string> merge_ordered(std::vector<std::string> command, std::vector<std::string> description);
bool includes_string(std::string input, std::vector<std::string> vInput);
std::vector<std::string> selection(std::vector<std::string>);
Race ExecuteRaceCommand(int cmdCode, Race currentRace, std::vector<std::string> parameters = {}, std::string context = {});
Race RaceConsole();

//Globals
HPack GlobalPack{};
std::vector<std::string> GlobalLanguages{
    "Giant", 
    "Common",
    "Celestial", 
    "Undercommon",
    "Goblin",
    "Dwarvish",
    "Abyssal", 
    "Sylvan", 
    "Orc", 
    "Deep Speech",
    "Primordial", 
    "Draconic",
    "Gnomish", 
    "Elvish",
    "Halfling",
    "Infernal"
};
std::vector<std::string> GlobalWeapons{
    "battleaxe", 
    "halberd", 
    "longsword",
    "dagger", 
    "blowgun", 
    "sickle", 
    "handaxe",
    "war-pick",
    "flail",
    "greatsword", 
    "whip", 
    "rapier",
    "spear",
    "net",
    "shortbow",
    "warhammer",
    "mace",
    "crossbow-heavy",
    "glaive", 
    "greataxe",
    "quarterstaff",
    "crossbow-light", 
    "sling", 
    "javelin", 
    "light-hammer",
    "longbow",
    "greatclub",
    "club", 
    "morningstar",
    "trident",
    "maul",
    "pike", 
    "lance",
    "shortsword",
    "crossbow-hand",
    "scimitar",
    "dart"
};
std::vector<std::string> GlobalSkills{
    "religion", 
    "persuasion", 
    "investigation",
    "acrobatics",
    "performance",
    "perception",
    "sleight-of-hand",
    "survival",
    "history",
    "animal-handling",
    "nature",
    "deception",
    "intimidation",
    "arcana",
    "athletics",
    "insight", 
    "medicine", 
    "stealth"
};
std::vector<std::string> GlobalTools{
    "cartographers-tools", 
    "painters-supplies", 
    "poisoners-kit", 
    "navigators-tools", 
    "glassblowers-tools", 
    "flute", 
    "dice-set", 
    "horn", 
    "herbalism-kit", 
    "dulcimer", 
    "disguise-kit", 
    "masons-tools", 
    "land-vehicles", 
    "viol", 
    "thieves-tools", 
    "jewelers-tools", 
    "leatherworkers-tools", 
    "smiths-tools", 
    "drum", 
    "cobblers-tools", 
    "potters-tools", 
    "dragonchess-set", 
    "playing-card-set", 
    "brewers-supplies", 
    "three-dragon-ante-set", 
    "forgery-kit", 
    "pan-flute", 
    "bagpipes", 
    "woodcarvers-tools", 
    "carpenters-tools", 
    "tinkers-tools", 
    "alchemists-supplies", 
    "water-vehicles", 
    "weavers-tools", 
    "shawm", 
    "cooks-utensils", 
    "lute", 
    "calligraphers-supplies", 
    "lyre"
};
std::vector<std::string> GlobalArmorType{
    "light",
    "medium", 
    "heavy", 
    "shield"
};
std::vector<std::string> GlobalDamageType{
    "fire", 
    "acid", 
    "psychic", 
    "force", 
    "bludgeoning", 
    "radiant", 
    "lightning", 
    "slashing", 
    "piercing", 
    "thunder", 
    "cold", 
    "traps", 
    "poison", 
    "necrotic"
};
std::vector<std::string> GlobalCommands{
    "exit",
    "help"
};
std::vector<std::string> GlobalCommandDefs{
    "Closes the program", 
    "Displays Commands"
};
std::vector<std::string> GlobalRaceOptions{ 
    "name", 
    "option-pack", 
    "description", 
    "str", 
    "dex", 
    "con", 
    "int", 
    "wis", 
    "cha", 
    "size", 
    "speed", 
    "flying-speed", 
    "swimming-speed", 
    "dark-vision", 
    "skill-opscount", 
    "lang-opscount", 
    "weapon-opscount", 
    "lizard-ac", 
    "tortle-ac", 
    "languages", 
    "tools", 
    "skill-ops", 
    "skill-profs", 
    "language-ops", 
    "weapon-ops", 
    "Weapon-profs", 
    "armor-profs", 
    "damage-res", 
    "damage-imm", 
    "traits" 
};
std::vector<std::string> GlobalRaceDefs{ 
    "The name of your Race", 
    "The name of the pack your race is in", 
    "The Description of your race", 
    "Strength mod", 
    "Dexterity mod",
    "Constitution mod",
    "Intelligence mod", 
    "Wisdom mod",
    "Charisma mod", 
    "The size of your race", 
    "Your race's speed", 
    "Your race's flying speed, 0 if none", 
    "Your race's swimming speed", 
    "Your race's dark vision",
    "The ammount of skill options you have, Min 1", 
    "The ammount of language options you have, Min 1", 
    "The ammount of weapon options you have, Min 1", 
    "Whether or no your race has lizardfolk AC", 
    "Whether or no your race has tortle AC",
    "The languages your race knows", 
    "The tools your race is proficent in", 
    "Your race's skill options", 
    "Your race's skill proficencies", 
    "Your race's language options", 
    "Your race's weapon options", 
    "Your race's weapon proficiencies", 
    "Your race's armor proficiencies", 
    "Types of damage your race is resistance to", 
    "Types of damage your race is immune to", 
    "The specific traits of your race"
};
bool displayCoolGUI{true};

int main()
{
    HPack SessionPack{};

    Console(std::vector<std::string>{"display", "add", "load", "save", "export", "name"}, std::vector<std::string>{"Displays stuff", "Add to pack", "Load from a file", "Save to a file", "Export to Orcbrew", "Rename Packs"}, SessionPack);
    //GenerateMenu();
    return 0;
}


void GenerateMenu() {
    GUI menuGUI{};
    std::string selection{};
    std::vector<Race> savedRaces{};
    std::vector<Pack> savedPacks{};
    HPack SaveFile{"Test"};
    Orcbrew SaveOrcbrew{};

    std::vector<std::string> namesOfPacks{};
    std::vector<std::string> namesOfRaces{};
    do {
        system("cls");
        savedPacks = SaveFile.get_packs();
        namesOfPacks.clear();
        namesOfRaces.clear();
        
        for (Pack i : savedPacks) {
            for (Race k : i.get_races()) {
                if (std::find(namesOfRaces.begin(), namesOfRaces.end(), k.get_name()) == namesOfRaces.end()) {
                    savedRaces.push_back(k);
                    namesOfRaces.push_back(k.get_name() + " (" + i.get_name() + ")");
                }
            }
            namesOfPacks.push_back(i.get_name());
        }

        menuGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);
        std::cout << std::endl;
        menuGUI.GenerateMenu("Menu Options", std::vector<std::string>{"D - Display", "A - Add Race", "E - Edit Race", "L - Load Pack", "S - Save Pack", "T - Testing", "Q - Quit"});
        std::cout << "Enter choice: ";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, selection);
        if (selection == "") {
            std::getline(std::cin, selection);
        }
        selection = HLib::InputCheck(selection,"Enter choice: ", true, false, std::vector<std::string>{ "D", "d", "A", "a", "E", "e", "T", "t", "S", "s", "L", "l", "Q", "q"});

        switch (selection[0])
        {
        case 'D':
        case 'd':
        {
            if (savedRaces.size() != 0) {
                std::string choice{};
                menuGUI.GenerateMenu("Select race", namesOfRaces);
                namesOfRaces.push_back("filter");
                std::cout << "To filter by pack use 'filter'\n";
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfRaces);
                if (choice == "filter") {
                    std::string filterChoice{};
                    std::vector<std::string> filteredNamesOfRaces{};
                    Pack filterPack{};
                    std::cout << "Enter Filter: ";
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, filterChoice);
                    filterChoice = HLib::InputCheck(filterChoice, "Enter Filter: ", false, false, namesOfPacks);
                    for (Pack i : savedPacks) {
                        if (i.get_name() == filterChoice) {
                            filterPack = i;
                            break;
                        }
                    }
                    for (Race i : filterPack.get_races()) {
                        filteredNamesOfRaces.push_back(i.get_name());
                    }
                    menuGUI.GenerateMenu("Select race", filteredNamesOfRaces);
                    std::cout << "Enter choice: ";
                    choice.clear();
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, choice);
                    choice = HLib::InputCheck(choice, "Enter choice: ", false, false, filteredNamesOfRaces);
                    savedRaces.at(index(choice, filteredNamesOfRaces)).display_info();
                    system("pause");
                    break;
                }
                system("cls");
                savedRaces.at(index(choice, namesOfRaces)).display_info();
            }
            else {
                std::cout << "You have no saved races currently" << std::endl;
            }
            std::cout << std::endl;
            system("pause");
            break;
        }
        case 'A':
        case 'a':
        {
            system("cls");
            Race newRace{};
            newRace = EditRaceInfo();
            bool found{};
            int pcounter{ 0 };
            for (Pack i : savedPacks) {
                if (newRace.get_optionPack() == i.get_name()) {
                    found = true;
                    std::vector<Race> races{ i.get_races() };
                    for (Race k : races) {
                        if (k.get_name() == newRace.get_name()) {
                            if (isalpha(k.get_name()[-1])) {
                                newRace.set_name(newRace.get_name() + '1');
                            }
                            else {
                                int num{ (k.get_name()[-1] -'0' ) + 1};
                                newRace.set_name(newRace.get_name() + std::to_string(num));
                            }
                        }
                    }
                    races.push_back(newRace);
                    savedPacks.at(pcounter).set_races(races);
                }
                pcounter++;
            }
            if (!found) {
                std::vector<Race> races{};
                races.push_back(newRace);
                Pack newPack{};
                newPack.set_name(newRace.get_optionPack());
                newPack.set_races(races);
                savedPacks.push_back(newPack);
            }
            break;
        }
        case 'E':
        case 'e':
        {
            if (!savedRaces.empty()){
                
                std::string choice{};
                std::vector<std::string> editChoices{"empty"};
                Race editedRace{};
                menuGUI.GenerateMenu("Select race", namesOfRaces);
                namesOfRaces.push_back("filter");
                std::cout << "To filter by pack use 'filter'\n";
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfRaces);
                if (choice == "filter") {
                    std::string filterChoice{};
                    std::vector<std::string> filteredNamesOfRaces{};
                    Pack filterPack{};
                    std::cout << "Enter Filter: ";
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, filterChoice);
                    filterChoice = HLib::InputCheck(filterChoice, "Enter Filter: ", false, false, namesOfPacks);
                    for (Pack i : savedPacks) {
                        if (i.get_name() == filterChoice) {
                            filterPack = i;
                            break;
                        }
                    }
                    for (Race i : filterPack.get_races()) {
                        filteredNamesOfRaces.push_back(i.get_name());
                    }
                    menuGUI.GenerateMenu("Select race", filteredNamesOfRaces);
                    std::cout << "Enter choice: ";
                    choice.clear();
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, choice);
                    choice = HLib::InputCheck(choice, "Enter choice: ", false, false, filteredNamesOfRaces);
                    editedRace = savedRaces.at(index(choice, filteredNamesOfRaces));
                }
                else {
                    editedRace = savedRaces.at(index(choice, namesOfRaces));
                }
                system("cls");
                editChoices = GetInputVector("edit option", RaceOptions,editChoices);
                if (!editChoices.empty()) {
                    //Race attributes
                    std::string Name = editedRace.get_name();
                    std::string OptionPack = editedRace.get_optionPack();
                    std::string Description = editedRace.get_description();
                    std::string Str = std::to_string(editedRace.get_str());
                    std::string Dex = std::to_string(editedRace.get_dex());
                    std::string Con = std::to_string(editedRace.get_con());
                    std::string Int = std::to_string(editedRace.get_int());
                    std::string Wis = std::to_string(editedRace.get_wis());
                    std::string Cha = std::to_string(editedRace.get_cha());
                    std::string SizeChoice{};
                    switch (editedRace.get_size()) {
                    case SizeEnum::small:
                        SizeChoice = "0";
                        break;
                    case SizeEnum::medium:
                        SizeChoice = "1";
                        break;
                    case SizeEnum::large:
                        SizeChoice = "2";
                        break;
                    }
                    std::string Speed = std::to_string(editedRace.get_speed());
                    std::string FlyingSpd = std::to_string(editedRace.get_flySpeed());
                    std::string SwimmingSpd = std::to_string(editedRace.get_swimSpeed());
                    std::string DarkVision = std::to_string(editedRace.get_darkVision());
                    std::string SkillOptionsCount = std::to_string(editedRace.get_skillOptionsCount());
                    std::string LanguageOptionsCount = std::to_string(editedRace.get_languageOptionsCount());
                    std::string WeaponOptionsCount = std::to_string(editedRace.get_weaponOptionsCount());
                    std::string LizFolkAC{};
                    if (editedRace.get_lizFolkAC()) { LizFolkAC = "true"; }
                    else { LizFolkAC = "false"; }
                    std::string TortAC{};
                    if (editedRace.get_lizFolkAC()) { TortAC = "true"; }
                    else { TortAC = "false"; }
                    std::vector<std::string> Languages = editedRace.get_language();
                    std::vector<std::string> Tools = editedRace.get_tool();
                    std::vector<std::string> SkillOptions = editedRace.get_skillOption();
                    std::vector<std::string> SkillProf = editedRace.get_skillProf();
                    std::vector<std::string> LanguageOptions = editedRace.get_languageOption();
                    std::vector<std::string> WeaponOptions = editedRace.get_weaponOption();
                    std::vector<std::string> WeaponProf = editedRace.get_weaponProf();
                    std::vector<std::string> ArmorProf = editedRace.get_armorProf();
                    std::vector<std::string> DamageRes = editedRace.get_damageRes();
                    std::vector<std::string> DamageImmun = editedRace.get_damageImmun();
                    std::vector<Trait> Traits = editedRace.get_trait();

                    for (std::string i : editChoices) {
                        if (i == "Name") {
                            Name.clear();
                        }
                        else if (i == "OptionPack") {
                            OptionPack.clear();
                        }
                        else if (i == "Description") {
                            Description.clear();
                        }
                        else if (i == "Str") {
                            Str.clear();
                        }
                        else if (i == "Dex") {
                            Dex.clear();
                        }
                        else if (i == "Con") {
                            Con.clear();
                        }
                        else if (i == "Int") {
                            Int.clear();
                        }
                        else if (i == "Wis") {
                            Wis.clear();
                        }
                        else if (i == "Cha") {
                            Cha.clear();
                        }
                        else if (i == "SizeChoice") {
                            SizeChoice.clear();
                        }
                        else if (i == "Speed") {
                            Speed.clear();
                        }
                        else if (i == "FlyingSpd") {
                            FlyingSpd.clear();
                        }
                        else if (i == "SwimmingSpd") {
                            SwimmingSpd.clear();
                        }
                        else if (i == "DarkVision") {
                            DarkVision.clear();
                        }
                        else if (i == "SkillOptionsCount") {
                            SkillOptionsCount.clear();
                        }
                        else if (i == "LanguageOptionsCount") {
                            LanguageOptionsCount.clear();
                        }
                        else if (i == "WeaponOptionsCount") {
                            WeaponOptionsCount.clear();
                        }
                        else if (i == "LizFolkAC") {
                            LizFolkAC.clear();
                        }
                        else if (i == "TortAC") {
                            TortAC.clear();
                        }
                        else if (i == "Languages") {
                            Languages.clear();
                            Languages.push_back("empty");
                        }
                        else if (i == "Tools") {
                            Tools.clear();
                            Tools.push_back("empty");
                        }
                        else if (i == "SkillOptions") {
                            SkillOptions.clear();
                            SkillOptions.push_back("empty");
                        }
                        else if (i == "SkillProf") {
                            SkillProf.clear();
                            SkillProf.push_back("empty");
                        }
                        else if (i == "LanguageOptions") {
                            LanguageOptions.clear();
                            LanguageOptions.push_back("empty");
                        }
                        else if (i == "WeaponOptions") {
                            WeaponOptions.clear();
                            WeaponOptions.push_back("empty");
                        }
                        else if (i == "WeaponProf") {
                            WeaponProf.clear();
                            WeaponProf.push_back("empty");
                        }
                        else if (i == "ArmorProf") {
                            ArmorProf.clear();
                            ArmorProf.push_back("empty");
                        }
                        else if (i == "DamageRes") {
                            DamageRes.clear();
                            DamageRes.push_back("empty");
                        }
                        else if (i == "DamageImmun") {
                            DamageImmun.clear();
                            DamageImmun.push_back("empty");
                        }
                        else if (i == "Traits") {
                            Traits.clear();
                        }


                    }
                    system("cls");
                    editedRace = (EditRaceInfo(Name, OptionPack, Description, Str, Dex, Con, Int, Wis, Cha, SizeChoice, Speed, FlyingSpd, SwimmingSpd, DarkVision, SkillOptionsCount, LanguageOptionsCount, WeaponOptionsCount, LizFolkAC, TortAC, Languages, Tools, SkillOptions, SkillProf, LanguageOptions, WeaponOptions, WeaponProf, ArmorProf, DamageRes, DamageImmun, Traits));
                    bool found{};
                    int pcounter{0};
                    for (Pack i : savedPacks) {
                        int counter{ 0 };
                        if (i.get_name() == editedRace.get_optionPack()) {
                            for (Race k : i.get_races()) {
                                if (k.get_name() == editedRace.get_name()) {
                                    std::vector<Race> races{ i.get_races() };
                                    races.at(counter) = editedRace;
                                    savedPacks.at(pcounter).set_races(races);
                                    found = true;

                                    int rcounter{ 0 };
                                    for (Race j : savedRaces) {
                                        if (editedRace.get_name() == j.get_name() && editedRace.get_optionPack() == j.get_optionPack()) {
                                            savedRaces.at(rcounter) = editedRace;
                                        }
                                        rcounter++;
                                    }
                                    break;
                                }
                                counter++;
                            }
                        }
                        if (found) {
                            break;
                        }
                        counter++;
                    }
                }
            }
            else {
                std::cout << "You have no saved races currently" << std::endl;
            }
            system("pause");
            break;
        }
        case 'L':
        case 'l':
        {
            std::string choice{};
            Pack newPack{};
            std::cout << "Is this pack saved as a pack file (pck), a pack set (hpck), or as a DMV pack (orcbrew)? " << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, choice);
            choice = HLib::InputCheck(choice, "Is this pack saved as a pack file (pck), a pack set (hpck), or as a DMV pack (orcbrew)?\n", true, false, std::vector<std::string>{"pck", "orcbrew"});
            if (choice == "pck") {
                std::string name{};
                std::cout << "Enter name of pack" << std::endl;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, name);
                if (std::find(namesOfPacks.begin(), namesOfPacks.end(), name) == namesOfPacks.end()) {
                    if (newPack.load_pack(name) == 0) {
                        savedPacks.push_back(newPack);
                    }
                    else {
                        std::cout << "Couldn't find pack. Make sure you spell it exactly as it's titled\n";
                    }
                }
                else {
                    std::cout << "Pack is already loaded" << std::endl;
                }
            }
            else if (choice == "hpck") {
                std::string name{};
                std::cout << "Enter name of pack" << std::endl;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, name);
                HPack newSaveFile{};
                newSaveFile.load(name);
                SaveFile = newSaveFile;
                savedPacks = SaveFile.get_packs();
            }
            else if (choice == "orcbrew") {
                std::string name{};
                std::cout << "Enter name of pack" << std::endl;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, name);
                Orcbrew newOrcbrew{};
                SaveFile = newOrcbrew.load(name);
                savedPacks = SaveFile.get_packs();
            }
            else {
                std::cout << "Only pck, hpck, and orcbrew files are supported at this time.\n";
            }
            system("pause");
            break;
        }
        case 'S':
        case 's':
        {
            std::cout << std::endl << std::endl;
            if (savedPacks.size() != 0) {
                std::string choice{};
                std::string packchoice{};
                std::cout << "Would you like to save this to a pack file (pck) or as a DMV pack (orcbrew)? NOTE: pck files DO NOT work on DMV" << std::endl;
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, packchoice);
                packchoice = HLib::InputCheck(packchoice, "Would you like to save this to a pack file (pck) or as a DMV pack (orcbrew)? NOTE: pck files DO NOT work on DMV\n", true, false, std::vector<std::string>{"pck", "orcbrew"});
                menuGUI.GenerateMenu("Select pack", namesOfPacks);
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfPacks);
                if (packchoice == "orcbrew") {
                    savedPacks.at(index(choice, namesOfPacks)).print_pack();
                }
                else {
                    savedPacks.at(index(choice, namesOfPacks)).save_pack();
                }
            }
            else {
                std::cout << "You have no saved packs currently" << std::endl;
            }
            system("pause");
            break;
        }
        case 'T':
        case 't':
        {
            std::cout << "Test function: HPack Merging" << std::endl << std::endl;
            HPack newSaveFile{"Austin's Pack"};
            HPack mergedSaveFiles{"Test Pack"};
            Orcbrew newOrcbrew{};
            newSaveFile = newOrcbrew.load("all-content");
            SaveFile = SaveOrcbrew.load("Tester");
            newSaveFile.set_name("Austin's Pack");
            SaveFile.set_name("Test Pack");
            mergedSaveFiles = SaveFile.merge(std::vector<HPack>{SaveFile, newSaveFile});
            savedPacks = mergedSaveFiles.get_packs();
            system("pause");
            break;
        }
        default:
            break;
        }

        SaveFile.set_packs(savedPacks);
    } while (selection[0] != 'Q' && selection[0] != 'q');
    system("cls");
}

std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno) {
    if (!yesno) {
        if (inputVar != "") {
            return inputVar;
        }
        std::cout << prompt;
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, inputVar);
        inputVar = HLib::InputCheck(inputVar, prompt, false, true);
        return inputVar;
    }
    else {
        if (inputVar == "true" || inputVar == "1" || inputVar == "y") {
            return "1";
        }
        else if (inputVar == "false" || inputVar == "0" || inputVar == "n") {
            return "0";
        }
        std::cout << prompt;
        std::cin.clear();
        std::cin.sync();
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
    GUI gui{};
    if (inputVar.empty() || ((!inputVar.empty()) && inputVar.at(0) != "empty")) {
        return inputVar;
    }
    if (inputVar.at(0) == "empty") {
        inputVar.clear();
    }
	do {
		system("CLS");
        gui.GenerateMenu("Please choose " + prompt,globalVector,"",true,4);
        if (inputVar.size() == 1 && inputVar.at(0) == "") {
            inputVar.clear();
        }
		if (inputVar.empty() != true) {
            gui.GenerateMenu("Already chosen " + prompt, inputVar, "", true, 4);
		}
		std::cout << "\nType command then the tool you want to add. Commands: add, all, remove, clear, done\n";
		std::cin.clear();
		std::cin.sync();
		std::getline(std::cin, selection);
		if (selection == "") {
			std::getline(std::cin, selection);
		}
		selection = HLib::InputCheck(selection, "\nType command then the tool you want to add. Commands: add, all, remove, clear, done\n");

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
        else if (cmd == "all") {
            inputVar = globalVector;
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
        GUI gui{};
        std::string selection{};
        do {
            system("CLS");
            std::cout << "Enter traits/feats for race\n\n";
            std::vector<std::string> displayVector{};
            if (!defaultVector.empty()) {
                for (Trait i : defaultVector) {
                    gui.GenerateMenu(i.get_name(), std::vector<std::string>{i.get_description()}, i.get_typename());
                    displayVector.push_back(i.get_name());
                }
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
                            Trait newTrait{ defaultVector.at(index(selection,displayVector)) };
                            std::string choice{};
                            std::cout << "\nWhat would you like to edit (name, description, type): ";
                            std::getline(std::cin, choice);
                            HLib::InputCheck(choice, "\nWhat would you like to edit (name, description, type): ", true, false, std::vector<std::string>{"name", "description", "type"});
                            if (choice == "name") {
                                defaultVector.at(index(selection,displayVector)) = newTrait.create_trait("", newTrait.get_description(), newTrait.get_typename());
                            }
                            else if (choice == "description") {
                                defaultVector.at(index(selection,displayVector)) = newTrait.create_trait(newTrait.get_name(), "", newTrait.get_typename());
                            }
                            else {
                                defaultVector.at(index(selection,displayVector)) = newTrait.create_trait(newTrait.get_name(), newTrait.get_description(), "");
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

Race FindRace(std::string raceName, std::vector<Pack> packSet, std::string packName) {
    Race foundRace{};
    for (Pack i : packSet) {
        if (packName != "") {
            if (i.get_name() == packName) {
                for (Race k : i.get_races()) {
                    if (k.get_name() == raceName) {
                        foundRace = k;
                    }
                }
            }
        }
        else {
            for (Race k : i.get_races()) {
                if (k.get_name() == raceName) {
                    foundRace = k;
                }
            }
        }
    }
    return foundRace;
}

void ExitProgram() {
    std::string input{};
    std::cout << "\nAre you sure you want to exit?\n";
    std::getline(std::cin, input);
    input = HLib::InputCheck(input, "\nInput incorrect format\nAre you sure you want to exit?\n", true, false, std::vector<std::string>{"yes", "no", "y", "n"});
    if (input == "yes" || input == "y") {
        std::cout << "\n\nGoodbye!\n";
        system("pause");
        exit(0);
    }
    else {
        std::cout << "\n\nReturning to console...\n";
        system("pause");
        system("cls");
        main();
    }
}

int CommandCode(std::string command) {
    if (command == "exit") {
        return 0;
    }
    else if (command == "help") {
        return 1;
    }
    else if (command == "display") {
        return 2;
    }
    else if (command == "add") {
        return 3;
    }
    else if (command == "load") {
        return 4;
    }
    else if (command == "save") {
        return 5;
    }
    else if (command == "export") {
        return 6;
    }
    else if (command == "name") {
        return 7;
    }
    else if (command == "edit") {
        return 8;
    }
    else {
        return -1;
    }
}

bool includes_string(std::string input, std::vector<std::string> vInput) {
    for (std::string i : vInput) {
        if (i == input) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> merge_ordered(std::vector<std::string> command, std::vector<std::string> description) {
    int index{};
    std::vector<std::string> combined{};
    for (std::string i : command) {
        combined.push_back(i);
        combined.push_back(description.at(index));
        index++;
    }
    return combined;
}

HPack ExecuteCommand(int cmdCode, HPack currentHPack, std::vector<std::string> parameters, std::string context) {
    switch (cmdCode)
    {
    //Exit
    case 0: {
        ExitProgram();
        break;
    }
    
    //Help
    case 1: {
		GUI HelpGui{};
		int index{};
		std::vector<std::string> commandsToDisplay{};
		for (std::string i : GlobalCommands) {
			commandsToDisplay.push_back(i);
			commandsToDisplay.push_back(GlobalCommandDefs.at(index));
			index++;
		}
        if (!parameters.empty()) { commandsToDisplay.insert(std::end(commandsToDisplay), std::begin(parameters), std::end(parameters)); }
        HelpGui.GenerateMenu("Command - Definition", commandsToDisplay, "", true, 2);
		break;
    }

    //Display
    case 2: {
        GUI menuGUI{};
        std::vector<std::string> options{"all", "options", "enable", "disable","races"};
        std::vector<std::string> option_desc{ "Displays everything", "Shows Parameters", "Enables fancy GUI", "Disables fancy GUI", "Displays Races"};
        std::vector<Race> savedRaces{};
        std::vector<Pack> savedPacks{};
        Orcbrew SaveOrcbrew{};

        std::vector<std::string> namesOfPacks{};
        std::vector<std::string> namesOfRaces{};

        std::cout << std::endl;
        if (parameters.empty() || parameters.at(0) == options.at(0)) {
            //menuGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);
            std::cout << std::endl;
            menuGUI.GenerateMenu("Display Options", options);
        }
        else if (parameters.at(0) == "help") {
            currentHPack = ExecuteCommand(CommandCode("help"), currentHPack, merge_ordered(options, option_desc));
        }
        else if (parameters.at(0) == options.at(1)) {
            //menuGUI.GenerateMenu("Display Options", options);
            currentHPack = ExecuteCommand(CommandCode("display"), currentHPack, std::vector<std::string>{}, "display");
        }
        else if (parameters.at(0) == options.at(2)) {
            displayCoolGUI = true;
            std::cout << "\nFancy GUI enabled.\n";
        }
        else if (parameters.at(0) == options.at(3)) {
            displayCoolGUI = false;
            std::cout << "\nFancy GUI disabled.\n";
        }
        else if (parameters.at(0) == options.at(4)) {
            system("cls");
            savedPacks = currentHPack.get_packs();
            namesOfPacks.clear();
            namesOfRaces.clear();
            for (Pack i : savedPacks) {
                for (Race k : i.get_races()) {
                    if (std::find(namesOfRaces.begin(), namesOfRaces.end(), k.get_name()) == namesOfRaces.end()) {
                        savedRaces.push_back(k);
                        namesOfRaces.push_back(k.get_name() + " (" + i.get_name() + ")");
                    }
                }
                namesOfPacks.push_back(i.get_name());
            }
            if (savedRaces.size() != 0) {
                std::string choice{};
                menuGUI.GenerateMenu("Select race", namesOfRaces);
                namesOfRaces.push_back("filter");
                std::cout << "To filter by pack use 'filter'\n";
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfRaces);
                if (choice == "filter") {
                    std::string filterChoice{};
                    std::vector<std::string> filteredNamesOfRaces{};
                    Pack filterPack{};
                    std::cout << "Enter Filter: ";
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, filterChoice);
                    filterChoice = HLib::InputCheck(filterChoice, "Enter Filter: ", false, false, namesOfPacks);
                    for (Pack i : savedPacks) {
                        if (i.get_name() == filterChoice) {
                            filterPack = i;
                            break;
                        }
                    }
                    for (Race i : filterPack.get_races()) {
                        filteredNamesOfRaces.push_back(i.get_name());
                    }
                    menuGUI.GenerateMenu("Select race", filteredNamesOfRaces);
                    std::cout << "Enter choice: ";
                    choice.clear();
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, choice);
                    choice = HLib::InputCheck(choice, "Enter choice: ", false, false, filteredNamesOfRaces);
                    savedRaces.at(index(choice, filteredNamesOfRaces)).display_info();
                    system("pause");
                    break;
                }
                system("cls");
                savedRaces.at(index(choice, namesOfRaces)).display_info();
            }
            else {
                std::cout << "You have no saved races currently" << std::endl;
            }
            std::cout << std::endl;
            system("pause");
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("display"), currentHPack, std::vector<std::string>{});
        }
        break;
    }
    
    //Add
    case 3: {
        GUI addGUI{};
        std::vector<std::string> addOptions{ "cancel","options","race" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat would you like to add?\n";
            std::getline(std::cin, input);
            addOptions.push_back("options");
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat would you like to add?\n", true, false, addOptions);
            currentHPack = ExecuteCommand(CommandCode("add"), currentHPack, std::vector<std::string>{input}, "add");
        }
        else if (parameters.at(0) == "options") {
            addGUI.GenerateMenu("Add Options", addOptions);
            std::cout << std::endl;
            currentHPack =  ExecuteCommand(CommandCode("add"), currentHPack, std::vector<std::string>{}, "add");
        }
        else if (parameters.at(0) == addOptions.at(0)) {
            break;
        }
        else if (parameters.at(0) == addOptions.at(2)) {
            Pack newPack{};
            Race newRace{};
            newRace = RaceConsole();
            if (newRace.get_name() != "%%CANCELED%%") {
                newPack.set_races(newRace);
                newPack.set_name(newPack.get_races().at(0).get_optionPack());
                newPack.merge(currentHPack.get_packs());
                currentHPack.add_pack(newPack);
            }
            else {
                std::cout << "\nRace creation canceled\n";
            }
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("add"), currentHPack, std::vector<std::string>{});
        }
        break;
    }
    
    //Load
    case 4: {
        GUI loadGUI{};
        std::vector<std::string> loadOptions{ "cancel","options","all","single","multi"};
        std::vector<std::string> fileTypes{ "hpck","pck","orcbrew" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nHow many packs do you want to load?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nHow many packs do you want to load?\n", true, false, loadOptions);
            currentHPack = ExecuteCommand(CommandCode("load"), currentHPack,std::vector<std::string>{input}, "load");
        }
        else if (parameters.at(0) == "options") {
            loadGUI.GenerateMenu("Load Options", loadOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("load"), currentHPack, std::vector<std::string>{}, "load");
        }
        else if (parameters.at(0) == loadOptions.at(0)) {
            break;
        }
        else if (parameters.at(0) == loadOptions.at(2)) {
            std::vector<std::string> nameOfFiles{};
            input.clear();
            
            if (parameters.size() <= 1) {
                std::cout << "\nWhat type of file would you like to load?\n";
                std::getline(std::cin, input);
            }
            else {
                input = parameters.at(1);
            }
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat type of file would you like to load?\n", true, false, fileTypes);
            
            std::cout << "\nAll " << input << " files will be loaded in the local folder. Please ensure the files you want to load are currently in the folder then hit enter.\n";
            system("pause");

            if (input == "hpck" || input == "pck") {
                for (const auto& i : std::filesystem::directory_iterator("CustomPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 12);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }
            else {
                for (const auto& i : std::filesystem::directory_iterator("OrcbrewPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 13);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }
            
            for (std::string i : nameOfFiles) {
                if (input == "hpck") {
                    HPack newHPack{};
                    i.erase(i.size()-5, 5);
                    newHPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
                else if (input == "pck") {
                    Pack newPack{};
                    i.erase(i.size() - 4, 4);
                    newPack.load_pack(i);
                    currentHPack.add_pack(newPack);
                }
                else if (input == "orcbrew") {
                    HPack newHPack{};
                    Orcbrew newPack{};
                    i.erase(i.size() - 4, 4);
                    newHPack = newPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
            }
        }
        else if (parameters.at(0) == loadOptions.at(3)) {
            std::vector<std::string> nameOfFiles{};
            input.clear();

            std::cout << "\nWhat type of file would you like to load?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat type of file would you like to load?\n", true, false, fileTypes);
            system("pause");

            if (input == "hpck" || input == "pck") {
                for (const auto& i : std::filesystem::directory_iterator("CustomPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 12);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }
            else {
                for (const auto& i : std::filesystem::directory_iterator("OrcbrewPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 13);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }
            std::string fileName{};
            std::cout << "\nPlease enter file to load\n";
            std::getline(std::cin, fileName);
            input = HLib::InputCheck(fileName + "." + input, "\nInvalid Item\nWhat type of file would you like to load?\n", true, false, nameOfFiles);


            nameOfFiles = selection(nameOfFiles);

            for (std::string i : nameOfFiles) {
                if (input == "hpck" && i == input) {
                    HPack newHPack{};
                    i.erase(i.size() - 5, 5);
                    newHPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
                else if (input == "pck" && i == input) {
                    Pack newPack{};
                    i.erase(i.size() - 4, 4);
                    newPack.load_pack(i);
                    currentHPack.add_pack(newPack);
                }
                else if (input == "orcbrew" && i == input) {
                    HPack newHPack{};
                    Orcbrew newPack{};
                    i.erase(i.size() - 4, 4);
                    newHPack = newPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
            }
        }
        else if (parameters.at(0) == loadOptions.at(4)) {

            std::vector<std::string> nameOfFiles{};
            input.clear();

            std::cout << "\nWhat type of file would you like to load?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat type of file would you like to load?\n", true, false, fileTypes);

            std::cout << "\nAll " << input << " files will be loaded in the local folder. Please ensure the files you want to load are currently in the folder then hit enter.\n";
            system("pause");

            if (input == "hpck" || input == "pck") {
                for (const auto& i : std::filesystem::directory_iterator("CustomPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 12);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }
            else {
                for (const auto& i : std::filesystem::directory_iterator("OrcbrewPacks")) {
                    std::string path{ i.path().string() };
                    path.erase(0, 13);
                    if (path.substr(path.find(".") + 1) == input) {
                        nameOfFiles.push_back(path);
                    }
                }
            }

            nameOfFiles = selection(nameOfFiles);

            for (std::string i : nameOfFiles) {
                if (input == "hpck") {
                    HPack newHPack{};
                    i.erase(i.size() - 5, 5);
                    newHPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
                else if (input == "pck") {
                    Pack newPack{};
                    i.erase(i.size() - 4, 4);
                    newPack.load_pack(i);
                    currentHPack.add_pack(newPack);
                }
                else if (input == "orcbrew") {
                    HPack newHPack{};
                    Orcbrew newPack{};
                    i.erase(i.size() - 4, 4);
                    newHPack = newPack.load(i);
                    currentHPack.merge(std::vector<HPack>{newHPack});
                }
            }
        }
        else {
        std::cout << "\nInvalid parameter\n";
        currentHPack = ExecuteCommand(CommandCode("load"), currentHPack, std::vector<std::string>{});
        }
        break;
    }

    //Save
    case 5: {
        GUI saveGUI{};
        std::vector<std::string> saveOptions{ "cancel","options","hpck","pck"};
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nHow do you want to save your packs?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nHow do you want to save your packs?\n", true, false, saveOptions);
            currentHPack = ExecuteCommand(CommandCode("save"), currentHPack, std::vector<std::string>{input}, "save");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            saveGUI.GenerateMenu("Save Options", saveOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("save"), currentHPack, std::vector<std::string>{}, "save");
        }
        else if (parameters.at(0) == saveOptions.at(2)) {
            currentHPack.save();
        }
        else if (parameters.at(0) == saveOptions.at(3)) {
            std::vector<std::string> packNames{};
            for (Pack i : currentHPack.get_packs()) {
                packNames.push_back(i.get_name());
            }
            std::cout << "\nWhich pack do you want to save?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhich pack do you want to save?\n", true, false, packNames);
            for (Pack i : currentHPack.get_packs()) {
                if (i.get_name() == input) {
                    i.save_pack();
                    break;
                }
            }
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("save"), currentHPack, std::vector<std::string>{});
        }
        break;
    }

    //Export
    case 6: {
        GUI exportGUI{};
        std::vector<std::string> exportOptions{ "cancel","options", "no", "yes"};
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nAre you sure you want to export your packs to orcbrew format? WARNING: Any orcbrew file with the same name as your current HPack will be overwritten\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nAre you sure you want to export your packs to orcbrew format?\n", true, false, exportOptions);
            currentHPack = ExecuteCommand(CommandCode("export"), currentHPack, std::vector<std::string>{input}, "export");
        }
        else if (parameters.at(0) == "cancel" || parameters.at(0) == exportOptions.at(2)) {
            break;
        }
        else if (parameters.at(0) == "options") {
            exportGUI.GenerateMenu("Export Options", exportOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("export"), currentHPack, std::vector<std::string>{}, "export");
        }
        else if (parameters.at(0) == exportOptions.at(3)) {
            Orcbrew tempOrcbrew{};
            tempOrcbrew.set_packs(currentHPack.get_packs());
            tempOrcbrew.set_name(currentHPack.get_name());
            tempOrcbrew.save();
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("export"), currentHPack, std::vector<std::string>{});
        }
        break;
    }

    //Name
    case 7: {
        GUI nameGUI{};
        std::vector<std::string> nameOptions{ "cancel", "options","hpck", "pck"};
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do you want to rename?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do you want to rename?\n", true, false, nameOptions);
            currentHPack = ExecuteCommand(CommandCode("name"), currentHPack, std::vector<std::string>{input}, "name");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            nameGUI.GenerateMenu("Name Options", nameOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("name"), currentHPack, std::vector<std::string>{}, "name");
        }
        else if (parameters.at(0) == nameOptions.at(2)) {
            std::cout << "\nWhat do you want to rename the pack to?\n";
            input.clear();
            std::getline(std::cin, input);
            currentHPack.set_name(input);
        }
        else if (parameters.at(0) == nameOptions.at(3)) {
            std::vector<std::string> packNames{};
            for (Pack i : currentHPack.get_packs()) {
                packNames.push_back(i.get_name());
            }
            nameGUI.GenerateMenu("Packs loaded", packNames, "", true, 4);
            std::cout << std::endl;
            std::cout << "\nWhich pack do you want to rename?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhich pack do you want to rename?\n", true, false, packNames);
            std::string newName{};
            std::cout << "\nWhat do you want to rename the pack to?\n";
            std::getline(std::cin, newName);
            currentHPack.set_pack_name(input, newName);
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("name"), currentHPack, std::vector<std::string>{});
        }

        break;
    }

    default:
        std::cout << "\n\nAn error has occured, write down what you did and report it to the devs\n";
        system("pause");
        break;
    }
    if (context == "") {
        system("pause");
        system("cls");
    }
    return currentHPack;
}

void Console(std::vector<std::string> currentCommands, std::vector<std::string> currentCmdDef, HPack currentHPack) {
    GUI consoleGUI{};
    std::string input{};
    std::vector<std::string> commands{};
    std::vector<std::string> combined{merge_ordered(currentCommands,currentCmdDef)};
    int index{};

    if (!currentCommands.empty()) { commands.insert(std::end(commands), std::begin(currentCommands), std::end(currentCommands)); }
    commands.insert(std::begin(commands), std::begin(GlobalCommands), std::end(GlobalCommands));
    
    do {
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        if (displayCoolGUI) {
            consoleGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);
        }

        std::cout << "\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        parameter = input;
        int parameterindex{};
        for (char i : input) {
            if (i != ' ') {
                if (std::isalpha(i)) {
                    command.push_back(std::tolower(i));
                    parameter.erase(0, 1);
                }
                else {
                    command.push_back(i);
                    parameter.erase(0, 1);
                }
            }
            else {
                parameter.erase(0, 1);
                break;
            }
        }
        if (includes_string(command, commands)) {
            if (command == "help") {
                currentHPack = ExecuteCommand(CommandCode(command), currentHPack, combined);
            }
            else {
                std::vector<std::string> parameters{ split(parameter) };
                currentHPack = ExecuteCommand(CommandCode(command), currentHPack, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }
    } while (input != "exit");
}

std::vector<std::string> split(std::string s){
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    return vstrings;
}

std::vector<std::string> selection(std::vector<std::string> parameters) {
    GUI selectionGUI{};
    std::vector<std::string> selected{};
    std::string input{};
    std::vector<std::string> commands{"add","remove","clear","done"};

    do {
        system("cls");

        std::string command{};
        std::string parameter{};

        selectionGUI.GenerateMenu("Enter selections ", parameters, "Use add, remove, and clear", true, 3);
        
        if (!selected.empty()) {
            std::cout << std::endl;
            selectionGUI.GenerateMenu("Already Selected ", selected, "", true, 4);
        }

        std::cout << "\nEnter input:\n"; 
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        parameter = input;
        int parameterindex{};
        for (char i : input) {
            if (i != ' ') {
                if (std::isalpha(i)) {
                    command.push_back(std::tolower(i));
                    parameter.erase(0, 1);
                }
                else {
                    command.push_back(i);
                    parameter.erase(0, 1);
                }
            }
            else {
                parameter.erase(0, 1);
                break;
            }
        }

        if (includes_string(command, commands)) {
            if (command == "add") {
                if (parameter != "all") {
                    bool found{ false };
                    for (std::string i : selected) {
                        if (i == parameter) {
                            found = true;
                        }
                    }
                    if (!found) {
                        selected.push_back(parameter);
                    }
                    else {
                        std::cout << "\nItem was already selected\n";
                    }
                }
                else {
                    selected.clear();
                    for (std::string i : parameters) {
                        selected.push_back(i);
                    }
                }
            }
            else if (command == "remove") {
                int index{-1};
                bool found{false};
                for (std::string i : selected) {
                    index++;
                    if (i == parameter) {
                        selected.erase(selected.begin() + index);
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "\nItem was not found\n";
                }
            }
            else if (command == "clear") {
                std::cout << "\nAre you sure you want to clear your selection?\n";
                input.clear();
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, input);
                input = HLib::InputCheck(input, "\nYes/No\nAre you sure you want to clear your selection?\n", true, false, { "Yes","No","yes","no" });
                if (input == "yes" || input == "Yes") {
                    selected.clear();
                }
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }

    } while (input != "done");


    return selected;
}

int RaceCommandCode(std::string command) {
    if (command == "done") {
        return 0;
    }
    else if (command == "help") {
        return 1;
    }
    else if (command == "cancel") {
        return 2;
    }
    else if (command == "add") {
        return 3;
    }
    else if (command == "edit") {
        return 4;
    }
    else if (command == "clear") {
        return 5;
    }
    else if (command == "remove") {
        return 6;
    }
    else {
        return -1;
    }
}

int RaceOptionCode(std::string option) {
    if (option == "name") {
        return 0;
    }
    else if (option == "option-pack") {
        return 1;
    }
    else if (option == "description") {
        return 2;
    }
    else if (option == "size") {
        return 3;
    }
    else if (option == "str") {
        return 4;
    }
    else if (option == "dex") {
        return 5;
    }
    else if (option == "con") {
        return 6;
    }
    else if (option == "int") {
        return 7;
    }
    else if (option == "wis") {
        return 8;
    }
    else if (option == "cha") {
        return 9;
    }
    else if (option == "speed") {
        return 10;
    }
    else if (option == "flying-speed") {
        return 11;
    }
    else if (option == "swimming-speed") {
        return 12;
    }
    else if (option == "dark-vision") {
        return 13;
    }
    else if (option == "skill-opcount") {
        return 14;
    }
    else if (option == "lang-opcount") {
        return 15;
    }
    else if (option == "weapon-opcount") {
        return 16;
    }
    else if (option == "lizard-ac") {
        return 17;
    }
    else if (option == "tortle-ac") {
        return 18;
    }
    else if (option == "languages") {
        return 19;
    }
    else if (option == "tools") {
        return 20;
    }
    else if (option == "skill-ops") {
        return 21;
    }
    else if (option == "skill-profs") {
        return 22;
    }
    else if (option == "language-ops") {
        return 23;
    }
    else if (option == "weapon-ops") {
        return 24;
    }
    else if (option == "weapon-profs") {
        return 25;
    }
    else if (option == "armor-profs") {
        return 26;
    }
    else if (option == "damage-res") {
        return 27;
    }
    else if (option == "dammage-imm") {
        return 28;
    }
    else if (option == "traits") {
        return 29;
    }
    else {
        return -1;
    }
}

Race ExecuteRaceCommand(int cmdCode, Race currentRace, std::vector<std::string> parameters, std::string context) {
    switch (cmdCode)
    {
    //Done
    case 0: {
        break;
    }
    
    //Help
    case 1: {
        GUI helpGUI{};
        std::vector<std::string> helpOptions{};
        std::string input{};

        if (parameters.empty()) {

            //Can't happen, Help always gets parameters

            //std::cout << "\nWhat do you need help with?\n";
            //std::getline(std::cin, input);
            //input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do you need help with?\n", true, false, GlobalRaceOptions);
            //currentHPack = ExecuteCommand(CommandCode("load"), currentHPack, std::vector<std::string>{input}, "load");
        }
		else {
			std::vector<std::string> selection{};
			int index{};
			if (parameters.at(0) == "all") {
				parameters.clear();
				parameters = merge_ordered(GlobalRaceOptions, GlobalRaceDefs);
			}
			if (context != "console") {
				for (std::string i : GlobalRaceOptions) {
					for (std::string k : parameters) {
						if (i == k) {
							selection.push_back(i);
							selection.push_back(GlobalRaceDefs.at(index));
						}
					}
					index++;
				}
            }
            else {
                context = "";
                selection = parameters;
            }
			if (selection.empty()) {
				std::cout << "\nInput not found, try again\n";
			}
			else {
				helpGUI.GenerateMenu("Command - Definition", selection, "", true, 2);
			}
		}
		break;
    }
    
    //Cancel
    case 2: {
        Race cancelRace{ "%%CANCELED%%" };
        currentRace = cancelRace;
        break;
    }
    
    //Add
    case 3: {
        GUI addGUI{};
        std::vector<std::string> addOptions{"cancel","options"};
        std::vector<std::string> addDefs{ "Cancels add", "Lists all possible options" };
        addDefs.insert(std::end(addDefs), std::begin(GlobalRaceDefs), std::end(GlobalRaceDefs));
        addOptions.insert(std::end(addOptions), std::begin(GlobalRaceOptions), std::end(GlobalRaceOptions));
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do want to add?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do want to add?\n", true, false, addOptions);
            currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, std::vector<std::string>{input}, "add");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            addOptions = merge_ordered(addOptions, addDefs);
            addGUI.GenerateMenu("Add Commands", addOptions, "", true, 2);
            currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, std::vector<std::string>{input}, "add");
        }
        else if (includes_string(parameters.at(0),addOptions)) {
            switch (RaceOptionCode(parameters.at(0)))
            {
				//Name
			case 0: {
				if (currentRace.get_name() == "") {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if(index!=0){newName += " " + parameters.at(index);}else{newName += parameters.at(index);}
							index++;
						}
						currentRace.set_name(newName);
					}
					else {
						std::cout << "\nWhat do you want your race to be called?\n";
						std::getline(std::cin, newName);
						currentRace.set_name(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //OptionPack
			case 1: {
				if (currentRace.get_optionPack() == "") {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if(index!=0){newName += " " + parameters.at(index);}else{newName += parameters.at(index);}
							index++;
						}
						currentRace.set_optionPack(newName);
					}
					else {
						std::cout << "\nWhat is the option pack name for your race?\n";
						std::getline(std::cin, newName);
						currentRace.set_optionPack(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Description
			case 2: {
				if (currentRace.get_description() == "") {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if(index!=0){newName += " " + parameters.at(index);}else{newName += parameters.at(index);}
							index++;
						}
						currentRace.set_description(newName);
					}
					else {
						std::cout << "\nWhat is the description for your race? Warning: Pressing enter will enter the description as is, formatting is currently not supported\n";
						std::getline(std::cin, newName);
						currentRace.set_description(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Size
			case 3: {
				if (currentRace.get_sizename() == "Small") {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInvalid Size\nWhat is the size of your character? (Small, Medium, Large)\n", true, false, std::vector<std::string>{"small", "medium", "large"});
						if (newName == "small") {
							currentRace.set_size(SizeEnum::small);
						}
						else if (newName == "medium") {
							currentRace.set_size(SizeEnum::medium);
						}
						else if (newName == "large") {
							currentRace.set_size(SizeEnum::large);
						}
					}
					else {
						std::cout << "\nWhat is the size of your character? (Small, Medium, Large)\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nWhat is the size of your character? (Small, Medium, Large)\n", true, false, std::vector<std::string>{"small", "medium", "large"});
						if (newName == "small") {
							currentRace.set_size(SizeEnum::small);
						}
						else if (newName == "medium") {
							currentRace.set_size(SizeEnum::medium);
						}
						else if (newName == "large") {
							currentRace.set_size(SizeEnum::large);
						}
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Str
			case 4: {
				if (currentRace.get_str() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's strength modifier?\n", false, true);
						currentRace.set_str(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's strength modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's strength modifier?\n", false, true);
						currentRace.set_str(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Dex
			case 5: {
				if (currentRace.get_dex() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dexterity modifier?\n", false, true);
						currentRace.set_dex(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's dexterity modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dexterity modifier?\n", false, true);
						currentRace.set_dex(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Con
			case 6: {
				if (currentRace.get_con() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's constitution modifier?\n", false, true);
						currentRace.set_con(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's constitution modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's constitution modifier?\n", false, true);
						currentRace.set_con(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Int
			case 7: {
				if (currentRace.get_int() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's intelligence modifier?\n", false, true);
						currentRace.set_int(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's intelligence modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's intelligence modifier?\n", false, true);
						currentRace.set_int(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Wis
			case 8: {
				if (currentRace.get_wis() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's wisdom modifier?\n", false, true);
						currentRace.set_wis(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's wisdom modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's wisdom modifier?\n", false, true);
						currentRace.set_wis(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Cha
			case 9: {
				if (currentRace.get_cha() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's charisma modifier?\n", false, true);
						currentRace.set_cha(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's charisma modifier?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's charisma modifier?\n", false, true);
						currentRace.set_cha(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				  //Speed
			case 10: {
				if (currentRace.get_speed() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's speed?\n", false, true);
						currentRace.set_speed(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's speed?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's speed?\n", false, true);
						currentRace.set_speed(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //FlyingSpeed
			case 11: {
				if (currentRace.get_flySpeed() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's fly speed?\n", false, true);
						currentRace.set_flySpeed(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's fly speed?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's fly speed?\n", false, true);
						currentRace.set_flySpeed(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //SwimmingSpeed
			case 12: {
				if (currentRace.get_swimSpeed() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's swim speed?\n", false, true);
						currentRace.set_swimSpeed(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's swim speed?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's swim speed?\n", false, true);
						currentRace.set_swimSpeed(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Dark vision
			case 13: {
				if (currentRace.get_darkVision() == 0) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dark vision distance? (0 means none)\n", false, true);
						currentRace.set_darkVision(std::stoi(newName));
					}
					else {
						std::cout << "\nWhat is your race's dark vision distance? (0 means none)\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dark vision distance? (0 means none)\n", false, true);
						currentRace.set_darkVision(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Skill Options Count
			case 14: {
				if (currentRace.get_skillOptionsCount() == 1) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many skills can your race choose to be proficent in?\n", false, true);
						currentRace.set_skillOptionsCount(std::stoi(newName));
					}
					else {
						std::cout << "\nHow many skills can your race choose to be proficent in?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many skills can your race choose to be proficent in?\n", false, true);
						currentRace.set_skillOptionsCount(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Language Options Count
			case 15: {
				if (currentRace.get_languageOptionsCount() == 1) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many languages can your race choose to be proficent in?\n", false, true);
						currentRace.set_languageOptionsCount(std::stoi(newName));
					}
					else {
						std::cout << "\nHow many languages can your race choose to be proficent in?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many languages can your race choose to be proficent in?\n", false, true);
						currentRace.set_languageOptionsCount(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Weapon Options Count
			case 16: {
				if (currentRace.get_weaponOptionsCount() == 1) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many weapons can your race choose to be proficent in?\n", false, true);
						currentRace.set_weaponOptionsCount(std::stoi(newName));
					}
					else {
						std::cout << "\nHow many weapons can your race choose to be proficent in?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many weapons can your race choose to be proficent in?\n", false, true);
						currentRace.set_weaponOptionsCount(std::stoi(newName));
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //LizFolkAC
			case 17: {
				if (currentRace.get_lizFolkAC() == false) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have lizardfolk AC?\n", true, false, std::vector<std::string>{"yes", "no"});
						if (newName == "yes") {
							currentRace.set_lizFolkAC(true);
						}
						else {
							currentRace.set_lizFolkAC(false);
						}
					}
					else {
						std::cout << "\nDoes your race have lizardfolk AC?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have lizardfolk AC?\n", true, false, std::vector<std::string>{"yes", "no"});
						if (newName == "yes") {
							currentRace.set_lizFolkAC(true);
						}
						else {
							currentRace.set_lizFolkAC(false);
						}
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //TortAC
			case 18: {
				if (currentRace.get_tortAC() == false) {
					std::string newName{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						newName = parameters.at(0);
						newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have tortle AC?\n", true, false, std::vector<std::string>{"yes", "no"});
						if (newName == "yes") {
							currentRace.set_tortAC(true);
						}
						else {
							currentRace.set_tortAC(false);
						}
					}
					else {
						std::cout << "\nDoes your race have tortle AC?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have tortle AC?\n", true, false, std::vector<std::string>{"yes", "no"});
						if (newName == "yes") {
							currentRace.set_tortAC(true);
						}
						else {
							currentRace.set_tortAC(false);
						}
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Languages
			case 19: {
				if (currentRace.get_language().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalLanguages)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded language\n";
							}
							index++;
						}
						currentRace.insert_language(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Languages", GlobalLanguages, "", true, 4);
						std::cout << "\nWhat language do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded language\nWhat language do you want to add to your race?\n", true, false, GlobalLanguages);
						currentRace.insert_language(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Tools
			case 20: {
				if (currentRace.get_tool().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalTools)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded tool\n";
							}
							index++;
						}
						currentRace.insert_tool(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Tools", GlobalTools, "", true, 4);
						std::cout << "\nWhat tool proficencies do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded tool\nWhat tool proficencies do you want to add to your race?\n", true, false, GlobalTools);
						currentRace.insert_tool(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Skill Options
			case 21: {
				if (currentRace.get_skillOption().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalSkills)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded skill\n";
							}
							index++;
						}
						currentRace.insert_skillOption(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Skills", GlobalSkills, "", true, 4);
						std::cout << "\nWhat skill options do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded skill\nWhat skill options do you want to add to your race?\n", true, false, GlobalSkills);
						currentRace.insert_skillOption(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Skill Profs
			case 22: {
				if (currentRace.get_skillProf().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalSkills)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded skill\n";
							}
							index++;
						}
						currentRace.insert_skillProf(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Skills", GlobalSkills, "", true, 4);
						std::cout << "\nWhat skill proficencies do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded skill\nWhat skill proficencies do you want to add to your race?\n", true, false, GlobalSkills);
						currentRace.insert_skillProf(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Language Options
			case 23: {
				if (currentRace.get_languageOption().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalLanguages)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded language\n";
							}
							index++;
						}
						currentRace.insert_languageOption(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Languages", GlobalLanguages, "", true, 4);
						std::cout << "\nWhat language options do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded language\nWhat language options do you want to add to your race?\n", true, false, GlobalLanguages);
						currentRace.insert_languageOption(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Weapon Options
			case 24: {
				if (currentRace.get_weaponOption().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalWeapons)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded weapon\n";
							}
							index++;
						}
						currentRace.insert_weaponOption(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Weapons", GlobalWeapons, "", true, 4);
						std::cout << "\nWhat weapon options do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon\nWhat weapon options do you want to add to your race?\n", true, false, GlobalWeapons);
						currentRace.insert_weaponOption(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Weapon Profs
			case 25: {
				if (currentRace.get_weaponProf().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalWeapons)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded weapon\n";
							}
							index++;
						}
						currentRace.insert_weaponProf(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Weapons", GlobalWeapons, "", true, 4);
						std::cout << "\nWhat weapon proficencies do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon\nWhat weapon proficencies do you want to add to your race?\n", true, false, GlobalWeapons);
						currentRace.insert_weaponProf(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Armor Profs
			case 26: {
				if (currentRace.get_armorProf().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalArmorType)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded armor type\n";
							}
							index++;
						}
						currentRace.insert_armorProf(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Armor", GlobalArmorType, "", true, 4);
						std::cout << "\nWhat armor types do you want to add to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded armor type\nWhat armor types do you want to add to your race?\n", true, false, GlobalArmorType);
						currentRace.insert_armorProf(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Damage Res
			case 27: {
				if (currentRace.get_damageRes().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalDamageType)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded damage type\n";
							}
							index++;
						}
						currentRace.insert_damageRes(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Damage Types", GlobalDamageType, "", true, 4);
						std::cout << "\nWhat damage types do you want to add resistance to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded damage type\nWhat damage types do you want to add resistance to your race?\n", true, false, GlobalDamageType);
						currentRace.insert_damageRes(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Damage Imm
			case 28: {
				if (currentRace.get_damageImmun().empty()) {
					std::string newName{};
					std::vector<std::string> newLanguages{};
					if (parameters.size() > 1) {
						parameters.erase(parameters.begin());
						int index{};
						for (std::string i : parameters) {
							if (includes_string(i, GlobalDamageType)) {
								newLanguages.push_back(i);
							}
							else {
								std::cout << "\n" << i << " is not a loaded damage type\n";
							}
							index++;
						}
						currentRace.insert_damageImmun(newLanguages);
					}
					else {
						addGUI.GenerateMenu("Damage Types", GlobalDamageType, "", true, 4);
						std::cout << "\nWhat damage types do you want to add immunity to your race?\n";
						std::getline(std::cin, newName);
						newName = HLib::InputCheck(newName, "\nThat is not a loaded damage type\nWhat damage types do you want to add immunity to your race?\n", true, false, GlobalDamageType);
						currentRace.insert_damageImmun(newName);
					}
				}
				else {
					currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
				}
				break;
			}
				   //Traits
			case 29: {
                if (currentRace.get_trait().empty()) {
                    //Testing phase
                }
                break;
            }
            default:
                break;
            }
        }
        else {
            std::cout << "\nInvalid Input\n";
        }

        break;
    }
    
    //Edit
    case 4: {
        GUI editGUI{};
        std::vector<std::string> editOptions{ "cancel","options" };
        std::vector<std::string> editDefs{ "Cancels edit", "Lists all possible options" };
        editDefs.insert(std::end(editDefs), std::begin(GlobalRaceDefs), std::end(GlobalRaceDefs));
        editOptions.insert(std::end(editOptions), std::begin(GlobalRaceOptions), std::end(GlobalRaceOptions));
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do want to edit?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do want to edit?\n", true, false, editOptions);
            currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, std::vector<std::string>{input}, "edit");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            editOptions = merge_ordered(editOptions, editDefs);
            editGUI.GenerateMenu("Add Commands", editOptions, "", true, 2);
            currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, std::vector<std::string>{input}, "add");
        }
        else if (includes_string(parameters.at(0), editOptions)) {
            switch (RaceOptionCode(parameters.at(0)))
            {
                //Name
            case 0: {
                if (currentRace.get_name() == "") {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, parameters, "edit");
                }
                else {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (index != 0) { newName += " " + parameters.at(index); }
                            else { newName += parameters.at(index); }
                            index++;
                        }
                        currentRace.set_name(newName);
                    }
                    else {
                        std::cout << "\nWhat do you want your race to be called?\n";
                        std::getline(std::cin, newName);
                        currentRace.set_name(newName);
                    }
                }
                break;
            }
                  //OptionPack
            case 1: {
                if (currentRace.get_optionPack() == "") {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, parameters, "edit");
                }
                else {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (index != 0) { newName += " " + parameters.at(index); }
                            else { newName += parameters.at(index); }
                            index++;
                        }
                        currentRace.set_optionPack(newName);
                    }
                    else {
                        std::cout << "\nWhat is the option pack name for your race?\n";
                        std::getline(std::cin, newName);
                        currentRace.set_optionPack(newName);
                    }
                }
                break;
            }
                  //Description
            case 2: {
                if (currentRace.get_description() == "") {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, parameters, "edit");
                }
                else {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (index != 0) { newName += " " + parameters.at(index); }
                            else { newName += parameters.at(index); }
                            index++;
                        }
                        currentRace.set_description(newName);
                    }
                    else {
                        std::cout << "\nWhat is the description for your race? Warning: Pressing enter will enter the description as is, formatting is currently not supported\n";
                        std::getline(std::cin, newName);
                        currentRace.set_description(newName);
                    }
                }
                break;
            }
                  //Size
            case 3: {
                if (currentRace.get_sizename() == "Small") {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("add"), currentRace, parameters, "edit");
                }
                else {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInvalid Size\nWhat is the size of your character? (Small, Medium, Large)\n", true, false, std::vector<std::string>{"small", "medium", "large"});
                        if (newName == "small") {
                            currentRace.set_size(SizeEnum::small);
                        }
                        else if (newName == "medium") {
                            currentRace.set_size(SizeEnum::medium);
                        }
                        else if (newName == "large") {
                            currentRace.set_size(SizeEnum::large);
                        }
                    }
                    else {
                        std::cout << "\nWhat is the size of your character? (Small, Medium, Large)\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nWhat is the size of your character? (Small, Medium, Large)\n", true, false, std::vector<std::string>{"small", "medium", "large"});
                        if (newName == "small") {
                            currentRace.set_size(SizeEnum::small);
                        }
                        else if (newName == "medium") {
                            currentRace.set_size(SizeEnum::medium);
                        }
                        else if (newName == "large") {
                            currentRace.set_size(SizeEnum::large);
                        }
                    }
                }
                break;
            }
                  //Str
            case 4: {
                if (currentRace.get_str() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's strength modifier?\n", false, true);
                        currentRace.set_str(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's strength modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's strength modifier?\n", false, true);
                        currentRace.set_str(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Dex
            case 5: {
                if (currentRace.get_dex() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dexterity modifier?\n", false, true);
                        currentRace.set_dex(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's dexterity modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dexterity modifier?\n", false, true);
                        currentRace.set_dex(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Con
            case 6: {
                if (currentRace.get_con() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's constitution modifier?\n", false, true);
                        currentRace.set_con(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's constitution modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's constitution modifier?\n", false, true);
                        currentRace.set_con(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Int
            case 7: {
                if (currentRace.get_int() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's intelligence modifier?\n", false, true);
                        currentRace.set_int(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's intelligence modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's intelligence modifier?\n", false, true);
                        currentRace.set_int(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Wis
            case 8: {
                if (currentRace.get_wis() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's wisdom modifier?\n", false, true);
                        currentRace.set_wis(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's wisdom modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's wisdom modifier?\n", false, true);
                        currentRace.set_wis(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Cha
            case 9: {
                if (currentRace.get_cha() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's charisma modifier?\n", false, true);
                        currentRace.set_cha(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's charisma modifier?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's charisma modifier?\n", false, true);
                        currentRace.set_cha(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                  //Speed
            case 10: {
                if (currentRace.get_speed() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's speed?\n", false, true);
                        currentRace.set_speed(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's speed?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's speed?\n", false, true);
                        currentRace.set_speed(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //FlyingSpeed
            case 11: {
                if (currentRace.get_flySpeed() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's fly speed?\n", false, true);
                        currentRace.set_flySpeed(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's fly speed?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's fly speed?\n", false, true);
                        currentRace.set_flySpeed(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //SwimmingSpeed
            case 12: {
                if (currentRace.get_swimSpeed() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's swim speed?\n", false, true);
                        currentRace.set_swimSpeed(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's swim speed?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's swim speed?\n", false, true);
                        currentRace.set_swimSpeed(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Dark vision
            case 13: {
                if (currentRace.get_darkVision() == 0) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dark vision distance? (0 means none)\n", false, true);
                        currentRace.set_darkVision(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nWhat is your race's dark vision distance? (0 means none)\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nWhat is your race's dark vision distance? (0 means none)\n", false, true);
                        currentRace.set_darkVision(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Skill Options Count
            case 14: {
                if (currentRace.get_skillOptionsCount() == 1) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many skills can your race choose to be proficent in?\n", false, true);
                        currentRace.set_skillOptionsCount(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nHow many skills can your race choose to be proficent in?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many skills can your race choose to be proficent in?\n", false, true);
                        currentRace.set_skillOptionsCount(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Language Options Count
            case 15: {
                if (currentRace.get_languageOptionsCount() == 1) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many languages can your race choose to be proficent in?\n", false, true);
                        currentRace.set_languageOptionsCount(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nHow many languages can your race choose to be proficent in?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many languages can your race choose to be proficent in?\n", false, true);
                        currentRace.set_languageOptionsCount(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Weapon Options Count
            case 16: {
                if (currentRace.get_weaponOptionsCount() == 1) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many weapons can your race choose to be proficent in?\n", false, true);
                        currentRace.set_weaponOptionsCount(std::stoi(newName));
                    }
                    else {
                        std::cout << "\nHow many weapons can your race choose to be proficent in?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be numeric\nHow many weapons can your race choose to be proficent in?\n", false, true);
                        currentRace.set_weaponOptionsCount(std::stoi(newName));
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //LizFolkAC
            case 17: {
                if (currentRace.get_lizFolkAC() == false) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have lizardfolk AC?\n", true, false, std::vector<std::string>{"yes", "no"});
                        if (newName == "yes") {
                            currentRace.set_lizFolkAC(true);
                        }
                        else {
                            currentRace.set_lizFolkAC(false);
                        }
                    }
                    else {
                        std::cout << "\nDoes your race have lizardfolk AC?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have lizardfolk AC?\n", true, false, std::vector<std::string>{"yes", "no"});
                        if (newName == "yes") {
                            currentRace.set_lizFolkAC(true);
                        }
                        else {
                            currentRace.set_lizFolkAC(false);
                        }
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //TortAC
            case 18: {
                if (currentRace.get_tortAC() == false) {
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        newName = parameters.at(0);
                        newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have tortle AC?\n", true, false, std::vector<std::string>{"yes", "no"});
                        if (newName == "yes") {
                            currentRace.set_tortAC(true);
                        }
                        else {
                            currentRace.set_tortAC(false);
                        }
                    }
                    else {
                        std::cout << "\nDoes your race have tortle AC?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nInput must be yes/no\nDoes your race have tortle AC?\n", true, false, std::vector<std::string>{"yes", "no"});
                        if (newName == "yes") {
                            currentRace.set_tortAC(true);
                        }
                        else {
                            currentRace.set_tortAC(false);
                        }
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Languages
            case 19: {
                if (currentRace.get_language().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalLanguages)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded language\n";
                            }
                            index++;
                        }
                        currentRace.insert_language(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Languages", GlobalLanguages, "", true, 4);
                        std::cout << "\nWhat language do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded language\nWhat language do you want to add to your race?\n", true, false, GlobalLanguages);
                        currentRace.insert_language(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Tools
            case 20: {
                if (currentRace.get_tool().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalTools)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded tool\n";
                            }
                            index++;
                        }
                        currentRace.insert_tool(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Tools", GlobalTools, "", true, 4);
                        std::cout << "\nWhat tool proficencies do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded tool\nWhat tool proficencies do you want to add to your race?\n", true, false, GlobalTools);
                        currentRace.insert_tool(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Skill Options
            case 21: {
                if (currentRace.get_skillOption().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalSkills)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded skill\n";
                            }
                            index++;
                        }
                        currentRace.insert_skillOption(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Skills", GlobalSkills, "", true, 4);
                        std::cout << "\nWhat skill options do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded skill\nWhat skill options do you want to add to your race?\n", true, false, GlobalSkills);
                        currentRace.insert_skillOption(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Skill Profs
            case 22: {
                if (currentRace.get_skillProf().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalSkills)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded skill\n";
                            }
                            index++;
                        }
                        currentRace.insert_skillProf(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Skills", GlobalSkills, "", true, 4);
                        std::cout << "\nWhat skill proficencies do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded skill\nWhat skill proficencies do you want to add to your race?\n", true, false, GlobalSkills);
                        currentRace.insert_skillProf(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Language Options
            case 23: {
                if (currentRace.get_languageOption().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalLanguages)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded language\n";
                            }
                            index++;
                        }
                        currentRace.insert_languageOption(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Languages", GlobalLanguages, "", true, 4);
                        std::cout << "\nWhat language options do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded language\nWhat language options do you want to add to your race?\n", true, false, GlobalLanguages);
                        currentRace.insert_languageOption(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Weapon Options
            case 24: {
                if (currentRace.get_weaponOption().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalWeapons)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded weapon\n";
                            }
                            index++;
                        }
                        currentRace.insert_weaponOption(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Weapons", GlobalWeapons, "", true, 4);
                        std::cout << "\nWhat weapon options do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon\nWhat weapon options do you want to add to your race?\n", true, false, GlobalWeapons);
                        currentRace.insert_weaponOption(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Weapon Profs
            case 25: {
                if (currentRace.get_weaponProf().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalWeapons)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded weapon\n";
                            }
                            index++;
                        }
                        currentRace.insert_weaponProf(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Weapons", GlobalWeapons, "", true, 4);
                        std::cout << "\nWhat weapon proficencies do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon\nWhat weapon proficencies do you want to add to your race?\n", true, false, GlobalWeapons);
                        currentRace.insert_weaponProf(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Armor Profs
            case 26: {
                if (currentRace.get_armorProf().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalArmorType)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded armor type\n";
                            }
                            index++;
                        }
                        currentRace.insert_armorProf(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Armor", GlobalArmorType, "", true, 4);
                        std::cout << "\nWhat armor types do you want to add to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded armor type\nWhat armor types do you want to add to your race?\n", true, false, GlobalArmorType);
                        currentRace.insert_armorProf(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Damage Res
            case 27: {
                if (currentRace.get_damageRes().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalDamageType)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded damage type\n";
                            }
                            index++;
                        }
                        currentRace.insert_damageRes(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Damage Types", GlobalDamageType, "", true, 4);
                        std::cout << "\nWhat damage types do you want to add resistance to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded damage type\nWhat damage types do you want to add resistance to your race?\n", true, false, GlobalDamageType);
                        currentRace.insert_damageRes(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Damage Imm
            case 28: {
                if (currentRace.get_damageImmun().empty()) {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        int index{};
                        for (std::string i : parameters) {
                            if (includes_string(i, GlobalDamageType)) {
                                newLanguages.push_back(i);
                            }
                            else {
                                std::cout << "\n" << i << " is not a loaded damage type\n";
                            }
                            index++;
                        }
                        currentRace.insert_damageImmun(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Damage Types", GlobalDamageType, "", true, 4);
                        std::cout << "\nWhat damage types do you want to add immunity to your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded damage type\nWhat damage types do you want to add immunity to your race?\n", true, false, GlobalDamageType);
                        currentRace.insert_damageImmun(newName);
                    }
                }
                else {
                    currentRace = ExecuteRaceCommand(RaceCommandCode("edit"), currentRace, parameters, "add");
                }
                break;
            }
                   //Traits
            case 29: {
                if (currentRace.get_trait().empty()) {
                    //Testing phase
                }
                break;
            }
            default:
                break;
            }
        }
        else {
            std::cout << "\nInvalid Input\n";
        }

        break;
    }
    
    //Clear
    case 5: {


        break;
    }
    
    //Remove
    case 6: {


        break;
    }
    default:
        break;
    }
    if (context == "") {
        system("pause");
        system("cls");
    }
    return currentRace;
}

void DrawRace(Race input) {
    GUI displayGUI{};
    std::vector<std::string> mods{};

    if (input.get_name() != "") {
        std::cout << std::endl << std::endl;
        displayGUI.MakeBox(input.get_name(), 2);
        std::cout << std::endl;
    }
    if (input.get_optionPack() != "") {
        displayGUI.MakeBox(input.get_optionPack(), 1);
        std::cout << std::endl;
    }
    if (input.get_sizename() != "") {
        displayGUI.MakeBox(input.get_sizename(), 1);
        std::cout << std::endl;
    }
    if (input.get_description() != "") {
        displayGUI.GenerateMenu("Description", std::vector<std::string>{input.get_description()});
        std::cout << std::endl;
    }
    if (input.get_str() != 0) {
        mods.push_back("Str: " + std::to_string(input.get_str()));
    }
    if (input.get_dex() != 0) {
        mods.push_back("Dex: " + std::to_string(input.get_dex()));
    }
    if (input.get_con() != 0) {
        mods.push_back("Con: " + std::to_string(input.get_con()));
    }
    if (input.get_int() != 0) {
        mods.push_back("Int: " + std::to_string(input.get_int()));
    }
    if (input.get_wis() != 0) {
        mods.push_back("Wis: " + std::to_string(input.get_wis()));
    }
    if (input.get_cha() != 0) {
        mods.push_back("Cha: " + std::to_string(input.get_cha()));
    }
    if (!mods.empty()) {
        displayGUI.GenerateGrid(mods);
    }

    if(!input.get_language().empty()){
    displayGUI.GenerateMenu("Languages", input.get_language(), "", true, 4);
    }
    if (!input.get_tool().empty()) {
    displayGUI.GenerateMenu("Tools", input.get_tool(), "", true, 4);
    }
    if (!input.get_skillOption().empty()) {
    displayGUI.GenerateMenu("Skill Options", input.get_skillOption(), "", true, 4);
    }
    if (!input.get_languageOption().empty()) {
    displayGUI.GenerateMenu("Language Options", input.get_languageOption(), "", true, 4);
    }
    if (!input.get_weaponOption().empty()) {
    displayGUI.GenerateMenu("Weapon Options", input.get_weaponOption(), "", true, 4);
    }
    if (!input.get_skillProf().empty()) {
    displayGUI.GenerateMenu("Skill Proficencies", input.get_skillProf(), "", true, 4);
    }
    if (!input.get_weaponProf().empty()) {
    displayGUI.GenerateMenu("Weapon Proficencies", input.get_weaponProf(), "", true, 4);
    }
    if (!input.get_armorProf().empty()) {
    displayGUI.GenerateMenu("Armor Proficencies", input.get_armorProf(), "", true, 4);
    }
    if (!input.get_damageRes().empty()) {
    displayGUI.GenerateMenu("Damage Resistance", input.get_damageRes(), "", true, 4);
    }
    if (!input.get_damageImmun().empty()) {
        displayGUI.GenerateMenu("Damage Immunites", input.get_damageImmun(), "", true, 4);
    }
    
    /*std::cout << std::endl;
    for (Trait i : input.get_trait()) {
        displayGUI.GenerateMenu(i.get_name(), std::vector<std::string>{i.get_description()}, i.get_typename());
    }
    std::cout << std::endl;*/
}

Race RaceConsole() {
    Race newRace{};
    GUI raceGUI{};
    std::vector<std::string> commands{"done","help","cancel","add","edit","clear","remove"};
    std::vector<std::string> commandsDef{"Finishes Race","Get help on command","Cancels current action","Add an aspect of race","Edit aspect","Clears race","Remove element"};
    std::vector<std::string> combined{merge_ordered(commands,commandsDef)};
    std::string input{};
    
    system("cls");
    

    do {
        raceGUI.MakeBox("Race Creator", 2);
        input.clear();
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        DrawRace(newRace);

        std::cout << "\n\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        parameter = input;
        int parameterindex{};
        for (char i : input) {
            if (i != ' ') {
                if (std::isalpha(i)) {
                    command.push_back(std::tolower(i));
                    parameter.erase(0, 1);
                }
                else {
                    command.push_back(i);
                    parameter.erase(0, 1);
                }
            }
            else {
                parameter.erase(0, 1);
                break;
            }
        }
        if (includes_string(command, commands)) {
            if (command == "help") {
                if (parameter == "") {
                    newRace = ExecuteRaceCommand(RaceCommandCode(command), newRace, combined,"console");
                }
                else {
                    std::vector<std::string> parameters{ split(parameter) };
                    newRace = ExecuteRaceCommand(RaceCommandCode(command), newRace, parameters);
                }
            }
            else {
                std::vector<std::string> parameters{ split(parameter) };
                newRace = ExecuteRaceCommand(RaceCommandCode(command), newRace, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }


    } while (input != "done" && newRace.get_name() != "%%CANCELED%%");

    return newRace;
}


Race EditRaceInfo(std::string Name, std::string OptionPack, std::string Description, std::string Str, std::string Dex, std::string Con, std::string Int, std::string Wis, std::string Cha, std::string SizeChoice, std::string Speed, std::string FlyingSpd, std::string SwimmingSpd, std::string DarkVision, std::string SkillOptionsCount, std::string LanguageOptionsCount, std::string WeaponOptionsCount, std::string LizFolkAC, std::string TortAC, std::vector<std::string> Languages, std::vector<std::string> Tools, std::vector<std::string> SkillOptions, std::vector<std::string> SkillProf, std::vector<std::string> LanguageOptions, std::vector<std::string> WeaponOptions, std::vector<std::string> WeaponProf, std::vector<std::string> ArmorProf, std::vector<std::string> DamageRes, std::vector<std::string> DamageImmun, std::vector<Trait> Traits) {
    Race NewRace{};
    bool check{};
    std::string selection{};

    if (Name == "") {
        std::cout << "Enter name for race: ";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, Name);
        if (Name == "") {
            std::getline(std::cin, Name);
        }
        Name = HLib::InputCheck(Name, "Enter name for race: ");
    }
    NewRace.set_name(Name);

    if (OptionPack == "") {
        std::cout << "\nDo you want to save it to a custon pack? (y/n) ";
        std::getline(std::cin, selection);
        selection = HLib::InputCheck(selection, "\nDo you want to save it to a custon pack? (y/n) ", true, false, std::vector<std::string>{"y", "n"});
        if (selection[0] == 'y') {
            std::string pack{};
            std::cout << "Please enter Pack name: ";
            std::getline(std::cin, pack);
            NewRace.set_optionPack(pack);
        }
        else {
            NewRace.set_optionPack("Default");
        }
    }
    else {
        NewRace.set_optionPack(OptionPack);
    }

    if (Description == "") {
        std::cout << "\nEnter description: ";
        std::getline(std::cin, Description);
    }
    NewRace.set_description(Description);

    if (SizeChoice == "") {
        std::cout << "\nWhat size is the race: Small (0), Medium (1), Large (2)\n";
        std::getline(std::cin, SizeChoice);
    }
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
    if (LizFolkAC == "true") {
        selection = "y";
    }
    else if (LizFolkAC == "false") {
        selection = "n";
    }
    NewRace.set_lizFolkAC(std::stoi(GetInputSingle("\nDo they have Lizard folk AC? (y/n) ", selection, true)));

    selection.clear();
    if (TortAC == "true") {
        selection = "y";
    }
    else if (TortAC == "false") {
        selection = "n";
    }
    NewRace.set_tortAC(std::stoi(GetInputSingle("\nDo they have Tortle AC? (y/n) ", selection, true)));
    
    system("pause");

    NewRace.insert_tool(GetInputVector("tool profs", GlobalTools, Tools));

    NewRace.insert_languageOption(GetInputVector("language options", GlobalLanguages, LanguageOptions));

    NewRace.insert_language(GetInputVector("languages", GlobalLanguages, Languages));

    NewRace.insert_skillOption(GetInputVector("skills", GlobalSkills, SkillOptions));

    NewRace.insert_skillProf(GetInputVector("skill profs", GlobalSkills, SkillProf));

    NewRace.insert_weaponOption(GetInputVector("weapon options", GlobalWeapons, WeaponOptions));

    NewRace.insert_weaponProf(GetInputVector("weapon profs", GlobalWeapons, WeaponProf));

    NewRace.insert_armorProf(GetInputVector("armor profs", GlobalArmorType, ArmorProf));

    NewRace.insert_damageRes(GetInputVector("damage resistance", GlobalDamageType, DamageRes));

    NewRace.insert_damageImmun(GetInputVector("damage immunities", GlobalDamageType, DamageImmun));

    NewRace.insert_trait(InsertTraitsPrompt(Traits));

    std::cout << "\n\nRace has been finished\n";

    system("pause");
    return NewRace;
}
