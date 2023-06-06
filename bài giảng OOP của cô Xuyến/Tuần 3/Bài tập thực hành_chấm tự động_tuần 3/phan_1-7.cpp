// Yêu cầu:
// 1. nhập số học sinh M (số học sinh trong khoảng 10 đến 30)
// 2. nhập số môn học N

// 3. nhập vào điểm các môn học của học sinh thứ nhất
// 4. nhập vào điểm các môn học của học sinh thứ M

// 5. in ra điểm trung bình cộng

#include <iostream>
#include <iomanip>
#define SIZE 1000
using namespace std;

int main(){
    int M;
    cin >> M;

    int N;
    cin >> N;

    int arr[SIZE][SIZE];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        } 
    }
    
    int tong = 0;
    float TBC = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tong = tong + arr[i][j];
        } 
        
        TBC = (float)tong / N;
        cout << fixed << setprecision(1);
        cout << TBC << " ";

        tong = 0;
        TBC = 0;
    }

    return 0;
}