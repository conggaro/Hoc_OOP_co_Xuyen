// độ dài xâu thì sử dụng .length()

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "Welcome";

    cout << "Do dai xau la: " << str.length() << endl;
    
    string b = "Wel\vcome";
    cout << b << endl;

    return 0;
}