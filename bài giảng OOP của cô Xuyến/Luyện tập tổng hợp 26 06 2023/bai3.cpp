// Tác giả: Nguyễn Chí Công

// Yêu cầu:
// 1. tạo lớp SINHVIEN
// 2. nhập n
// 3. thông tin cho n sinh viên
// 4. hiển thị dữ liệu đã nhập ra màn hình

// 5. đếm xem
// có bao nhiêu sinh viên tên là "Binh"
// và sinh năm 1982

// 6. sắp xếp danh sách
// theo thứ tự không giảm
// tức là tăng dần
// tức là ai nhiều tuổi hơn thì đứng sau

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

class SINHVIEN{
    private:
        string ho_ten;
        int nam_sinh;
        double diemTB;
        bool gioi_tinh;     // 1 là nam, 0 là nữ

    public:
        // hàm khởi tạo không tham số
        SINHVIEN(){
            ho_ten = "";
            nam_sinh = 0;
            diemTB = 0;
            gioi_tinh = 0;
        }

        // hàm khởi tạo 4 tham số
        SINHVIEN(string data1, int data2, double data3, bool data4){
            ho_ten = data1;
            nam_sinh = data2;
            diemTB = data3;
            gioi_tinh = data4;
        }

        // hàm nhập dữ liệu cho đối tượng
        void NhapDuLieu(){
            cout << "Nhap ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap nam sinh: ";
            cin >> nam_sinh;

            cout << "Nhap diem trung binh: ";
            cin >> diemTB;

            cout << "Nhap gioi tinh: ";
            cin >> gioi_tinh;
            cin.ignore();
        }

        // hàm hiển thị thông tin đối tượng
        void HienThi(){
            cout << "[ho ten: " << ho_ten << ", ";
            cout << "nam sinh: " << nam_sinh << ", ";
            cout << "diem trung binh: " << diemTB << ", ";
            cout << "gioi tinh: " << gioi_tinh << "]";
        }

        // hàm toán tử so sánh ">"
        // nạp chồng toán tử
        // sử dụng hàm bạn
        friend bool operator>(SINHVIEN dt1, SINHVIEN dt2);

        // get_HoTen
        string get_HoTen(){
            return ho_ten;
        }

        // get_NamSinh
        int get_NamSinh(){
            return nam_sinh;
        }

        // hàm lấy tên
        string Ham_LayTen(){
            string ten = "";

            // việc 1:
            // tìm vị trí khoảng trống đầu tiên từ cuối về
            int vi_tri = 0;
            vi_tri = ho_ten.rfind(' ', ho_ten.length() - 1);

            // việc 2:
            // hứng dữ liệu vào biến "ten"
            ten = ho_ten.substr(vi_tri + 1, ho_ten.length() - 1 - vi_tri);

            return ten;
        }
};

bool operator>(SINHVIEN dt1, SINHVIEN dt2){
    bool ketQua;

    // nếu dt1 có năm sinh
    // nhỏ hơn dt2
    // thì dt1 phải lớn hơn dt2
    if (dt1.nam_sinh < dt2.nam_sinh)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }

    return ketQua;
}

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n;
    cin >> n;
    
    while (n <= 0)
    {
        cout << "Nhap lai n (n > 0): ";
        cin >> n;
    }
    cin.ignore();

    // tạo mảng
    SINHVIEN arr[SIZE];

    // gọi phương thức nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].NhapDuLieu();
        cout << "\n";
    }

    // gọi phương thức hiển thị dữ liệu
    cout << "\n-------------------- HIEN THI DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n\n";
    }

    // tạo biến đếm "Binh" - 1982
    int dem_Binh_1982 = 0;

    for (int i = 0; i < n; i++)
    {
        bool kiemTra1;
        if (arr[i].Ham_LayTen() == "Binh")
        {
            kiemTra1 = true;
        }
        else
        {
            kiemTra1 = false;
        }

        bool kiemTra2 = arr[i].get_NamSinh() == 1982 ? true : false;

        if (kiemTra1 && kiemTra2)
        {
            dem_Binh_1982 ++;
        }        
    }

    cout << "\nCo " << dem_Binh_1982 << " nguoi thoa man yeu cau\n";
    if (dem_Binh_1982 != 0)
    {
        cout << "\n---------- DANH SACH NGUOI TEN LA BINH, SINH NAM 1982 ----------\n";
        for (int i = 0; i < n; i++)
        {
            bool kiemTra1;
            if (arr[i].Ham_LayTen() == "Binh")
            {
                kiemTra1 = true;
            }
            else
            {
                kiemTra1 = false;
            }

            bool kiemTra2 = arr[i].get_NamSinh() == 1982 ? true : false;

            if (kiemTra1 && kiemTra2)
            {
                arr[i].HienThi();
                cout << "\n\n";
            }        
        }
    }
    
    // sắp xếp theo năm sinh
    // ai nhiều tuổi hơn thì đứng sau
    SINHVIEN temp;

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

    cout << "\n-------------------- SAU KHI SAP XEP --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n\n";
    }    

    return 0;
}