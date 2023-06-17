// Yêu cầu:
// 1. tạo hàm nhập n số nguyên
// nhập luôn n phần tử

// 2. in ra n phần tử đã nhập

// 3. đếm số nguyên tố trong dãy đã nhập

#include <iostream>
using namespace std;

// hàm nhập dữ liệu
void NhapDuLieu(int *p, int n){
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> *(p + i);
    }    
}

// hàm hiển thị dữ liệu
void HienThi(int *p, int n){
    cout << "\n-------------------- HIEN THI DU LIEU --------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = " << *(p + i) << "\n";
    }
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
    }
    else
    {
        ketQua = false;
    }    

    return ketQua;
}

// hàm đếm số nguyên tố
void Dem_SNT(int *p, int n){
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SNT(*(p + i)) == true)
        {
            dem ++;
        }        
    }
    
    cout << "\n-------------------- DEM SO NGUYEN TO --------------------\n";

    cout << "Co " << dem << " so nguyen to." << "\n\n";
}

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n = 0;
    cin >> n;

    // tạo biến con trỏ
    int *pointer = 0;

    // cấp phát vùng nhớ
    pointer = new int[n];

    // gọi hàm nhập dữ liệu
    NhapDuLieu(pointer, n);

    // gọi hàm hiển thị dữ liệu
    HienThi(pointer, n);

    // gọi hàm đếm số nguyên tố
    Dem_SNT(pointer, n);

    // thu hồi vùng nhớ
    delete[] pointer;

    return 0;
}