// Yêu cầu:
// 1. nhập số nguyên n (n < 100)
// 2. nhập n phần tử
// 3. đưa ra dãy số đã nhập
// 4. liệt kê các giá trị lẻ trong mảng
// 5. tìm phần tử lớn nhất trong mảng
// 6. in ra vị trí đầu tiên của phần tử lớn nhất
// 7. đếm số phần tử lớn nhất
// 8. tính tổng các phần tử là số chính phương
// 9. sắp xếp mảng theo chiều không giảm 

#include <iostream>
#include <cmath>
#define SIZE 100
using namespace std;

// hàm kiểm tra số chính phương
bool KiemTra_SCP(int thamSo){
    bool ketQua;

    int kiemTra = sqrt(thamSo);

    if(pow(kiemTra, 2) == thamSo){
        ketQua = true;
    }else{
        ketQua = false;
    }

    return ketQua;
}

int main(){
    cout << "nhap vao so nguyen n: ";
    int n;
    cin >> n;

    int arr[SIZE];

    cout << "\nnhap n phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "\nn phan tu vua nhap la:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i];
        cout << "\n";
    }
    
    cout << "\ncac gia tri le trong mang la:\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << "arr[" << i << "] = " << arr[i];
            cout << "\n";
        }
    }

    cout << "\nphan tu lon nhat trong mang la: ";
    int max = arr[0];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }        
    }
    cout << max << endl;
    
    cout << "\nvi tri dau tien cua phan tu lon nhat la: ";
    for (int i = 0; i < n; i++)
    {
        if (max == arr[i])
        {
            index = i;
            break;
        }        
    }
    cout << index << endl;

    int dem = 0;
    cout << "\ndem so phan tu lon nhat la: ";
    for (int i = 0; i < n; i++)
    {
        if (max == arr[i])
        {
            dem ++;
        }        
    }
    cout << dem << endl;

    int tong_scp = 0;
    cout << "\ntong cac phan tu la so chinh phuong: tong = ";
    for (int i = 0; i < n; i++)
    {
        if(KiemTra_SCP(arr[i]) == true){
            tong_scp = tong_scp + arr[i];
        }
    }
    cout << tong_scp << endl;
    
    cout << "\nsap xep mang thieu chieu khong giam (la chieu tang dan)\n";
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }        
    }

    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i];
        cout << "\n";
    }
    
    cout << "\n";

    return 0;
}