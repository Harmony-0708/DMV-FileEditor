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
#include "CommandObject.h"

void DrawRace(Race input);
void DrawSpell(Spell input);
void DrawTrait(Trait input);
void GrabObjectName(std::vector<std::string>& parameters, HPack& currentHPack, std::string& objectName, std::string& displayType, Pack& loadedPack);
HPack Display(HPack currentHPack, std::vector<std::string> parameters);
HPack Load(HPack currentHPack, std::vector<std::string> parameters);
HPack Save(HPack currentHPack, std::vector<std::string> parameters);
HPack Edit(HPack currentHPack, std::vector<std::string> parameters);
HPack Add(HPack currentHPack, std::vector<std::string> parameters);
Race RaceAdd(Race currentRace, std::vector<std::string>& parameters);
Race RaceEdit(Race currentRace, std::vector<std::string>& parameters);
Race RaceRemove(Race currentRace, std::vector<std::string>& parameters);
Spell SpellAdd(Spell currentSpell, std::vector<std::string>& parameters);
Spell SpellEdit(Spell currentSpell, std::vector<std::string>& parameters);
Spell SpellRemove(Spell currentSpell, std::vector<std::string>& parameters);

std::vector<Trait> remove(std::vector<Trait> input, int index);
std::vector<Spell> remove(std::vector<Spell> input, int index);
std::vector<std::string> remove(std::vector<std::string> input, int index);
std::vector<std::string> selection(std::vector<std::string>);

Race FindRace(std::string raceName, std::vector<Pack> packSet, std::string packName = "");

int CommandCode(std::string command, std::vector<std::string> commands);

HPack ExecuteCommand(int cmdCode, HPack currentHPack, std::vector<std::string> parameters = {}, std::string context = {});
Race ExecuteRaceCommand(int cmdCode, Race currentRace, std::vector<std::string> parameters = {}, std::string context = {});
Spell ExecuteSpellCommand(int cmdCode, Spell currentSpell, std::vector<std::string> parameters, std::string context = {});


void ConsoleInput(std::string& parameter, std::string& input, std::string& command);
void Console(std::vector<std::string> currentCommands = {}, std::vector<std::string> currentCmdDef = {}, HPack currentHPack = {});
void ConsoleInput(std::string& parameter, std::string& input, std::string& command);
Race RaceConsole(Race currentRace = {});
Spell SpellConsole(Spell currentSpell = {});
Trait EditTrait(Trait currentTrait = {});

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

//Console
std::vector<std::string> GlobalCommands{
    "exit",
    "help",
    "display", 
    "add", 
    "load", 
    "save", 
    "export", 
    "name", 
    "edit"
};
std::vector<std::string> GlobalCommandDefs{
    "Closes the program", 
    "Displays Commands",
    "Displays stuff", 
    "Add to pack", 
    "Load from a file", 
    "Save to a file", 
    "Export to Orcbrew", 
    "Rename Packs", 
    "Edit an item"
};

//Race
std::vector<std::string> GlobalRaceCommands{ 
    "done",
    "help",
    "cancel",
    "add",
    "edit",
    "clear",
    "remove" 
};
std::vector<std::string> GlobalRaceCommandDefs{ 
    "Finishes Race",
    "Get help on command",
    "Cancels current action",
    "Add an aspect of race",
    "Edit aspect",
    "Clears race",
    "Remove element" 
};
std::vector<std::string> GlobalRaceOptions{ 
    "name", 
    "option-pack", 
    "description", 
    "size",
    "str", 
    "dex", 
    "con", 
    "int", 
    "wis", 
    "cha", 
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
    "trait" 
};
std::vector<std::string> GlobalRaceDefs{ 
    "The name of your Race", 
    "The name of the pack your race is in", 
    "The Description of your race",
    "The size of your race",
    "Strength mod", 
    "Dexterity mod",
    "Constitution mod",
    "Intelligence mod", 
    "Wisdom mod",
    "Charisma mod", 
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

//Spell
std::vector<std::string> GlobalSpellCommands{ 
    "done",
    "help",
    "cancel",
    "add",
    "edit",
    "clear",
    "remove" 
};
std::vector<std::string> GlobalSpellCommandDefs{ 
    "Finishes Spell",
    "Get help on command",
    "Cancels current action",
    "Add an aspect of spell",
    "Edit aspect",
    "Clears spell",
    "Remove element" 
};
std::vector<std::string> GlobalSpellOptions{ 
    "name", 
    "option-pack", 
    "description",
    "school",
    "duration",
    "component",
    "casting-time",
    "level",
    "verbal",
    "somatic",
    "material",
    "ritual",
    "attack-roll",
    "classes",
    "range"
};
std::vector<std::string> GlobalSpellDefs{ 
    "The name of your Spell",
    "The name of the pack your spell is in", 
    "The Description of your spell",
    "The school of magic your spell is under",
    "The duration of the spell",
    "Components needed to case spell",
    "How long it takes to cast",
    "Level of spell, 0 is cantrip",
    "Veberal spell",
    "Somatic spell",
    "Material Spell",
    "Ritual Spell",
    "If spell is an attack roll",
    "The classes that can use the spell",
    "The range of the spell"
};


int main()
{
    Console(GlobalCommands,GlobalCommandDefs, GlobalPack);
    return 0;
}

//System
void DrawRace(Race input) {
    GUI displayGUI{};
    std::vector<std::string> mods{};

    if (input.get_name() != "") {
        displayGUI.MakeBox(input.get_name(), 2);
    }
    if (input.get_optionPack() != "") {
        displayGUI.MakeBox(input.get_optionPack(), 1);
    }
    if (input.get_sizename() != "") {
        displayGUI.MakeBox(input.get_sizename(), 1);
    }
    if (input.get_description() != "") {
        displayGUI.GenerateMenu("Description", std::vector<std::string>{input.get_description()});
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
    if (input.get_lizFolkAC()) {
        displayGUI.MakeBox("Lizard Folk AC: True", 1);
    }
    if (input.get_tortAC()) {
        displayGUI.MakeBox("Tortle AC: True", 1);
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
    
    if (!input.get_trait().empty()) {
        for (Trait i : input.get_trait()) {
            displayGUI.GenerateMenu(i.get_name(), std::vector<std::string>{i.get_description()}, i.get_typename());
        }
    }
}
void DrawSpell(Spell input) {
    GUI spellGUI{};

    if (input.get_name() != "") {
        spellGUI.MakeBox(input.get_name(), 2);
    }
    if (input.get_optionPack() != "") {
        spellGUI.MakeBox(input.get_optionPack(), 1);
    }
    if (input.get_school() != "") {
        spellGUI.MakeBox("School: " + input.get_school(), 1);
    }
    if (input.get_duration() != "") {
        spellGUI.MakeBox("Duration: " + input.get_duration(), 1);
    }
    if (input.get_component() != "") {
        spellGUI.MakeBox("Components: " + input.get_component(), 1);
    }
    if (input.get_castingTime() != "") {
        spellGUI.MakeBox("Casting Time: " + input.get_castingTime(), 1);
    }
    if (input.get_range() != "") {
        spellGUI.MakeBox("Range: " + input.get_range(), 1);
    }
    if (input.get_level() != 0) {
        spellGUI.MakeBox("Level: " + std::to_string(input.get_level()), 1);
    }
    if (input.is_verbal()) {
        spellGUI.MakeBox("Verbal: True", 1);
    }
    if (input.is_somatic()) {
        spellGUI.MakeBox("Somatic: True", 1);
    }
    if (input.is_material()) {
        spellGUI.MakeBox("Material: True", 1);
    }
    if (input.is_ritual()) {
        spellGUI.MakeBox("Ritual: True", 1);
    }
    if (input.is_attackRoll()) {
        spellGUI.MakeBox("Attack roll: True", 1);
    }
    if (input.get_description() != "") {
        spellGUI.GenerateMenu("Description", std::vector<std::string>{input.get_description()});
    }
    if (!input.get_class().empty()) {
        spellGUI.GenerateMenu("Classes", input.get_class(), "", true, 4);
    }

}
void DrawTrait(Trait input) {
    GUI drawGUI{};
    drawGUI.MakeBox((input.get_name() == "") ? "New Trait" : input.get_name(), 2);
    drawGUI.MakeBox(input.get_typename(), 2);
    if (input.get_description() != "") {
        drawGUI.GenerateMenu("Description", std::vector<std::string>{input.get_description()});
    }
}
void GrabObjectName(std::vector<std::string>& parameters, HPack& currentHPack, std::string& objectName, std::string& displayType, Pack& loadedPack)
{
    GUI gui{};
    int index{};
    bool foundPack{ false };
    bool foundObject{ false };
    std::string input{};
    std::string packName{};
    std::vector<std::string> packs{};
    std::vector<std::string> chosenType{};

    parameters.erase(std::begin(parameters));

    for (Pack i : currentHPack.get_packs()) {
        packs.push_back(i.get_name());
    }
    for (std::string i : parameters) {
        if (index == 0) { packName += i; }
        else { packName += " " + i; }
        if (HLib::IncludesString(packName, packs)) { foundPack = true; break; }
        index++;
    }
    if (foundPack) {
        for (int i{ -1 }; i < index; i++) {
            parameters.erase(std::begin(parameters));
        }
        if (!parameters.empty()) {
            int index{};
            for (std::string i : parameters) {
                if (index == 0) { objectName += i; }
                else { objectName += " " + i; }
                index++;
            }
        }
    }

    if (!foundPack) {
        gui.GenerateMenu("Packs", packs);
        std::cout << "\nWhat pack is the " << displayType << " in?\n";
        std::getline(std::cin, packName);
    }
    packName = HLib::InputCheck(packName, "\nWhat pack is the " + displayType + " in?\n", packs, false, false);

    loadedPack = currentHPack.get_pack(packName);

    if (displayType == "race") {
        for (Race i : loadedPack.get_races()) {
            if (i.get_name() == objectName) {
                foundObject = true;
            }
            chosenType.push_back(i.get_name());
        }
    }
    else if (displayType == "spell") {
        for (Spell i : loadedPack.get_spells()) {
            if (i.get_name() == objectName) {
                foundObject = true;
            }
            chosenType.push_back(i.get_name());
        }
    }

    if (!foundObject) {
        gui.GenerateMenu("Loaded", chosenType);
        std::cout << "\nWhat " << displayType << " do you want?\n";
        std::getline(std::cin, objectName);
    }
    if (!chosenType.empty()) { objectName = HLib::InputCheck(objectName, "\nWhat " + displayType + " do you want?\n", chosenType, false, false); }
    else { std::cout << "\nList empty\n"; objectName = "null"; }
}

//Object Editing
HPack Display(HPack currentHPack, std::vector<std::string> parameters) {
    Pack loadedPack{};
    std::string objectName{};
    std::string displayType{ parameters.at(0) };

    GrabObjectName(parameters, currentHPack, objectName, displayType, loadedPack);
    
    if (displayType == "race") {
        DrawRace(loadedPack.get_race(objectName));
    }
    else if (displayType == "spell") {
        DrawSpell(loadedPack.get_spell(objectName));
    }
    
    return currentHPack;
}
HPack Load(HPack currentHPack, std::vector<std::string> parameters) {
    GUI loadGUI{};
    std::vector<std::string> fileTypes{ "hpck","pck","orcbrew" };
    std::vector<std::string> countOptions{ "single","multi","all" };
    std::string countFiles{};
    std::string fileType{};
    std::string fileName{};
    std::vector<std::string> nameOfFiles{};
    //parameters[0] = amount of files to load (single, multi, all)
    //parameters[1] = type of file to load (pck,hpck,orcbrew)
    //parameters[2] = name of the file to load (only works in single)

    switch (parameters.size())
    {
    case 0: {
        //Count
        std::cout << "\nHow many files do you want to load?\n";
        std::getline(std::cin, countFiles);
        countFiles = HLib::InputCheck(countFiles, "\nInvalid Item\nHow many files do you want to load?\n", countOptions), true, false;

        //File Type
        std::cout << "\nWhat type of file do you want to load?\n";
        std::getline(std::cin, fileType);
        fileType = HLib::InputCheck(fileType, "\nInvalid Item\nWhat type of file do you want to load?\n", fileTypes, true, false);

        break;
    }
    case 1: {
        //Count
        countFiles = parameters.at(0);
        countFiles = HLib::InputCheck(countFiles, "\nInvalid Item\nHow many files do you want to load?\n", countOptions, true, false);

        //File Type
        std::cout << "\nWhat type of file do you want to load?\n";
        std::getline(std::cin, fileType);
        fileType = HLib::InputCheck(fileType, "\nInvalid Item\nWhat type of file do you want to load?\n", fileTypes, true, false);
        break;
    }
    case 2: {
        //Count
        countFiles = parameters.at(0);
        countFiles = HLib::InputCheck(countFiles, "\nInvalid Item\nHow many files do you want to load?\n", countOptions, true, false);

        //File Type
        fileType = parameters.at(1);
        fileType = HLib::InputCheck(fileType, "\nInvalid Item\nWhat type of file do you want to load?\n", fileTypes, true, false);
        break;
    }
    default: {
        //Count
        countFiles = parameters.at(0);
        countFiles = HLib::InputCheck(countFiles, "\nInvalid Item\nLoad by filename must be single\n", std::vector<std::string>{"single"} , true, false);

        //File Type
        fileType = parameters.at(1);
        fileType = HLib::InputCheck(fileType, "\nInvalid Item\nWhat type of file do you want to load?\n", fileTypes, true, false);

        int index{ 0 };
        for (std::string i : parameters) {
            if (index > 2) {
                fileName += " " + i;
            }
            else if (index == 2) {
                fileName += i;
            }
            index++;
        }

        break;
    }
    }

    std::cout << "\nThe " << fileType << " files will be loaded in the local folder. Please ensure the files you want to load are currently in the folder then hit enter.\n";
    system("pause");


    if (fileType == "hpck" || fileType == "pck") {
        for (const auto& i : std::filesystem::directory_iterator("CustomPacks")) {
            std::string path{ i.path().string() };
            path.erase(0, 12);
            if (path.substr(path.find(".") + 1) == fileType && path != "buffer.hpck") {
                nameOfFiles.push_back(path);
            }
        }
    }
    else {
        for (const auto& i : std::filesystem::directory_iterator("OrcbrewPacks")) {
            std::string path{ i.path().string() };
            path.erase(0, 13);
            if (path.substr(path.find(".") + 1) == fileType) {
                nameOfFiles.push_back(path);
            }
        }
    }

    if (countFiles == "multi") {
        nameOfFiles = selection(nameOfFiles);
    }
    else if (countFiles == "single") {
        if (fileName == "") {
            loadGUI.GenerateMenu("Loaded Files", nameOfFiles);

            std::cout << "\nWhat is the name of your file?\n";
            std::getline(std::cin, fileName);
            fileName = HLib::InputCheck(fileName, "\nInvalid Item\nWhat is the name of your file?\n", nameOfFiles, false, false);

            nameOfFiles.clear();
            nameOfFiles.push_back(fileName);
        }
        else {
            fileName = HLib::InputCheck(fileName, "\nInvalid Item\nWhat is the name of your file?\n", nameOfFiles, false, false);
            nameOfFiles.clear();
            nameOfFiles.push_back(fileName);
        }
    }


    for (std::string i : nameOfFiles) {
        if (fileType == "hpck") {
            HPack newHPack{};
            i.erase(i.size() - 5, 5);
            newHPack.load(i);
            if (currentHPack.get_name() == "Default") { currentHPack.set_name(i); }
            currentHPack = currentHPack.merge(std::vector<HPack>{ currentHPack, newHPack});
        }
        else if (fileType == "pck") {
            HPack newHPack{};
            Pack newPack{};
            i.erase(i.size() - 4, 4);
            newPack.load_pack(i);
            newHPack.add_pack(newPack);
            currentHPack = currentHPack.merge(std::vector<HPack>{currentHPack, newHPack});
        }
        else if (fileType == "orcbrew") {
            HPack newHPack{};
            Orcbrew newPack{};
            i.erase(i.size() - 8, 8);
            newHPack = newPack.load(i);
            currentHPack = currentHPack.merge(std::vector<HPack>{ currentHPack, newHPack});
        }
    }
    
    return currentHPack;
}
HPack Save(HPack currentHPack, std::vector<std::string> parameters) {
    if (parameters.at(0) == "hpck") {
        currentHPack.save();
        return currentHPack;
    }
    else if (parameters.at(0) == "pck") {
        std::string packName{};
        std::vector<std::string> packNames{};
        for (Pack i : currentHPack.get_packs()) {
            packNames.push_back(i.get_name());
        }
        std::cout << "\nWhich pack do you want to save?\n";
        std::getline(std::cin, packName);
        packName = HLib::InputCheck(packName, "\nInvalid Item, use options to find valid items\nWhich pack do you want to save?\n", packNames, true, false);
        for (Pack i : currentHPack.get_packs()) {
            if (i.get_name() == packName) {
                i.save_pack();
                break;
            }
        }
        return currentHPack;
    }
    else if (parameters.at(0) == "orcbrew") {
        Orcbrew tempOrcbrew{};
        tempOrcbrew.set_packs(currentHPack.get_packs());
        tempOrcbrew.set_name(currentHPack.get_name());
        tempOrcbrew.save();
        return currentHPack;
    }
    else {
        return currentHPack;
    }
}
HPack Edit(HPack currentHPack, std::vector<std::string> parameters) {
    Pack loadedPack{};
    std::string objectName{};
    std::string editType{ parameters.at(0) };

    GrabObjectName(parameters, currentHPack, objectName, editType, loadedPack);

    if (editType == "race") {
        Race newRace{ RaceConsole(RaceConsole(loadedPack.get_race(objectName))) };
        if (newRace.get_name() != "%%CANCELED%%") { loadedPack.update_race(newRace);}
    }
    else if (editType == "spell") {
        Spell newSpell{ SpellConsole(loadedPack.get_spell(objectName)) };
        if (newSpell.get_name() != "%%CANCELED%%") { loadedPack.update_spell(newSpell); };
    }
    currentHPack.update_pack(loadedPack);
    return currentHPack;
}
HPack Add(HPack currentHPack, std::vector<std::string> parameters) {
    std::string objectName{};
    std::string addType{ parameters.at(0) };
    int index{};
    if (parameters.size() > 1) {
        for (std::string i : parameters) {
            if (index == 0) { objectName += i; }
            else { objectName += " " + i; }
            index++;
        }
    }
    Pack newPack{};
    if (addType == "race") {
        Race newRace{};
        if (objectName != "") {
            newRace.set_optionPack(objectName);
        }
        newRace = RaceConsole(newRace);
        if (newRace.get_name() != "%%CANCELED%%") { newPack.set_races(newRace); newPack.set_name(newPack.get_races().at(0).get_optionPack());}
    }
    else if (addType == "spell") {
        Spell newSpell{};
        if (objectName != "") {
            newSpell.set_optionPack(objectName);
        }
        newSpell = SpellConsole(newSpell);
        if (newSpell.get_name() != "%%CANCELED%%") { newPack.set_spells(newSpell);newPack.set_name(newPack.get_spells().at(0).get_optionPack()); }
    }
    newPack.merge(currentHPack.get_packs());
    currentHPack.add_pack(newPack);
    return currentHPack;
}
Race RaceAdd(Race currentRace, std::vector<std::string>& parameters)
{
    GUI addGUI{};
    std::string newName{};
    std::vector<std::string> compareBase{};
    bool multi{ true };
    int cmdCode{ CommandCode(parameters.at(0), GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18: {
        currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "edit");
        multi = false;
        break;
    }
    case 19: {
        compareBase = GlobalLanguages;
        break;
    }
    case 20: {
        compareBase = GlobalTools;
        break;
    }
    case 21: {
        compareBase = GlobalSkills;
        break;
    }
    case 22: {
        compareBase = GlobalSkills;
        break;
    }
    case 23: {
        compareBase = GlobalLanguages;
        break;
    }
    case 24: {
        compareBase = GlobalWeapons;
        break;
    }
    case 25: {
        compareBase = GlobalWeapons;
        break;
    }
    case 26: {
        compareBase = GlobalArmorType;
        break;
    }
    case 27: {
        compareBase = GlobalDamageType;
        break;
    }
    case 28: {
        compareBase = GlobalDamageType;
        break;
    }
    case 29: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            for (std::string i : parameters) {
                newName += i;
            }
        }
        multi = false;
        break;
    }
    }
    if (multi) {
        if (parameters.size() == 1) {
            addGUI.GenerateMenu("Loaded", compareBase, "", true, 4);
            std::cout << "\nWhat do you want to add?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhat do you want to add?\n", compareBase, true, false);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
    }
    switch (cmdCode)
    {
        //Languages
    case 19: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Tools
    case 20: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Skill Options
    case 21: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Skill Profs
    case 22: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Language Options
    case 23: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Weapon Options
    case 24: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Weapon Profs
    case 25: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Armor Profs
    case 26: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Damage Res
    case 27: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Damage Imm
    case 28: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                currentRace.insert_language(i);
            }
            index++;
        }
        break;
    }
           //Traits
    case 29: {
        Trait newTrait{};
        newTrait.set_name(newName);
        newTrait = EditTrait(newTrait);
        if (newTrait.get_name() != "%%CANCELED%%") {
            currentRace.insert_trait(newTrait);
        }
        break;
    }
    default:
        break;
    }
    return currentRace;
}
Race RaceEdit(Race currentRace, std::vector<std::string>& parameters)
{
    GUI editGUI{};
    std::string newName{};
    std::vector<std::string> traitNames{};
    for (Trait i : currentRace.get_trait()) {
        traitNames.push_back(i.get_name());
    }
    int cmdCode{ CommandCode(parameters.at(0), GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        break;
    }
    case 3: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{"small", "medium", "large"}, true, false);
        break;
    }
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{}, false, true);
        break;
    }
    case 17:
    case 18: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{"yes", "no"}, true, false);
        break;
    }
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28: {
        currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, std::vector<std::string>{}, "edit");
        break;
    }
    case 29: {
        parameters.erase(parameters.begin());
        if (parameters.size() == 0) {
            std::cout << "\nWhich trait do you want to edit?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhich trait do you want to edit?\n", traitNames, true, false);
        }
        else {
            int index{};
            for (std::string i : parameters) {
                if (index == 0) { newName += i; }
                else { newName += " " + i; }
                index++;
            }
        }


        break;
    }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        currentRace.set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        currentRace.set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        currentRace.set_description(newName);
        break;
    }
          //Size
    case 3: {
        if (newName == "small") {
            currentRace.set_size(SizeEnum::small);
        }
        else if (newName == "medium") {
            currentRace.set_size(SizeEnum::medium);
        }
        else if (newName == "large") {
            currentRace.set_size(SizeEnum::large);
        }
        break;
    }
          //Str
    case 4: {
        currentRace.set_str(std::stoi(newName));
        break;
    }
          //Dex
    case 5: {
        currentRace.set_dex(std::stoi(newName));
        break;
    }
          //Con
    case 6: {
        currentRace.set_con(std::stoi(newName));
        break;
    }
          //Int
    case 7: {
        currentRace.set_int(std::stoi(newName));
        break;
    }
          //Wis
    case 8: {
        currentRace.set_wis(std::stoi(newName));
        break;
    }
          //Cha
    case 9: {
        currentRace.set_cha(std::stoi(newName));
        break;
    }
          //Speed
    case 10: {
        currentRace.set_speed(std::stoi(newName));
        break;
    }
           //FlyingSpeed
    case 11: {
        currentRace.set_flySpeed(std::stoi(newName));
        break;
    }
           //SwimmingSpeed
    case 12: {
        currentRace.set_swimSpeed(std::stoi(newName));
        break;
    }
           //Dark vision
    case 13: {
        currentRace.set_darkVision(std::stoi(newName));
        break;
    }
           //Skill Options Count
    case 14: {
        currentRace.set_skillOptionsCount(std::stoi(newName));
        break;
    }
           //Language Options Count
    case 15: {
        currentRace.set_languageOptionsCount(std::stoi(newName));
        break;
    }
           //Weapon Options Count
    case 16: {
        currentRace.set_weaponOptionsCount(std::stoi(newName));
        break;
    }
           //LizFolkAC
    case 17: {
        if (newName == "yes") {
            currentRace.set_lizFolkAC(true);
        }
        else {
            currentRace.set_lizFolkAC(false);
        }
        break;
    }
           //TortAC
    case 18: {
        if (newName == "yes") {
            currentRace.set_tortAC(true);
        }
        else {
            currentRace.set_tortAC(false);
        }
        break;
    }
           //Traits
    case 29: {
        Trait newTrait{};
        std::vector<Trait> allTraits{ currentRace.get_trait() };
        int index{};
        for (Trait i : allTraits) {
            if (i.get_name() == newName) {
                newTrait = i;
            }
            index++;
        }
        allTraits.at(index) = EditTrait(newTrait);
        currentRace.insert_trait(allTraits);
        break;
    }
    default:
        break;
    }
    return currentRace;
}
Race RaceRemove(Race currentRace, std::vector<std::string>& parameters)
{
    GUI removeGUI{};
    std::string newName{};
    std::vector<std::string> compareBase{};
    bool multi{ true };
    int cmdCode{ CommandCode(parameters.at(0), GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18: {
        multi = false;
        break;
    }
    case 19: {
        compareBase = currentRace.get_language();
        break;
    }
    case 20: {
        compareBase = currentRace.get_tool();
        break;
    }
    case 21: {
        compareBase = currentRace.get_skillOption();
        break;
    }
    case 22: {
        compareBase = currentRace.get_skillProf();
        break;
    }
    case 23: {
        compareBase = currentRace.get_languageOption();
        break;
    }
    case 24: {
        compareBase = currentRace.get_weaponOption();
        break;
    }
    case 25: {
        compareBase = currentRace.get_weaponProf();
        break;
    }
    case 26: {
        compareBase = currentRace.get_armorProf();
        break;
    }
    case 27: {
        compareBase = currentRace.get_damageRes();
        break;
    }
    case 28: {
        compareBase = currentRace.get_damageImmun();
        break;
    }
    case 29: {
        currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "remove");
        multi = false;
        break;
    }
    }
    if (multi) {
        if (parameters.size() == 1) {
            removeGUI.GenerateMenu("Loaded", compareBase, "", true, 4);
            std::cout << "\nWhat do you want to remove?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhat do you want to remove?\n", compareBase, true, false);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        if (currentRace.get_name() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_name("");
        }
        break;
    }
          //OptionPack
    case 1: {
        if (currentRace.get_optionPack() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_optionPack("");
        }
        break;
    }
          //Description
    case 2: {
        if (currentRace.get_description() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_description("");
        }
        break;
    }
          //Size
    case 3: {
        if (currentRace.get_sizename() == "Small") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_size(SizeEnum::small);
        }
        break;
    }
          //Str
    case 4: {
        if (currentRace.get_str() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_str(0);
        }
        break;
    }
          //Dex
    case 5: {
        if (currentRace.get_dex() == 0) {
            std::cout << "\nNothing to remove\n"; break;

        }
        else {
            currentRace.set_dex(0);
        }
        break;
    }
          //Con
    case 6: {
        if (currentRace.get_con() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_con(0);
        }
        break;
    }
          //Int
    case 7: {
        if (currentRace.get_int() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_int(0);
        }
        break;
    }
          //Wis
    case 8: {
        if (currentRace.get_wis() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_wis(0);
        }
        break;
    }
          //Cha
    case 9: {
        if (currentRace.get_cha() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_cha(0);
        }
        break;
    }
          //Speed
    case 10: {
        if (currentRace.get_speed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_speed(0);
        }
        break;
    }
           //FlyingSpeed
    case 11: {
        if (currentRace.get_flySpeed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_flySpeed(0);
        }
        break;
    }
           //SwimmingSpeed
    case 12: {
        if (currentRace.get_swimSpeed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_swimSpeed(0);
        }
        break;
    }
           //Dark vision
    case 13: {
        if (currentRace.get_darkVision() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_darkVision(0);
        }
        break;
    }
           //Skill Options Count
    case 14: {
        if (currentRace.get_skillOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_skillOptionsCount(0);
        }
        break;
    }
           //Language Options Count
    case 15: {
        if (currentRace.get_languageOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_languageOptionsCount(0);
        }
        break;
    }
           //Weapon Options Count
    case 16: {
        if (currentRace.get_weaponOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_weaponOptionsCount(0);
        }
        break;
    }
           //LizFolkAC
    case 17: {
        if (currentRace.get_lizFolkAC() == false) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_lizFolkAC(false);
        }
        break;
    }
           //TortAC
    case 18: {
        if (currentRace.get_tortAC() == false) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            currentRace.set_tortAC(false);
        }
        break;
    }
           //Languages
    case 19: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_language()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_language(newInsert);
        break;
    }
           //Tools
    case 20: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_tool()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_tool(newInsert);
        break;
    }
           //Skill Options
    case 21: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_skillOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_skillOption(newInsert);
        break;
    }
           //Skill Profs
    case 22: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_skillProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_skillProf(newInsert);
        break;
    }
           //Language Options
    case 23: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_languageOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_languageOption(newInsert);
        break;
    }
           //Weapon Options
    case 24: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_weaponOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_weaponOption(newInsert);
        break;
    }
           //Weapon Profs
    case 25: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_weaponProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_weaponProf(newInsert);
        break;
    }
           //Armor Profs
    case 26: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_armorProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_armorProf(newInsert);
        break;
    }
           //Damage Res
    case 27: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_damageRes()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_damageRes(newInsert);
        break;
    }
           //Damage Imm
    case 28: {
        std::vector<std::string> newInsert{};
        for (std::string i : currentRace.get_damageImmun()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        currentRace.insert_damageImmun(newInsert);
        break;
    }
    }
    return currentRace;
}
Spell SpellAdd(Spell currentSpell, std::vector<std::string>& parameters)
{
    GUI addGUI{};
    std::string newName{};
    int cmdCode{ CommandCode(parameters.at(0), GlobalSpellOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: {
        currentSpell = ExecuteSpellCommand(CommandCode("edit", GlobalSpellCommands), currentSpell, parameters, "add");
        break;
    }
    case 13: {
        if (parameters.size() == 1) {
            std::cout << "\nWhat class do you want to add?\n";
            std::getline(std::cin, newName);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
        break;
    }
    case 14: {
        currentSpell = ExecuteSpellCommand(CommandCode("edit", GlobalSpellCommands), currentSpell, parameters, "add");
        break;
    }
    }
    switch (cmdCode)
    {
        //Classes
    case 13: {
        for (std::string i : parameters) {
            currentSpell.insert_class(i);
        }
        break;
    }
    default:
        break;
    }
    return currentSpell;
}
Spell SpellEdit(Spell currentSpell, std::vector<std::string>& parameters)
{
    GUI editGUI{};
    std::string newName{};
    int cmdCode{ CommandCode(parameters.at(0), GlobalSpellOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        break;
    }
    case 7: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{}, false, true);
        break;
    }
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{"yes", "no"}, true, false);
        break;
    }
    case 13: {
        currentSpell = ExecuteSpellCommand(CommandCode("add", GlobalSpellCommands), currentSpell, parameters, "edit");
        break;
    }
    case 14: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        break;
    }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        currentSpell.set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        currentSpell.set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        currentSpell.set_description(newName);
        break;
    }
          //School
    case 3: {
        currentSpell.set_school(newName);
        break;
    }
          //Duration
    case 4: {
        currentSpell.set_duration(newName);
        break;
    }
          //Component
    case 5: {
        currentSpell.set_component(newName);
        break;
    }
          //Casting time
    case 6: {
        currentSpell.set_castingTime(newName);
        break;
    }
          //Level
    case 7: {
        currentSpell.set_level(std::stoi(newName));
        break;
    }
          //Verbal
    case 8: {
        if (newName == "yes") {
            currentSpell.set_verbal(true);
        }
        else {
            currentSpell.set_verbal(false);
        }
        break;
    }
          //Somatic
    case 9: {
        if (newName == "yes") {
            currentSpell.set_somatic(true);
        }
        else {
            currentSpell.set_somatic(false);
        }
        break;
    }
          //Material
    case 10: {
        if (newName == "yes") {
            currentSpell.set_material(true);
        }
        else {
            currentSpell.set_material(false);
        }
        break;
    }
           //Ritual
    case 11: {
        if (newName == "yes") {
            currentSpell.set_ritual(true);
        }
        else {
            currentSpell.set_ritual(false);
        }
        break;
    }
           //Attack Roll
    case 12: {
        if (newName == "yes") {
            currentSpell.set_attackRoll(true);
        }
        else {
            currentSpell.set_attackRoll(false);
        }
        break;
    }
           //Range
    case 14: {
        currentSpell.set_range(newName);
        break;
    }
    }
    return currentSpell;
}
Spell SpellRemove(Spell currentSpell, std::vector<std::string>& parameters)
{
    std::string newName{};
    int cmdCode{ CommandCode(parameters.at(0), GlobalSpellOptions) };
    GUI editGUI{};
    if (cmdCode == 13) {
        if (parameters.size() == 1) {
            std::cout << "\nWhat class do you want to remove?\n";
            std::getline(std::cin, newName);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        currentSpell.set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        currentSpell.set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        currentSpell.set_description(newName);
        break;
    }
          //School
    case 3: {
        currentSpell.set_school(newName);
        break;
    }
          //Duration
    case 4: {
        currentSpell.set_duration(newName);
        break;
    }
          //Component
    case 5: {
        currentSpell.set_component(newName);
        break;
    }
          //Casting time
    case 6: {
        currentSpell.set_castingTime(newName);
        break;
    }
          //Level
    case 7: {
        currentSpell.set_level(0);
        break;
    }
          //Verbal
    case 8: {
        currentSpell.set_verbal(false);
        break;
    }
          //Somatic
    case 9: {
        currentSpell.set_somatic(false);
        break;
    }
          //Material
    case 10: {
        currentSpell.set_material(false);
        break;
    }
           //Ritual
    case 11: {
        currentSpell.set_ritual(false);
        break;
    }
           //Attack Roll
    case 12: {
        currentSpell.set_attackRoll(false);
        break;
    }
           //Classes
    case 13: {
        std::vector<std::string> newClasses{};
        for (std::string i : currentSpell.get_class()) {
            if (!HLib::IncludesString(i, parameters)) {
                newClasses.push_back(i);
            }
        }
        currentSpell.set_classes(newClasses);
        break;
    }
           //Range
    case 14: {
        currentSpell.set_range(newName);
        break;
    }
    default:
        break;
    }
    return currentSpell;
}

//Functional
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
std::vector<std::string> selection(std::vector<std::string> parameters) {
    GUI selectionGUI{};
    std::vector<std::string> selected{};
    std::string input{};
    std::vector<std::string> commands{"add","remove","clear","done"};

    do {
        system("cls");

        std::string command{};
        std::string parameter{};

        selectionGUI.GenerateMenu("Enter selections ", parameters, "Use add, remove, and clear", true, 4);
        
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

        if (HLib::IncludesString(command, commands)) {
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
            int index{ -1 };
            bool found{ false };
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
            input = HLib::InputCheck(input, "\nYes/No\nAre you sure you want to clear your selection?\n", { "Yes","No","yes","no" }, true, false);
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

//Indexes
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

//Command stuff

//Execute commands
HPack ExecuteCommand(int cmdCode, HPack currentHPack, std::vector<std::string> parameters, std::string context) {
    switch (cmdCode)
    {
    //Exit
    case 0: {
        HLib::ExitProgram();
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
        std::vector<std::string> options{ "race" , "spell" };
        std::vector<std::string> optionDefs{ "Displays a race", "Displays a spell" };

        switch (ValidateCommand("What would you like to display?", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = Display(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Add
    case 3: {
        std::vector<std::string> options{ "race", "spell"};
        std::vector<std::string> optionDefs{ "Add race", "Add spell"};

        switch (ValidateCommand("What would you like to add?",options,optionDefs,parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = Add(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Load
    case 4: {
        std::vector<std::string> options{ "all","single","multi" };
        std::vector<std::string> optionDefs{ "Load all", "Load a single file", "Load multiple files"};

        switch (ValidateCommand("How many packs do you want to load?", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = Load(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }

    //Save
    case 5: {
        std::vector<std::string> options{ "hpck","pck" };
        std::vector<std::string> optionDefs{ "Saves all packs into one pack", "Save a single pack"};

        switch (ValidateCommand("How do you want to save your packs?", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = Save(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }

    //Export
    case 6: {
        std::vector<std::string> options{ "yes","no" };
        std::vector<std::string> optionDefs{ "", "" };

        switch (ValidateCommand("Are you sure you want to export your packs to orcbrew format? WARNING: Any orcbrew file with the same name as your current HPack will be overwritten", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            parameters.clear();
            parameters.push_back("orcbrew");
            currentHPack = Save(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
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
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do you want to rename?\n", nameOptions, true, false);
            currentHPack = ExecuteCommand(CommandCode("name", GlobalCommands), currentHPack, std::vector<std::string>{input}, "name");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            nameGUI.GenerateMenu("Name Options", nameOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("name", GlobalCommands), currentHPack, std::vector<std::string>{}, "name");
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
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhich pack do you want to rename?\n", packNames, true, false);
            std::string newName{};
            std::cout << "\nWhat do you want to rename the pack to?\n";
            std::getline(std::cin, newName);
            currentHPack.set_pack_name(input, newName);
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("name", GlobalCommands), currentHPack, std::vector<std::string>{});
        }

        break;
    }
    
    //Edit
    case 8: {
        std::vector<std::string> options{ "race", "spell" };
        std::vector<std::string> optionDefs{ "Edit a race", "Edit a spell" };

        switch (ValidateCommand("What would you like to edit?", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = Edit(currentHPack, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(cmdCode, currentHPack, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    default:
        std::cout << "\n\nAn error has occured, write down what you did and report it to the dev\n";
        break;
    }
    if (context == "") {
        system("pause");
        system("cls");
    }
    return currentHPack;
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
        }
		else {
			std::vector<std::string> selection{};
			int index{};
			if (parameters.at(0) == "all") {
				parameters.clear();
				parameters = HLib::MergeOrdered(GlobalRaceOptions, GlobalRaceDefs);
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
        switch (ValidateCommand("What would you like to add?", GlobalRaceOptions, GlobalRaceDefs, parameters))
        {
        case 0: {
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentRace = RaceAdd(currentRace, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Edit
    case 4: {
        switch (ValidateCommand("What would you like to edit?", GlobalRaceOptions, GlobalRaceDefs, parameters))
        {
        case 0: {
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentRace = RaceEdit(currentRace, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Clear
    case 5: {
        std::vector<std::string> options{ "yes", "no" };
        std::vector<std::string> optionDefs{ "", "" };

        switch (ValidateCommand("Are you sure?", options, optionDefs, parameters))
        {
        case 0: {
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            Race newRace{};
            currentRace = newRace;
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Remove
    case 6: {
        switch (ValidateCommand("What would you like to remove?", GlobalRaceOptions, GlobalRaceDefs, parameters))
        {
        case 0: {
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentRace = RaceRemove(currentRace, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentRace = ExecuteRaceCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
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
Spell ExecuteSpellCommand(int cmdCode, Spell currentSpell, std::vector<std::string> parameters, std::string context) {
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
        }
		else {
			std::vector<std::string> selection{};
			int index{};
			if (parameters.at(0) == "all") {
				parameters.clear();
				parameters = HLib::MergeOrdered(GlobalSpellOptions, GlobalSpellDefs);
			}
			if (context != "console") {
				for (std::string i : GlobalSpellOptions) {
					for (std::string k : parameters) {
						if (i == k) {
							selection.push_back(i);
							selection.push_back(GlobalSpellDefs.at(index));
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
        Spell cancelSpell{ "%%CANCELED%%" };
        currentSpell = cancelSpell;
        break;
    }
    
    //Add
    case 3: {
        switch (ValidateCommand("What would you like to add?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = SpellAdd(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Edit
    case 4: {
        switch (ValidateCommand("What would you like to edit?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = SpellEdit(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Clear
    case 5: {
        std::vector<std::string> options{ "yes", "no" };
        std::vector<std::string> optionDefs{ "", "" };

        switch (ValidateCommand("Are you sure?", options, optionDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            Spell newSpell{};
            currentSpell = newSpell;
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    
    //Remove
    case 6: {
        switch (ValidateCommand("What would you like to remove?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = SpellRemove(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteSpellCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }
    default:
        break;
    }
    if (context == "") {
        system("pause");
        system("cls");
    }
    return currentSpell;
}

//Consoles
void Console(std::vector<std::string> currentCommands, std::vector<std::string> currentCmdDef, HPack currentHPack) {
    GUI consoleGUI{};
    std::string input{};
    std::vector<std::string> combined{HLib::MergeOrdered(currentCommands,currentCmdDef)};
    int index{};
    
    do {
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        consoleGUI.MakeBox("Harmony's Dungeon Master's Vault file editor", 2);

        std::cout << "\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        ConsoleInput(parameter, input, command);
        std::vector<std::string> parameters{ HLib::Split(parameter) };

        if (HLib::IncludesString(command, currentCommands)) {
            if (command == "help") {
                currentHPack = ExecuteCommand(CommandCode(command, currentCommands), currentHPack, combined);
            }
            else {
                currentHPack = ExecuteCommand(CommandCode(command, currentCommands), currentHPack, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }
    } while (input != "exit");
}
void ConsoleInput(std::string& parameter, std::string& input, std::string& command)
{
    int parameterindex{};
    parameter = input;
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
}
Race RaceConsole(Race currentRace) {
    GUI raceGUI{};
    std::vector<std::string> commands{"done","help","cancel","add","edit","clear","remove"};
    std::vector<std::string> commandsDef{"Finishes Race","Get help on command","Cancels current action","Add an aspect of race","Edit aspect","Clears race","Remove element"};
    std::vector<std::string> combined{HLib::MergeOrdered(commands,commandsDef)};
    std::string input{};
    
    system("cls");
    

    do {
        raceGUI.MakeBox("###-Race Creator-###", 2);
        input.clear();
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        DrawRace(currentRace);

        std::cout << "\n\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        int parameterindex{};
        parameter = input;
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
        if (HLib::IncludesString(command, commands)) {
            if (command == "help") {
                if (parameter == "") {
                    currentRace = ExecuteRaceCommand(CommandCode(command, GlobalRaceCommands), currentRace, combined,"console");
                }
                else {
                    std::vector<std::string> parameters{ HLib::Split(parameter) };
                    currentRace = ExecuteRaceCommand(CommandCode(command, GlobalRaceCommands), currentRace, parameters);
                }
            }
            else {
                std::vector<std::string> parameters{ HLib::Split(parameter) };
                currentRace = ExecuteRaceCommand(CommandCode(command, GlobalRaceCommands), currentRace, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }


    } while (input != "done" && currentRace.get_name() != "%%CANCELED%%");

    return currentRace;
}
Spell SpellConsole(Spell currentSpell) {
    GUI spellGUI{};
    std::vector<std::string> commands{ GlobalSpellCommands };
    std::vector<std::string> commandsDef{ GlobalSpellCommandDefs };
    std::vector<std::string> combined{HLib::MergeOrdered(commands,commandsDef)};
    std::string input{};
    
    system("cls");
    

    do {
        spellGUI.MakeBox("###-Spell Creator-###", 2);
        input.clear();
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        DrawSpell(currentSpell);

        std::cout << "\n\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        ConsoleInput(parameter, input, command);
        if (HLib::IncludesString(command, commands)) {
            if (command == "help") {
                if (parameter == "") {
                    currentSpell = ExecuteSpellCommand(CommandCode(command,GlobalSpellCommands), currentSpell, combined,"console");
                }
                else {
                    std::vector<std::string> parameters{ HLib::Split(parameter) };
                    currentSpell = ExecuteSpellCommand(CommandCode(command, GlobalSpellCommands), currentSpell, parameters);
                }
            }
            else {
                std::vector<std::string> parameters{ HLib::Split(parameter) };
                currentSpell = ExecuteSpellCommand(CommandCode(command, GlobalSpellCommands), currentSpell, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }


    } while (input != "done" && currentSpell.get_name() != "%%CANCELED%%");

    return currentSpell;
}
Trait EditTrait(Trait currentTrait) {
    GUI traitGUI{};
    Trait bufferTrait{};
    std::vector<std::string> commands{ "done","help","cancel","edit","remove" };
    std::vector<std::string> commandsDef{ "Finishes Trait","Lists commands","Cancels trait","Edit aspect","Remove element" };
    std::vector<std::string> combined{ HLib::MergeOrdered(commands,commandsDef) };
    std::string input{};

    system("cls");


    do {
        system("cls");
        input.clear();
        std::string command{};
        std::string parameter{};
        std::string bufferCommand{};

        DrawTrait(currentTrait);

        std::cout << "\n\nEnter input:\n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin, input);

        //seperates the command
        ConsoleInput(parameter, input, command);
        if (HLib::IncludesString(command, commands)) {
            if (command == "help") {
                traitGUI.GenerateMenu("Trait Commands", combined,"",true,2);
                system("pause");
            }
			else if (command == "done" && (currentTrait.get_name() == "" || currentTrait.get_description() == "")) {
				std::cout << "\nTrait incomplete\n";
				command = "notdone";
				system("pause");
            }
            else if (command == "cancel") {
                std::cout << "\nTrait canceled\n";
                currentTrait.set_name("%%CANCELED%%");
            }
            else if (command == "edit") {
                std::vector<std::string> parameters{HLib::Split(parameter)};
                std::string newCommand{};
                if (!parameters.empty()) {
                    newCommand = parameters.at(0);
                    parameters.erase(std::begin(parameters));
                }
                std::string newString{};
                if (parameters.size() >= 1) {
                    parameters.insert(std::begin(parameters), std::begin(parameters), std::end(parameters));
                    if (parameters.at(0) == "name") {
                        parameters.erase(std::begin(parameters));
                        for (std::string i : parameters) {
                            newString += i;
                        }
                        currentTrait.set_name(newString);
                    }
                    else if (parameters.at(0) == "description") {
                        parameters.erase(std::begin(parameters));
                        for (std::string i : parameters) {
                            newString += i;
                        }
                        currentTrait.set_description(newString);
                    }
                    else if (parameters.at(0) == "type" && parameters.size() < 3) {
                        parameters.erase(std::begin(parameters));
                        for (std::string i : parameters) {
                            newString += i;
                        }
                        if (newString == "action") {
                            currentTrait.set_type(TraitType::Action);
                        }
                        else if (newString == "bonus action") {
                            currentTrait.set_type(TraitType::BAction);
                        }
                        else if (newString == "reaction") {
                            currentTrait.set_type(TraitType::Reaction);
                        }
                        else {
                            currentTrait.set_type(TraitType::Other);
                        }
                    }
                    else {
                        std::cout << "\nInvalid input\n";
                    }
                }
                else {
                    if (newCommand == "") {
                        std::cout << "\nEnter options to edit:\n";
                        std::cin.clear();
                        std::cin.sync();
                        std::getline(std::cin, newString);
                    }
                    newString = HLib::InputCheck(newCommand, "\nInvalid input\nEnter input:\n", std::vector<std::string>{"name", "description", "type"}, true, false);
                    if (newString == "name") {
                        newString.clear();
                        std::cout << "\nEnter name:\n";
                        std::cin.clear();
                        std::cin.sync();
                        std::getline(std::cin, newString);
                        currentTrait.set_name(newString);
                    }
                    else if (newString == "description") {
                        newString.clear();
                        std::cout << "\nEnter description:\n";
                        std::cin.clear();
                        std::cin.sync();
                        std::getline(std::cin, newString);
                        currentTrait.set_description(newString);
                    }
                    else if (newString == "type") {
                        newString.clear();
                        std::cout << "\nEnter type:\n";
                        std::cin.clear();
                        std::cin.sync();
                        std::getline(std::cin, newString);
                        currentTrait.set_description(newString);
                        newString = HLib::InputCheck(newString, "\nInvalid input\nEnter input:\n", std::vector<std::string>{"action", "bonus action", "reaction", "other"}, true, false);
                        if (newString == "action") {
                            currentTrait.set_type(TraitType::Action);
                        }
                        else if (newString == "bonus action") {
                            currentTrait.set_type(TraitType::BAction);
                        }
                        else if (newString == "reaction") {
                            currentTrait.set_type(TraitType::Reaction);
                        }
                        else {
                            currentTrait.set_type(TraitType::Other);
                        }
                    }
                }
                system("pause");
            }
            else if (command == "remove") {
                std::vector<std::string> parameters{ HLib::Split(parameter) };
                std::string newString{};
                if (parameters.size() > 1) {
                    if (parameters.at(0) == "name") {
                        newString.clear();
                        currentTrait.set_name(newString);
                    }
                    else if (parameters.at(0) == "description") {
                        newString.clear();
                        currentTrait.set_description(newString);
                    }
                    else if (parameters.at(0) == "type") {
                        currentTrait.set_type(TraitType::Other);
                    }
                    else {
                        std::cout << "\nInvalid input\n";
                    }
                }
                else {
                    std::cout << "\nEnter option to remove:\n";
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, newString);
                    newString = HLib::InputCheck(newString, "\nInvalid input\nEnter input:\n", std::vector<std::string>{"name", "description", "type"}, true, false);
                    if (newString == "name") {
                        newString.clear();
                        currentTrait.set_name(newString);
                    }
                    else if (newString == "description") {
                        newString.clear();
                        currentTrait.set_description(newString);
                    }
                    else if (newString == "type") {
                        currentTrait.set_type(TraitType::Other);
                    }
                }
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
            system("pause");
        }


    } while (input != "done" && currentTrait.get_name() != "%%CANCELED%%");
    if (currentTrait.get_name() == "%%CANCELED%%") {
        return bufferTrait;
    }
    else {
        return currentTrait;
    }
}

