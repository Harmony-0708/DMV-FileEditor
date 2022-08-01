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

void HPack::set_name(std::string name)
{
	Name = name;
}

void HPack::set_packs(std::vector<Pack> packs)
{
	Packs = packs;
}

void HPack::add_pack(Pack pack)
{
	std::vector<Pack> currentPacks{ get_packs() };
	currentPacks.push_back(pack);
	set_packs(currentPacks);
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
			add_pack(newPack);
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

//Orcbrew HPack::convert_pack_file()
//{
//	return Orcbrew();
//}
