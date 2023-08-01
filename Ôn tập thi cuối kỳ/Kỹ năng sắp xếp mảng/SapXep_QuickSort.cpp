// Yêu cầu:
// 1. sắp xếp theo thứ tự tăng dần

#include <iostream>
#define SIZE 100
using namespace std;

// hàm phân hoạch, phân vùng
int PhanHoach(int arr[SIZE], int left, int right){
    // tạo biến chốt
    int chot = arr[left];

    int i = left;
    int j = right;

    while (true)
    {
        while (arr[i] < chot)
        {
            i ++;
        }
        
        while (arr[j] > chot)
        {
            j --;
        }
        
        if (i < j)
        {
            int temp = 0;

            // hoán đổi arr[i] và arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i ++;
            j --;
        }
        else if (i >= j)
        {
            return j;
        }
    }
}

// hàm QuickSort
void QuickSort(int arr[SIZE], int left, int right){
    // điều kiện dừng đệ quy
    if (left >= right)
    {
        return;
    }

    // tạo biến vị trí
    int vi_tri = PhanHoach(arr, left, right);
    
    // đệ quy bên trái vi_tri
    QuickSort(arr, left, vi_tri);

    // đệ quy bên phải vi_tri
    QuickSort(arr, vi_tri + 1, right);
}

int main(){
    // fake nhập n
    int n = 10;

    // tạo mảng
    int arr[SIZE] = {6, 1, 2, 7, 8, 9, 3, 4, 10, 5};

    // in ra mảng ban đầu
    cout << "Ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    // gọi hàm sắp xếp QuickSort
    QuickSort(arr, 0, n - 1);

    // in ra mảng sau khi sap xếp
    cout << "\n\nSau khi sap xep (QuickSort):\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    return 0;
}