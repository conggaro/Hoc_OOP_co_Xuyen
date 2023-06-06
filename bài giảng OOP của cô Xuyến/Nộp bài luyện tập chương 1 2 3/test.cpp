// loại bỏ số trùng nhau

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1,1,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    int j = 0;
    for (int i = 1; i < n; i++){
        if(arr[i] != arr[j]){
            arr[++j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
