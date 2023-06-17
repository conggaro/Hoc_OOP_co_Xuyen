// Yêu cầu:
// 1. sử dụng biến con trỏ và hàm
// 2. tức là truyền địa chỉ vào trong hàm đấy

#include <iostream>
using namespace std;

int cong_2_so(int *bien1, int bien2){
    *bien1 = *bien1 + 2;
    bien2 = bien2 + 4;
    return *bien1 + bien2;
}

int main(){
    int a = 15;
    int b = 20;

    int c = cong_2_so(&a, b);       // gọi hàm cộng 2 số
    
    cout << "a la: " << a << "\n";
    cout << "b la: " << b << "\n";
    cout << "Tong cua a + b la: " << c << "\n\n";

    return 0;
}