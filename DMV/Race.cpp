#include "Race.h"
Race::Race()
{
	Key = "key";
	Name = "";
	OptionPack = "";
	Description = "";
	Size = SizeEnum::small;
	Speed = 30;
	FlyingSpd = 0;
	SwimmingSpd = 0;
	DarkVision = 0;
	SkillOptionsCount = 1;
	LanguageOptionsCount = 1;
	WeaponOptionsCount = 1;
	LizFolkAC = false;
	TortAC = false;
}
Race::Race(std::string name)
{
	//Key = "";
	for (char i : name){
		if (isalpha(i)) {
			Key += tolower(i);
		}
	}
	Name = name;
	OptionPack = "";
	Description = "";
	Size = SizeEnum::small;
	Speed = 30;
	FlyingSpd = 0;
	SwimmingSpd = 0;
	DarkVision = 0;
	SkillOptionsCount = 1;
	LanguageOptionsCount = 1;
	WeaponOptionsCount = 1;
	LizFolkAC = false;
	TortAC = false;
}
std::string Race::get_key()
{
	return Key;
}
std::string Race::get_name()
{
	return Name;
}
std::string Race::get_optionPack()
{
	return OptionPack;
}
std::string Race::get_description()
{
	return Description;
}
SizeEnum::Size Race::get_size()
{
	return Size;
}
int Race::get_speed()
{
	return Speed;
}
int Race::get_flySpeed()
{
	return FlyingSpd;
}
int Race::get_swimSpeed()
{
	return SwimmingSpd;
}
int Race::get_darkVision()
{
	return DarkVision;
}
int Race::get_skillOptionsCount()
{
	return SkillOptionsCount;
}
int Race::get_languageOptionsCount()
{
	return LanguageOptionsCount;
}
int Race::get_weaponOptionsCount()
{
	return WeaponOptionsCount;
}
bool Race::get_lizFolkAC()
{
	return LizFolkAC;
}
bool Race::get_tortAC()
{
	return TortAC;
}
std::string Race::get_language(int index)
{
	if (index < Languages.size()) {
		return "";
	}
	else {
		return Languages[index];
	}
}
std::vector<std::string> Race::get_language()
{
	return Languages;
}
std::string Race::get_tool(int index)
{
	if (index < Tools.size()) {
		return "";
	}
	else {
		return Tools[index];
	}
}
std::vector<std::string> Race::get_tool()
{
	return Tools;
}
std::string Race::get_skillOption(int index)
{
	if (index < SkillOptions.size()) {
		return "";
	}
	else {
		return SkillOptions[index];
	}
}
std::vector<std::string> Race::get_skillOption()
{
	return SkillOptions;
}
std::string Race::get_skillProf(int index)
{
	if (index < SkillProf.size()) {
		return "";
	}
	else {
		return SkillProf[index];
	}
}
std::vector<std::string> Race::get_skillProf()
{
	return SkillProf;
}
std::string Race::get_languageOption(int index)
{
	if (index < LanguageOptions.size()) {
		return "";
	}
	else {
		return LanguageOptions[index];
	}
}
std::vector<std::string> Race::get_languageOption()
{
	return LanguageOptions;
}
std::string Race::get_weaponOption(int index)
{
	if (index < WeaponOptions.size()) {
		return "";
	}
	else {
		return WeaponOptions[index];
	}
}
std::vector<std::string> Race::get_weaponOption()
{
	return WeaponOptions;
}
std::string Race::get_weaponProf(int index)
{
	if (index < WeaponProf.size()) {
		return "";
	}
	else {
		return WeaponProf[index];
	}
}
std::vector<std::string> Race::get_weaponProf()
{
	return WeaponProf;
}
std::string Race::get_armorProf(int index)
{
	if (index < ArmorProf.size()) {
		return "";
	}
	else {
		return ArmorProf[index];
	}
}
std::vector<std::string> Race::get_armorProf()
{
	return ArmorProf;
}
std::string Race::get_damageRes(int index)
{
	if (index < DamageRes.size()) {
		return "";
	}
	else {
		return DamageRes[index];
	}
}
std::vector<std::string> Race::get_damageRes()
{
	return DamageRes;
}
std::string Race::get_damageImmun(int index)
{
	if (index < DamageImmun.size()) {
		return "";
	}
	else {
		return DamageImmun[index];
	}
}
std::vector<std::string> Race::get_damageImmun()
{
	return DamageImmun;
}
Trait Race::get_trait(int index)
{
	if (index < Traits.size()) {
		Trait emptyTrait{ "empty" };
		return emptyTrait;
	}
	else {
		return Traits[index];
	}
}
std::vector<Trait> Race::get_trait()
{
	return Traits;
}
//Spell Race::get_spell(int index,std::string spellName)
//{
//	if (index < Spells.size()) {
//		Spell emptySpell{ "empty" };
//		return emptySpell;
//	}
//	else {
//		for (Spell i : Spells[index]) {
//			if (i.get_key() == spellName) {
//				return i;
//			}
//		}
//	}
//}
//std::vector<std::vector<Spell>> Race::get_spell()
//{
//	return Spells;
//}

//Assign Functions
/// <summary>
/// Sets new key for race
/// </summary>
/// <param name="key">- The new key</param>
void Race::set_key(std::string key)
{
	Key = key;
}
/// <summary>
/// Sets new name for race
/// </summary>
/// <param name="name">- The new name</param>
void Race::set_name(std::string name)
{
	Name = name;
	for (char i : name) {
		if (isalpha(i)) {
			Key += tolower(i);
		}
	}
}
/// <summary>
/// Sets new Options Pack for race
/// </summary>
/// <param name="optionPack">- The new options pack</param>
void Race::set_optionPack(std::string optionPack)
{
	OptionPack = optionPack;
}
/// <summary>
/// Sets new description for race
/// </summary>
/// <param name="description">- The new description</param>
void Race::set_description(std::string description)
{
	Description = description;
}
/// <summary>
/// Sets new size for race
/// </summary>
/// <param name="size">- The new size</param>
void Race::set_size(SizeEnum::Size size)
{
	Size = size;
}
/// <summary>
/// Sets new speed for race.
/// </summary>
/// <param name="speed">- The new speed, must be between 0 and 50</param>
void Race::set_speed(int speed)
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 50) {
		speed = 50;
	}
	Speed = speed;
}
/// <summary>
/// Sets new flying speed for race.
/// </summary>
/// <param name="flyspeed">- The new flyspeed, must be between 0 and 50</param>
void Race::set_flySpeed(int flyspeed)
{
	if (flyspeed < 0) {
		flyspeed = 0;
	}
	else if (flyspeed > 50) {
		flyspeed = 50;
	}
	FlyingSpd = flyspeed;
}
/// <summary>
/// Sets new swimming speed for race.
/// </summary>
/// <param name="swimspeed">- The new swimspeed, must be between 0 and 50</param>
void Race::set_swimSpeed(int swimspeed)
{
	if (swimspeed < 0) {
		swimspeed = 0;
	}
	else if (swimspeed > 50) {
		swimspeed = 50;
	}
	SwimmingSpd = swimspeed;
}
/// <summary>
/// Sets new Dark Vision distance for race
/// </summary>
/// <param name="darkVision">- The new dark vision, must be between 0 and 120</param>
void Race::set_darkVision(int darkVision)
{
	if (darkVision < 0) {
		darkVision = 0;
	}
	else if (darkVision > 120) {
		darkVision = 120;
	}
	DarkVision = darkVision;
}
/// <summary>
/// Sets new amount of skill options.
/// </summary>
/// <param name="skillOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_skillOptionsCount(int skillOptionsCount)
{
	if (skillOptionsCount < 0) {
		skillOptionsCount = 0;
	}
	else if (skillOptionsCount > 5) {
		skillOptionsCount = 5;
	}
	SkillOptionsCount = skillOptionsCount;
}
/// <summary>
/// Sets new amount of language options.
/// </summary>
/// <param name="languageOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_languageOptionsCount(int languageOptionsCount)
{
	if (languageOptionsCount < 0) {
		languageOptionsCount = 0;
	}
	else if (languageOptionsCount > 5) {
		languageOptionsCount = 5;
	}
	LanguageOptionsCount = languageOptionsCount;
}
/// <summary>
/// Sets new amount of weapon options.
/// </summary>
/// <param name="weaponOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_weaponOptionsCount(int weaponOptionsCount)
{
	if (weaponOptionsCount < 0) {
		weaponOptionsCount = 0;
	}
	else if (weaponOptionsCount > 5) {
		weaponOptionsCount = 5;
	}
	WeaponOptionsCount = weaponOptionsCount;
}
/// <summary>
/// Sets whether using lizard folk AC
/// </summary>
/// <param name="lizAC">- </param>
void Race::set_lizFolkAC(bool lizAC)
{
	LizFolkAC = lizAC;
}
/// <summary>
/// Sets whether using tortle folk AC
/// </summary>
/// <param name="tortAC">- </param>
void Race::set_tortAC(bool tortAC)
{
	TortAC = tortAC;
}
/// <summary>
/// Inserts a single language into the race
/// </summary>
/// <param name="language">- Language to be passed in</param>
void Race::insert_language(std::string language)
{
	Languages.push_back(language);
}
/// <summary>
/// Sets languages to new set of languages
/// </summary>
/// <param name="languages">- The new languages to be passed in</param>
void Race::insert_language(std::vector<std::string> languages)
{
	Languages = languages;
}
/// <summary>
/// Inserts a single tool into the race
/// </summary>
/// <param name="language">- Tool to be passed in</param>
void Race::insert_tool(std::string tool)
{
	Tools.push_back(tool);
}
/// <summary>
/// Sets tools to new set of tools
/// <param name="tools">- The new tools to be passed in</param>
void Race::insert_tool(std::vector<std::string> tools)
{
	Tools = tools;
}
/// <summary>
/// Inserts a single skill option into the race
/// </summary>
/// <param name="skillOption">- Skill option to be passed in</param>
void Race::insert_skillOption(std::string skillOption)
{
	SkillOptions.push_back(skillOption);
}
/// <summary>
/// Sets skill options to new set of skill options
/// </summary>
/// <param name="skillOptions">- The new skill options to be passed in</param>
void Race::insert_skillOption(std::vector<std::string> skillOptions)
{
	SkillOptions = skillOptions;
}
/// <summary>
/// Inserts a single Skill prof into the race
/// </summary>
/// <param name="skillProf">- Skill prof to be passed in</param>
void Race::insert_skillProf(std::string skillProf)
{
	SkillProf.push_back(skillProf);
}
/// <summary>
/// Sets skill profs to new set of skill profs
/// </summary>
/// <param name="skillProfs">- The new skill profs to be passed in</param>
void Race::insert_skillProf(std::vector<std::string> skillProfs)
{
	SkillProf = skillProfs;
}
/// <summary>
/// Inserts a single language option into the race
/// </summary>
/// <param name="languageOption">- Language option to be passed in</param>
void Race::insert_languageOption(std::string languageOption)
{
	LanguageOptions.push_back(languageOption);
}
/// <summary>
/// Sets language options to new set of language options
/// </summary>
/// <param name="languageOptions">- The new Language options to be passed in</param>
void Race::insert_languageOption(std::vector<std::string> languageOptions)
{
	LanguageOptions = languageOptions;
}
/// <summary>
/// Inserts a single weapon option into the race
/// </summary>
/// <param name="weaponOption">- Weapon option to be passed in</param>
void Race::insert_weaponOption(std::string weaponOption)
{
	WeaponOptions.push_back(weaponOption);
}
/// <summary>
/// Sets weapon options to new set of weapon options
/// </summary>
/// <param name="weaponOptions">- The new weapon options to be passed in</param>
void Race::insert_weaponOption(std::vector<std::string> weaponOptions)
{
	WeaponOptions = weaponOptions;
}
/// <summary>
/// Inserts a single weapon prof into the race
/// </summary>
/// <param name="weaponProf">- Weapon prof to be passed in</param>
void Race::insert_weaponProf(std::string weaponProf)
{
	WeaponProf.push_back(weaponProf);
}
/// <summary>
/// Sets weapon profs to new set of weapon profs
/// </summary>
/// <param name="weaponProfs">- The new weapon profs to be passed in</param>
void Race::insert_weaponProf(std::vector<std::string> weaponProfs)
{
	WeaponProf = weaponProfs;
}
/// <summary>
/// Inserts a single armor prof into the race
/// </summary>
/// <param name="armorProf">- Language to be passed in</param>
void Race::insert_armorProf(std::string armorProf)
{
	ArmorProf.push_back(armorProf);
}
/// <summary>
/// Sets armor profs to new set of armor profs
/// </summary>
/// <param name="armorProfs">- The new armor profs to be passed in</param>
void Race::insert_armorProf(std::vector<std::string> armorProfs)
{
	ArmorProf = armorProfs;
}
/// <summary>
/// Inserts a single damage resistance into the race
/// </summary>
/// <param name="damageRes">- Damage resistance to be passed in</param>
void Race::insert_damageRes(std::string damageRes)
{
	DamageRes.push_back(damageRes);
}
/// <summary>
/// Sets damage resistances to new set of damage resistances
/// </summary>
/// <param name="damageResList">- The new damage resistances to be passed in</param>
void Race::insert_damageRes(std::vector<std::string> damageResList)
{
	DamageRes = damageResList;
}
/// <summary>
/// Inserts a single damage immunity into the race
/// </summary>
/// <param name="damageImmun">- Damage immunity to be passed in</param>
void Race::insert_damageImmun(std::string damageImmun)
{
	DamageImmun.push_back(damageImmun);
}
/// <summary>
/// Sets damage immunities to new set of damage immunities
/// </summary>
/// <param name="damageImmunList">- The new damage immunities to be passed in</param>
void Race::insert_damageImmun(std::vector<std::string> damageImmunList)
{
	DamageImmun = damageImmunList;
}
/// <summary>
/// Inserts a single trait into the race
/// </summary>
/// <param name="trait">- Trait to be passed in</param>
void Race::insert_trait(Trait trait)
{
	Traits.push_back(trait);
}
/// <summary>
/// Sets traits to new set of traits
/// </summary>
/// <param name="traits">- The traits to be passed in</param>
void Race::insert_trait(std::vector<Trait> traits)
{
	Traits = traits;
}
/// <summary>
/// Inserts spell at specfic index of the spell list, with the index meaning the level its unlocked
/// </summary>
/// <param name="index">- Index of spell, level that spell is unlocked</param>
/// <param name="spell">- The spell to be passed in</param>
void Race::insert_spell(int index, Spell spell)
{
	Spells[index].push_back(spell);
}
/// <summary>
/// Sets Spells to new list of spells
/// </summary>
/// <param name="spellList">- The new list of spells</param>
void Race::insert_spell(std::vector<std::vector<Spell>> spellList)
{
	Spells = spellList;
}


//Display

/// <summary>
/// Displays the race and all of it's features
/// </summary>
void Race::display_info()
{
	int counter{};
	
	std::cout << std::endl						<< std::endl;
	std::cout << "Race: "		 << Name		<< std::endl;
	std::cout << "Pack: "		 << OptionPack	<< std::endl;
	std::cout << "Description: ";
	WordWrap(100, Description);
	std::cout << std::endl;
	std::cout << "Size: " << Size << std::endl;
	std::cout << "Speed: " << Speed << std::endl;
	std::cout << "Fly Speed: " << FlyingSpd << std::endl;
	std::cout << "Swimming Speed: " << SwimmingSpd << std::endl;
	std::cout << "Dark Vision: " << DarkVision << std::endl;
	std::cout << "Skill options count: " << SkillOptionsCount << std::endl;
	std::cout << "Language options count: " << LanguageOptionsCount << std::endl;
	std::cout << "Weapon options count: " << WeaponOptionsCount << std::endl;
	std::cout << "Do they have Lizard Folk AC: " << LizFolkAC << std::endl;
	std::cout << "Do they have Tortle AC: " << TortAC << std::endl;
	//std::cout << "Languages: ";
	//DisplayVector(100, Languages);
	//std::cout << std::endl;
	//std::cout << "Tools: ";
	//DisplayVector(100, Tools);
	//std::cout << std::endl;
	//std::cout << "Skill Options: ";
	//DisplayVector(100, SkillOptions);
	//std::cout << std::endl;
	//std::cout << "Skill Proficencies: ";
	//DisplayVector(100, SkillProf);
	//std::cout << std::endl;
	//std::cout << "Language Options: ";
	//DisplayVector(100, LanguageOptions);
	//std::cout << std::endl;
	//std::cout << "Weapon Options: ";
	//DisplayVector(100, WeaponOptions);
	//std::cout << std::endl;
	//std::cout << "Weapon Proficencies: ";
	//DisplayVector(100, WeaponProf);
	//std::cout << std::endl;
	//std::cout << "Armor Proficencies: ";
	//DisplayVector(100, ArmorProf);
	//std::cout << std::endl;
	//std::cout << "Damage Resistance: ";
	//DisplayVector(100, DamageRes);
	//std::cout << std::endl;
	//std::cout << "Damage Immunites: ";
	//DisplayVector(100, DamageImmun);
	//std::cout << std::endl;


}