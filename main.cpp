#include <iostream>
#include <ctime>
#include "SensorData.h"
#include "SensorRules.h"
using namespace std;

SensorData handleExpression(SensorData &data, SensorRules &rules) {
    cparse::calculator c1(rules.expr); // Create calculator based on expression
    cparse::TokenMap vars;
    vars["value"] = data.value;
    vars["previous_value"] = rules.prevValue;
    rules.prevValue = data.value; // Set new previous value

    cparse::packToken temp;
    temp = c1.eval(vars);
    int outputValue = temp.asInt(); // Store calculator output

    time_t currTimeTemp = std::time(nullptr); // Get current time
    int currTime = static_cast<int>(currTimeTemp);

    SensorData output(currTime, rules.labelOut, rules.unitsOut, outputValue); // Create output sensor data object
    return output;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
