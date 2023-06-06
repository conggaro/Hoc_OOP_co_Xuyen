// Yêu cầu:
// 1. nhập m dòng
// 2. nhập n cột
// 3. nhập các phần tử số nguyên cho mảng

// 4. hiển thị mảng vừa nhập ra màn hình

// 5. nhập vào số "k"
// đếm số lần xuất hiện của số "k" trong mảng

// 6. in ra max
// 7. in ra min

// 8. in ra các số nguyên khác nhau

#include <iostream>
#include <vector>
#define SIZE 50
using namespace std;

// hàm nhập dữ liệu cho các phần tử
void NhapDuLieu(int mang[SIZE][SIZE], int m, int n){
    cout << "nhap du lieu:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> mang[i][j];
        }        
    }    
}

// hàm hiển thị dữ liệu cho các phần tử
void HienThiDuLieu(int mang[SIZE][SIZE], int m, int n){
    cout << "du lieu vua nhap:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mang[i][j] << "\t";
        }        
        cout << endl;
    }    
}

// hàm đếm số lần k xuất hiện
int Dem_k(int mang[SIZE][SIZE], int m, int n, int k){
    int dem = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k == mang[i][j])
            {
                dem ++;
            }
            
        }
        
    }
    
    return dem;
}

// hàm tìm max
int Tim_Max(int mang[SIZE][SIZE], int m, int n){
    int max = mang[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (max < mang[i][j])
            {
                max = mang[i][j];
            }            
        }        
    }

    return max;
}

// hàm tìm max
int Tim_Min(int mang[SIZE][SIZE], int m, int n){
    int min = mang[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > mang[i][j])
            {
                min = mang[i][j];
            }            
        }        
    }

    return min;
}

// hàm xóa phần tử tại vị trí thứ i
void XoaPhanTu(int mang[200], int &do_dai, int vi_tri){
    for (int i = vi_tri; i <= do_dai - 1; i++){
        mang[i] = mang[i+1];
    }
    do_dai = do_dai - 1;
}

// hàm in ra các số nguyên khác nhau
void HamInRa_SoNguyenKhacNhau(int mang[SIZE][SIZE], int m, int n){
    int arr[200];
    int length = m*n;
    int index = 0;
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[index] = mang[i][j];
            index ++;
        }        
    }
    
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // for (int i = 0; i <= length - 1; i++)
    // {
    //     for (int j = i + 1; j <= length - 1; j++)
    //     {

    //         if (arr[i] == arr[i+1])
    //         {
    //             XoaPhanTu(arr, length, i);
    //         }
    //     }      
    // }
    
    // hiển thị
    // for (int i = 0; i <= length-1; i++)
    // {
    //     cout << arr[i] << "\t";
    // }

    int j = 0;
    for (int i = 1; i < n; i++){
        if(arr[i] != arr[j]){
            arr[++j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++){
        cout << arr[i] << " ";
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

    cout << "\n";
    NhapDuLieu(arr, m, n);

    cout << "\n";
    HienThiDuLieu(arr, m, n);

    cout << "\n";
    cout << "nhap vao so nguyen \"k\" la: ";
    int k;
    cin >> k;
    int dem_k = Dem_k(arr, m, n, k);
    cout << "so lan \"k\" xuat hien: ";
    cout << dem_k << endl;

    cout << "\n";
    cout << "max cua mang la: " << Tim_Max(arr, m, n) << endl;

    cout << "\n";
    cout << "min cua mang la: " << Tim_Min(arr, m, n) << endl;

    cout << "\n";
    cout << "ham in ra man hinh cac so nguyen khac nhau:\n";
    HamInRa_SoNguyenKhacNhau(arr, m, n);

    cout << "\n\n";
    return 0;
}