// Yêu cầu:
// 1. nhập số dòng M 
// 2. nhập số cột N
// 3. nhập giá trị cho k

// 4. in ra giá trị nhỏ nhất tại dòng k
// 5. in ra giá trị lớn nhất tại dòng k

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

    int min = 0;
    int max = 0;

    if(k <= M){
        min = arr[k][0];
        max = arr[k][0];

        for(int i = 0; i < N; i++){
            if(min > arr[k][i]){
                min = arr[k][i];
            }

            if(max < arr[k][i]){
                max = arr[k][i];
            }
        }
    }else{
        min = -1;
        max = -1;
    }

    cout << min << " " << max << endl;

    return 0;
}