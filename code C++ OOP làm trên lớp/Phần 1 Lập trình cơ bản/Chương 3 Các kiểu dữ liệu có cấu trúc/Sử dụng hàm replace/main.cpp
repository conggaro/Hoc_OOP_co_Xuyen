#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "abcd1234";
    string str2 = str.replace(2, 1, "OOO");

    // kết quả mong đợi "abOOOd1234"
    cout << str2 << endl;

    return 0;
}