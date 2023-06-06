#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "Hello Blue";
    cout << str << endl;

    string str2 = "Hello \rBlue"; // tự nhiên kết quả kiểu Blueo --> lạ ghê
    cout << str2 << endl;

    return 0;
}