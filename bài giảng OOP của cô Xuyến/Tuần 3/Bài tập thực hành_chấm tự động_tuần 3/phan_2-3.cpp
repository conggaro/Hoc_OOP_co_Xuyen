// Yêu cầu:
// 1. nhập số n từ bàn phím
// 2. nhập các phần tử a[0] đến a[n-1]
// 3. tìm số lớn nhất của dãy số
// 4. tìm số nhỏ nhất của dãy số

// 5. in ra min max

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

    int min = arr[0];
    int max = arr[0];

    for(int i = 0; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }

    cout << min << " " << max << endl;

    return 0;
}