#ifndef PASSGEN_FUNCTIONS_H
#define PASSGEN_FUNCTIONS_H
#include <iostream>
#include <random>
#include "ostream"
#include "filesystem"
#include "string"
#include "fstream"

using namespace std;
random_device seed;
#define Fast std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
#define Srengine default_random_engine engine (seed());
string hardPass(short numOfChars){
    Srengine
    uniform_int_distribution<short> randomInt(33,126);
    string pass;
    for(short i =0;i<numOfChars;i++){
        pass += static_cast<char>(randomInt(engine));
    }
    return pass;
}
string midPass(short numOfChars){
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
string ezPass(short numOfChars){
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
void writeToFile(const string& password,const string& fileName){
    filesystem::path currentPath = filesystem::current_path();
    string path = currentPath.string()+"\\"+fileName;
    ofstream vault(path,std::ios::app);
    if(vault.is_open()){
        vault<<password<<endl;
        vault.close();
        cout<<"---Successful---";
    }
    else
        cout<<"***Failed to Open/Create: "<<fileName<<"***";
}
#endif //PASSGEN_FUNCTIONS_H
