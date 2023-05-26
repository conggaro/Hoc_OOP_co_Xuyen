// Yêu cầu:
// 1. Nhập vào 1 số nguyên N
// 2. Tính tổng các chữ số trong biểu diễn thập phân của N

#include <iostream>
using namespace std;

int main(){
    int khoi_tao = 0;

    cout << "Nhap vao mot so nguyen N: ";
    int N;
    cin >> N;

    while (N < 0)
    {
        cout << "Hay nhap lai: ";
        cin >> N;
    }
    
    // chỉ cần N khác 0 là true 
    // thì sẽ thực hiện các phép toán bên trong while()
    while (N != 0)
    {
        khoi_tao = khoi_tao + (N % 10);
        N = N / 10;
    }

    cout << "Tong cac chu so cua so nguyen N la: " << khoi_tao << endl;
    
    return 0;
}