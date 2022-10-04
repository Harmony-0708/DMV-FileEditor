#include "Orcbrew.h"

Orcbrew::Orcbrew()
{
    Name = "Default";
}

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

void Orcbrew::set_name(std::string name)
{
    Name = name;
}

Pack Orcbrew::add_to_pack(Pack inPack, std::string command, std::string input, std::string packPart, std::string objectName)
{
    if (packPart == "race") {
        Race newRace{};
        for (Race i : inPack.get_races()) {
            if (i.get_key() == objectName) {
                newRace = i;
            }
        }
        if (command == "raceName") {
            newRace.set_key(input);
        }
        else if (command == "key") {
            std::string newInput{};
            for (int k{}; k < input.size(); k++) {
                if (k >= 5) {
                    newInput.push_back(input[k]);
                }
            }
            newRace.set_key(newInput);
        }
        else if (command == "name") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newRace.set_name(newInput);
        }
        else if (command == "swimming-speed") {
            newRace.set_swimSpeed(std::stoi(input));
        }
        else if (command == "help") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newRace.set_description(newInput);
        }
        else if (command == "option-pack") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newRace.set_optionPack(newInput);
        }
        else if (command == "speed") {
            newRace.set_speed(std::stoi(input));
        }
        else if (command == "flying-speed") {
            newRace.set_flySpeed(std::stoi(input));
        }
        else if (command == "darkvision") {
            newRace.set_darkVision(std::stoi(input));
        }
        else if (command == "lizardfolk-ac") {
            if (input == "false") {
                newRace.set_lizFolkAC(false);
            }
            else {
                newRace.set_lizFolkAC(true);
            }
        }
        else if (command == "tortle-ac") {
            if (input == "false") {
                newRace.set_tortAC(false);
            }
            else {
                newRace.set_tortAC(true);
            }
        }
        else if (command == "size") {
            std::string newInput{};
            for (int k{}; k < input.size(); k++) {
                if (k > 5) {
                    newInput.push_back(input[k]);
                }
            }
            if (newInput == "small") {
                newRace.set_size(SizeEnum::small);
            }
            else if (newInput == "large") {
                newRace.set_size(SizeEnum::large);
            }
            else {
                newRace.set_size(SizeEnum::medium);
            }
        }
        inPack.update_race(newRace);
    }
    else if (packPart == "spell") {
        Spell newSpell{};
        for (Spell i : inPack.get_spells()) {
            if (i.get_key() == objectName) {
                newSpell = i;
            }
        }
        if (command == "spellName") {
            newSpell.set_key(input);
        }
        else if (command == "key") {
            std::string newInput{};
            for (int k{}; k < input.size(); k++) {
                if (k >= 5) {
                    newInput.push_back(input[k]);
                }
            }
            newSpell.set_key(newInput);
        }
        else if (command == "name") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_name(newInput);
        }
        else if (command == "description") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_description(newInput);
        }
        else if (command == "range") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_range(newInput);
        }
        else if (command == "school") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_school(newInput);
        }
        else if (command == "duration") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_duration(newInput);
        }
        else if (command == "option-pack") {
            std::string newInput{};
            if (input[0] == '\"') {
                input.erase(0, 1);
                for (char k : input) {
                    if (k != '\"') {
                        newInput.push_back(k);
                    }
                    else {
                        break;
                    }
                }
            }
            newSpell.set_optionPack(newInput);
        }
        else if (command == "level") {
            newSpell.set_level(std::stoi(input));
        }
        else if (command == "ritual") {
            if (input == "false") {
                newSpell.set_ritual(false);
            }
            else {
                newSpell.set_ritual(true);
            }
        }
        else if (command == "attack-roll?") {
            if (input == "false") {
                newSpell.set_attackRoll(false);
            }
            else {
                newSpell.set_attackRoll(true);
            }
        }
        inPack.update_spell(newSpell);
    }
    return inPack;
}

Pack Orcbrew::add_to_pack(Pack inPack, std::string command, std::vector<std::string> input, std::string packPart, std::string objectName)
{
    if (packPart == "race") {
        Race newRace{};
        for (Race i : inPack.get_races()) {
            if (i.get_key() == objectName) {
                newRace = i;
            }
        }
        if (command == "abilities") {
            bool Itterate{};
            int index{ 0 };
            for (std::string i : input) {
                if (!Itterate) {
                    std::string newInput{};
                    if (i[0] == 'c' && i[1] == 'm' && i[2] == 'd') {
                        Itterate = true;
                        newInput = i;
                        newInput.erase(0, 29);
                    }
                    if (newInput == "str") {
                        newRace.set_str(std::stoi(input[index + 1]));
                    }
                    else if (newInput == "dex") {
                        newRace.set_dex(std::stoi(input[index + 1]));
                    }
                    else if (newInput == "con") {
                        newRace.set_con(std::stoi(input[index + 1]));
                    }
                    else if (newInput == "int") {
                        newRace.set_int(std::stoi(input[index + 1]));
                    }
                    else if (newInput == "wis") {
                        newRace.set_wis(std::stoi(input[index + 1]));
                    }
                    else if (newInput == "cha") {
                        newRace.set_cha(std::stoi(input[index + 1]));
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }
        else if (command == "languages") {
            for (std::string i : input) {
                std::string newInput{};
                if (i[0] == '\"') {
                    i.erase(0, 1);
                    for (char k : i) {
                        if (k != '\"') {
                            newInput.push_back(k);
                        }
                        else {
                            break;
                        }
                    }
                }
                newRace.insert_language(newInput);
            }
        }
        else if (command == "profs") {
            bool Itterate{ false };
            bool inTools{ false };
            bool inSkillOptions{ false };
            bool inLanguageOptions{ false };
            bool inWeaponProfs{ false };
            bool endGroup{ false };
            int index{ 0 };
            int inputSize{};
            inputSize = input.size();
            for (std::string i : input) {
                if (!Itterate) {
                    std::string newInput{};
                    for (int k{}; k < i.size(); k++) {
                        if (!endGroup) {
                            if (k >= 5) {
                                newInput.push_back(i[k]);
                            }
                        }
                        else {
                            newInput.push_back(i[k]);
                        }
                    }
                    
                    if ((index + 1) < inputSize) {
                        if (newInput == "}" && input[index + 1] == "}") {
                            index++;
                            continue;
                        }
                    }

                    endGroup = false;

                    if (inTools) {
                        newRace.insert_tool(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inTools = false;
                        }
                    }
                    else if (inSkillOptions) {
                        if (newInput == "choose"){
                            newRace.set_skillOptionsCount(std::stoi(input[index + 1]));
                            Itterate = true;
                        }
                        else if (newInput == "options") {
                            Itterate = true;
                        }
                        else {
                            newRace.insert_skillOption(newInput);
                            Itterate = true;
                            if (input[index + 2] == "}") {
                                endGroup = true;
                                inSkillOptions = false;
                            }
                        }
                    }
                    else if (inLanguageOptions) {
                        if (newInput == "choose") {
                            newRace.set_languageOptionsCount(std::stoi(input[index + 1]));
                            Itterate = true;
                        }
                        else if (newInput == "options") {
                            Itterate = true;
                        }
                        else {
                            newRace.insert_languageOption(newInput);
                            Itterate = true;
                            if (input[index + 2] == "}") {
                                endGroup = true;
                                inLanguageOptions = false;
                            }
                        }

                    }
                    else if (inWeaponProfs) {
                        if (newInput == "choose") {
                            newRace.set_weaponOptionsCount(std::stoi(input[index + 1]));
                            Itterate = true;
                        }
                        else if (newInput == "options") {
                            Itterate = true;
                        }
                        else {
                            newRace.insert_weaponOption(newInput);
                            Itterate = true;
                            if (input[index + 2] == "}") {
                                endGroup = true;
                                inWeaponProfs = false;
                            }
                        }
                    }

                    if (newInput == "tool") {
                        Itterate = true;
                        inTools = true;
                        inSkillOptions = false;
                        inLanguageOptions = false;
                        inWeaponProfs = false;
                    }
                    else if (newInput == "skill-options") {
                        Itterate = true;
                        inTools = false;
                        inSkillOptions = true;
                        inLanguageOptions = false;
                        inWeaponProfs = false;
                    }
                    else if (newInput == "language-options") {
                        Itterate = true;
                        inTools = false;
                        inSkillOptions = false;
                        inLanguageOptions = true;
                        inWeaponProfs = false;
                    }
                    else if (newInput == "weapon-proficiency-options") {
                        Itterate = true;
                        inTools = false;
                        inSkillOptions = false;
                        inLanguageOptions = false;
                        inWeaponProfs = true;
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }
        else if (command == "props") {
            bool Itterate{ false };
            bool inWeaponProf{ false };
            bool inSkillProf{ false };
            bool inArmorProf{ false };
            bool inDamageRes{ false };
            bool inDamageImm{ false };
            bool endGroup{ false };
            int index{ 0 };
            int inputSize{};
            inputSize = input.size();
            for (std::string i : input) {
                if (!Itterate) {
                    std::string newInput{};
                    for (int k{}; k < i.size(); k++) {
                        if (!endGroup) {
                            if (k >= 5) {
                                newInput.push_back(i[k]);
                            }
                        }
                        else {
                            newInput.push_back(i[k]);
                        }
                    }

                    if ((index + 1) < inputSize) {
                        if (newInput == "}" && input[index + 1] == "}") {
                            index++;
                            continue;
                        }
                    }

                    endGroup = false;

                    if (inWeaponProf) {
                        newRace.insert_weaponProf(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inWeaponProf = false;
                        }
                    }
                    else if (inSkillProf) {
                        newRace.insert_skillProf(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inSkillProf = false;
                        }
                    }
                    else if (inArmorProf) {
                        newRace.insert_armorProf(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inArmorProf = false;
                        }
                    }
                    else if (inDamageRes) {
                        newRace.insert_damageRes(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inDamageRes = false;
                        }
                    }
                    else if (inDamageImm) {
                        newRace.insert_damageImmun(newInput);
                        Itterate = true;
                        if (input[index + 2] == "}") {
                            endGroup = true;
                            inDamageImm = false;
                        }
                    }

                    if (newInput == "weapon-prof") {
                        Itterate = true;
                        inWeaponProf = true;
                        inSkillProf = false;
                        inArmorProf = false;
                        inDamageRes = false;
                        inDamageImm = false;
                    }
                    else if (newInput == "armor-prof") {
                        Itterate = true;
                        inWeaponProf = false;
                        inSkillProf = false;
                        inArmorProf = true;
                        inDamageRes = false;
                        inDamageImm = false;
                    }
                    else if (newInput == "damage-resistance") {
                        Itterate = true;
                        inWeaponProf = false;
                        inSkillProf = false;
                        inArmorProf = false;
                        inDamageRes = true;
                        inDamageImm = false;
                    }
                    else if (newInput == "damage-immunity") {
                        Itterate = true;
                        inWeaponProf = false;
                        inSkillProf = false;
                        inArmorProf = false;
                        inDamageRes = false;
                        inDamageImm = true;
                    }
                    else if (newInput == "skill-prof") {
                        Itterate = true;
                        inWeaponProf = false;
                        inSkillProf = true;
                        inArmorProf = false;
                        inDamageRes = false;
                        inDamageImm = false;
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }
        else if (command == "traits") {
            bool Itterate{};
            int index{};
            Trait newTrait{};
            for (std::string i : input) {
                if (!Itterate) {
                    if (i == "{") {
                        Trait resetTrait{};
                        newTrait = resetTrait;
                    }
                    else if (i == "cmd :name") {
                        Itterate = true;
                        newTrait.set_name(input[index + 1]);
                    }
                    else if (i == "cmd :description") {
                        Itterate = true;
                        newTrait.set_description(input[index + 1]);
                    }
                    else if (i == "cmd :type") {
                        Itterate = true;
                        if (input[index + 1] == "cmd :action") {
                            newTrait.set_type(TraitType::Action);
                        } 
                        else if (input[index + 1] == "cmd :b-action") {
                            newTrait.set_type(TraitType::BAction);
                        } 
                        else if (input[index + 1] == "cmd :reaction") {
                            newTrait.set_type(TraitType::Reaction);
                        } 
                        else if (input[index + 1] == "cmd :other") {
                            newTrait.set_type(TraitType::Other);
                        }
                    }
                    else if (i == "}") {
                        newRace.insert_trait(newTrait);
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }

        inPack.update_race(newRace);
    }
    else if (packPart == "spell") {
        Spell newSpell{};
        for (Spell i : inPack.get_spells()) {
            if (i.get_key() == objectName) {
                newSpell = i;
            }
        }
        if (command == "spell-lists") {
            bool Itterate{ false };
            bool inClasses{ true };;
            bool endGroup{ false };
            int index{ 0 };
            int inputSize{};
            inputSize = input.size();
            for (std::string i : input) {
                if (!Itterate) {
                    std::string newInput{};
                    for (int k{}; k < i.size(); k++) {
                        if (!endGroup) {
                            if (k >= 5) {
                                newInput.push_back(i[k]);
                            }
                        }
                        else {
                            newInput.push_back(i[k]);
                        }
                    }
                    
                    if ((index + 1) < inputSize) {
                        if (newInput == "}" && input[index + 1] == "}") {
                            index++;
                            continue;
                        }
                    }

                    endGroup = false;

                    if (inClasses) {
                        newSpell.insert_class(newInput);
                        Itterate = true;
                        if (input.size() > index + 2) {
                            if (input[index + 2] == "}") {
                                endGroup = true;
                                inClasses = false;
                            }
                        }
                        else if (input.size() <= index + 2) {
                            endGroup = true;
                            inClasses = false;
                        }
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }
        else if (command == "components") {
            bool Itterate{};
            int index{ 0 };
            for (std::string i : input) {
                if (!Itterate) {
                    std::string newInput{};
                    if (i[0] == 'c' && i[1] == 'm' && i[2] == 'd') {
                        Itterate = true;
                        newInput = i;
                        newInput.erase(0, 5);
                    }
                    if (newInput == "verbal") {
                        newSpell.set_verbal(HLib::StringToBool(input[index + 1]));
                    }
                    else if (newInput == "somatic") {
                        newSpell.set_somatic(HLib::StringToBool(input[index + 1]));
                    }
                    else if (newInput == "material") {
                        newSpell.set_material(HLib::StringToBool(input[index + 1]));
                    }
                    else if (newInput == "material-component") {
                        std::string newString{ input[index + 1] };
                        newInput.clear();
                        if (newString[0] == '\"') {
                            newString.erase(0, 1);
                            for (char k : newString) {
                                if (k != '\"') {
                                    newInput.push_back(k);
                                }
                                else {
                                    break;
                                }
                            }
                        }
                        newSpell.set_component(newInput);
                    }
                }
                else {
                    Itterate = false;
                }
                index++;
            }
        }
        inPack.update_spell(newSpell);
    }
    return inPack;
}

std::vector<Pack> Orcbrew::load(std::string fileName)
{
    std::fstream myfile{};
    std::fstream tempfile{};
    
    myfile.open("OrcbrewPacks/" + fileName + ".orcbrew", std::ios::in | std::ios::out);

    std::vector<Pack> convertedPack{};
    Pack newPack{};


    std::string line{};
    std::string combinedlines{};
    std::vector<std::string> brokenUpLine{};
    int counter{-1};
    bool isGrouping{};
    bool beginning{};
    bool input{};
    bool didItterate{};
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
        if ((i == '{' || i == '}' || i == '[' || i == ']') && !namemode) {
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
        if ((i == ',' || i == ' ' || i == '\n' || i == '\t' || i == '#') && !namemode) {
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
    
    int index{};
    int toIndex{};
    bool inCommand{};
    bool inList{};
    bool inRaces{ false };
    bool inSpells{ false };
    bool inTraits{ false };
    std::string command{};
    std::string newString{};
    std::string raceName{};
    std::string spellName{};
    for (std::string i : brokenUpLine) {
        newString.clear();
        command.clear();
        if (didItterate) {
            index++;
            if (index != toIndex) {
                continue;
            }
            else {
                index--;
                didItterate = false;
            }
        }

        if (i == "{" || i == "[") {
            index++;
            counter++;
            continue;
        }
        else if (i == "}" || i == "]") {
            index++;
            counter--;
            if (counter == 0) {
                convertedPack.push_back(newPack);
                Pack resetPack{};
                newPack = resetPack;
                if (i[0] == '\"') {
                    i.erase(0, 1);
                    for (char k : i) {
                        if (k != '\"') {
                            newString.push_back(k);
                        }
                        else {
                            break;
                        }
                    }
                    newPack.set_name(newString);
                }
            }
            continue;
        }

        if (i.size() > 3) {
            if (i[0] == 'c' && i[1] == 'm' && i[2] == 'd') {
                for (int k{ 0 }; k < i.size(); k++) {
                    if (k >= 5) {
                        command.push_back(i[k]);
                    }
                }
                inCommand = true;
            }
        }
        
        if (inCommand) {
            if (command == "orcpub.dnd.e5/races") {
                inRaces = true;
                inSpells = false;
            }
            else if (command == "orcpub.dnd.e5/spells") {
                inSpells = true;
                inRaces = false;
            }
            else if (inRaces) {
                if (counter >= 3) {
                    if (brokenUpLine[index + 1] == "{" || brokenUpLine[index + 1] == "[") {
                        int tempCounter{ counter };
                        counter++;
                        std::vector<std::string> inputVec{};
                        int incre{ 2 };
                        while (true) {
                            if (brokenUpLine[index + incre] == "{" || brokenUpLine[index + incre] == "[") {
                                counter++;
                            }
                            else if (brokenUpLine[index + incre] == "}" || brokenUpLine[index + incre] == "]") {
                                counter--;
                            }
                            if ((brokenUpLine[index + incre] != "}" && brokenUpLine[index + incre] != "]") || tempCounter != counter) {
                                inputVec.push_back(brokenUpLine[index + incre]);
                                incre++;
                            }
                            else {
                                break;
                            }
                        }
                        didItterate = true;
                        toIndex = index + incre + 2;
                        newPack = add_to_pack(newPack, command, inputVec, "race", raceName);
                    }
                    else {
                        didItterate = true;
                        toIndex = index + 2;
                        newPack = add_to_pack(newPack, command, brokenUpLine[index + 1], "race", raceName);
                    }
                }
                else if (counter != 0) {
                    raceName = command;
                    newPack = add_to_pack(newPack, "raceName", command, "race", raceName);
                }
            }
            else if (inSpells) {
                if (counter >= 3) {
                    if (brokenUpLine[index + 1] == "{" || brokenUpLine[index + 1] == "[") {
                        int tempCounter{ counter };
                        counter++;
                        std::vector<std::string> inputVec{};
                        int incre{ 2 };
                        while (true) {
                            if (brokenUpLine[index + incre] == "{" || brokenUpLine[index + incre] == "[") {
                                counter++;
                            }
                            else if (brokenUpLine[index + incre] == "}" || brokenUpLine[index + incre] == "]") {
                                counter--;
                            }
                            if ((brokenUpLine[index + incre] != "}" && brokenUpLine[index + incre] != "]") || tempCounter != counter) {
                                inputVec.push_back(brokenUpLine[index + incre]);
                                incre++;
                            }
                            else {
                                break;
                            }
                        }
                        didItterate = true;
                        toIndex = index + incre + 2;
                        newPack = add_to_pack(newPack, command, inputVec, "spell", spellName);
                    }
                    else {
                        didItterate = true;
                        toIndex = index + 2;
                        newPack = add_to_pack(newPack, command, brokenUpLine[index + 1], "spell", spellName);
                    }
                }
                else if (counter != 0) {
                    spellName = command;
                    newPack = add_to_pack(newPack, "spellName", command, "spell", spellName);
                }
            }
            inCommand = false;
        }
        if (counter == 0) {
            if (i[0] == '\"') {
                i.erase(0, 1);
                for (char k : i) {
                    if (k != '\"') {
                        newString.push_back(k);
                    }
                    else {
                        break;
                    }
                }
                newPack.set_name(newString);
            }
        }
        
        index++;

    }

    //convertedPack.at(0).(Name);
    return convertedPack;
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
