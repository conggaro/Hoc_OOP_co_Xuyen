// Yêu cầu:
// 1. tạo lớp ConNguoi
// 2. tạo lớp SinhVien
// 3. tạo lớp GiaoSu

#include <iostream>
#include <string>
using namespace std;

// tạo lớp ConNguoi
class ConNguoi{
    private:
        string CCCD;                // căn cước công dân
        string ho_ten;
        bool gioi_tinh;             // 1 là nam, 0 là nữ
        string ngay_sinh;           // định dạng dd/MM/yyyy
        string que_quan;

    protected:
        // hàm khởi tạo không tham số
        ConNguoi(){
            CCCD = "";
            ho_ten = "";
            gioi_tinh = 1;
            ngay_sinh = "";
            que_quan = "";
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap CCCD: ";
            cin >> CCCD;
            cin.ignore();

            cout << "Nhap ho ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap gioi tinh: ";
            cin >> gioi_tinh;
            cin.ignore();

            cout << "Nhap ngay sinh: ";
            cin >> ngay_sinh;
            cin.ignore();

            cout << "Nhap que quan: ";
            getline(cin, que_quan, '\n');
        }

        // hàm hiển thị dữ liệu
        void HienThi(){
            cout << "[" << CCCD << ", ";
            cout << ho_ten << ", ";
            cout << gioi_tinh << ", ";
            cout << ngay_sinh << ", ";
            cout << que_quan << ", ";
        }

    // nếu có get_Ten() hoặc set_Ten() thì để public
};

// tạo lớp SinhVien
class SinhVien : protected ConNguoi{
    private:
        string ma_sv;

    public:
        // kế thừa hàm khởi tạo không tham số
        SinhVien() : ConNguoi(){
            ma_sv = "";
        }

        // kế thừa hàm nhập dữ liệu
        void Nhap_DuLieu_SinhVien(){
            ConNguoi::NhapDuLieu();

            cout << "Nhap ma sinh vien: ";
            cin >> ma_sv;
            cin.ignore();
        }

        // kế thừa hàm hiển thị dữ liệu
        void HienThi_SinhVien(){
            ConNguoi::HienThi();

            cout << ma_sv << "]\n";
        }
};

// tạo lớp GiaoSu
class GiaoSu : protected ConNguoi{
    private:
        string ma_gs;

    public:
        // kế thừa hàm khởi tạo không tham số
        GiaoSu() : ConNguoi(){
            ma_gs = "";
        }

        // kế thừa hàm nhập dữ liệu
        void Nhap_DuLieu_GiaoSu(){
            ConNguoi::NhapDuLieu();

            cout << "Nhap ma giao su: ";
            cin >> ma_gs;
            cin.ignore();
        }

        // kế thừa hàm hiển thị dữ liệu
        void HienThi_GiaoSu(){
            ConNguoi::HienThi();

            cout << ma_gs << "]\n";
        }
};

int main(){
    // tạo đối tượng
    SinhVien dt1 = SinhVien();
    GiaoSu dt2 = GiaoSu();

    // nhập dữ liệu
    dt1.Nhap_DuLieu_SinhVien();
    cout << "\n";
    dt2.Nhap_DuLieu_GiaoSu();
    cout << "\n";

    // hiển thị
    dt1.HienThi_SinhVien();
    dt2.HienThi_GiaoSu();
    cout << "\n";

    return 0;
}