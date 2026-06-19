#pragma once
#include <string>
#include <functional>

class ProcUsage {
private:
    long user, nice, system, idle;
    long numbersSum(std::stringstream& ss);
    long getIdle(const std::string& s);    
public:
    float getUsage();
};