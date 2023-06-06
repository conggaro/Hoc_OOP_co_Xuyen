#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1 = "123456";
    string str2 = str1.insert(2, "abc");

    // mong đợi kết quả 12abc3456
    cout << str2 << endl;

    return 0;
}