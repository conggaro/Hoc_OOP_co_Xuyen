// Yêu cầu:
// 1. Nhập vào 2 số tự nhiên a, b
// 2. Tìm ước chung lớn nhất của a và b

// Sử dụng thuật toán Euclid

#include <iostream>
using namespace std;

int main(){
    cout << "Nhap vao 2 so tu nhien: " << endl;
    int a, b;
    cin >> a >> b;

    int data_a = a, data_b = b;

    while(a<=0 || b<=0){
        cout << "Nhap lai 2 so tu nhien: " << endl;
        cin >> a >> b;
    }

    while (a != 0 && b != 0)
    {
        if(a > b){
            a = a % b;
        }else if(a <= b){
            b = b % a;
        }
    }

    if(a == 0){
        cout << "UCLN(" << data_a << ", " << data_b << ") = " << b << endl;
    }else if(b == 0){
        cout << "UCLN(" << data_a << ", " << data_b << ") = " << a << endl;
    }
    
    return 0;
}