#pragma once
#include <vector>
#include <string>
class CommandObject
{
private:
	std::string Title{};
	std::string DoneVariable{};
	std::vector<std::string> Commands{};
	std::vector<std::string> CommandDefs{};
public:
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
	
    virtual CommandObject* ExecuteCommand(int cmdCode, CommandObject *object, std::vector<std::string> parameters = {}, std::string context = {}) = 0;
	virtual void Display() = 0;
	virtual std::string get_title() = 0;
	virtual bool IsDone(std::string input) = 0;
	virtual std::vector<std::string> get_commands() = 0;
	virtual std::vector<std::string> get_command_defs() = 0;
};

