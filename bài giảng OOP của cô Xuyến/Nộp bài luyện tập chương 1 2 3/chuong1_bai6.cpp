// Yêu cầu:
// 1. nhập số nguyên dương n
// 2. 3 <= n và n <=9

// hiển thị tam giác số như hình sau với n = 5

// 1
// 22
// 333
// 4444
// 55555

#include <iostream>
using namespace std;

// hàm vẽ hình tam giác 1
void VeTamGiac_1(int thamSo){
    int dem = 0;
    for (int i = 1; i <= thamSo; i++)
    {
        dem ++;
        for (int j = 1; j <= i; j++)
        {
            cout << dem;
        }
        cout << endl;        
    }    
}

// hàm vẽ hình tam giác 2
void VeTamGiac_2(int thamSo){
    int dem = 0;

    int k = 1;

    for (int i = 1; i <= thamSo; i++)
    {
        dem ++;
        for (; k <= thamSo - i; k++)
        {
            cout << ' ';
        }
        
        if(k > thamSo - i){
            for (int j = 1; j <= i; j++)
            {
                cout << dem;
            }
        }        
        cout << endl;
        k = 1;        
    }    
}

int main(){
    cout << "nhap so nguyen n:";
    int n;
    cin >> n;

    VeTamGiac_1(n);

    cout << "\n\n";
    VeTamGiac_2(n);

    return 0;
}