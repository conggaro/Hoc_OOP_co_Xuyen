#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "abcd1234";

    int vi_tri = str.find("d1", 0);

    cout << vi_tri << endl;

    return 0;
}