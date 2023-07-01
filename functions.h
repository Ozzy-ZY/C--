#pragma once
#ifndef PASSGEN_FUNCTIONS_H
#define PASSGEN_FUNCTIONS_H
#if defined(_WIN32)
    #include <windows.h>
#elif defined(__APPLE__)
    #include <ApplicationServices/ApplicationServices.h>
#elif defined(__linux__)
    #include <unistd.h>
    #include <fcntl.h>
    #include <cstring>
#endif
#include <iostream>
#include <random>
#include "ostream"
#include "filesystem"
#include "string"
#include "fstream"
#include "ctime"
#include <chrono>

using namespace std;
random_device seed;
#define Fast std::ios_base::sync_with_stdio(false);
#define Srengine default_random_engine engine (seed());

inline string getCurrentTime() {
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* timeInfo = localtime(&currentTime);

    ostringstream time;
    time << setfill('0');
    time << setw(2) << timeInfo->tm_hour << ":"<< setw(2) << timeInfo->tm_min << ":"
    << setw(2) << timeInfo->tm_sec;

    return time.str();
}
inline string hardPass(short numOfChars){
    Srengine
    uniform_int_distribution<short> randomInt(33,126);
    string pass;
    for(short i =0;i<numOfChars;i++){
        pass += static_cast<char>(randomInt(engine));
    }
    return pass;
}
inline string midPass(short numOfChars){
    Srengine
    uniform_int_distribution<short>randomInt1(48,57);
    uniform_int_distribution<short>randomInt2(97,100);
    
    string pass;
    int rem = numOfChars - (numOfChars / 2);
    for(short i = 0 ; i < numOfChars / 2 ; i++){
        pass += static_cast<char>(randomInt1(engine));
    }
    for(int i = 0; i < rem ; i++){
        pass+=static_cast<char>(randomInt2(engine));
    }
    return pass;
}
inline string ezPass(short numOfChars){
    Srengine
    uniform_int_distribution<short>randomInt1(48,53);
    uniform_int_distribution<short>randomInt2(56,57);
    string pass;
    int rem = numOfChars - (numOfChars / 2);
    for(short i = 0 ; i <numOfChars / 2 ; i++){
        pass += static_cast<char>(randomInt1(engine));
    }
    for(int i = 0; i < rem ; i++){
        pass+=static_cast<char>(randomInt2(engine));
    }
    return pass;
}
inline void writeToFile(const string& password,const string& fileName){
    filesystem::path currentPath = filesystem::current_path();
    #if defined (__linux__)
        string path = currentPath.string()+"/"+fileName;
    #elif defined(_WIN32)
            string path = currentPath.string()+"\\"+fileName;
    #elif defined (__APPLE__)
        string path = currentPath.string()+"/"+fileName;
    #endif
    ofstream vault(path, ios::app);
    if(vault.is_open()){
        vault<<password<<"  Generated at=>> "<<getCurrentTime()<<endl;
        vault.close();
        cout<<"---Successful---";
    }
    else
        cout<<"***Failed to Open/Create: "<<fileName<<"***";
}
#endif 
