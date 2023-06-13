// Mô tả:
// cho màn cờ có kích thước n * m
// n dòng
// m cột

// tại mỗi ô của bàn cờ
// người ta đặt 1 quân cờ có sức mạnh arr[i][j]

// (0 <= i <= n - 1)
// (0 <= j <= m - 1)

// bạn được phép di chuyển từ dòng đầu đến dòng cuối của bàn cờ

// tại mỗi dòng bạn nhận được 1 quân cờ
// có chỉ số sức mạnh lớn nhất trong dòng đó

// Yêu cầu:
// 1. đọc file
// 2. ghi file

// 3. ghi ra tổng sức mạnh các quân cờ mà bạn nhận được
// sau khi di chuyển từ dòng đầu đến dòng cuối của bàn cờ

// FILE INPUT
// dòng 1       --> là 2 số n và m

// n dòng tiếp theo 
// m dòng tiếp theo là chỉ số sức mạnh của m quân cờ tại dòng đó

// FILE OUT
// ghi tổng số sức mạnh nhận được

#include <iostream>
#include <fstream>
#define SIZE 10
using namespace std;

int main(){
    // tạo mảng lưu dữ liệu
    int arr[SIZE][SIZE];

    // tạo n
    int n = 0;

    // tạo m
    int m = 0;

    // tạo đối tượng đọc dữ liệu
    ifstream file_in;
    file_in.open("CHESS.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CHESS.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CHESS.INP THANH CONG\n\n";

        // ghi vào n
        file_in >> n;

        // ghi vào m
        file_in >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                file_in >> arr[i][j];
            }            
        }

        file_in.close();
    }

    // tạo đối tượng ghi file 
    ofstream file_out;
    file_out.open("CHESS.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file CHESS.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file CHESS.OUT THANH CONG\n\n";

        // tìm tong_max theo chiều ngang
        // tìm tong_max theo cả chiều dọc luôn
        int tong_max = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];

        int tong_dong = 0;      // tổng dòng

        // tìm tổng max trong dòng
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < m; j++)
            {
                tong_dong = tong_dong + arr[i][j];
            }

            if (tong_max < tong_dong)
            {
                tong_max = tong_dong;
            }
            tong_dong = 0;
        }
        
        int tong_cot = 0;      // tổng cột

        // tìm tổng max trong cột
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                tong_cot = tong_cot + arr[j][i];
            }

            if (tong_max < tong_cot)
            {
                tong_max = tong_cot;
            }
            tong_cot = 0;
        }

        file_out << tong_max;

        file_out.close();
    }

    return 0;
}