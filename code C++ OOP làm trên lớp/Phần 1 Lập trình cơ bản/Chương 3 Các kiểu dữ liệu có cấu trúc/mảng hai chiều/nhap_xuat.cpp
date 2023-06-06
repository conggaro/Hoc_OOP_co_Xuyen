// Yêu cầu:
// 1. nhập vào 2 số M, N nhưng M, N phải bé hơn hoặc bằng DONG, COT
// 2. tạo mảng 2 chiều

#include <iostream>
#define DONG 50
#define COT 50
using namespace std;

int main(){
    cout << "Nhap vao so dong (dong <= 50): ";
    int M;
    cin >> M;

    cout << "Nhap vao so cot (cot <= 50): ";
    int N;
    cin >> N;

    int arr[DONG][COT];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }

    cout << endl << "Hien thi mang:\n";
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << "arr[" << i << "][" << j << "] = ";
            cout << arr[i][j] << endl;
        }
    }

    return 0;
}