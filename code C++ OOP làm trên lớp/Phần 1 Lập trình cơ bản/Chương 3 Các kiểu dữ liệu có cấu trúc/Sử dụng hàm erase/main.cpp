#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "abcd1234";
    string str2 = str.erase(2, 4);

    // kết quả mong đợi "ab34"
    cout << str2 << endl;

    return 0;
}