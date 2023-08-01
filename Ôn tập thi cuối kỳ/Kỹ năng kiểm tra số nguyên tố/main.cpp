// Yêu cầu:
// 1. nhập n
// 2. kiểm tra n có phải số nguyên tố không

// số 1 không phải số nguyên tố

// số nguyên tố kiểu
// 2, 3, 5, 7, 11, 13, 17, ...

#include <iostream>
#include <cmath>
using namespace std;

// hàm kiểm tra số nguyên tố
bool Ham_KiemTra_SoNguyenTo(int thamSo){
    if (thamSo < 2)
    {
        return false;
    }
    else if (thamSo >= 2)
    {
        for (int i = 2; i <= sqrt(thamSo); i++)
        {
            if (thamSo % i == 0)
            {
                return false;
            }            
        }
        
        return true;
    }    
}

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n = 0;
    cin >> n;

    if (Ham_KiemTra_SoNguyenTo(n) == true)
    {
        cout << "Ket qua: " << n << " la so nguyen to\n\n";
    }
    else
    {
        cout << "Ket qua: " << n << " khong phai so nguyen to\n\n";
    }

    return 0;
}