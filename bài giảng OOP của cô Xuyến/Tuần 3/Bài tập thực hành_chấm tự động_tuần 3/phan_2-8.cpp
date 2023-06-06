// Yêu cầu:
// 1. nhập số dòng M 
// 2. nhập số cột N
// 3. nhập giá trị cho k

// 4. in ra tổng các số trên dòng k
// 5. in ra tổng các số trên cột k

// nếu k >= dòng M thì in ra 0
// nếu k >= cột N thì in ra 0

// cú pháp "tổng_cột" "tổng_dòng"

#include <iostream>
#define SIZE 100
using namespace std;

int main(){
    int M;
    cin >> M;

    int N;
    cin >> N;

    int k;
    cin >> k;

    int arr[SIZE][SIZE];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        } 
    }

    int tong_cot = 0;
    int tong_dong = 0;

    // tính tổng cột
    if(k >= N){
        tong_cot = 0;
    }else{
        for (int i = 0; i < M; i++)
        {
            tong_cot = tong_cot + arr[i][k];
        }
    }

    // tính tổng dòng
    if(k >= M){
        tong_dong = 0;
    }else{
        for (int i = 0; i < N; i++)
        {
            tong_dong = tong_dong + arr[k][i];
        }
    }

    cout << tong_cot << " " << tong_dong << endl;

    return 0;
}