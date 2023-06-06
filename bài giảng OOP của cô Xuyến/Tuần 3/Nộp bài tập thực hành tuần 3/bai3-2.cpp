// Yêu cầu:
// 1. cho ma trận N x M (N, M < 100)
// 2. nhập số dòng N
// 3. nhập số cột M
// 4. nhập giá trị cho tất cả phần tử (kiểu int)

// 5. hiển thị dưới dạng ma trận

#include <iostream>
#define SIZE 100
using namespace std;

// hàm tìm số lớn nhất
int Tim_Max(int mang[SIZE][SIZE], int dong, int cot){
    int max = mang[0][0];

    for (int i = 0; i < dong; i++)
    {
        for (int  j = 0; j < cot; j++)
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
    cout << "Nhap vao so dong N: ";
    int N;
    cin >> N;

    cout << "Nhap vao so cot M: ";
    int M;
    cin >> M;

    int arr[SIZE][SIZE];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << "Nhap arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nGia tri lon nhat la: ";
    cout << Tim_Max(arr, N, M);
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        for (int  j = 0; j < M; j++)
        {
            if(Tim_Max(arr, N, M) == arr[i][j]){
                cout << "Vi tri gia tri lon nhat la: ";
                cout << "(" << i << ", " << j << ")";
                cout << endl;
            }
        }               
    }   

    return 0;
}