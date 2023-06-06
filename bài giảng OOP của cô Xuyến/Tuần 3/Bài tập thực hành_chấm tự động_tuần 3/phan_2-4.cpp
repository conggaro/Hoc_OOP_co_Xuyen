// Yêu cầu:
// 1. nhập số n từ bàn phím
// 2. nhập các phần tử a[0] đến a[n-1]
// 3. tìm vị trí đầu tiên của số lớn nhất
// 4. tìm vị trí đầu tiên của số lớn nhất

// 5. in ra "index_of_min" "index_of_max"

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

    int index_of_min = 0;
    int index_of_max = 0;

    for(int i = 0; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(min == arr[i]){
            index_of_min = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(max == arr[i]){
            index_of_max = i;
            break;
        }
    }

    cout << index_of_min << " " << index_of_max << endl;

    return 0;
}