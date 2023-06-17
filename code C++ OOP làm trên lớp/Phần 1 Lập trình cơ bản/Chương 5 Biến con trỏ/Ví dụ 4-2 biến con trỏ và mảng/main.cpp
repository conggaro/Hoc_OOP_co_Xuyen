// Yêu cầu:
// 1. sử dụng biến con trỏ để nhập mảng 1 chiều
// 2. in ra màn hình tổng của các phần tử

#include <iostream>
using namespace std;

int main(){
    int *pointer = 0;

    int n = 0;

    int arr[100];

    cout << "Nhap vao so nguyen n: ";
    cin >> n;

    pointer = arr;      // biến con trỏ pointer trỏ vào mảng arr

    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> *(pointer + i);
    }
    
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong = tong + *(pointer + i);
    }
    
    cout << "Tong cac phan tu: " << tong << "\n\n";

    return 0;
}