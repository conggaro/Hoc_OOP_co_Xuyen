// Yêu cầu:
// 1. nhập số nguyên dương n (3 <= n <= 9)
// 2. hiển thị tam giác

// n = 5
//     *        1
//    * *       2
//   * * *      3
//  * * * *     4
// * * * * *    5

#include <iostream>
using namespace std;

// hàm vẽ tam giác
// input: n
// output: hình tam giác
void VeTamGiac(int thamSo){
    int k = 1;

    for (int i = 1; i <= thamSo; i++)
    {
        for (; k <= thamSo - i; k++)
        {
            cout << ' ';
        }
        
        if (k > thamSo - i)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << '*' << ' ';
            }    
        }
        cout << endl;
        k = 1;
    }
}

// hàm vẽ hình thoi
// input: n
// output: vẽ hình thoi
void VeHinhThoi(int thamSo){
    int k = 1;

    for (int i = 1; i <= thamSo; i++)
    {
        for (; k <= thamSo - i; k++)
        {
            cout << ' ';
        }
        
        if (k > thamSo - i)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << '*' << ' ';
            }    
        }
        cout << endl;
        k = 1;
    }

    for (int i = thamSo - 1; i >= 1; i--)
    {
        for (; k <= thamSo - i; k++)
        {
            cout << ' ';
        }
        
        if (k > thamSo - i)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << '*' << ' ';
            }            
        }
        cout << endl;
        k = 1;
    }    
}

int main(){
    cout << "nhap vao so nguyen duong n (3 <= n <= 9): ";
    int n;
    cin >> n;

    cout << "\nVE HINH TAM GIAC\n\n";
    VeTamGiac(n);

    cout << "\n\nVE HINH THOI\n\n";
    VeHinhThoi(n);
    cout << endl;

    return 0;
}