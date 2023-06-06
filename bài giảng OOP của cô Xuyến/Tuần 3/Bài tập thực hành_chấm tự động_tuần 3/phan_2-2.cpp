// Yêu cầu:
// 1. nhập từ bàn phím số nguyên n
// 2. nhập từ bàn phím số nguyên x
// 3. nhập dãy số a[0] đến a[n-1]

// 4. có bao nhiêu số lớn hơn x

#include <iostream>
#define SIZE 1000
using namespace std;

int main(){
    int n;
    cin >> n;

    int x;
    cin >> x;

    int arr[SIZE];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > x){
            dem ++;
        }
    }

    cout << dem;

    return 0;
}