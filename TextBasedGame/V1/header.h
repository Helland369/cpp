// #pragma once
#ifndef HEADER_H
#define HEADER_R

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>

// Linux problems...
void Sleeps(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// sysm pause linux problems.
void Pause() {
    std::system("read -p 'Press Enter to continue...' var");
}

#endif
