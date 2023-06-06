#include <iostream>
#include <vector>
using namespace std;

int main(){
    // khai báo vector kiểu 1
    vector<int> v1;
    vector<float> v2;
    vector<string> v3;

    // khai báo vector kiểu 2
    vector<int> v4(4); // 4 phần tử
    vector<float> v5(10); // 10 phần tử
    vector<string> v6(40); // 40 phần tử

    // khai báo vector kiểu 3
    vector<int> v7(100, 1); // có 100 phần tử, tất cả điền số 1

    // khai báo vector kiểu 4
    vector<int> v8 = {1, 2, 3, 4, 5};

    // khai báo vector kiểu 5
    vector<int> v9(5);
    v9 = {6, 7, 8, 9, 10};

    return 0;
}