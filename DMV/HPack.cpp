#include "HPack.h"

HPack::HPack()
{
	set_name("Default");
}

HPack::HPack(std::string name)
{
	set_name(name);
}

std::vector<Pack> HPack::get_packs()
{
	return Packs;
}

Pack HPack::get_pack(std::string name)
{
	Pack emptyPack{};
	for (Pack i : get_packs()) {
		if (i.get_name() == name) {
			return i;
		}
	}
	return emptyPack;
}

std::string HPack::get_name()
{
	return Name;
}

void HPack::set_name(std::string name)
{
	Name = name;
}

void HPack::set_packs(std::vector<Pack> packs)
{
	Packs = packs;
}

void HPack::set_pack_name(std::string packName, std::string newName)
{
	int index{};
	for (Pack i : get_packs()) {
		if (i.get_name() == packName) {
			Packs.at(index).set_name(newName);
		}
		index++;
	}
}

void HPack::update_pack(Pack pack)
{
	int index{};
	for (Pack i : get_packs()) {
		if (i.get_name() == pack.get_name()) {
			Packs.at(index) = pack.merge(std::vector<Pack>{pack, i});
		}
		index++;
	}
}

void HPack::add_pack(Pack pack)
{

	std::vector<Pack> currentPacks{ get_packs() };
	currentPacks.push_back(pack);
	set_packs(currentPacks);
}

bool HPack::has_pack(Pack inputPack)
{
	for (Pack i : get_packs()) {
		if (i.get_name() == inputPack.get_name()) {
			return true;
		}
	}
	return false;
}

std::vector<Pack> HPack::merge(std::vector<std::vector<Pack>> PackSet)
{
    return std::vector<Pack>();
}

CommandObject* HPack::merge(std::vector<HPack> HPackPack)
{
	HPack MergedHPack{};
	int index{};
	bool samePack{};
	MergedHPack.set_name(get_name());
	MergedHPack = HPackPack.at(0);

	bool skip{true};
	for (HPack i : HPackPack) {
		if (!skip) {
			Pack tempPack{};
			for (Pack j : i.get_packs()) {
				if (MergedHPack.has_pack(j)) {
					samePack = true;
					tempPack = j;
				}
				if (samePack) {
					tempPack = tempPack.merge(std::vector<Pack>{MergedHPack.get_pack(tempPack.get_name()), tempPack});
					MergedHPack.update_pack(tempPack);
				}
				else {
					MergedHPack.add_pack(j);
				}
			}
		}
		else {
			skip = false;
		}
	}
    *this = MergedHPack;
    CommandObject* newObject{ &MergedHPack };
	return newObject;
}

void HPack::load(std::string fileName)
{
    Name = fileName;
    std::ifstream myfile{};

	if (!std::filesystem::exists("CustomPacks")) {
		std::filesystem::create_directory("CustomPacks");
	}
	else if (!std::filesystem::exists("CustomPacks/" + Name + ".hpck")) {
		std::cout << "\nFile does not exist\n";
	}

	myfile.open("CustomPacks/" + Name + ".hpck", std::ios::out);
	bool beginpackCheck{ false };
	int counter{0};
	int lineIndex{0};
	std::string line;

	while (!myfile.eof()) {
		std::fstream outputfile{};
		Pack newPack{};
		bool emptyPack{};

		outputfile.open("CustomPacks/buffer.hpck", std::ios::in | std::ios::out | std::ios::trunc);
		while (std::getline(myfile, line)) {
			if (line != "" && line != " " && line != "\n") {
				if (line == ":beginpack:\n" || line == ":beginpack:") {
					beginpackCheck = true;
				}
				else if (line == ":endpack:\n" || line == ":endpack:") {
					beginpackCheck = false;
					break;
				}
				else if (beginpackCheck) {
					outputfile
						<< line << "\n";
				}
			}
			else {
				if (beginpackCheck != true) {
					emptyPack = true;
					break;
				}
				else {
					outputfile
						<< line << "\n";
				}
			}
		}
		if (!emptyPack && !myfile.eof()) {
			newPack.load_pack(outputfile);
			this->add_pack(newPack);
			outputfile.close();
		}
	}
}

void HPack::save()
{
	std::ofstream myfile{};

	if (!std::filesystem::exists("CustomPacks")) {
		std::filesystem::create_directory("CustomPacks");
	}

	myfile.open("CustomPacks/" + Name + ".hpck", std::ios::in | std::ios::trunc);

	for (Pack i : Packs) {
		myfile
			<< ":beginpack:\n{\n";
		i.save_pack(myfile);
		myfile
			<< "}\n:endpack:\n";
	}
}

void HPack::GrabObjectName(std::vector<std::string>& parameters, CommandObject*& currentHPack, std::string& objectName, std::string& displayType, Pack& loadedPack)
{
	GUI gui{};
	int index{};
	bool foundPack{ false };
	bool foundObject{ false };
	std::string input{};
	std::string packName{};
	std::vector<std::string> packs{};
	std::vector<std::string> chosenType{};

	if (parameters.size() > 0) { parameters.erase(std::begin(parameters)); }

	for (Pack i : this->get_packs()) {
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

	loadedPack = this->get_pack(packName);

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

CommandObject* HPack::ObjectDisplay(CommandObject* currentHPack, std::vector<std::string> parameters) {
    Pack loadedPack{};
    std::string objectName{};
    std::string displayType{ parameters.at(0) };

    GrabObjectName(parameters, currentHPack, objectName, displayType, loadedPack);

    if (displayType == "race") {
        loadedPack.get_race(objectName).Display();
    }
    else if (displayType == "spell") {
        loadedPack.get_spell(objectName).Display();
    }

    return currentHPack;
}
CommandObject* HPack::Load(CommandObject* currentHPack, std::vector<std::string> parameters) {
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
        countFiles = HLib::InputCheck(countFiles, "\nInvalid Item\nLoad by filename must be single\n", std::vector<std::string>{"single"}, true, false);

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
        nameOfFiles = HLib::Selection(nameOfFiles);
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
            HPack newHPackcurrent{this->get_name()};
            i.erase(i.size() - 5, 5);
            newHPack.load(i);
            if (this->get_name() == "Default") { this->set_name(i); }
            for (Pack i : this->get_packs()) {
                newHPackcurrent.add_pack(i);
            }
            this->merge(std::vector<HPack>{ newHPackcurrent, newHPack});
        }
        else if (fileType == "pck") {
            HPack newHPack{};
            HPack newHPackcurrent{ this->get_name() };
            Pack newPack{};
            i.erase(i.size() - 4, 4);
            newPack.load_pack(i);
            newHPack.add_pack(newPack);
            for (Pack i : this->get_packs()) {
                newHPackcurrent.add_pack(i);
            }
            this->merge(std::vector<HPack>{ newHPackcurrent, newHPack});
        }
        else if (fileType == "orcbrew") {
            HPack newHPack{};
            HPack newHPackcurrent{ this->get_name() };
            Orcbrew newPack{};
            i.erase(i.size() - 8, 8);
            //newHPack = newPack.load(i);
            for (Pack i : this->get_packs()) {
                newHPackcurrent.add_pack(i);
            }
            this->merge(std::vector<HPack>{ newHPackcurrent, newHPack});
        }
    }

    return this;
}
CommandObject* HPack::Save(CommandObject* currentHPack, std::vector<std::string> parameters) {
    if (parameters.at(0) == "hpck") {
        this->save();
        return currentHPack;
    }
    else if (parameters.at(0) == "pck") {
        std::string packName{};
        std::vector<std::string> packNames{};
        for (Pack i : this->get_packs()) {
            packNames.push_back(i.get_name());
        }
        std::cout << "\nWhich pack do you want to save?\n";
        std::getline(std::cin, packName);
        packName = HLib::InputCheck(packName, "\nInvalid Item, use options to find valid items\nWhich pack do you want to save?\n", packNames, true, false);
        for (Pack i : this->get_packs()) {
            if (i.get_name() == packName) {
                i.save_pack();
                break;
            }
        }
        return currentHPack;
    }
    else if (parameters.at(0) == "orcbrew") {
        Orcbrew tempOrcbrew{};
        tempOrcbrew.set_packs(this->get_packs());
        tempOrcbrew.set_name(this->get_name());
        tempOrcbrew.save();
        return currentHPack;
    }
    else {
        return currentHPack;
    }
}
CommandObject* HPack::Edit(CommandObject* currentHPack, std::vector<std::string> parameters) {
    Pack loadedPack{};
    std::string objectName{};
    std::string editType{ parameters.at(0) };

    GrabObjectName(parameters, currentHPack, objectName, editType, loadedPack);

    if (editType == "race") {
        Race newRace{ loadedPack.get_race(objectName) };
        HPackConsole.Run(&newRace);
        if (newRace.get_name() != "%%CANCELED%%") { loadedPack.update_race(newRace); }
    }
    else if (editType == "spell") {
        Spell newSpell{ loadedPack.get_spell(objectName) };
        HPackConsole.Run(&newSpell);
        if (newSpell.get_name() != "%%CANCELED%%") { loadedPack.update_spell(newSpell); };
    }
    this->update_pack(loadedPack);
    return currentHPack;
}
CommandObject* HPack::Add(CommandObject* currentHPack, std::vector<std::string> parameters) {
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
        HPackConsole.Run(&newRace);
        if (newRace.get_name() != "%%CANCELED%%") { newPack.set_races(newRace); newPack.set_name(newPack.get_races().at(0).get_optionPack()); }
    }
    else if (addType == "spell") {
        Spell newSpell{};
        if (objectName != "") {
            newSpell.set_optionPack(objectName);
        }
        HPackConsole.Run(&newSpell);
        if (newSpell.get_name() != "%%CANCELED%%") { newPack.set_spells(newSpell); newPack.set_name(newPack.get_spells().at(0).get_optionPack()); }
    }
    newPack.merge(this->get_packs());
    this->add_pack(newPack);
    return currentHPack;
}

CommandObject* HPack::ExecuteCommand(int cmdCode, CommandObject* currentHPack, std::vector<std::string> parameters, std::string context)
{
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
        if (!parameters.empty()) { commandsToDisplay.insert(std::end(commandsToDisplay), std::begin(parameters), std::end(parameters)); }
        HelpGui.GenerateMenu("Command - Definition", commandsToDisplay, "", true, 2);
        break;
    }

          //Display
    case 2: {
        std::vector<std::string> options{ "race" , "spell" };
        std::vector<std::string> optionDefs{ "Displays a race", "Displays a spell" };

        if (this->get_packs().empty()) {
            std::cout << "\nNo packs are currently loaded\n";
            break;
        }

        switch (HPackConsole.ValidateCommand("What would you like to display?", options, optionDefs, parameters))
        {
        case 0: {
            currentHPack = ExecuteCommand(cmdCode, currentHPack, parameters, std::to_string(cmdCode));
            break;
        }
        case 1: {
            break;
        }
        case 2: {
            currentHPack = ObjectDisplay(currentHPack, parameters);
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
        std::vector<std::string> options{ "race", "spell" };
        std::vector<std::string> optionDefs{ "Add race", "Add spell" };

        switch (HPackConsole.ValidateCommand("What would you like to add?", options, optionDefs, parameters))
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
        std::vector<std::string> optionDefs{ "Load all", "Load a single file", "Load multiple files" };

        switch (HPackConsole.ValidateCommand("How many packs do you want to load?", options, optionDefs, parameters))
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
        std::vector<std::string> optionDefs{ "Saves all packs into one pack", "Save a single pack" };

        switch (HPackConsole.ValidateCommand("How do you want to save your packs?", options, optionDefs, parameters))
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

        switch (HPackConsole.ValidateCommand("Are you sure you want to export your packs to orcbrew format? WARNING: Any orcbrew file with the same name as your current HPack will be overwritten", options, optionDefs, parameters))
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
        std::vector<std::string> nameOptions{ "cancel", "options","hpck", "pck" };
        std::string input{};

        if (parameters.empty()) {
            std::cout << "\nWhat do you want to rename?\n";
            std::getline(std::cin, input);
            input = HLib::InputCheck(input, "\nInvalid Item, use options to find valid items\nWhat do you want to rename?\n", nameOptions, true, false);
            currentHPack = ExecuteCommand(HPackConsole.CommandCode("name", Commands), currentHPack, std::vector<std::string>{input}, "name");
        }
        else if (parameters.at(0) == "cancel") {
            break;
        }
        else if (parameters.at(0) == "options") {
            nameGUI.GenerateMenu("Name Options", nameOptions);
            std::cout << std::endl;
            currentHPack = ExecuteCommand(HPackConsole.CommandCode("name", Commands), currentHPack, std::vector<std::string>{}, "name");
        }
        else if (parameters.at(0) == nameOptions.at(2)) {
            std::cout << "\nWhat do you want to rename the pack to?\n";
            input.clear();
            std::getline(std::cin, input);
            this->set_name(input);
        }
        else if (parameters.at(0) == nameOptions.at(3)) {
            std::vector<std::string> packNames{};
            for (Pack i : this->get_packs()) {
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
            this->set_pack_name(input, newName);
        }
        else {
            std::cout << "\nInvalid parameter\n";
            currentHPack = ExecuteCommand(HPackConsole.CommandCode("name", Commands), currentHPack, std::vector<std::string>{});
        }

        break;
    }

          //Edit
    case 8: {
        std::vector<std::string> options{ "race", "spell" };
        std::vector<std::string> optionDefs{ "Edit a race", "Edit a spell" };

        switch (HPackConsole.ValidateCommand("What would you like to edit?", options, optionDefs, parameters))
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
    if (context == "" || context == "console") {
        system("pause");
        system("cls");
    }
    return currentHPack;
}

void HPack::Display()
{
	GUI gui{};
	std::vector<std::string> packs{};
	for (Pack i : this->get_packs()) {
		packs.push_back(i.get_name());
	}
	gui.GenerateMenu("Packs", packs);
}

std::string HPack::get_title()
{
	return this->Title;
}

bool HPack::IsDone(std::string input)
{
	if (input == "done" || input == "exit") {
		return false;
	}
	else {
		return true;
	}
}

std::vector<std::string> HPack::get_commands()
{
	return this->Commands;
}

std::vector<std::string> HPack::get_command_defs()
{
	return this->CommandDefs;
}

