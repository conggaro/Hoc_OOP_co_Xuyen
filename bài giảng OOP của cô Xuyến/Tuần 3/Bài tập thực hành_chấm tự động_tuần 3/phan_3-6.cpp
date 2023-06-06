// Yêu cầu:
// 1. nhập vào số nguyên m
// 2. nhập vào số nguyên n

// in ra ma trận hoán vị

#include <iostream>
#define SIZE 50
using namespace std;

// hàm nhập dữ liệu
void Nhap_Du_lieu(int mang[SIZE][SIZE], int dong, int cot){
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cin >> mang[i][j];
        }        
    }    
}

int main(){
    // dòng
    int m;
    cin >> m;

    // cột
    int n;
    cin >> n;

    int arr[SIZE][SIZE];

    Nhap_Du_lieu(arr, m, n);

    // ma trận hoán vị
    int arr2[SIZE][SIZE];

    // code hoán vị
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[j][i] = arr[i][j];
        }
    }
    
    // code hiển thị
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}