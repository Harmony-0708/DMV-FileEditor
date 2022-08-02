#include "Orcbrew.h"

std::vector<Pack> Orcbrew::merge(std::vector<std::vector<Pack>> PackSet)
{
    return std::vector<Pack>();
}

Orcbrew merge(std::vector<Orcbrew> OrcbrewPack) 
{
    return Orcbrew();
}

void Orcbrew::set_packs(std::vector<Pack> packs) {
    Packs = packs;
}

void Orcbrew::load(std::string fileName)
{
    std::fstream myfile{};
    std::fstream tempfile{};
    
    myfile.open("OrcbrewPacks/" + fileName + ".orcbrew", std::ios::in | std::ios::out);
    tempfile.open("OrcbrewPacks/buffer.bffr", std::ios::in | std::ios::out | std::ios::trunc);

    HPack convertedPack{};
    Pack newPack{};

    std::string line{};
    std::string combinedlines{};
    std::vector<std::string> brokenUpLine{};
    int counter{-1};
    bool isGrouping{};
    bool beginning{};
    bool input{};
    bool didItterate{};
    std::vector<bool> listmode{};
    bool namemode{ false };
    std::string tempString{};
    std::string inputString{};
    int listSize{};
    int templistSize{};

    while (std::getline(myfile, line)) {
        combinedlines += line;
    }
    for (char i : combinedlines) {
        input = false;
        inputString.clear();
        if ((i == '{' || i == '}' || i == '[' || i == ']' || i == '#') && !namemode) {
            if (tempString == "") {
                inputString.push_back(i);
                brokenUpLine.push_back(inputString);
                input = true;
            }
            else {
                inputString.push_back(i);
                brokenUpLine.push_back(tempString);
                brokenUpLine.push_back(inputString);
                tempString.clear();
                input = true;
            }
        }
        if ((i == ',' || i == ' ' || i == '\n' || i == '\t') && !namemode) {
            input = true;
        }
        if (i == '\"') {
            namemode = !namemode;
            if (!namemode) {
                tempString += "\"";
                input = true;
            }
        }
        if (i == ':') {
            tempString += "cmd ";
        }

        if (!namemode) {
            if (!input) {
                tempString += i;
            }
            else if (tempString != "") {
                    brokenUpLine.push_back(tempString);
                    tempString.clear();
            }
        }
        else {
            tempString += i;
        }

    }
    std::string command{};
    std::string newString{};
    for (std::string i : brokenUpLine) {
        if (didItterate) {
            didItterate = false;
            continue;
        }

        if (i == "{" || i == "[") {
            counter++;
            listmode.push_back(true);
            continue;
        }
        else if (i == "}" || i == "]") {
            counter--;
            listmode.pop_back();
            continue;
        }

        
        if (i[0] == '\"') {
            for (char k : i) {
                if (k != '\"') {
                    newString.push_back(k);
                }
                else {
                    break;
                }
            }
        }


        if (i.size() > 3) {
            if (i[0] == 'c' && i[1] == 'm' && i[2] == 'd') {
                for (int k{ 0 }; k < i.size(); k++) {
                    if (k >= 5) {
                        command.push_back(i[k]);
                    }
                }
            }
        }

        



        if (counter == 0) {
            newPack.set_name(newString);
        }

        counter++;

    }

}

void Orcbrew::save()
{
    std::ofstream myfile{};

    if (!std::filesystem::exists("OrcbrewPacks")) {
        std::filesystem::create_directory("OrcbrewPacks");
    }

    myfile.open("OrcbrewPacks/" + Name + ".orcbrew", std::ios::in | std::ios::trunc);

    myfile
        << "{\n";

    for (Pack i : Packs) {
        i.print_pack(true,myfile);
    }

    myfile
        << "}";
}

//HPack Orcbrew::convert_pack_file()
//{
//    return HPack();
//}
