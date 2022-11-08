#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include "HPack.h"
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
