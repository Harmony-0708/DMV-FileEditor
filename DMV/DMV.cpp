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

//Globals
HPack GlobalPack{};
std::vector<std::string> GlobalLanguages{"Giant", "Common", "Celestial", "Undercommon", "Goblin", "Dwarvish", "Abyssal", "Sylvan", "Orc", "Deep Speech", "Primordial", "Draconic", "Gnomish", "Elvish", "Halfling", "Infernal" };
std::vector<std::string> GlobalWeapons{"battleaxe", "halberd", "longsword", "dagger", "blowgun", "sickle", "handaxe", "war-pick", "flail", "greatsword", "whip", "rapier", "spear", "net", "shortbow", "warhammer", "mace", "crossbow-heavy", "glaive", "greataxe", "quarterstaff", "crossbow-light", "sling", "javelin", "light-hammer", "longbow", "greatclub", "club", "morningstar", "trident", "maul", "pike", "lance", "shortsword", "crossbow-hand", "scimitar", "dart"};
std::vector<std::string> GlobalSkills{"religion", "persuasion", "investigation", "acrobatics", "performance", "perception", "sleight-of-hand", "survival", "history", "animal-handling", "nature", "deception", "intimidation", "arcana", "athletics", "insight", "medicine", "stealth"};
std::vector<std::string> GlobalTools{"cartographers-tools", "painters-supplies", "poisoners-kit", "navigators-tools", "glassblowers-tools", "flute", "dice-set", "horn", "herbalism-kit", "dulcimer", "disguise-kit", "masons-tools", "land-vehicles", "viol", "thieves-tools", "jewelers-tools", "leatherworkers-tools", "smiths-tools", "drum", "cobblers-tools", "potters-tools", "dragonchess-set", "playing-card-set", "brewers-supplies", "three-dragon-ante-set", "forgery-kit", "pan-flute", "bagpipes", "woodcarvers-tools", "carpenters-tools", "tinkers-tools", "alchemists-supplies", "water-vehicles", "weavers-tools", "shawm", "cooks-utensils", "lute", "calligraphers-supplies", "lyre"};
std::vector<std::string> GlobalArmorType{"light","medium", "heavy", "shield"};
std::vector<std::string> GlobalDamageType{"fire", "acid", "psychic", "force", "bludgeoning", "radiant", "lightning", "slashing", "piercing", "thunder", "cold", "traps", "poison", "necrotic"};
std::vector<std::string> GlobalCommands{"exit","help"};
std::vector<std::string> GlobalCommandDefs{"Closes the program", "Displays Commands"};
bool displayCoolGUI{true};

int main()
{
    HPack SessionPack{};

    Console(std::vector<std::string>{"display", "add", "load", "save", "export"}, std::vector<std::string>{"Displays stuff", "Add to pack", "Load from a file", "Save to a file", "Export to Orcbrew"}, SessionPack);
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
        std::vector<std::string> option_desc{ "Displays everything", "Shows Parameters", "Enables fancy GUI", "Disables fancy GUI" };
        std::vector<Race> savedRaces{};
        std::vector<Pack> savedPacks{};
        Orcbrew SaveOrcbrew{};

        std::vector<std::string> namesOfPacks{};
        std::vector<std::string> namesOfRaces{};

        std::cout << std::endl;
        if (parameters.empty() || parameters.at(0) == options.at(0)) {
            menuGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);
            std::cout << std::endl;
            menuGUI.GenerateMenu("Display Options", options);
        }
        else if (parameters.at(0) == "help") {
            ExecuteCommand(CommandCode("help"), currentHPack, merge_ordered(options, option_desc));
        }
        else if (parameters.at(0) == options.at(1)) {
            menuGUI.GenerateMenu("Display Options", options);
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
        }
        break;
    }
    
    //Add
    case 3: {
        GUI addGUI{};
        std::vector<std::string> addOptions{ "cancel","race" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat would you like to add?\n";
            std::getline(std::cin, input);
            addOptions.push_back("options");
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat would you like to add?\n", true, false, addOptions);
            ExecuteCommand(CommandCode("add"), currentHPack, std::vector<std::string>{input}, "add");
        }
        else if (parameters.at(0) == "options") {
            addGUI.GenerateMenu("Add Options", addOptions);
            std::cout << std::endl;
            ExecuteCommand(CommandCode("add"), currentHPack, std::vector<std::string>{}, "add");
        }
        else if (parameters.at(0) == addOptions.at(0)) {
            break;
        }
        else if (parameters.at(0) == addOptions.at(1)) {
            Pack newPack{};
            newPack.set_races(EditRaceInfo());
            newPack.set_name(newPack.get_races().at(0).get_optionPack());
            newPack.merge(currentHPack.get_packs());
            currentHPack.add_pack(newPack);
        }
        break;
    }
    
    //Load
    case 4: {
        GUI loadGUI{};
        std::vector<std::string> loadOptions{ "cancel","all","single","multi"};
        std::vector<std::string> fileTypes{ "hpck","pck","orcbrew" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nHow many packs do you want to load?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nHow many packs do you want to load?\n", true, false, loadOptions);
            ExecuteCommand(CommandCode("load"), currentHPack,std::vector<std::string>{input}, "load");
        }
        else if (parameters.at(0) == "options") {
            loadGUI.GenerateMenu("Load Options", loadOptions);
            std::cout << std::endl;
            ExecuteCommand(CommandCode("load"), currentHPack, std::vector<std::string>{}, "load");
        }
        else if (parameters.at(0) == loadOptions.at(0)) {
            break;
        }
        else if (parameters.at(0) == loadOptions.at(1)) {
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
        else if (parameters.at(0) == loadOptions.at(2)) {
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
        else if (parameters.at(0) == loadOptions.at(3)) {

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
        break;
    }

    //Save
    case 5: {
        GUI saveGUI{};
        std::vector<std::string> saveOptions{ "cancel","hpck","pck" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nHow do you want to save your packs?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nHow do you want to save your packs?\n", true, false, loadOptions);
            ExecuteCommand(CommandCode("load"), currentHPack, std::vector<std::string>{input}, "load");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            saveGUI.GenerateMenu("Save Options", saveOptions);
            std::cout << std::endl;
            ExecuteCommand(CommandCode("save"), currentHPack, std::vector<std::string>{}, "save");
        }
        else if (parameters.at(0) == saveOptions.at(1)) {
            currentHPack.save();
        }
        else if (parameters.at(0) == saveOptions.at(2)) {

        }
        break;
    }

    //Export
    case 6: {
        //orcbrew shit
        /*else if (parameters.at(0) == saveOptions.at(3)) {
            Orcbrew tempOrcbrew{};
            tempOrcbrew.set_packs(currentHPack.get_packs());
            tempOrcbrew.set_name(currentHPack.get_name());
            tempOrcbrew.save();
        }*/
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
    std::vector<std::string> combined{};
    int index{};

    if (!currentCommands.empty()) { commands.insert(std::end(commands), std::begin(currentCommands), std::end(currentCommands)); }
    for (std::string i : commands) {
        combined.push_back(i);
        combined.push_back(currentCmdDef.at(index));
        index++;
    }
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
            std::vector<std::string> parameters{ split(parameter) };
            currentHPack = ExecuteCommand(CommandCode(command), currentHPack, parameters);
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