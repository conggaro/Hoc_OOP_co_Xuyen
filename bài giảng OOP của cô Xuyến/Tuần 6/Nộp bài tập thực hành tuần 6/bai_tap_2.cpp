// Yêu cầu:
// 1. nhập vào số nguyên n
// 2. nhập n số từ bàn phím
// 3. đưa ra dãy số đã nhập
// 4. tính tổng các số nguyên dương của dãy số

// Gợi ý:
// 1. sử dụng mảng
// 2. sử dụng vector
// 3. sử dụng con trỏ
// 4. in ra vị trí của các phần tử có giá trị nhỏ nhất
// 5. in ra màn hình các số nguyên khác nhau trong dãy số

// bài toán này thì tôi sử dụng biến con trỏ để code

#include <iostream>
using namespace std;

// hàm nhập dữ liệu
void NhapDuLieu(int *p, int do_dai){
    cout << "\n----------------- NHAP DU LIEU -----------------\n\n";

    for (int i = 0; i < do_dai; i++)
    {
        cout << "p[" << i << "] = ";
        cin >> *(p + i);
    }
}

// hàm hiển thị dữ liệu
void HienThi(int *p, int do_dai){
    cout << "\n----------------- HIEN THI DU LIEU -----------------\n\n";

    for (int i = 0; i < do_dai; i++)
    {
        cout << "p[" << i << "] = " << *(p + i) << "\n";
    }    
}

// hàm tính tổng các số nguyên dương
void TinhTong_SoNguyenDuong(int *p, int do_dai){
    int tong = 0;

    for (int i = 0; i < do_dai; i++)
    {
        if (*(p + i) > 0)
        {
            tong = tong + *(p + i);
        }
    }

    cout << "\n------------- TINH TONG CAC SO NGUYEN DUONG -------------\n\n";
    cout << "tong = " << tong << "\n";
}

// hàm in ra vị trí của các phần tử
// có giá trị nhỏ nhất
void In_Ra_PhanTu_Co_Gia_Tri_NhoNhat(int *p, int do_dai){
    int min = *(p + 0);

    // việc 1:
    // tìm giá trị nhỏ nhất
    for (int i = 0; i < do_dai; i++)
    {
        if (min > *(p + i))
        {
            min = *(p + i);
        }        
    }

    // việc 2:
    // in ra địa chỉ thôi
    cout << "\n--------- VI TRI CUA PHAN TU CO GIA TRI NHO NHAT ---------\n\n";
    for (int i = 0; i < do_dai; i++)
    {
        if (min == *(p + i))
        {
            cout << "index = " << i << "\n";
        }        
    }
}

// hàm xóa phần tử ở vị trí bất kỳ
void Xoa_PhanTu_O_ViTri_BatKy(int *p, int &do_dai, int vi_tri){
    for (int i = vi_tri; i < do_dai; i++)
    {
        *(p + i) = *(p + i + 1);       
    }
    do_dai = do_dai - 1;
}

// hàm in ra màn hình các số nguyên khác nhau trong dãy số
void Ham_In_Ra_SoNguyen_Khac_Nhau(int *p, int &do_dai){
    int index = 0;

    int temp = 0;

    // việc 1:
    // sắp xếp các phần tử theo thứ tự tăng dần
    for (int i = 0; i < do_dai; i++)
    {
        for (int j = i + 1; j < do_dai; j++)
        {
            if (*(p + i) > *(p + j))
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }            
        }        
    }
    
    // việc 2:
    // xóa phần tử trùng nhau
    while (index < do_dai)
    {
        if (*(p + index) == *(p + index + 1))
        {
            Xoa_PhanTu_O_ViTri_BatKy(p, do_dai, index);
        }
        else if (*(p + index) != *(p + index + 1))
        {
            index = index + 1;
        }                
    }
    
    // in ra màn hình các số nguyên khác nhau trong dãy số
    cout << "\n--------- CAC SO NGUYEN KHAC NHAU TRONG DAY SO ---------\n\n";
    for (int i = 0; i < do_dai; i++)
    {
        cout << *(p + i) << "  ";
    }

    cout << "\n";
}

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;

    // tạo con trỏ
    int *pointer;

    // cấp phát vùng nhớ cho con trỏ
    pointer = new int[n];

    // gọi hàm nhập dữ liệu
    NhapDuLieu(pointer, n);

    // gọi hàm hiển thị dữ liệu
    HienThi(pointer, n);

    // gọi hàm tính tổng các số nguyên dương
    TinhTong_SoNguyenDuong(pointer, n);

    // gọi hàm in ra vị trí của các phần tử
    // có giá trị nhỏ nhất
    In_Ra_PhanTu_Co_Gia_Tri_NhoNhat(pointer, n);

    // gọi hàm in ra các số nguyên khác nhau trong dãy số
    Ham_In_Ra_SoNguyen_Khac_Nhau(pointer, n);

    cout << "\n";

    // giải phóng bộ nhớ
    delete[] pointer;

    return 0;
}