#pragma once
#ifndef PASSGEN_FUNCTIONS_H
#define PASSGEN_FUNCTIONS_H

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;
#define Fast std::ios_base::sync_with_stdio(false);
#define Srengine default_random_engine engine (seed());
random_device seed;

inline string getCurrentTime() {
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm timeInfo;
    // Use localtime_s on Windows, which is safer
#if defined(_WIN32)
    if (localtime_s(&timeInfo, &currentTime) != 0) {
        // Handle the error if localtime_s fails
        return "00:00:00"; // Return a default time or handle the error differently
    }
#else
    // On non-Windows platforms, use the traditional localtime
    timeInfo = *localtime(&currentTime);
#endif
    ostringstream time;
    time << setfill('0');
    time << setw(2) << timeInfo.tm_hour << ":" << setw(2) << timeInfo.tm_min << ":"
        << setw(2) << timeInfo.tm_sec;

    return time.str();
}

inline string hardPass(short numOfChars) {
    Srengine
        uniform_int_distribution<short> randomInt(33, 126);
    string pass;
    for (short i = 0; i < numOfChars; i++) {
        pass += static_cast<char>(randomInt(engine));
    }
    return pass;
}

inline string midPass(short numOfChars) {
    Srengine
        uniform_int_distribution<short> randomInt1(48, 57);
    uniform_int_distribution<short> randomInt2(97, 100);

    string pass;
    int rem = numOfChars - (numOfChars / 2);
    for (short i = 0; i < numOfChars / 2; i++) {
        pass += static_cast<char>(randomInt1(engine));
    }
    for (int i = 0; i < rem; i++) {
        pass += static_cast<char>(randomInt2(engine));
    }
    return pass;
}

inline string ezPass(short numOfChars) {
    Srengine
        uniform_int_distribution<short> randomInt1(48, 53);
    uniform_int_distribution<short> randomInt2(56, 57);
    string pass;
    int rem = numOfChars - (numOfChars / 2);
    for (short i = 0; i < numOfChars / 2; i++) {
        pass += static_cast<char>(randomInt1(engine));
    }
    for (int i = 0; i < rem; i++) {
        pass += static_cast<char>(randomInt2(engine));
    }
    return pass;
}

inline void writeToFile(const string& name, const string& password, const string& fileName) {
    fs::path currentPath = fs::current_path();
    fs::path path = currentPath / fileName;

    ofstream vault(path.string(), ios::app);
    if (vault.is_open()) {
        vault << name << " " << password << "  Generated at=>> " << getCurrentTime() << endl;
        vault.close();
        cout << "---Successful---";
    }
    else
        cout << "***Failed to Open/Create: " << fileName << "***";
}

#endif

