// Yêu cầu:
// 1. nhập số dòng M 
// 2. nhập số cột N

// 3. tạo ma trận "maTran1"
// 4. tạo ma trận "maTran2"

// 5. tạo ma trận 3 = maTran1 + maTran2

#include <iostream>
#define SIZE 100
using namespace std;

int main(){
    int M;
    cin >> M;

    int N;
    cin >> N;

    int maTran1[SIZE][SIZE];
    int maTran2[SIZE][SIZE];
    int maTran3[SIZE][SIZE];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maTran1[i][j];
        } 
    }
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maTran2[i][j];
        } 
    }

    // code tính tổng
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            maTran3[i][j] = maTran1[i][j] + maTran2[i][j];
            cout << maTran3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}