#include <iostream>
#define SIZE 50
using namespace std;

int main(){
    cout << "Nhap vao do dai n: ";
    int n = 0;
    cin >> n;

    int arr[SIZE];

    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << endl << "Hien thi mang vua nhap:\n";
    for(int i = 0; i < n; i++){
        cout << "arr[" << i << "] = " << arr[i];
        cout << endl;
    }

    return 0;
}