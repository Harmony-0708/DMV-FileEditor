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

void DrawRace(Race input);
void ExitProgram();

bool includes_string(std::string input, std::vector<std::string> vInput);
std::vector<Trait> remove(std::vector<Trait> input, int index);
std::vector<Spell> remove(std::vector<Spell> input, int index);
std::vector<std::string> remove(std::vector<std::string> input, int index);
std::vector<std::string> merge_ordered(std::vector<std::string> command, std::vector<std::string> description);
std::vector<std::string> split(std::string input);
std::vector<std::string> selection(std::vector<std::string>);

int index(std::string input, std::vector<std::string> inputVector);
Race FindRace(std::string raceName, std::vector<Pack> packSet, std::string packName = "");

int CommandCode(std::string command, std::vector<std::string> commands);

HPack ExecuteCommand(int cmdCode, HPack currentHPack, std::vector<std::string> parameters = {}, std::string context = {});
Race ExecuteRaceCommand(int cmdCode, Race currentRace, std::vector<std::string> parameters = {}, std::string context = {});

void Console(std::vector<std::string> currentCommands = {}, std::vector<std::string> currentCmdDef = {}, HPack currentHPack = {});
Race RaceConsole(Race currentRace = {});
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
    "trait" 
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
    "classes"
};
std::vector<std::string> GlobalSpellDefs{ 
    "The name of your Spell", 
    "The name of the pack your spell is in", 
    "The Description of your spell"
    "The school of magic your spell is under",
    "The duration of the spell",
    "Components needed to case spell",
    "How long it takes to case",
    "Level of spell, 0 is cantrip",
    "Veberal spell",
    "Somatic spell",
    "Material Spell",
    "Ritual Spell",
    "If spell is an attack roll",
    "The classes that can use the spell"
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

}
void DrawTrait(Trait input) {
    GUI drawGUI{};
    drawGUI.MakeBox((input.get_name() == "") ? "New Trait" : input.get_name(), 2);
    drawGUI.MakeBox(input.get_typename(), 2);
    if (input.get_description() != "") {
        drawGUI.GenerateMenu("Description", std::vector<std::string>{input.get_description()});
    }
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

//Functional
bool includes_string(std::string input, std::vector<std::string> vInput) {
    for (std::string i : vInput) {
        if (i == input) {
            return true;
        }
    }
    return false;
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
std::vector<std::string> remove(std::vector<std::string> input, int index) {
    std::vector<std::string> newVector{};
    int counter{};
    for (std::string i : input) {
        if (counter != index) {
            newVector.push_back(i);
        }
        counter++;
    }
    return newVector;
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

//Indexes
int index(std::string input, std::vector<std::string> inputVector) {
    return (std::distance(inputVector.begin(), std::find(inputVector.begin(), inputVector.end(), input)));
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

//Command Codes
int CommandCode(std::string command,std::vector<std::string> commands) {
    if (includes_string(command, commands)) {
        return index(command, commands);
    }
    else {
        return -1;
    }
}

//Execute commands
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
            currentHPack = ExecuteCommand(CommandCode("help",GlobalCommands), currentHPack, merge_ordered(options, option_desc));
        }
        else if (parameters.at(0) == options.at(1)) {
            //menuGUI.GenerateMenu("Display Options", options);
            currentHPack = ExecuteCommand(CommandCode("display",GlobalCommands), currentHPack, std::vector<std::string>{}, "display");
        }
        else if (parameters.at(0) == options.at(2)) {
            std::cout << "\nFancy GUI enabled.\n";
        }
        else if (parameters.at(0) == options.at(3)) {
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
            currentHPack = ExecuteCommand(CommandCode("display",GlobalCommands), currentHPack, std::vector<std::string>{});
        }
        break;
    }
    
    //Add
    case 3: {
        GUI addGUI{};
        std::vector<std::string> addOptions{ "cancel","options","race", "spell"};
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat would you like to add?\n";
            std::getline(std::cin, input);
            addOptions.push_back("options");
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat would you like to add?\n", true, false, addOptions);
            currentHPack = ExecuteCommand(CommandCode("add",GlobalCommands), currentHPack, std::vector<std::string>{input}, "add");
        }
        else if (parameters.at(0) == "options") {
            addGUI.GenerateMenu("Add Options", addOptions);
            std::cout << std::endl;
            currentHPack =  ExecuteCommand(CommandCode("add", GlobalCommands), currentHPack, std::vector<std::string>{}, "add");
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
            currentHPack = ExecuteCommand(CommandCode("add", GlobalCommands), currentHPack, std::vector<std::string>{});
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
            currentHPack = ExecuteCommand(CommandCode("load", GlobalCommands), currentHPack,std::vector<std::string>{input}, "load");
        }
        else if (parameters.at(0) == "options") {
            loadGUI.GenerateMenu("Load Options", loadOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("load", GlobalCommands), currentHPack, std::vector<std::string>{}, "load");
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
        currentHPack = ExecuteCommand(CommandCode("load", GlobalCommands), currentHPack, std::vector<std::string>{});
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
            currentHPack = ExecuteCommand(CommandCode("save", GlobalCommands), currentHPack, std::vector<std::string>{input}, "save");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            saveGUI.GenerateMenu("Save Options", saveOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("save", GlobalCommands), currentHPack, std::vector<std::string>{}, "save");
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
            currentHPack = ExecuteCommand(CommandCode("save", GlobalCommands), currentHPack, std::vector<std::string>{});
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
            currentHPack = ExecuteCommand(CommandCode("export", GlobalCommands), currentHPack, std::vector<std::string>{input}, "export");
        }
        else if (parameters.at(0) == "cancel" || parameters.at(0) == exportOptions.at(2)) {
            break;
        }
        else if (parameters.at(0) == "options") {
            exportGUI.GenerateMenu("Export Options", exportOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("export", GlobalCommands), currentHPack, std::vector<std::string>{}, "export");
        }
        else if (parameters.at(0) == exportOptions.at(3)) {
            Orcbrew tempOrcbrew{};
            tempOrcbrew.set_packs(currentHPack.get_packs());
            tempOrcbrew.set_name(currentHPack.get_name());
            tempOrcbrew.save();
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("export", GlobalCommands), currentHPack, std::vector<std::string>{});
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
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhich pack do you want to rename?\n", true, false, packNames);
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
        GUI editGUI{};
        std::vector<std::string> nameOptions{ "cancel", "options","race" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do you want to edit?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do you want to edit?\n", true, false, nameOptions);
            currentHPack = ExecuteCommand(CommandCode("edit", GlobalCommands), currentHPack, std::vector<std::string>{input}, "edit");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            editGUI.GenerateMenu("Edit Options", nameOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(CommandCode("edit", GlobalCommands), currentHPack, std::vector<std::string>{}, "edit");
        }
        else if (parameters.at(0) == nameOptions.at(2)) {
            std::vector<Race> races{};
            std::vector<std::string> raceNames{};
            std::string packName{};
            std::cout << "\n";
            
            for (Pack i : currentHPack.get_packs()) {
                raceNames.push_back(i.get_name());
            }
            editGUI.GenerateMenu("Current Packs", raceNames, "", true, ((raceNames.size() > 10) ? 2 : 1));
            std::cout << "\nWhat option pack is the race in?\n";
            input.clear();
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat option pack is the race in?\n", true, false, raceNames);
            packName = input;

            raceNames.clear();
            for (Pack i : currentHPack.get_packs()) {
                if (i.get_name() == input) {
                    races = i.get_races();
                    break;
                }
            }
            for (Race i : races) {
                raceNames.push_back(i.get_name());
            }
            editGUI.GenerateMenu("Current Races", raceNames, "", true, ((raceNames.size() > 10) ? 2 : 1));
            std::cout << "\nWhat race do you want to edit?\n";
            input.clear();
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat race do you want to edit?\n", true, false, raceNames);

            races.at(index(input, raceNames)) = RaceConsole(races.at(index(input, raceNames)));
            std::vector<Pack> newPacks{currentHPack.get_packs()};
            int index{};
            for (Pack i : newPacks){
                if (i.get_name() == packName) {
                    newPacks.at(index).set_races(races);
                }
                index++;
            }
            currentHPack.set_packs(newPacks);
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(CommandCode("edit", GlobalCommands), currentHPack, std::vector<std::string>{});
        }

        break;
    }
    default:
        std::cout << "\n\nAn error has occured, write down what you did and report it to the dev\n";
        system("pause");
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
            currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "add");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            addOptions = merge_ordered(addOptions, addDefs);
            addGUI.GenerateMenu("Add Commands", addOptions, "", true, 2);
            currentRace = ExecuteRaceCommand(CommandCode("add", GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "add");
        }
        else if (includes_string(parameters.at(0),addOptions)) {
            switch (CommandCode(parameters.at(0), GlobalRaceOptions))
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
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
					currentRace = ExecuteRaceCommand(CommandCode("edit",GlobalRaceCommands), currentRace, parameters, "add");
				}
				break;
			}
				   //Traits
			case 29: {
				Trait newTrait{};
				std::string newName{};
				if (parameters.size() > 1) {
					parameters.erase(parameters.begin());
					for (std::string i : parameters) {
						newName += i;
					}
					newTrait.set_name(newName);
				}
				currentRace.insert_trait(EditTrait(newTrait));
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
            currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "edit");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            editOptions = merge_ordered(editOptions, editDefs);
            editGUI.GenerateMenu("Remove Commands", editOptions, "", true, 2);
            currentRace = ExecuteRaceCommand(CommandCode("edit", GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "edit");
        }
        else if (includes_string(parameters.at(0), editOptions)) {
            switch (CommandCode(parameters.at(0),GlobalRaceOptions))
            {
                //Name
            case 0: {
                if (currentRace.get_name() == "") {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
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
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
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
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
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
                        editGUI.GenerateMenu("Current Description", std::vector<std::string>{currentRace.get_description()});
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
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
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
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                  //Dex
            case 5: {
                if (currentRace.get_dex() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                    
                }
                else {
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
                break;
            }
                  //Con
            case 6: {
                if (currentRace.get_con() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                  //Int
            case 7: {
                if (currentRace.get_int() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                  //Wis
            case 8: {
                if (currentRace.get_wis() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                  //Cha
            case 9: {
                if (currentRace.get_cha() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                  //Speed
            case 10: {
                if (currentRace.get_speed() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //FlyingSpeed
            case 11: {
                if (currentRace.get_flySpeed() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //SwimmingSpeed
            case 12: {
                if (currentRace.get_swimSpeed() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Dark vision
            case 13: {
                if (currentRace.get_darkVision() == 0) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Skill Options Count
            case 14: {
                if (currentRace.get_skillOptionsCount() == 1) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Language Options Count
            case 15: {
                if (currentRace.get_languageOptionsCount() == 1) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Weapon Options Count
            case 16: {
                if (currentRace.get_weaponOptionsCount() == 1) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //LizFolkAC
            case 17: {
                if (currentRace.get_lizFolkAC() == false) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //TortAC
            case 18: {
                if (currentRace.get_tortAC() == false) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Languages
            case 19: {
                if (currentRace.get_language().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Tools
            case 20: {
                if (currentRace.get_tool().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Skill Options
            case 21: {
                if (currentRace.get_skillOption().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Skill Profs
            case 22: {
                if (currentRace.get_skillProf().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Language Options
            case 23: {
                if (currentRace.get_languageOption().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Weapon Options
            case 24: {
                if (currentRace.get_weaponOption().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Weapon Profs
            case 25: {
                if (currentRace.get_weaponProf().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Armor Profs
            case 26: {
                if (currentRace.get_armorProf().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Damage Res
            case 27: {
                if (currentRace.get_damageRes().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Damage Imm
            case 28: {
                if (currentRace.get_damageImmun().empty()) {
                    currentRace = ExecuteRaceCommand(CommandCode("add",GlobalRaceCommands), currentRace, parameters, "edit");
                }
                else {
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
                break;
            }
                   //Traits
            case 29: {
                Trait newTrait{};
                std::vector<Trait> allTraits{ currentRace.get_trait() };
                std::string newName{};
                if (parameters.size() > 1) {
                    parameters.erase(parameters.begin());
                    for (std::string i : parameters) {
                        newName += i;
                    }
                    int index{};
                    for (Trait i : allTraits) {
                        if (i.get_name() == newName) {
                            newTrait = i;
                        }
                        index++;
                    }
                    allTraits.at(index) = EditTrait(newTrait);
                    currentRace.insert_trait(allTraits);
                }
                else {
                    std::vector<std::string> traitNames{};
                    for (Trait i : allTraits) {
                        traitNames.push_back(i.get_name());
                    }
                    std::cout << "\nWhich trait do you want to edit?\n";
                    std::getline(std::cin, newName);
                    newName = HLib::InputCheck(newName, "\nThat is not a saved trait\nWhich trait do you want to edit?\n", true, false, traitNames);
                    int index{};
                    for (Trait i : allTraits) {
                        if (i.get_name() == newName) {
                            newTrait = i;
                        }
                        index++;
                    }
                    allTraits.at(index) = EditTrait(newTrait);
                    currentRace.insert_trait(allTraits);
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
        GUI editGUI{};
        std::vector<std::string> editOptions{ "yes", "no"};
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nAre you sure?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid option\nAre you sure?\n", true, false, editOptions);
            currentRace = ExecuteRaceCommand(CommandCode("clear", GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "clear");
        }
        else if (parameters.at(0) == "yes") {
            std::vector<std::string> empty{};
            currentRace.set_key("");
            currentRace.set_name("");
            currentRace.set_optionPack("");
            currentRace.set_description("");
            currentRace.set_size(SizeEnum::small);
            currentRace.set_str(0);
            currentRace.set_dex(0);
            currentRace.set_con(0);
            currentRace.set_int(0);
            currentRace.set_wis(0);
            currentRace.set_cha(0);
            currentRace.set_speed(0);
            currentRace.set_flySpeed(0);
            currentRace.set_swimSpeed(0);
            currentRace.set_darkVision(0);
            currentRace.set_skillOptionsCount(0);
            currentRace.set_languageOptionsCount(0);
            currentRace.set_weaponOptionsCount(0);
            currentRace.set_lizFolkAC(false);
            currentRace.set_tortAC(false);
            currentRace.insert_language(empty);
            currentRace.insert_tool(empty);
            currentRace.insert_skillOption(empty);
            currentRace.insert_skillProf(empty);
            currentRace.insert_languageOption(empty);
            currentRace.insert_weaponOption(empty);
            currentRace.insert_weaponProf(empty);
            currentRace.insert_armorProf(empty);
            currentRace.insert_damageRes(empty);
            currentRace.insert_damageImmun(empty);
            break;
        }
        else {
            std::cout << "\nCanceled\n";
        }
        break;
    }
    
    //Remove
    case 6: {
        GUI editGUI{};
        std::vector<std::string> editOptions{ "cancel","options" };
        std::vector<std::string> editDefs{ "Cancels remove", "Lists all possible options" };
        editDefs.insert(std::end(editDefs), std::begin(GlobalRaceDefs), std::end(GlobalRaceDefs));
        editOptions.insert(std::end(editOptions), std::begin(GlobalRaceOptions), std::end(GlobalRaceOptions));
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do want to remove?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do want to remove?\n", true, false, editOptions);
            currentRace = ExecuteRaceCommand(CommandCode("remove", GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "remove");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            editOptions = merge_ordered(editOptions, editDefs);
            editGUI.GenerateMenu("Remove Commands", editOptions, "", true, 2);
            currentRace = ExecuteRaceCommand(CommandCode("remove",GlobalRaceCommands), currentRace, std::vector<std::string>{input}, "remove");
        }
        else if (includes_string(parameters.at(0), editOptions)) {
            switch (CommandCode(parameters.at(0),GlobalRaceOptions))
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
                if (currentRace.get_language().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_language(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Current Languages", currentRace.get_language(), "", true, 4);
                        std::cout << "\nWhat language do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded language\nWhat language do you want to remove from your race?\n", true, false, currentRace.get_language());
                        std::vector<std::string> newVector{remove(currentRace.get_language(),index(newName,currentRace.get_language()))};
                        currentRace.insert_language(newVector);
                    }
                }
                break;
            }
                   //Tools
            case 20: {
                if (currentRace.get_tool().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_tool(newLanguages);
                    }
                    else {
                        editGUI.GenerateMenu("Current Tools", currentRace.get_tool(), "", true, 4);
                        std::cout << "\nWhat tool do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded tool\nWhat tool do you want to remove from your race?\n", true, false, currentRace.get_tool());
                        std::vector<std::string> newVector{ remove(currentRace.get_tool(),index(newName,currentRace.get_tool())) };
                        currentRace.insert_tool(newVector);
                    }
                }
                break;
            }
                   //Skill Options
            case 21: {
                if (currentRace.get_skillOption().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_skillOption(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_skillOption();
                        editGUI.GenerateMenu("Current Skill Options", newLanguages, "", true, 4);
                        std::cout << "\nWhat skill option do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded skill option\nWhat skill option do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_skillOption(newVector);
                    }
                }
                break;
            }
                   //Skill Profs
            case 22: {
                if (currentRace.get_skillProf().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_skillProf(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_skillProf();
                        editGUI.GenerateMenu("Current Skill Prof", newLanguages, "", true, 4);
                        std::cout << "\nWhat skill prof do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded skill prof\nWhat skill prof do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_skillProf(newVector);
                    }
                }
                break;
            }
                   //Language Options
            case 23: {
                if (currentRace.get_languageOption().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_languageOption(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_languageOption();
                        editGUI.GenerateMenu("Current Language Options", newLanguages, "", true, 4);
                        std::cout << "\nWhat language option do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded language option\nWhat language option do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_languageOption(newVector);
                    }
                }
                break;
            }
                   //Weapon Options
            case 24: {
                if (currentRace.get_weaponOption().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_weaponOption(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_weaponOption();
                        editGUI.GenerateMenu("Current Weapon Options", newLanguages, "", true, 4);
                        std::cout << "\nWhat weapon option do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon option\nWhat weapon option do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_weaponOption(newVector);
                    }
                }
                break;
            }
                   //Weapon Profs
            case 25: {
                if (currentRace.get_weaponProf().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_weaponProf(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_weaponProf();
                        editGUI.GenerateMenu("Current Weapon Prof", newLanguages, "", true, 4);
                        std::cout << "\nWhat weapon prof do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded weapon prof\nWhat skill prof do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_weaponProf(newVector);
                    }
                }
                break;
            }
                   //Armor Profs
            case 26: {
                if (currentRace.get_armorProf().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_armorProf(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_armorProf();
                        editGUI.GenerateMenu("Current Skill Prof", newLanguages, "", true, 4);
                        std::cout << "\nWhat armor prof do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded armor prof\nWhat armor prof do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_armorProf(newVector);
                    }
                }
                break;
            }
                   //Damage Res
            case 27: {
                if (currentRace.get_damageRes().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_damageRes(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_damageRes();
                        editGUI.GenerateMenu("Current Damage Res", newLanguages, "", true, 4);
                        std::cout << "\nWhat damage res do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded damage res\nWhat damage res do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_damageRes(newVector);
                    }
                }
                break;
            }
                   //Damage Imm
            case 28: {
                if (currentRace.get_damageImmun().empty()) {
                    std::cout << "\nNothing to remove\n"; break;
                }
                else {
                    std::string newName{};
                    std::vector<std::string> newLanguages{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        newLanguages = currentRace.get_language();
                        for (std::string i : parameters) {
                            if (includes_string(i, newLanguages)) {
                                newLanguages = remove(newLanguages, index(i, newLanguages));
                            }
                            else {
                                std::cout << "\n" << i << " is not added\n";
                            }
                        }
                        currentRace.insert_damageImmun(newLanguages);
                    }
                    else {
                        newLanguages = currentRace.get_damageImmun();
                        editGUI.GenerateMenu("Current Damage Immun", newLanguages, "", true, 4);
                        std::cout << "\nWhat damage immunity do you want to remove from your race?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a loaded damage immunity\nWhat damage immunity do you want to remove from your race?\n", true, false, newLanguages);
                        std::vector<std::string> newVector{ remove(newLanguages,index(newName,newLanguages)) };
                        currentRace.insert_damageImmun(newVector);
                    }
                }
                break;
            }
                   //Traits
            case 29: {
                if (currentRace.get_trait().empty()) {
                    std::cout << "\nNothing to remove\n";
                }
                else {
                    std::vector<Trait> newTraits{};
                    std::vector<Trait> allTraits{ currentRace.get_trait() };
                    std::string newName{};
                    if (parameters.size() > 1) {
                        parameters.erase(parameters.begin());
                        for (std::string i : parameters) {
                            newName += i;
                        }
                        int index{};
                        for (Trait i : allTraits) {
                            if (i.get_name() != newName) {
                                newTraits.push_back(i);
                            }
                        }
                        currentRace.insert_trait(allTraits);
                    }
                    else {
                        std::vector<std::string> traitNames{};
                        for (Trait i : allTraits) {
                            traitNames.push_back(i.get_name());
                        }
                        std::cout << "\nWhich trait do you want to edit?\n";
                        std::getline(std::cin, newName);
                        newName = HLib::InputCheck(newName, "\nThat is not a saved trait\nWhich trait do you want to edit?\n", true, false, traitNames);
                        int index{};
                        for (Trait i : allTraits) {
                            if (i.get_name() != newName) {
                                newTraits.push_back(i);
                            }
                        }
                        currentRace.insert_trait(allTraits);
                    }
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
    default:
        break;
    }
    if (context == "") {
        system("pause");
        system("cls");
    }
    return currentRace;
}

//Consoles
void Console(std::vector<std::string> currentCommands, std::vector<std::string> currentCmdDef, HPack currentHPack) {
    GUI consoleGUI{};
    std::string input{};
    std::vector<std::string> combined{merge_ordered(currentCommands,currentCmdDef)};
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
        if (includes_string(command, currentCommands)) {
            if (command == "help") {
                currentHPack = ExecuteCommand(CommandCode(command, currentCommands), currentHPack, combined);
            }
            else {
                std::vector<std::string> parameters{ split(parameter) };
                currentHPack = ExecuteCommand(CommandCode(command, currentCommands), currentHPack, parameters);
            }
            input = command;
        }
        else {
            std::cout << "\nInvalid Command, use 'help' for list of commands\n";
        }
    } while (input != "exit");
}
Race RaceConsole(Race currentRace) {
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

        DrawRace(currentRace);

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
                    currentRace = ExecuteRaceCommand(CommandCode(command, GlobalRaceCommands), currentRace, combined,"console");
                }
                else {
                    std::vector<std::string> parameters{ split(parameter) };
                    currentRace = ExecuteRaceCommand(CommandCode(command, GlobalRaceCommands), currentRace, parameters);
                }
            }
            else {
                std::vector<std::string> parameters{ split(parameter) };
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
    std::vector<std::string> commands{"done","help","cancel","add","edit","clear","remove"};
    std::vector<std::string> commandsDef{"Finishes Spell","Get help on command","Cancels current action","Add an aspect of spell","Edit aspect","Clears spell","Remove element"};
    std::vector<std::string> combined{merge_ordered(commands,commandsDef)};
    std::string input{};
    
    system("cls");
    

    do {
        spellGUI.MakeBox("Spell Creator", 2);
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
                    currentSpell = ExecuteSpellCommand(SpellCommandCode(command), currentSpell, combined,"console");
                }
                else {
                    std::vector<std::string> parameters{ split(parameter) };
                    currentSpell = ExecuteSpellCommand(SpellCommandCode(command), currentSpell, parameters);
                }
            }
            else {
                std::vector<std::string> parameters{ split(parameter) };
                currentSpell = ExecuteSpellCommand(SpellCommandCode(command), currentSpell, parameters);
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
    std::vector<std::string> combined{ merge_ordered(commands,commandsDef) };
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
                std::vector<std::string> parameters{split(parameter)};
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
                    newString = HLib::InputCheck(newCommand, "\nInvalid input\nEnter input:\n", true, false, std::vector<std::string>{"name", "description", "type"});
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
                        newString = HLib::InputCheck(newString, "\nInvalid input\nEnter input:\n", true, false, std::vector<std::string>{"action", "bonus action", "reaction", "other"});
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
                std::vector<std::string> parameters{ split(parameter) };
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
                    newString = HLib::InputCheck(newString, "\nInvalid input\nEnter input:\n", true, false, std::vector<std::string>{"name", "description", "type"});
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

