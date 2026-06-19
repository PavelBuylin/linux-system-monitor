#include "procUsage.h"
#include "memUsage.h"

#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    ProcUsage proc;
    MemUsage mem;
    while (true) {
        float procUsage = proc.getUsage();

        if (procUsage >= 0) {
            std::ofstream fCPU("/tmp/cpu_usage.txt");
            fCPU << std::fixed << std::setprecision(2) << procUsage;
        }

        float memUsage = mem.getUsage();

        if (memUsage >= 0) {
            std::ofstream fRAM("/tmp/ram_usage.txt");
            fRAM << std::fixed << std::setprecision(2) << memUsage;
        }
    }

    return 0;
}