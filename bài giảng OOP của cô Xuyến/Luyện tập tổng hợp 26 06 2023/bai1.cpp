// Tác giả: Nguyễn Chí Công

// Yêu cầu:
// 1. nhập n (N < 1000);
// 2. nhập n số nguyên dương

// 3. nhập số nguyên X bất kỳ
// đếm số lần X xuất hiện trong dãy

// 4. sắp xếp lại dãy theo quy tắc
// đoạn đầu chỉ gồm các số chẵn
// đoạn sau gồm các số lẻ

// 5. in ra màn hình các số nguyên tố khác nhau trong dãy

// 6. liệt kê bộ 3 số a, b, c có mặt trong dãy
// thỏa mãn a^2 = b^2 + c^2

#include <iostream>
#include <cmath>
#define SIZE 100
using namespace std;



// hàm đếm số lần X xuất hiện
int Dem_So_Lan_X_XuatHien(int arr[SIZE], int n, int thamSo){
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == thamSo)
        {
            dem ++;
        }
    }    

    return dem;
}

// hàm xóa phần tử tại vị trí bất kỳ
// trong mảng
void Xoa_PhanTu(int arr[SIZE], int &n, int index){
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
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

// tạo lớp Data
// để lưu dữ liệu của a, b, c
// a^2 = b^2 + c^2
class Data{
    public:
        int a;
        int b;
        int c;

    public:
        // hàm khởi tạo không tham số
        Data(){
            a = -1;
            b = -1;
            c = -1;
        }
};

int main(){
    // nhập n
    cout << "Nhap n (0 <= n < 1000):\n";
    cout << "Moi nhap: ";
    int n;
    cin >> n;

    while (n <= 0 || n >= 1000)
    {
        cout << "Nhap lai n: ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng để hứng dữ liệu
    int arr[SIZE];

    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap arr[" << i << "] = ";
        cin >> arr[i];

        while (arr[i] <= 0)
        {
            cout << "Nhap lai arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    // nhập x
    cout << "\nNhap so nguyen X: ";
    int X;
    cin >> X;

    // gọi hàm đếm số lần xuất hiện của X
    int dem = Dem_So_Lan_X_XuatHien(arr, n, X);
    cout << "So lan X xuat hien la: " << dem << "\n\n";
    
    // tạo 2 mảng
    int arr_chan[500];
    int index_chan = 0;

    int arr_le[500];
    int index_le = 0;

    int dem_chan = 0;
    int dem_le = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr_chan[index_chan] = arr[i];
            index_chan ++;

            dem_chan ++;
        }
        else if (arr[i] % 2 != 0)
        {
            arr_le[index_le] = arr[i];
            index_le ++;

            dem_le ++;
        }        
    }
    
    index_chan = 0;
    index_le = 0;

    for (int i = 0; i < n; i++)
    {
        if (index_chan <= dem_chan - 1)
        {
            arr[i] = arr_chan[index_chan];
            index_chan ++;
        }
        else if (index_chan > dem_chan - 1)
        {
            arr[i] = arr_le[index_le];
            index_le ++;
        }        
    }
    
    // hiển thị mảng sau khi sắp xếp
    cout << "--------------- MANG SAU KHI SAP XEP ---------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
    
    // sắp xếp mảng tăng dần
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
    
    // xóa phần tử trùng nhau
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            Xoa_PhanTu(arr, n, i);
        }        
    }

    // gọi hàm kiểm tra số nguyên tố
    cout << "\n--------------- IN RA SO NGUYEN TO ---------------\n";
    for (int i = 0; i < n; i++)
    {
        if (KiemTra_SNT(arr[i]) == true)
        {
            cout << "arr[" << i << "] = " << arr[i] << "\n";
        }
    }

    // tính tổng bình phương của 2 số bất kỳ
    // tạo mảng để lưu tổng
    int arr_tong[SIZE][SIZE];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            arr_tong[i][j] = pow(arr[i], 2) + pow(arr[j], 2);
        }        
    }
    
    // in ra màn hình
    cout << "\n-------------------- TONG BINH PHUONG CUA 2 SO NGAU NHIEN --------------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr_tong[i][j] << "\t";
        }
        cout << "\n\n";
    }

    // đếm thử xem có số nào bằng tổng bình phương
    // của 2 số còn lại không
    int dem_data = 0;

    // tạo mảng để hứng dữ liệu
    // cụ thể là hứng a, b, c
    Data arr_data[SIZE];

    for (int index = 0; index < n; index++)
    {

        // dùng cái vòng lặp for kiểu này để duyệt
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr_tong[i][j] == pow(arr[index], 2))
                {
                    // ghi vào cái thuộc tính a
                    arr_data[dem_data].a = index;

                    // ghi vào cái thuộc tính b
                    arr_data[dem_data].b = i;

                    // ghi vào cái thuộc tính c
                    arr_data[dem_data].c = j;
                    
                    dem_data ++;                    
                }
            }
        }

    }

    cout << "Co " << dem_data << " bo gia tri (a, b, c) thoa man a^2 = b^2 + c^2\n\n";
    if (dem_data != 0)
    {
        cout << "------------- DANH SACH BO 3 SO (a, b, c) THOA MAN -------------\n";
        for (int i = 0; i < dem_data; i++)
        {
            cout << "Bo (a, b, c) co index = " << i << "\n";
            cout << "a la arr[" << arr_data[i].a << "] = " << arr[arr_data[i].a] << "\n";
            cout << "b la arr[" << arr_data[i].b << "] = " << arr[arr_data[i].b] << "\n";
            cout << "c la arr[" << arr_data[i].c << "] = " << arr[arr_data[i].c] << "\n\n";
        }        
    }

    return 0;
}