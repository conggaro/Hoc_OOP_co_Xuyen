#include <iostream>
#include <string>
using namespace std;

int main(){
    string str_cha = "abcdefghijk";

    string str_con = str_cha.substr(2, 4); // mong đợi cdef
    cout << str_con << endl; // đúng là cdef luôn

    return 0;
}