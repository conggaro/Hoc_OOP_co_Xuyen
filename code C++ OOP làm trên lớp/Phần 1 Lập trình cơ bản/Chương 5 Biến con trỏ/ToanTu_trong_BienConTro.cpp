// Toán tử trong biến con trỏ

// lấy giá trị của biến con trỏ:
// --> sử dụng toán tử "*"

// lấy địa chỉ của 1 biến bình thường
// --> sử dụng toán tử "&"

// biến con trỏ thì chỉ dùng để lưu địa chỉ thôi

#include <iostream>
using namespace std;

int main(){
    int *pointer = 0;

    int x = 10;

    pointer = &x;       // gán địa chỉ của x cho BIẾN CON TRỎ

    cout << "Dia chi cua x la: " << pointer << "\n";
    cout << "Gia tri cua x la: " << *pointer << "\n\n";

    return 0;
}