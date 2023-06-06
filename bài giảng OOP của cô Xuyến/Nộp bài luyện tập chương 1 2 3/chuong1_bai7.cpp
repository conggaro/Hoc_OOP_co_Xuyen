// Yêu cầu:
// 1. nhập vào số nguyên dương n (n > 0) và (n < 100000)

// 2. kiểm tra n có phải số đối xứng không
// số đối xứng thì viết từ phải sang trái
// hoặc viết từ trái sang phải thì giá trị không thay đổi

// 3. kiểm tra số nguyên tố

// 4. tính tổng các số nguyên tố nhỏ hơn n

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// hàm kiểm tra đối xứng
// input: n
// output: true hoặc false
bool KiemTra_SoDoiXung(int thamSo){
    bool ketQua;
    int clone = thamSo;
    
    vector<int> v1;

    while (clone != 0)
    {
        v1.push_back(clone % 10);
        clone = clone / 10;
    }

    int soDaoNguoc = 0;
    int cong_cu = 1;

    for (int i = 0; i < v1.size(); i++)
    {
        soDaoNguoc = soDaoNguoc + v1[i]*pow(10, v1.size() - cong_cu);
        cong_cu ++;
    }
    
    if (soDaoNguoc - thamSo == 0)
    {
        ketQua = true;
    }else
    {
        ketQua = false;
    }

    return ketQua;
}

// hàm kiểm tra số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool ketQua;

    int dem = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        if (thamSo % i == 0)
        {
            dem ++;
        }        
    }

    if (dem == 2)
    {
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

// tổng các số nguyên tố nhỏ hơn n
int TinhTong_SNT(int thamSo){
    int ketQua = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        if (KiemTra_SNT(i) == true)
        {
            ketQua = ketQua + i;
        }        
    }    

    return ketQua;
}

int main(){
    cout << "nhap vao 1 so n (0 < n <100000): ";
    int n;
    cin >> n;

    while (n <= 0 || n >= 100000)
    {
        cout << "nhap lai n: ";
        cin >> n;
    }
    
    if(KiemTra_SoDoiXung(n) == true){
        cout << n << " la so doi xung.";
    }else{
        cout << n << " khong phai so doi xung.";
    }
    cout << endl;

    if(KiemTra_SNT(n) == true){
        cout << n << " la so nguyen to.";
    }else{
        cout << n << " khong phai so nguyen to.";
    }
    cout << endl;

    cout << "tong so nguyen to la: " << TinhTong_SNT(n) << endl;

    return 0;
}