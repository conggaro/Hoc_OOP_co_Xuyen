// Yêu cầu:
// giáo viên cần xử lý điểm cho học sinh
// số lượng học sinh (10 đến 30)

// 1. nhập m học sinh
// 2. nhập n môn học

// 3. nhập điểm cho cái mảng 2 chiều arr[m][n]

// 4. in ra điểm trung bình của tất cả học sinh

// lấy 1 chữ số sau dấu phẩy thập phân

#include <iostream>
#include <iomanip>
#define SIZE 50
using namespace std;

int main(){
    int m;
    cin >> m;

    int n;
    cin >> n;

    int arr[SIZE][SIZE];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }        
    }

    for (int i = 0; i < m; i++)
    {
        int tong = 0;
        for (int j = 0; j < n; j++)
        {
            tong = tong + arr[i][j];
        }
        float TBC = (float)tong / n;
        cout << fixed << setprecision(1);
        cout << TBC << " ";
    }
    cout << endl;

    return 0;
}