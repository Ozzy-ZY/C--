#include "functions.h"
#include <cctype>
using namespace std;

unordered_map<string, string> name_pass;

string string_to_lower(string given){
    string lower = given;
    for(short i =0;i<given.size();i++){
       lower[i] = tolower(given[i]);
    }
    return lower;
}
void normWay(){
    string fileName;
    short numOfChars;
    string platform;
    cout<<"__Welcome to passgenOZ__\n enter the filename you want to save your password at: ";
    cin>>fileName;
    cout<<"For what do you want this password: ";
    cin>>platform;
    cout<<"enter the desired Length: ";
    cin>>numOfChars;
    cout<<"How hard do you want it bae\n*Africa->1\n*America->2\n*Asia->3\n";
    short hardness;
    cin>>hardness;
    if(hardness == 1){
        const string pass = hardPass(numOfChars);
        writeToFile(pass, fileName);
    }
    else if (hardness == 2){
        const string pass = midPass(numOfChars);
        writeToFile(pass, fileName);
    }
    else if (hardness == 3) {
        const string pass = ezPass(numOfChars);
        writeToFile(pass, fileName);
    }
    else
    cout<<"U entered a wrong character!!";
}
void queryway(){

}
int main(int argc,char** argv) {
    Fast
    if(argc == 1){
        normWay();
    }
    else {
        queryway();
    }
    // ADD user experience
    // ADD Query System to get password of the specific account and put it in the clipboard
    return 0;
}
