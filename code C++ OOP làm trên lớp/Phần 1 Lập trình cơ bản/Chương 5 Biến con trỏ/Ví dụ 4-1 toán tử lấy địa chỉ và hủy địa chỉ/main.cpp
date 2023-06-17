// Toán tử lấy địa chỉ "&"

// Toán tử hủy địa chỉ "*"

#include <iostream>
using namespace std;

int main(){
    int y;          // tạo biến bình thường

    int *yPtr;      // tạo biến con trỏ

    y = 10;

    yPtr = &y;

    cout << "Dia chi cua y: " << &y << "\n";
    cout << "Gia tri cua y: " << y << "\n\n";

    cout << "Gia tri cua yPtr: " << yPtr << "\n";
    cout << "Gia tri ma yPtr lay duoc: " << *yPtr << "\n\n";

    return 0;
}