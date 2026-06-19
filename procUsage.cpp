#include "procUsage.h"
#include "systemCall.h"

#include <sstream>
#include <thread>

long ProcUsage::numbersSum(std::stringstream& ss) {
    long number, sum = 0;
    
    while (ss >> number) {
        sum += number;
    }

    return sum;
}

long ProcUsage::getIdle(const std::string& s) {
    std::stringstream ss(s);
    ss >> user >> nice >> system >> idle;
    return idle;
}

float ProcUsage::getUsage() {
    const std::string cmd = "awk '/^cpu /{print $2,$3,$4,$5,$6,$7,$8}' /proc/stat";
    
    std::string totalStr1 = execSystemCall_StdString(cmd);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::string totalStr2 = execSystemCall_StdString(cmd);
    
    std::stringstream ss1(totalStr1);
    std::stringstream ss2(totalStr2);

    long diffTotal = numbersSum(ss2) - numbersSum(ss1);
    long diffIdle = getIdle(totalStr2) - getIdle(totalStr1);

    if (diffTotal <= 0) return -1.0f;
    return (1.0f - ((float)diffIdle / (float)diffTotal)) * 100;
}