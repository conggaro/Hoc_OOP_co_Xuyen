// sử dụng \b là lùi trái
// cái \b cũng là backspace

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "Hello\b\bA"; // ồ, ở đây cũng gặp cái "o"

    cout << str << endl;

    return 0;
}