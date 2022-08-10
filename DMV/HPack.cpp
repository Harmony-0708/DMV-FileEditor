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
			Packs.at(index) = pack.merge(std::vector<Pack>{i, pack});
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

HPack HPack::merge(std::vector<HPack> HPackPack)
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
	return MergedHPack;
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
