// Yêu cầu:
// 1. tạo mảng kiểu int arr[10]
// 2. tạo mảng kiểu int arr[5] = {1, 2, 3, 4, 5}
// 3. tạo mảng kiểu int arr[] = {2, 4, 6, 8}
// 4. tạo mảng kiểu float mang[3] = {1.2, 8.8, 9.9}
// 5. tạo mảng kiểu string arr_str[3] = {"C++", "OOP", "C#"}

#include <iostream>
#include <random>
using namespace std;

int main(){
    // kiểu 1
    int arr1[10];

    // kiểu 2
    int arr2[5] = {1, 2, 3, 4, 5};

    // truy cập vào phần từ của mảng để in ra màn hình
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        arr1[i] = rand()%10 + 1;
    }
    
    for(int i = 0; i < 10; i++){
        cout << arr1[i] << "\t";
    }
    cout << endl;

    for(int i = 0; i < 5; i++){
        cout << arr2[i] << "\t";
    }
    cout << endl;

    float arr3[5] = {1.1, 1.5, 6.6, 7.5, 9.9};

    // nếu viết như này cũng được
    // nhưng tôi không thích
    int mang[] = {6, 7, 8, 9, 10};

    string arr_str[3] = {"C++", "OOP", "C#"};
    for(int i = 0; i < 3; i++){
        cout << arr_str[i] << " ";
    }
    cout << endl;

    return 0;
}