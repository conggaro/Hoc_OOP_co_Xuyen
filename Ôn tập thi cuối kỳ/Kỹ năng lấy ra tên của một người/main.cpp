// Yêu cầu:
// 1. lấy ra tên của một người

#include <iostream>
#include <string>
using namespace std;

int main(){
    // fake nhập họ tên
    string ho_ten = "Nguyen Van An";

    // tìm vị trí của dấu cách đầu tiên
    // từ phải qua trái
    int vi_tri = ho_ten.rfind(" ");

    // lấy ra tên
    string ten = ho_ten.substr(vi_tri + 1, ho_ten.length() - 1 - vi_tri);

    // in ra ten
    cout << "ten: " << ten << "\n\n";

    return 0;
}