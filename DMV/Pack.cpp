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

void Pack::set_name(std::string name)
{
	Name = name;
}

void Pack::set_races(Race inputRace)
{

}

void Pack::set_races(std::vector<Race> inputRaces)
{
	Races = inputRaces;
}

void Pack::set_traits(Race inputTrait)
{
}

void Pack::set_traits(std::vector<Race> inputTraits)
{
}

void Pack::set_spells(Race inputSpell)
{
}

void Pack::set_spells(std::vector<Race> inputSpells)
{
}

void Pack::set_items(Race inputItem)
{
}

void Pack::set_items(std::vector<Race> inputItems)
{
}

void Pack::print_pack()
{
	std::ofstream myfile{};
	std::vector<Race> myRaces{Races};

	myfile.open(Name + ".orcbrew", std::ios::in | std::ios::trunc);
	myfile
		<< "{\"" << Name
		<< "\"{:orcpub.dnd.e5/races{";

	for (Race i : Races) 
	{
		myfile
			<< ":" << i.get_key()
			<< "{:key :" << i.get_key()
			<< ", :name \"" << i.get_name()
			<< "\", :help \"" << i.get_description()
			<< "\", :option-pack \"" << i.get_optionPack()
			<< "\", :speed " << i.get_speed()
			<< ", :flying-speed " << i.get_flySpeed()
			<< ", :swimming-speed " << i.get_swimSpeed()
			<< ", :darkvision " << i.get_darkVision()
			<< std::boolalpha
			<< ", :lizardfolk-ac " << i.get_lizFolkAC()
			<< ", :tortle-ac " << i.get_tortAC()
			<< std::boolalpha
			<< ", :languages #{";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_languageOption()) {
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
		/*:draconic true,
		: deep-speech true,
		: orc true,
		: dwarvish true,
		: gnomish true,
		: sylvan true,
		: elvish true,
		: abyssal true,
		: infernal true,
		: celestial true,
		: common true,
		: undercommon true,
		: primordial true,
		: giant true,
		: halfling true,
		: goblin true*/
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
						newLanguages.push_back(newK);
						break;
					}
				}
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
					<< " :type :" << i.get_type()
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
