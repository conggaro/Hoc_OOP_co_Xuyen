// Kỹ năng xóa phần tử
// ở vị trí index trong mảng

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

int main(){
    // fake nhập n
    int n = 10;

    // tạo mảng
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // in ra mảng ban đầu
    cout << "Ban dau:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    // nhập vào vị trí index muốn xóa
    cout << "\n\nNhap vi tri index muon xoa: ";
    int index = 0;
    cin >> index;

    // gọi hàm xóa
    Ham_Xoa_PhanTu(arr, n, index);

    // in ra mảng sau khi xóa
    cout << "\nSau khi xoa:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    return 0;
}