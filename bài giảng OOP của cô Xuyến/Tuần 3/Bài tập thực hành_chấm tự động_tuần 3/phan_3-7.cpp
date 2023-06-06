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

// hàm tìm phần tử nhỏ nhất
// input: ma trận, m, n
// output: số nhỏ nhất
int Tim_Min(int mang[SIZE][SIZE], int m, int n){
    int min = mang[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > mang[i][j])
            {
                min = mang[i][j];
            }            
        }        
    }

    return min;
}

// hàm tìm phần tử lớn nhất
// input: ma trận, m, n
// output: số lớn nhất
int Tim_Max(int mang[SIZE][SIZE], int m, int n){
    int max = mang[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < mang[i][j])
            {
                max = mang[i][j];
            }            
        }        
    }

    return max;
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

    cout << Tim_Min(arr, m, n) << " ";
    cout << Tim_Max(arr, m, n) << endl;

    return 0;
}