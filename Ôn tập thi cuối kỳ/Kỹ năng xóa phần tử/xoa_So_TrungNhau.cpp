// Yêu cầu:
// 1. xóa số bị trùng nhau trong mảng

#include <iostream>
#define SIZE 100
using namespace std;

// hàm xóa phần tử ở vị trí index
void Ham_Xoa_PhanTu(int arr[SIZE], int &n, int index){
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    n --;
}

// hàm xóa phần tử
// bị trùng nhau trong mảng
void Xoa_PhanTu_TrungNhau(int arr[SIZE], int &n){
    int i = 0;

    for (; i <= n - 2;)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                Ham_Xoa_PhanTu(arr, n, j);
            }
        }

        if (arr[i] != arr[i + 1])
        {
            i ++;
        }
    }
}

int main(){
    // fake nhập n
    int n = 16;

    // tạo mảng
    int arr[SIZE] = {6, 1, 2, 7, 5, 5, 5, 8, 9, 5, 3, 4, 10, 5, 5, 5};

    // in ra mảng ban đầu
    cout << "Ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // gọi hàm xóa phần tử trùng nhau
    Xoa_PhanTu_TrungNhau(arr, n);

    // in ra mảng sau khi xóa
    cout << "\n\nSau khi xoa:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    return 0;
}