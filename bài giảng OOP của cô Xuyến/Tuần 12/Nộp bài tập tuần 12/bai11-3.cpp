// Yêu cầu:
// 1. tạo lớp LoDat
// 2. nhập n (n < 200)
// 3. nhập thông tin cho n lô đất

// 4. in ra danh sách lô đất 
// có diện tích > 200 (mét vuông)

// 5. in ra lô đất có giá trị lớn nhất
// biết 1 (m2) là 20 triệu

// 6. in ra tiền thuế
// biết 1000 VND / 1 (m2)

#include <iostream>
#define SIZE 200
using namespace std;

// tạo lớp LoDat
class LoDat{
    private:
        float chieu_dai;
        float chieu_rong;
        float dien_tich;

    public:
        // hàm khởi tạo không tham số
        LoDat(){
            chieu_dai = 0;
            chieu_rong = 0;
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap chieu dai: ";
            cin >> chieu_dai;

            cout << "Nhap chieu rong: ";
            cin >> chieu_rong;
            cin.ignore();

            dien_tich = chieu_dai * chieu_rong;
        }

        // hàm hiển thị
        void HienThi(){
            cout << "[chieu dai: " << chieu_dai << ", chieu rong: ";
            cout << chieu_rong << "]\n";
        }

        // hàm get_DienTich
        float get_DienTich(){
            return dien_tich;
        }
};

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n <= 0 || n >= 200)
    {
        cout << "Nhap lai n (0 < n < 200): ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng
    LoDat arr[SIZE];

    // gọi phương thức nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].NhapDuLieu();
        cout << "\n";
    }
    
    // in ra danh sách lô đất
    // có diện tích lớn hơn 200 mét vuông
    cout << "-------------------- LO DAT LON HON 200 MET VUONG --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].get_DienTich() > 200)
        {
            arr[i].HienThi();
            cout << "\n";
        }
    }

    // tìm lô đất giá cao nhất
    float max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i].get_DienTich())
        {
            max = arr[i].get_DienTich();
        }        
    }

    // in ra lô đất có giá trị lớn nhất
    cout << "-------------------- LO DAT GIA TRI NHAT --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].get_DienTich() == max)
        {
            arr[i].HienThi();
            long long int gia = arr[i].get_DienTich() * 20000000;
            cout << "Gia: " << gia << " VND\n\n";
        }
    }

    // in ra tiền thuế
    float tong_DienTich = 0;
    for (int i = 0; i < n; i++)
    {
        tong_DienTich = tong_DienTich + arr[i].get_DienTich();
    }
    cout << "Tong tien thue = " << tong_DienTich * 1000 << " VND\n\n";
    
    return 0;
}