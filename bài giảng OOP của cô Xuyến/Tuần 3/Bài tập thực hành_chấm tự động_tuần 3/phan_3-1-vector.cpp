// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập vào n phần tử
// 3. đếm số lượng số chính phương

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// hàm kiểm tra số chính phương
bool KiemTra_SCP(int thamSo){
    bool ketQua;

    int data = sqrt(thamSo);

    if (pow(data, 2) == thamSo)
    {
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

int main(){
    int n;
    cin >> n;

    vector<int> v1(n);

    for (int i = 0; i < v1.size(); i++)
    {
        cin >> v1[i];
    }
    
    int dem = 0;

    for (int i = 0; i < v1.size(); i++)
    {
        if (KiemTra_SCP(v1[i]) == true)
        {
            dem = dem + 1;
        }
        
    }
    
    cout << dem << endl;

    return 0;
}