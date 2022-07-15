#include "HPack.h"

HPack::HPack()
{
	set_name("Default");
}

HPack::HPack(std::string name)
{
	set_name(name);
}

void HPack::set_name(std::string name)
{
	Name = name;
}

void HPack::set_packs(std::vector<Pack> packs)
{
	Packs = packs;
}

std::vector<Pack> HPack::merge(std::vector<std::vector<Pack>> PackSet)
{
    return std::vector<Pack>();
}

HPack merge(std::vector<HPack> HPackPack)
{
    return HPack();
}

void HPack::load(std::string fileName)
{
    Name = fileName;
    std::ifstream myfile{};

	if (!std::filesystem::exists("CustomPacks")) {
		std::filesystem::create_directory("CustomPacks");
	}
	else if (!std::filesystem::exists("CustomPacks/" + Name + ".hpck")) {
		
	}

	myfile.open("CustomPacks/" + Name + ".hpck", std::ios::out);



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

//Orcbrew HPack::convert_pack_file()
//{
//	return Orcbrew();
//}
