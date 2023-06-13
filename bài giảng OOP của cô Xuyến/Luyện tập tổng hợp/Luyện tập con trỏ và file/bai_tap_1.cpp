// Yêu cầu:
// 1. nhập n
// 2. nhập n số nguyên
// 3. in ra số đã nhập

#include <iostream>
using namespace std;

// hàm nhập dữ liệu
void NhapDuLieu(int *p, int n){
    cout << "\n----------------- NHAP DU LIEU -----------------\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap p[" << i << "] = ";
        cin >> *(p + i);
    }    
    cout << "\n";
}

// hàm hiển thị
void HienThi(int *p, int n){
    cout << "\n----------------- HIEN THI DU LIEU -----------------\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "p[" << i << "] = " << *(p + i) << "\n";
    }
    cout << "\n";
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

// hàm tính tổng số nguyên tố
void TinhTong_SNT(int *p, int n){
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SNT(*(p + i)))
        {
            tong = tong + *(p + i);
        }        
    }
    
    cout << "\n----------------- TINH TONG SO NGUYEN TO -----------------\n\n";
    cout << "tong = " << tong << "\n";
}

// hàm nhân đôi phần tử ở vị trí k
void NhanDoi(int *p, int n){
    cout << "\n----------------- NHAN DOI PHAN TU -----------------\n\n";
    cout << "Nhap vi tri \"k\": ";
    int k;
    cin >> k;

    *(p + k) = *(p + k) * 2;

    cout << "Phan tu o vi tri \"k\" sau khi x2 la: ";
    cout << "p[" << k << "] = " << *(p + k) << "\n";
}

int main(){
    // nhập n
    cout << "Nhap so nguyen n: ";
    int n;
    cin >> n;

    // tạo biến con trỏ
    int *pointer = 0;

    // cấp phát vùng nhớ
    pointer = new int[n];

    // gọi hàm nhập dữ liệu
    NhapDuLieu(pointer, n);

    // gọi hàm hiển thị dữ liệu
    HienThi(pointer, n);

    // gọi hàm tính tổng
    TinhTong_SNT(pointer, n);

    // gọi hàm x2 phần tử ở vị trí thứ "k"
    NhanDoi(pointer, n);

    // thu hồi vùng nhớ
    delete[] pointer;

    cout << "\n";

    return 0;
}