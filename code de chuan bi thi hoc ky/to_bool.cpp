// yêu cầu:
// 1. chuyển từ string sang bool

#include <iostream>
#include <string>
using namespace std;

bool to_bool(string thamSo){
    bool ketQua;

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
    // fake nhập vào 1 chuỗi
    string data1 = "true";
    string data2 = "1";

    string data3 = "false";
    string data4 = "0";

    cout << to_bool(data1) << "\n\n";
    cout << to_bool(data2) << "\n\n";
    cout << to_bool(data3) << "\n\n";
    cout << to_bool(data4) << "\n\n";

    return 0;
}