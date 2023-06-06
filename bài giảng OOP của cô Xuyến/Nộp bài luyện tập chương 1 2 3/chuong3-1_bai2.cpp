// Yêu cầu:
// 1. nhập m dòng
// 2. nhập n cột
// 3. nhập phần tử cho mảng 2 chiều
// 4. in ra mảng vừa nhập

// 5. tính tổng các phần tử của mảng
// 6. tính tổng dòng thứ k ("k" nhập từ bàn phím)
// 7. tính tổng cột thứ k
// 8. đếm số lượng cái số nguyên tố trong mảng

// 9. sắp xếp dòng k theo chiều không giảm (là tăng dần)
// hiển thị ra màn hình

// 10. hoán đổi dòng và cột
// in ra màn hình
// --> gọi là ma trận chuyển vị

#include <iostream>
#define SIZE 50
using namespace std;

// kiểm tra số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool ketQua;
    int dem = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        if(thamSo % i == 0){
            dem ++;
        }
    }
    
    if(dem == 2){
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

// hàm chuyển vị mảng 2 chiều (ma trận)
// input: mảng, m, n
// output: mảng đã bị chuyển vị
void HamChuyenVi(int mang[SIZE][SIZE], int m_, int n_){
    int chuyen_vi = 0;
    
    if(m_ <= n_){        
        for (int i = 0; i < m_; i++)
        {
            for (int j = i; j < n_; j++)
            {
                chuyen_vi = mang[i][j];
                mang[i][j] = mang[j][i];
                mang[j][i] = chuyen_vi;
            }
        }
    }else if (m_ > n_)
    {
        for (int i = 0; i < n_; i++)
        {
            for (int j = i; j < m_; j++)
            {
                chuyen_vi = mang[j][i];
                mang[j][i] = mang[i][j];
                mang[i][j] = chuyen_vi;
            }
        }
    }
    
}

int main(){
    cout << "nhap m dong: ";
    int m;
    cin >> m;

    cout << "nhap n cot: ";
    int n;
    cin >> n;

    int arr[SIZE][SIZE];

    cout << "\nnhap phan tu cho mang:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }        
    }
    
    cout << "\nmang vua nhap la:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }   
        cout << endl;
    }

    cout << "\ntong cac phan tu cua mang la: ";
    int tong1 = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tong1 = tong1 + arr[i][j];
        }        
    }
    cout << tong1 << endl;

    cout << "\nnhap vao so nguyen k (k >= 0): ";
    int k;
    cin >> k;

    cout << "\ntong dong thu " << k <<" la: ";
    int tong_dong_k = 0;
    for (int i = 0; i < n; i++)
    {
        tong_dong_k = tong_dong_k + arr[k][i];
    }
    cout << tong_dong_k << endl;

    cout << "\ntong cot thu " << k <<" la: ";
    int tong_cot_k = 0;
    for (int i = 0; i < m; i++)
    {
        tong_cot_k = tong_cot_k + arr[i][k];
    }
    cout << tong_cot_k << endl;

    int dem_SNT = 0;
    cout << "\ntrong mang co: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(KiemTra_SNT(arr[i][j]) == true){
                dem_SNT ++;
            }
        }        
    }
    cout << dem_SNT << " so nguyen to.\n";

    cout << "\n";
    cout << "sap xep dong " << k << " theo chieu khong giam: \n";
    int clone[SIZE][SIZE];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            clone[i][j] = arr[i][j];
        }        
    }
    
    // sắp xếp dòng "k" theo chiều tăng dần
    int temp_clone = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (clone[k][i] > clone[k][j])
            {
                temp_clone = clone[k][i];
                clone[k][i] = clone [k][j];
                clone[k][j] = temp_clone;
            }            
        }                
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << clone[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nHOAN VI DONG VA COT\n";
    HamChuyenVi(arr, m, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\n";

    return 0;
}