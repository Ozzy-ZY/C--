#include "functions.h"
using namespace std;

unordered_map<string, string> name_pass;

string string_to_lower(string given){
    string lower = given;
    for(short i =0;i<given.size();i++){
       lower[i] = tolower(given[i]);
    }
    return lower;
}
void normWay(string name){
    string fileName;
    short numOfChars;
    cout<<"__Welcome to passgenOZ__\n enter the filename you want to save your password at: ";
    cin>>fileName;
    cout<<"enter the desired Length: ";
    cin>>numOfChars;
    cout<<"How hard do you want it bae\n*Africa->1\n*America->2\n*Asia->3\n";
    short hardness;
    cin>>hardness;
    if(hardness == 1){
        const string pass = hardPass(numOfChars);
        writeToFile(name,pass, fileName);
    }
    else if (hardness == 2){
        const string pass = midPass(numOfChars);
        writeToFile(name, pass, fileName);
    }
    else if (hardness == 3) {
        const string pass = ezPass(numOfChars);
        writeToFile(name, pass, fileName);
    }
    else
    cout<<"U entered a wrong character!!";
}
void queryway(string name){
    name = string_to_lower(name);
}
int main(int argc,char** argv) {
    if(argc!=3){
        cout<<"Error: please Enter valid arguments\n-q query\n-a newname\n";
        return 0;   
    }
    Fast
    string qr = "-q";
    string add = "-a";
    if(qr.compare(argv[1]) == 0){
        if(!argv[2]){
            cout<<"error: You have to add a query!\n";
            return 0;
        }
        else{
        queryway(argv[2]);
        }
    }
    else if(add.compare(argv[1]) == 0){
        if(!argv[2]){
            cout<<"error: You have to add a name!\n";
            return 0;
        }
        else {
            normWay(argv[2]);
        } 
    }
    else {
    cout<<"Error: please Enter valid arguments\n-q query\n-a newname\n";
    }
    // ADD user experience
    // ADD Query System to get password of the specific account and put it in the clipboard
    return 0;
}
