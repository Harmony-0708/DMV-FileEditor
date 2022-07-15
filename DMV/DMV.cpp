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


void GenerateMenu();
Race EditRaceInfo(std::string Name = "", std::string OptionPack = "", std::string Description = "", std::string Str = "", std::string Dex = "", std::string Con = "", std::string Int = "", std::string Wis = "", std::string Cha = "", std::string SizeChoice = "", std::string Speed = "", std::string FlyingSpd = "", std::string SwimmingSpd = "", std::string DarkVision = "", std::string SkillOptionsCount = "", std::string LanguageOptionsCount = "", std::string WeaponOptionsCount = "", std::string LizFolkAC = "", std::string TortAC = "", std::vector<std::string> Languages = {"empty"}, std::vector<std::string> Tools = {"empty"}, std::vector<std::string> SkillOptions = {"empty"}, std::vector<std::string> SkillProf = {"empty"}, std::vector<std::string> LanguageOptions = {"empty"}, std::vector<std::string> WeaponOptions = {"empty"}, std::vector<std::string> WeaponProf = {"empty"}, std::vector<std::string> ArmorProf = {"empty"}, std::vector<std::string> DamageRes = {"empty"}, std::vector<std::string> DamageImmun = {"empty"}, std::vector<Trait> Traits = {});
std::string GetInputSingle(std::string prompt, std::string inputVar, bool yesno = false);
std::vector<std::string> GetInputVector(std::string prompt, std::vector<std::string> globalVector, std::vector<std::string> inputVar = {});
std::vector<Trait> InsertTraitsPrompt(std::vector<Trait> defaultVector = {});
std::vector<std::string> RaceOptions{ "Name", "OptionPack", "Description", "Str", "Dex", "Con", "Int", "Wis", "Cha", "SizeChoice", "Speed", "FlyingSpd", "SwimmingSpd", "DarkVision", "SkillOptionsCount", "LanguageOptionsCount", "WeaponOptionsCount", "LizFolkAC", "TortAC", "Languages", "Tools", "SkillOptions", "SkillProf", "LanguageOptions", "WeaponOptions", "WeaponProf", "ArmorProf", "DamageRes", "DamageImmun", "Traits"};
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
    std::vector<Race> savedRaces{};
    std::vector<Pack> savedPacks{};

    std::vector<std::string> namesOfPacks{};
    std::vector<std::string> namesOfRaces{};
    do {
        system("cls");

        namesOfPacks.clear();
        namesOfRaces.clear();

        for (Pack i : savedPacks) {
            for (Race k : i.get_races()) {
                if (std::find(namesOfRaces.begin(), namesOfRaces.end(), k.get_name()) == namesOfRaces.end()) {
                    savedRaces.push_back(k);
                    namesOfRaces.push_back(k.get_name());
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
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfRaces);
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
            savedRaces.push_back(EditRaceInfo());
            if (std::find(namesOfPacks.begin(), namesOfPacks.end(), savedRaces.back().get_name()) == namesOfPacks.end()) {
                Pack newPack{ savedRaces.back().get_optionPack() };
                newPack.set_races(savedRaces);
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
                std::cout << "Enter choice: ";
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, choice);
                choice = HLib::InputCheck(choice, "Enter choice: ", false, false, namesOfRaces);
                editedRace = savedRaces.at(index(choice, namesOfRaces));
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
            std::cout << "Is this pack saved as a pack file (pck) or as a DMV pack (orcbrew)? " << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, choice);
            choice = HLib::InputCheck(choice, "Is this pack saved as a pack file (pck) or as a DMV pack (orcbrew)?\n", true, false, std::vector<std::string>{"pck", "orcbrew"});
            if (choice == "pck") {
                std::string name{};
                std::cout << "Enter name of pack" << std::endl;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, name);
                newPack.load(name);
                if (std::find(namesOfPacks.begin(), namesOfPacks.end(), newPack.get_name()) == namesOfPacks.end()) {
                    savedPacks.push_back(newPack);
                }
                else {
                    std::cout << "Pack is already loaded" << std::endl;
                }
            }
            else {
                std::cout << "Only pck files are supported at this time.\n";
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
            std::cout << "Test function: Grid testing" << std::endl << std::endl;
            menuGUI.GenerateMenu("Tools", std::vector<std::string>{}, "", true, 4);
            //displayGUI.GenerateMenu("Tools", get_tool(), "", true, 4);
            system("pause");
            break;
        }
        default:
            break;
        }

        
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

