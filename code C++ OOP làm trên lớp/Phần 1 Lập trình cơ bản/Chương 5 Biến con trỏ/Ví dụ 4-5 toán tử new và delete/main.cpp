// Toán tử new
// cấp phát vùng nhớ cho biến con trỏ
// => có thể sử dụng thay cho mảng để tối ưu bộ nhớ

// Toán tử delete
// thu hồi vùng nhớ đã cấp phát cho biến con trỏ

#include <iostream>
using namespace std;

int main(){
    // tạo biến con trỏ
    int *pointer;

    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;

    // cấp phát vùng nhớ
    pointer = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> *(pointer + i);
    }

    // tính tổng các phần tử của p
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong = tong + *(pointer + i);
    }
    
    cout << "Tong cac phan tu: " << tong << "\n\n";
    
    // thu hồi vùng nhớ
    delete[] pointer;

    return 0;
}