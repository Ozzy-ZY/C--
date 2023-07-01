#include "functions.h"
#include <regex>
#include <string>
using namespace std;
int main(int argc,char** argv) {
    Fast
    string fileName;
    short numOfChars;
    cout<<"__Welcome to passgenOZ__\n enter the filename you want to save your password at: ";
    cin>>fileName;
    cout<<"enter the desired Length: ";
    cin>>numOfChars;
    cout<<"How hard do you want it bae\n Africa->1\n America->2\nAsia->3\n";
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
    // ADD user experience
    // ADD Query System to get password of the specific account and put it in the clipboard
    return 0;
}
