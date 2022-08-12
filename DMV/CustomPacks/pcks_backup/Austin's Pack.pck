name="Austin's Pack"
Races{
giff{
Name="Giff"
OptionPack="Austin's Pack"
Description="Giff are tall, broad-shouldered folk with hippo-like features. Some have smooth skin, while others have short bristles on their faces and the tops of their heads. As beings of impressive size and unforgettable appearance, giff are noticed wherever they go. Storytelling is a rich tradition among giff, and it's not uncommon to see a giff recounting their past exploits to an enraptured crowd. Having a friendly giff nearby when a tavern brawl erupts can also be useful, for a giff can usually more than hold their own when pleasant revelry devolves into fisticuffs. The giff are split into two camps concerning how their name is pronounced. Half of them say it with a hard g, half with a soft g. Disagreements over the correct pronunciation often blossom into hard feelings, loud arguments, and headbutting contests, but rarely escalate beyond that."
Size=Medium
Str=2
Dex=0
Con=1
Int=0
Wis=0
Cha=0
Speed=30
FlySpeed=0
SwimSpeed=0
DarkVision=0
SKOC=1
LNOC=1
WPOC=1
LizFolkAC=0
TortAC=0
Languages={"Common""Giant"}
LanguageOptions={"Giant""Common""Celestial""Undercommon""Goblin""Dwarvish""Abyssal""Sylvan""Orc""Deep Speech""Primordial""Draconic""Gnomish""Elvish""Halfling""Infernal"}
SkillProf={}
SkillOptions={}
WeaponProf={}
WeaponOptions={}
DamageRes={}
DamageImmun={}
ArmorProf={"medium""heavy"}
Tools={}
Traits={
{name="Headbutt"
description="Your strong head is a natural melee weapon, which you can use to make unarmed strikes. If you hit with it, you deal bludgeoning damage equal to 1d4 + your Strength modifier."
type=0
}
{name="Headfirst Charge"
description="If you move at least 20 feet straight toward a target and then hit it with a melee weapon attack on the same turn, you can immediately follow that attack with a bonus action, making one attack against the target with your headbutt."
type=1
}
{name="Giff Firearms Master"
description="You gain proficiency in a firearm of your choice. At 3rd level, your mastery of firearms allows you to ignore the loading property of any firearm you are proficient in."
type=3
}
{name="Natural Armor"
description="You have thick, leathery skin. When you aren't wearing armor, your AC is 12 + your Constitution modifier. You can use your natural armor to determine your AC if the armor you wear would leave you with a lower AC. A shield's benefits apply as normal while you use your natural armor."
type=3
}
}
}
vampire{
Name="Vampire"
OptionPack="Austin's Pack"
Description="Vampires are associated with necromancy. Their existence is predicated on draining the life from others to fuel their own existence, and on putting their own lives ahead of all other concerns. Philosophically, they do not constrain themselves with artificial rules of morality, but believe that the strong can and should take what they need from the weak."
Size=Medium
Str=0
Dex=0
Con=0
Int=1
Wis=0
Cha=2
Speed=30
FlySpeed=0
SwimSpeed=30
DarkVision=60
SKOC=1
LNOC=1
WPOC=1
LizFolkAC=0
TortAC=0
Languages={"Common"}
LanguageOptions={"Giant""Common""Celestial""Undercommon""Goblin""Dwarvish""Abyssal""Sylvan""Orc""Deep Speech""Primordial""Draconic""Gnomish""Elvish""Halfling""Infernal"}
SkillProf={}
SkillOptions={}
WeaponProf={}
WeaponOptions={}
DamageRes={"necrotic"}
DamageImmun={}
ArmorProf={}
Tools={}
Traits={
{name="Bloodthirst"
description="You can drain blood and life energy from a willing creature, or one that is grappled by you, incapacitated, or restrained. Make a melee attack against the target. If you hit, you deal 1 piercing damage and 1d6 necrotic damage. The target's hit point maximum is reduced by an amount equal to the necrotic damage taken, and you regain hit points equal to that amount. The reduction lasts until the target finishes a long rest. The target dies if this effect reduces its hit point maximum to 0."
type=0
}
{name="Feast of Blood"
description="When you drain blood with your Bloodthirst ability, you experience a surge of vitality. Your speed increases by 10 feet, and you gain advantage on Strength and Dexterity checks and saving throws for 1 minute."
type=3
}
}
}
}
Spells{
baja-blast{
Name="Baja Blast"
OptionPack="Harmony's Pack"
Description="A teal spray of sweet but seemingly corrosive liquid from another universe blasts from your hands or feet. Depending on which you choose, you gain one of the following benefits for the duration: Hands: You can now use an action on each of your turns to force creatures in a 15 foot cone to make a Dexterity saving throw. A creature takes 2d6 acid damage on a failed save, or half as much on a success. Feet: Your long jump is up to 30 feet and your high jump is up to 15 feet, with or without a running start."
School="evocation"
Duration="Concentration, up to 1 minute"
Component="V, S, M (a citrus fruit imbued with magic of some kind)"
CastingTime="1 bonus action"
Range="Self"
Level=1
Verbal=false
Somatic=false
Material=false
Ritual=false
AttackRoll=false
ClassList={}
}
}
}
