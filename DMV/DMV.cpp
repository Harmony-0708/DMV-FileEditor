#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include "TraitType.h"
#include "SizeEnum.h"
#include "Spell.h"
#include "Trait.h"
#include "Race.h"
#include "GUI.h"
#include "harmonylib.h"
#include "Pack.h"
#include "HPack.h"
#include "Orcbrew.h"
#include "CommandObject.h"
#include "Console.h"

//Globals
Console newConsole{};
HPack GlobalPack{};

int main()
{
    newConsole.Run(&GlobalPack);
    return 0;
}
