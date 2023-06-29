// Yêu cầu:
// 1. nhập n
// 2. nhập thông tin cho n người (cả sinh viên và giáo sư)
// 3. in ra màn hình người kiệt xuất

#include <iostream>
#include <string>
#define SIZE 50
using namespace std;

// tạo lớp Person
class Person{
    private:
        string ho_ten;
        int tuoi;

    public:
        // hàm khởi tạo không tham số
        Person(){
            ho_ten = "NO NAME";
            tuoi = 0;
        }

        // hàm nhập dữ liệu
        // KHÔNG THAM SỐ
        void NhapDuLieu(){
            cout << "Nhap ho ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap tuoi: ";
            cin >> tuoi;
            cin.ignore();
        }

        // hàm get_HoTen
        string get_HoTen(){
            return ho_ten;
        }

        // hàm get_Tuoi
        int get_Tuoi(){
            return tuoi;
        }

        // kiểm tra người kiệt xuất
        virtual bool KiemTra_KietXuat() = 0;
};

// tạo lớp Student
class Student : public Person{
    private:
        float diem_TB;

    public:
        // hàm khởi tạo không tham số
        Student() : Person(){
            diem_TB = 0;
        }

        // hàm nhập dữ liệu
        // KHÔNG THAM SỐ
        void NhapDuLieu(){
            // gọi hàm của lớp cha
            Person::NhapDuLieu();
            
            cout << "Nhap diem trung binh: ";
            cin >> diem_TB;
            cin.ignore();
        }

        // hàm kiểm tra
        // sinh viên này có phải loại kiệt xuất không
        bool KiemTra_KietXuat(){
            bool ketQua;

            if (9.5 < diem_TB && diem_TB <= 10)
            {
                ketQua = true;
            }
            else if (0 <= diem_TB && diem_TB <= 9.5)
            {
                ketQua = false;
            }

            return ketQua;
        }

        // nạp chồng toán tử hiển thị "<<"
        friend ostream &operator<<(ostream &dt_cout, Student dt);
};

ostream &operator<<(ostream &dt_cout, Student dt){
    dt_cout << "[Hoc sinh: " << dt.get_HoTen() << ", tuoi: " << dt.get_Tuoi();
    dt_cout << ", diem trung binh: " << dt.diem_TB << "]";

    return dt_cout;
}

// tạo lớp Professor (giáo sư)
class Professor : public Person{
    private:
        int so_luong_bao;   // số lượng bài báo đã xuất bản

    public:
        // hàm khởi tạo không tham số
        Professor() : Person(){
            so_luong_bao = 0;
        }

        // hàm nhập dữ liệu
        // KHÔNG THAM SỐ
        void NhapDuLieu(){
            Person::NhapDuLieu();

            cout << "Nhap so luong bao: ";
            cin >> so_luong_bao;
            cin.ignore();
        }

        // hàm kiểm tra
        // giáo sư này có phải loại kiệt xuất không
        bool KiemTra_KietXuat(){
            bool ketQua;

            if (so_luong_bao >= 100)
            {
                ketQua = true;
            }
            else
            {
                ketQua = false;
            }

            return ketQua;
        }

        // nạp chồng toán tử hiển thị "<<"
        friend ostream &operator<<(ostream &dt_cout, Professor dt);
};

ostream &operator<<(ostream &dt_cout, Professor dt){
    dt_cout << "[Giao su: " << dt.get_HoTen() << ", tuoi: " << dt.get_Tuoi();
    dt_cout << ", so luong bao: " << dt.so_luong_bao << "]";

    return dt_cout;
}

// tạo lớp "Mảng"
class Mang{
    public:
        // học sinh thì (đánh dấu = 1)
        // giáo sư thì (đánh dấu = 2)
        // "biến đánh dấu" cũng như cái "biến cờ" vậy
        int danh_dau;

    public:
        Student dt_student;         // đối tượng học sinh
        Professor dt_professor;     // đối tượng giáo sư
};

int main(){
    cout << "Nhap n: ";
    int n;
    cin >> n;
    cin.ignore();

    // tạo mảng để hứng dữ liệu
    Mang arr[SIZE];

    // nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap hoc sinh (bam phim 1), nhap giao su (bam phim 2):\n";
        cout << "Moi nhap: ";
        cin >> arr[i].danh_dau;
        cin.ignore();

        while (arr[i].danh_dau != 1 && arr[i].danh_dau != 2)
        {
            cout << "Moi nhap lai: ";
            cin >> arr[i].danh_dau;
            cin.ignore();
        }
        
        if (arr[i].danh_dau == 1)
        {
            arr[i].dt_student.NhapDuLieu();
        }
        else if (arr[i].danh_dau == 2)
        {
            arr[i].dt_professor.NhapDuLieu();
        }

        cout << "\n";
    }
    
    // hiển thị dữ liệu vừa nhập
    // nhập dữ liệu
    cout << "-------------------- HIEN THI DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].danh_dau == 1)
        {
            cout << arr[i].dt_student << "\n";
        }
        else if (arr[i].danh_dau == 2)
        {
            cout << arr[i].dt_professor << "\n";
        }        
    }
    
    cout << "\n";

    // in ra danh sách những người kiệt xuất
    cout << "-------------------- DANH SACH NGUOI KIET XUAT --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].danh_dau == 1 && arr[i].dt_student.KiemTra_KietXuat() == true)
        {
            cout << arr[i].dt_student << "\n";
        }
        else if (arr[i].danh_dau == 2 && arr[i].dt_professor.KiemTra_KietXuat() == true)
        {
            cout << arr[i].dt_professor << "\n";
        }
    }
    
    cout << "\n";

    return 0;
}