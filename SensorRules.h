#include <string>
#include <SensorData.h>
#include "cparse/shunting-yard.h"
using namespace std;
#pragma once

struct SensorRules {
    string name;
    string labelIn;
    string unitsIn;
    char* expr;
    string labelOut;
    string unitsOut;
    int prevValue;
    SensorRules(string n, string lIn, string uIn, char* e, string lOut, string uOut, int pV = 0) {
        name = n;
        labelIn = lIn;
        unitsIn = uIn;
        expr = e;
        labelOut = lOut;
        unitsOut = uOut;
        prevValue = pV;
    }
};
