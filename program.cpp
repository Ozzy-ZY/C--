#include "functions.h"
using namespace std;
#define Fast std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
int main(int argc, char** argv) {
    Fast
    // ADD user experience
    // ADD Query System to get password of the specific account and put it in the clipboard
    string fileName;
    short numOfChars;
    cin>>numOfChars;
    cin>>fileName;
    const string pass = midPass(numOfChars);
    writeToFile(pass,fileName);

    return 0;
}
