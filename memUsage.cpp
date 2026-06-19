#include "memUsage.h"
#include "systemCall.h"

#include <sstream>
#include <thread>

MemInfo MemUsage::getMemInfo() {
    MemInfo memory{};

    std::string memData = execSystemCall_StdString("cat /proc/meminfo");
    std::istringstream stream(memData);

    while(stream >> key) {
        if (key == "MemTotal:") stream >> memory.MemTotal;
        if (key == "MemAvailable:") stream >> memory.MemAvailable;
    }

    return memory;
}

float MemUsage::getUsage() {
    MemInfo info = getMemInfo();
    return (1.0f - ((float)info.MemAvailable / (float)info.MemTotal)) * 100;
}