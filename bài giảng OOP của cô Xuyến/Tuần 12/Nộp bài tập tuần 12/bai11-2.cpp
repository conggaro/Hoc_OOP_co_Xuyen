// Yêu cầu:
// 1. tạo lớp Person
// 2. nhập n (n < 50)
// 3. nhập n đối tượng

// 4. sắp xếp danh sách theo chiều không giảm của tuổi
// tức là sắp xếp tăng dần

// 5. tìm và in ra những người
// trong họ tên có từ "Anh"

#include <iostream>
#include <string>
#include <ctime>
#define SIZE 50
using namespace std;

// tạo lớp TDate
class TDate{
    public:
        short ngay;
        short thang;
        short nam;
};

// tạo lớp Person
class Person{
    private:
        string ho_ten;
        TDate ngay_sinh;
        string que_quan;
        
    public:
        int tuoi;

    public:
        // hàm khởi tạo có tham số
        Person(string data1 = "", short data2 = 0, short data3 = 0, short data4 = 0, string data5 = ""){
            ho_ten = data1;
            ngay_sinh.ngay = data2;
            ngay_sinh.thang = data3;
            ngay_sinh.nam = data4;
            que_quan = data5;

            time_t dt_time = time(0);
    
            // Chuyển đổi thành cấu trúc tm để trích xuất thông tin năm
            tm *dt = localtime(&dt_time);
            
            // Lấy năm từ cấu trúc tm
            int year = 1900 + dt->tm_year;

            tuoi = year - ngay_sinh.nam;
        }

        // hàm khởi tạo sao chép
        Person(Person &dt){
            ho_ten = dt.ho_ten;
            ngay_sinh.ngay = dt.ngay_sinh.ngay;
            ngay_sinh.thang = dt.ngay_sinh.thang;
            ngay_sinh.nam = dt.ngay_sinh.nam;
            que_quan = dt.que_quan;
            tuoi = dt.tuoi;
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap ho ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap ngay: ";
            cin >> ngay_sinh.ngay;

            cout << "Nhap thang: ";
            cin >> ngay_sinh.thang;

            cout << "Nhap nam: ";
            cin >> ngay_sinh.nam;
            cin.ignore();

            cout << "Nhap que quan: ";
            getline(cin, que_quan, '\n');

            time_t dt_time = time(0);
    
            // Chuyển đổi thành cấu trúc tm để trích xuất thông tin năm
            tm *dt = localtime(&dt_time);
            
            // Lấy năm từ cấu trúc tm
            int year = 1900 + dt->tm_year;

            tuoi = year - ngay_sinh.nam;
        }

        // hàm hiển thị
        void HienThi(){
            cout << "Thong tin Person:\n";
            cout << "Ho ten: " << ho_ten << "\n";
            cout << "Ngay sinh: " << ngay_sinh.ngay << "/";
            cout << ngay_sinh.thang << "/";
            cout << ngay_sinh.nam << "\n";
            cout << "Que quan: " << que_quan << "\n";
        }

        // hàm kiểm tra từ "Anh"
        // trong họ tên
        bool KiemTra_TuAnh(){
            bool ketQua;

            if (ho_ten.find("Anh", 0) != -1)
            {
                ketQua = true;
            }
            else if (ho_ten.find("Anh", 0) == -1)
            {
                ketQua = false;
            }            

            return ketQua;
        }
};

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n;
    cin >> n;

    while (n >= 50 || n <= 0)
    {
        cout << "Nhap lai n (0 < n < 50): ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng
    Person arr[SIZE];

    // gọi phương thức nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].NhapDuLieu();
        cout << "\n";
    }
    
    // gọi phương thức hiển thị dữ liệu
    cout << "-------------------- HIEN THI DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n";
    }

    // sắp xếp tăng dần
    // theo tuổi
    Person temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].tuoi > arr[j].tuoi)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }        
    }
    
    cout << "-------------------- SAP XEP TANG DAN --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n";
    }

    // đếm người có từ "Anh" trong tên
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].KiemTra_TuAnh() == true)
        {
            dem ++;
        }
    }
    cout << "Co " << dem << " nguoi, co tu \"Anh\" trong ho ten\n\n";

    if (dem > 0)
    {
        cout << "----------------- IN RA NGUOI CO TU \"Anh\" TRONG HO TEN -----------------\n";
        for (int i = 0; i < n; i++)
        {
            if (arr[i].KiemTra_TuAnh() == true)
            {
                arr[i].HienThi();
                cout << "\n";
            }
        }
    }

    return 0;
}