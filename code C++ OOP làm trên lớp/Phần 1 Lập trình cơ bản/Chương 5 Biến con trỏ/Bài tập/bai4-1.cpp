// Yêu cầu:
// 1. nhập vào n
// 2. nhập n phần tử
// 3. tính tổng các phần tử chia hết cho 2 và 3
// 4. in tổng ra màn hình

#include <iostream>
using namespace std;

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;

    // tạo biến con trỏ
    int *pointer;

    // cấp phát vùng nhớ
    pointer = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> *(pointer + i);
    }
    
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(pointer + i) % 2 == 0 && *(pointer + i) % 3 == 0)
        {
            tong = tong + *(pointer + i);
        }        
    }
    
    cout << "Tong = " << tong << "\n\n";

    // thu hồi vùng nhớ
    delete[] pointer;

    return 0;
}