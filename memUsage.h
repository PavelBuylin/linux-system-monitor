#pragma once

#include <string>

struct MemInfo {
    long MemTotal, MemAvailable;
};

class MemUsage {
private:
    std::string key;
    MemInfo getMemInfo();
public:
    float getUsage();
};