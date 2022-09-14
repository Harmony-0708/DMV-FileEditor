#include "Spell.h"

Spell::Spell()
{
	this->ClassList = {};
	this->Key = "";
	this->Name = "";
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}
Spell::Spell(std::string name)
{
	this->set_name(name);
	this->ClassList = {};
	this->set_name(name);
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}

//Gets
std::string Spell::get_key()
{
	return this->Key;
}
std::string Spell::get_name()
{
	return this->Name;
}
std::string Spell::get_description()
{
	return this->Description;
}
std::string Spell::get_school()
{
	return this->School;
}
std::string Spell::get_duration()
{
	return this->Duration;
}
std::string Spell::get_optionPack()
{
	return this->OptionPack;
}
std::string Spell::get_component()
{
	return this->Component;
}
std::string Spell::get_castingTime()
{
	return this->CastingTime;
}
std::string Spell::get_range()
{
	return this->Range;
}
int Spell::get_level()
{
	return this->Level;
}
bool Spell::is_verbal()
{
	return this->Verbal;
}
bool Spell::is_somatic()
{
	return this->Somatic;
}
bool Spell::is_material()
{
	return this->Material;
}
bool Spell::is_ritual()
{
	return this->Ritual;
}
bool Spell::is_attackRoll()
{
	return this->AttackRoll;
}
bool Spell::has_class(std::string Class)
{
	for (std::string i : this->ClassList) {
		if (i == Class) {
			return true;
		}
	}
	return false;
}
std::string Spell::get_class(int index)
{
	int Index{};
	for (std::string i : this->ClassList) {
		if (Index == index) {
			return i;
		}
		Index++;
	}
	return "";
}
std::vector<std::string> Spell::get_class()
{
	return this->ClassList;
}


//Assignment
void Spell::set_key(std::string key)
{
	this->Key = key;
}
void Spell::set_name(std::string input)
{
	std::string newString{};
	this->Name = input;
	for (char i : input) {
		if (i == ' ') {
			newString.push_back('-');
		}
		else if (isalpha(i)) {
			newString.push_back(tolower(i));
		}
		else {
			newString.push_back(i);
		}
	}
	this->set_key(newString);
}
void Spell::set_description(std::string input)
{
	this->Description = input;
}
void Spell::set_school(std::string input)
{
	this->School = input;
}
void Spell::set_duration(std::string input)
{
	this->Duration = input;
}
void Spell::set_optionPack(std::string input)
{
	this->OptionPack = input;
}
void Spell::set_component(std::string input)
{
	this->Component = input;
}
void Spell::set_castingTime(std::string input)
{
	this->CastingTime = input;
}
void Spell::set_range(std::string input)
{
	this->Range = input;
}
void Spell::set_level(int input)
{
	this->Level = input;
}
void Spell::set_verbal(bool input)
{
	this->Verbal = input;
}
void Spell::set_somatic(bool input)
{
	this->Somatic = input;
}
void Spell::set_material(bool input)
{
	this->Material = input;
}
void Spell::set_ritual(bool input)
{
	this->Ritual = input;
}
void Spell::set_attackRoll(bool input)
{
	this->AttackRoll = input;
}
void Spell::set_classes(std::vector<std::string> input)
{
	this->ClassList = input;
}
void Spell::insert_class(std::string input)
{
	this->ClassList.push_back(input);
}
void Spell::remove_class(std::string input)
{
	std::vector<std::string> newClassList{};
	for (std::string i : this->ClassList) {
		if (i != input) {
			newClassList.push_back(i);
		}
	}
	this->ClassList = newClassList;
}
void Spell::remove_class(int index)
{
	int Index{};
	std::vector<std::string> newClassList{};
	for (std::string i : this->ClassList) {
		if (Index != index) {
			newClassList.push_back(i);
		}
		Index++;
	}
	this->ClassList = newClassList;
}

//Clear
void Spell::clear()
{
	this->ClassList = {};
	this->Key = "";
	this->Name = "";
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}


CommandObject* Spell::Add(CommandObject* currentSpell, std::vector<std::string>& parameters)
{
    GUI addGUI{};
    std::string newName{};
    int cmdCode{ SpellConsole.CommandCode(parameters.at(0), GlobalSpellOptions) };
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
        currentSpell = ExecuteCommand(SpellConsole.CommandCode("edit", Commands), currentSpell, parameters, "add");
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
        currentSpell = ExecuteCommand(SpellConsole.CommandCode("edit", Commands), currentSpell, parameters, "add");
        break;
    }
    }
    switch (cmdCode)
    {
        //Classes
    case 13: {
        for (std::string i : parameters) {
            this->insert_class(i);
        }
        break;
    }
    default:
        break;
    }
    return currentSpell;
}
CommandObject* Spell::Edit(CommandObject* currentSpell, std::vector<std::string>& parameters)
{
    GUI editGUI{};
    std::string newName{};
    int cmdCode{ SpellConsole.CommandCode(parameters.at(0), GlobalSpellOptions) };
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
        currentSpell = ExecuteCommand(SpellConsole.CommandCode("add", Commands), currentSpell, parameters, "edit");
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
        this->set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        this->set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        this->set_description(newName);
        break;
    }
          //School
    case 3: {
        this->set_school(newName);
        break;
    }
          //Duration
    case 4: {
        this->set_duration(newName);
        break;
    }
          //Component
    case 5: {
        this->set_component(newName);
        break;
    }
          //Casting time
    case 6: {
        this->set_castingTime(newName);
        break;
    }
          //Level
    case 7: {
        this->set_level(std::stoi(newName));
        break;
    }
          //Verbal
    case 8: {
        if (newName == "yes") {
            this->set_verbal(true);
        }
        else {
            this->set_verbal(false);
        }
        break;
    }
          //Somatic
    case 9: {
        if (newName == "yes") {
            this->set_somatic(true);
        }
        else {
            this->set_somatic(false);
        }
        break;
    }
          //Material
    case 10: {
        if (newName == "yes") {
            this->set_material(true);
        }
        else {
            this->set_material(false);
        }
        break;
    }
           //Ritual
    case 11: {
        if (newName == "yes") {
            this->set_ritual(true);
        }
        else {
            this->set_ritual(false);
        }
        break;
    }
           //Attack Roll
    case 12: {
        if (newName == "yes") {
            this->set_attackRoll(true);
        }
        else {
            this->set_attackRoll(false);
        }
        break;
    }
           //Range
    case 14: {
        this->set_range(newName);
        break;
    }
    }
    return currentSpell;
}
CommandObject* Spell::Remove(CommandObject* currentSpell, std::vector<std::string>& parameters)
{
    std::string newName{};
    int cmdCode{ SpellConsole.CommandCode(parameters.at(0), GlobalSpellOptions) };
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
        this->set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        this->set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        this->set_description(newName);
        break;
    }
          //School
    case 3: {
        this->set_school(newName);
        break;
    }
          //Duration
    case 4: {
        this->set_duration(newName);
        break;
    }
          //Component
    case 5: {
        this->set_component(newName);
        break;
    }
          //Casting time
    case 6: {
        this->set_castingTime(newName);
        break;
    }
          //Level
    case 7: {
        this->set_level(0);
        break;
    }
          //Verbal
    case 8: {
        this->set_verbal(false);
        break;
    }
          //Somatic
    case 9: {
        this->set_somatic(false);
        break;
    }
          //Material
    case 10: {
        this->set_material(false);
        break;
    }
           //Ritual
    case 11: {
        this->set_ritual(false);
        break;
    }
           //Attack Roll
    case 12: {
        this->set_attackRoll(false);
        break;
    }
           //Classes
    case 13: {
        std::vector<std::string> newClasses{};
        for (std::string i : this->get_class()) {
            if (!HLib::IncludesString(i, parameters)) {
                newClasses.push_back(i);
            }
        }
        this->set_classes(newClasses);
        break;
    }
           //Range
    case 14: {
        this->set_range(newName);
        break;
    }
    default:
        break;
    }
    return currentSpell;
}

CommandObject* Spell::ExecuteCommand(int cmdCode, CommandObject* currentSpell, std::vector<std::string> parameters, std::string context)
{
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
        currentSpell = &cancelSpell;
        break;
    }

          //Add
    case 3: {
        switch (SpellConsole.ValidateCommand("What would you like to add?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = Add(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }

          //Edit
    case 4: {
        switch (SpellConsole.ValidateCommand("What would you like to edit?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = Edit(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }

          //Clear
    case 5: {
        std::vector<std::string> options{ "yes", "no" };
        std::vector<std::string> optionDefs{ "", "" };

        switch (SpellConsole.ValidateCommand("Are you sure?", options, optionDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            Spell newSpell{};
            currentSpell = &newSpell;
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
            break;
        }
        }
        break;
    }

          //Remove
    case 6: {
        switch (SpellConsole.ValidateCommand("What would you like to remove?", GlobalSpellOptions, GlobalSpellDefs, parameters))
        {
        case 0: {
            currentSpell = ExecuteCommand(cmdCode, currentSpell, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentSpell = Remove(currentSpell, parameters);
            break;
        }
        case 3: {
            std::cout << "\nInvalid parameter\n";
            currentSpell = ExecuteCommand(cmdCode, currentSpell, std::vector<std::string>{}, std::to_string(cmdCode));
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

void Spell::Display()
{
	GUI spellGUI{};

	if (this->get_name() != "") {
		spellGUI.MakeBox(this->get_name(), 2);
	}
	if (this->get_optionPack() != "") {
		spellGUI.MakeBox(this->get_optionPack(), 1);
	}
	if (this->get_school() != "") {
		spellGUI.MakeBox("School: " + this->get_school(), 1);
	}
	if (this->get_duration() != "") {
		spellGUI.MakeBox("Duration: " + this->get_duration(), 1);
	}
	if (this->get_component() != "") {
		spellGUI.MakeBox("Components: " + this->get_component(), 1);
	}
	if (this->get_castingTime() != "") {
		spellGUI.MakeBox("Casting Time: " + this->get_castingTime(), 1);
	}
	if (this->get_range() != "") {
		spellGUI.MakeBox("Range: " + this->get_range(), 1);
	}
	if (this->get_level() != 0) {
		spellGUI.MakeBox("Level: " + std::to_string(this->get_level()), 1);
	}
	if (this->is_verbal()) {
		spellGUI.MakeBox("Verbal: True", 1);
	}
	if (this->is_somatic()) {
		spellGUI.MakeBox("Somatic: True", 1);
	}
	if (this->is_material()) {
		spellGUI.MakeBox("Material: True", 1);
	}
	if (this->is_ritual()) {
		spellGUI.MakeBox("Ritual: True", 1);
	}
	if (this->is_attackRoll()) {
		spellGUI.MakeBox("Attack roll: True", 1);
	}
	if (this->get_description() != "") {
		spellGUI.GenerateMenu("Description", std::vector<std::string>{this->get_description()});
	}
	if (!this->get_class().empty()) {
		spellGUI.GenerateMenu("Classes", this->get_class(), "", true, 4);
	}
}

std::string Spell::get_title()
{
	return this->Title;
}

bool Spell::IsDone(std::string input)
{
	if (input == "done" || input == "exit" || this->get_name() == "%%CANCELED%%") {
		return false;
	}
	else {
		return true;
	}
}

std::vector<std::string> Spell::get_commands()
{
	return this->Commands;
}

std::vector<std::string> Spell::get_command_defs()
{
	return this->CommandDefs;
}