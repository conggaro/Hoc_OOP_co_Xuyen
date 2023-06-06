// Yêu cầu:
// 1. nhập từ bàn phím số nguyên n
// 2. nhập dãy số a[0] đến a[n-1]
// 3. sắp xếp dãy số theo thứ tự tăng dần

#include <iostream>
#define SIZE 1000
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[SIZE];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}