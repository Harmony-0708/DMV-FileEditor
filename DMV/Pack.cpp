#include "Pack.h"

Pack::Pack()
{
	Name = "Default";
}

Pack::Pack(std::string name)
{
	Name = name;
}

std::string Pack::get_name()
{
	return Name;
}

std::vector<Race> Pack::get_races()
{
	return Races;
}

void Pack::set_name(std::string name)
{
	Name = name;
}

void Pack::set_races(Race inputRace)
{
	Races.push_back(inputRace);
}

void Pack::set_races(std::vector<Race> inputRaces)
{
	Races = inputRaces;
}

void Pack::set_traits(Trait inputTrait)
{
}

void Pack::set_traits(std::vector<Trait> inputTraits)
{
}

void Pack::set_spells(Spell inputSpell)
{
}

void Pack::set_spells(std::vector<Spell> inputSpells)
{
}

void Pack::set_items(Item inputItem)
{
}

void Pack::set_items(std::vector<Item> inputItems)
{
}

void Pack::load(std::string packName)
{
	Name = packName;
	int load_err{};
	load_err = load_pack();
	switch (load_err) {
	case 0:
		std::cout << "\nPack loaded\n";
		break;
	case 1:
		std::cout << "\nCustomPacks Folder does not exsist\n";
		break;
	case 2:
		std::cout << "\nPack not found in folder. Make sure your pack in inside of the CustomPacks folder.\n";
		break;
	}
}

int Pack::load_pack()
{
	std::ifstream myfile{};
	std::vector<Race> myRaces{ Races };
	Race newRace{};
	Trait newTrait{};

	if (!std::filesystem::exists("CustomPacks")) {
		return 1;
	}
	else if (!std::filesystem::exists("CustomPacks/" + Name + ".pck")) {
		return 2;
	}

	myfile.open("CustomPacks/" + Name + ".pck", std::ios::out);

	std::string line;
	int counter{};
	bool inRaces{};
	bool inTraits{};
	bool input{};
	while (std::getline(myfile, line))
	{
		std::istringstream iss(line);
		std::string variable{ line };
		std::string declared{};
		for (char i : line) {
			if (inTraits) {
				if (!isalpha(i) && i != '{' && i != '}') {
					variable.erase(0, 1);
					break;
				}
			}
			else if (!isalpha(i) && i != '}') {
				variable.erase(0, 1);
				break;
			}
			variable.erase(0, 1);
			declared += i;
		}

		if (!inRaces && !inTraits) {

			if (counter == 0) {
				unsigned first = line.find('\"');
				unsigned last = line.find_last_of('\"');
				std::string lineNew = line.substr(first+1, last - first-1);
				Name = lineNew;
			}
			if (declared == "Races") {
				inRaces = true;
			}
		}
		else if (inRaces) {
			if (inTraits) {
				if (declared == "}" && input) {
					input = false;
					newRace.insert_trait(newTrait);
					newTrait.clear();
				}
				else if (declared == "}" && !input) {
					inTraits = false;
				}
				else if (declared == "{name") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_name(variableNew);
					input = true;
				}
				else if (declared == "description") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_description(variableNew);
				}
				else if (declared == "type") {
					switch (std::stoi(variable)) {
					case 0:
						newTrait.set_type(TraitType::Action);
						break;
					case 1:
						newTrait.set_type(TraitType::BAction);
						break;
					case 2:
						newTrait.set_type(TraitType::Reaction);
						break;
					case 3:
						newTrait.set_type(TraitType::Other);
						break;
					}
				}
			}
			else if (declared == "Name") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_name(variableNew);
			}
			else if (declared == "OptionPack") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_optionPack(variableNew);
			}
			else if (declared == "Description") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_description(variableNew);
			}
			else if (declared == "Size") {
				if (variable == "Small") {
					newRace.set_size(SizeEnum::small);
				}
				else if (variable == "Medium") {
					newRace.set_size(SizeEnum::medium);
				}
				else if (variable == "Large") {
					newRace.set_size(SizeEnum::large);
				}
			}
			else if (declared == "Str") {
				newRace.set_str(std::stoi(variable));
			}
			else if (declared == "Dex") {
				newRace.set_dex(std::stoi(variable));
			}
			else if (declared == "Con") {
				newRace.set_con(std::stoi(variable));
			}
			else if (declared == "Int") {
				newRace.set_int(std::stoi(variable));
			}
			else if (declared == "Wis") {
				newRace.set_wis(std::stoi(variable));
			}
			else if (declared == "Cha") {
				newRace.set_cha(std::stoi(variable));
			}
			else if (declared == "Speed") {
				newRace.set_speed(std::stoi(variable));
			}
			else if (declared == "FlySpeed") {
				newRace.set_flySpeed(std::stoi(variable));
			}
			else if (declared == "SwimSpeed") {
				newRace.set_swimSpeed(std::stoi(variable));
			}
			else if (declared == "DarkVision") {
				newRace.set_darkVision(std::stoi(variable));
			}
			else if (declared == "SKOC") {
				newRace.set_skillOptionsCount(std::stoi(variable));
			}
			else if (declared == "LNOC") {
				newRace.set_languageOptionsCount(std::stoi(variable));
			}
			else if (declared == "WPOC") {
				newRace.set_weaponOptionsCount(std::stoi(variable));
			}
			else if (declared == "LizFolkAC") {
				if (variable == "0") {
					newRace.set_lizFolkAC(false);
				}
				else {
					newRace.set_lizFolkAC(true);
				}
			}
			else if (declared == "TortAC") {
				if (variable == "0") {
					newRace.set_tortAC(false);
				}
				else {
					newRace.set_tortAC(true);
				}
			}
			else if (declared == "Languages") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_language(vector);
			}
			else if (declared == "LanguageOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_languageOption(vector);

			}
			else if (declared == "SkillProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_skillProf(vector);

			}
			else if (declared == "SkillOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_skillOption(vector);

			}
			else if (declared == "WeaponProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponProf(vector);

			}
			else if (declared == "WeaponOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponOption(vector);

			}
			else if (declared == "DamageRes") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_damageRes(vector);

			}
			else if (declared == "DamageImmun") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_damageImmun(vector);

			}
			else if (declared == "ArmorProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_armorProf(vector);

			}
			else if (declared == "Tools") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_tool(vector);
			}
			else if (declared == "Traits") {
				inTraits = true;
			}
			else if (!inTraits && declared == "}") {
				if (newRace.get_name() != "") {
				myRaces.push_back(newRace);
				}
				newRace.clear();
			}
		}
		counter++;
	}
	
	set_races(myRaces);
	return 0;
}

void Pack::save_pack()
{
	std::ofstream myfile{};
	std::vector<Race> myRaces{ Races };

	if (!std::filesystem::exists("CustomPacks")) {
		std::filesystem::create_directory("CustomPacks");
	}

	myfile.open("CustomPacks/" + Name + ".pck", std::ios::in | std::ios::trunc);

	myfile
		<< "name=\"" << Name
		<< "\"\nRaces{\n";
	for (Race i : Races) {
		myfile
			<< i.get_key() << "{\n"
			<< "Name=\"" << i.get_name()
			<< "\"\nOptionPack=\"" << i.get_optionPack()
			<< "\"\nDescription=\"" << i.get_description()
			<< "\"\nSize=" << i.get_sizename()
			<< "\nStr=" << i.get_str()
			<< "\nDex=" << i.get_dex()
			<< "\nCon=" << i.get_con()
			<< "\nInt=" << i.get_int()
			<< "\nWis=" << i.get_wis()
			<< "\nCha=" << i.get_cha()
			<< "\nSpeed=" << i.get_speed()
			<< "\nFlySpeed=" << i.get_flySpeed()
			<< "\nSwimSpeed=" << i.get_swimSpeed()
			<< "\nDarkVision=" << i.get_darkVision()
			<< "\nSKOC=" << i.get_skillOptionsCount()
			<< "\nLNOC=" << i.get_languageOptionsCount()
			<< "\nWPOC=" << i.get_weaponOptionsCount()
			<< "\nLizFolkAC=" << i.get_lizFolkAC()
			<< "\nTortAC=" << i.get_tortAC();
		myfile
			<< "\nLanguages={";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nLanguageOptions={";
		if (i.get_languageOption().size() > 0) {
			for (std::string k : i.get_languageOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillProf={";
		if (i.get_skillProf().size() > 0) {
			for (std::string k : i.get_skillProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillOptions={";
		if (i.get_skillOption().size() > 0) {
			for (std::string k : i.get_skillOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponProf={";
		if (i.get_weaponProf().size() > 0) {
			for (std::string k : i.get_weaponProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponOptions={";
		if (i.get_weaponOption().size() > 0) {
			for (std::string k : i.get_weaponOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageRes={";
		if (i.get_damageRes().size() > 0) {
			for (std::string k : i.get_damageRes()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageImmun={";
		if (i.get_damageImmun().size() > 0) {
			for (std::string k : i.get_damageImmun()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nArmorProf={";
		if (i.get_armorProf().size() > 0) {
			for (std::string k : i.get_armorProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTools={";
		if (i.get_tool().size() > 0) {
			for (std::string k : i.get_tool()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTraits={";
		if (i.get_trait().size() > 0) {
			for (Trait k : i.get_trait()) {
				myfile
					<< "\n{name=\"" << k.get_name()
					<< "\"\ndescription=\"" << k.get_description()
					<< "\"\ntype=" << k.get_type()
					<< "\n}";
			}
		}
		myfile
			<< "\n}\n}\n";
	}
	myfile
		<< "}\n";

}

void Pack::print_pack()
{
	std::ofstream myfile{};
	std::vector<Race> myRaces{Races};

	if (!std::filesystem::exists("OrcbrewPacks")) {
		std::filesystem::create_directory("OrcbrewPacks");
	}

	myfile.open("OrcbrewPacks/" + Name + ".orcbrew", std::ios::in | std::ios::trunc);
	myfile
		<< "{\"" << Name
		<< "\"{:orcpub.dnd.e5/races{";

	for (Race i : Races) 
	{
		if (i.get_optionPack() != Name) {
			break;
		}
		myfile
			<< ":" << i.get_key()
			<< "{:key :" << i.get_key()
			<< ", :name \"" << i.get_name()
			<< "\", :swimming-speed " << i.get_swimSpeed()
			<< ", :help \"" << i.get_description()
			<< "\", :option-pack \"" << i.get_optionPack()
			<< "\", :speed " << i.get_speed()
			<< ", :flying-speed " << i.get_flySpeed()
			<< ", :darkvision " << i.get_darkVision()
			<< std::boolalpha
			<< ", :lizardfolk-ac " << i.get_lizFolkAC()
			<< ", :tortle-ac " << i.get_tortAC()
			<< std::boolalpha
			<< ", :abilities{";
		if (i.get_str() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/str " << i.get_str();
			if (i.get_dex() != 0 || i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_dex() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/dex " << i.get_dex();
			if (i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_con() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/con " << i.get_con();
			if (i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_int() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/int " << i.get_int();
			if (i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_wis() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/wis " << i.get_wis();
			if (i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_cha() != 0) {
			myfile
				<< " :orcpub.dnd.e5.character/cha " << i.get_cha();
		}

		myfile
			<< "}, :languages #{";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				myfile
					<< " \"" << k << "\"";
			}
		}
		myfile
			<< "}, :profs {";
		if (i.get_tool().size() > 0) {
			int counter{};
			myfile
				<< " :tool{";
			for (std::string k : i.get_tool()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_tool().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "},";
		}
		if (i.get_skillOption().size() > 0) {
			int counter{};
			myfile
				<< " :skill-options {"
				<< " :choose " << i.get_skillOptionsCount()
				<< ", :options {";
			for (std::string k : i.get_skillOption()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_skillOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "}},";
		}
		if (i.get_languageOption().size() > 0) {
			int counter{};
			std::vector<std::string> languagesOrdered{"draconic","deep-speech","orc","dwarvish","gnomish","sylvan","elvish","abyssal","infernal","celestial","common","undercommon","primordial","giant","halfling","goblin"};
			std::vector<std::string> newLanguages{"","","","","","","","","","","","","","","","","","","","",};
			for (std::string k : i.get_languageOption()) {
				std::string newK;
				for (char j : k) {
					if (isalpha(j)) {
						newK += tolower(j);
					}
					else if(j == '-') {
						newK += j;
					}
				}
				int jcounter{};
				for (std::string j : languagesOrdered) {
					if (j == newK) {
						newLanguages.at(jcounter) = newK;
						break;
					}
					jcounter++;
				}
			}
			int index{0};
			for (std::string k : newLanguages) {
				if (k == "") {
					newLanguages.erase(newLanguages.begin() + index);
					index--;
				}
				index++;
			}
			myfile
				<< " :language-options {"
				<< " :choose " << i.get_languageOptionsCount()
				<< ", :options {";
			for (std::string k : newLanguages) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_languageOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "}},";
		}
		if (i.get_weaponOption().size() > 0) {
			int counter{};
			myfile
				<< " :weapon-proficiency-options {"
				<< " :choose " << i.get_weaponOptionsCount()
				<< ", :options {";
			for (std::string k : i.get_weaponOption()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_weaponOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "}}";
		}
		myfile
			<< "}, :props {";
		if (i.get_weaponProf().size() > 0) {
			int counter{};
			myfile
				<< " :weaponProf{";
			for (std::string k : i.get_weaponProf()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_weaponProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "},";
		}
		if (i.get_armorProf().size() > 0) {
			int counter{};
			myfile
				<< " :armor-prof{";
			for (std::string k : i.get_armorProf()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_armorProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "},";
		}
		if (i.get_damageRes().size() > 0) {
			int counter{};
			myfile
				<< " :damage_resistance{";
			for (std::string k : i.get_damageRes()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_damageRes().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "},";
		}
		if (i.get_damageImmun().size() > 0) {
			int counter{};
			myfile
				<< " :damage-immunity{";
			for (std::string k : i.get_damageImmun()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_damageImmun().size()) {
					myfile << ",";
				}
			}
			myfile
				<< "},";
		}
		if (i.get_skillProf().size() > 0) {
			int counter{};
			myfile
				<< " :skill-prof{";
			for (std::string k : i.get_skillProf()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_skillProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "}";
		}
		myfile
			<< "}, :traits [";
		if (i.get_trait().size() > 0) {
			for (Trait i : i.get_trait()) {
				myfile
					<< "{"
					<< " :type :" << i.get_typename()
					<< ", :name \"" << i.get_name()
					<< "\", :description \"" << i.get_description() << "\""
					<< "}";
			}
		}
		myfile
			<< "]}}}}";

	}
		/*<< myRace.get_key()
		<< "{:key " << myRace.get_key()
		<< ", :name \"" << myRace.get_name()
		<< "\", :option-pack \"" << myRace.get_optionPack()
		<< "\", :languages #{}, :size :" << myRace.get_size()
		<< ", :speed " << myRace.get_speed()
		<< "}}}}";*/

	myfile.close();

	std::cout << std::endl << "File printed" << std::endl;
}
