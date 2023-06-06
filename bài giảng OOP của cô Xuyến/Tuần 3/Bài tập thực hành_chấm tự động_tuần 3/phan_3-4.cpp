// Yêu cầu:
// 1. nhập vào số nguyên n (n > 0)
// 2. nhập vào n phần tử (phần tử thuộc Z)
// 3. tìm vị trí số dương nhỏ nhất đầu tiên trong dãy

// nếu không có thì trả về -1

#include <iostream>
#define SIZE 500
using namespace std;

// hàm kiểm tra xem mảng có số dương nào không
bool KiemTraSoDuong(int mang[SIZE], int n){
    bool ketQua = false;

    for (int i = 0; i < n; i++)
    {
        if (mang[i] > 0)
        {
            ketQua = true;
            break;
        }        
    }

    return ketQua;
}

// hàm tìm số dương bé nhất
// input: mảng
// output: vị trí số dương bé nhất
int Tim_Index_SoDuongBeNhat(int mang[SIZE], int n){
    int ketQua;
    int min_duong;

    if(KiemTraSoDuong(mang, n) == true){
        for (int i = 0; i < n; i++)
        {
            if (mang[i] > 0)
            {
                min_duong = mang[i];
                ketQua = i;
                break;
            }            
        }

        for (int i = 0; i < n; i++)
        {
            if (mang[i] > 0)
            {
                if (min_duong > mang[i])    
                {
                    min_duong = mang[i];
                    ketQua = i;
                }
            }               
        }   

    }else{
        ketQua = -1;
    }
    
    return ketQua;
}

int main(){
    int n;
    cin >> n;

    int v1[SIZE];

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    
    cout << Tim_Index_SoDuongBeNhat(v1, n) << endl;

    return 0;
}