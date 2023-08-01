// Yêu cầu:
// 1. sắp xếp theo thứ tự tăng dần

#include <iostream>
#define SIZE 100
using namespace std;

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

    // tạo biến temp
    int temp = 0;

    // giải thuật sắp xếp nổi bọt
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // in ra mảng sau khi sap xếp
    cout << "\n\nSau khi sap xep:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n";

    return 0;
}