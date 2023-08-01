// Yêu cầu:
// 1. chuyển "true" hoặc "1" sang true
// 2. chuyển "false" hoặc "0" sang false

#include <iostream>
using namespace std;

// hàm chuyển string sang bool
bool to_bool(string thamSo){
    bool ketQua = NULL;

    if (thamSo == "true" || thamSo == "1")
    {
        ketQua = true;
    }
    else if (thamSo == "false" || thamSo == "0")
    {
        ketQua = false;
    }    

    return ketQua;
}

int main(){
    // cho "true" và "false"
    string str1 = "true";
    string str2 = "false";

    cout << to_bool(str1) << "\n";
    cout << to_bool(str2) << "\n\n";

    return 0;
}