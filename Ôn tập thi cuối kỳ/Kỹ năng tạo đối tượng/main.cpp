// Yêu cầu:
// 1. hàm tạo không tham số
// 2. hàm tạo có tham số
// 3. hàm tạo sao chép
// 4. hàm hủy
// 5. hàm nhập dữ liệu
// 6. hàm hiển thị

#include <iostream>
#include <string>
using namespace std;

// tạo lớp ConNguoi
class ConNguoi{
    private:
        int id;
        string ho_ten;

    public:
        // hàm khởi tạo không tham số
        ConNguoi(){
            id = 0;
            ho_ten = "";
        }

        // hàm khởi tạo có tham số
        ConNguoi(int data1, string data2){
            id = data1;
            ho_ten = data2;
        }

        // hàm tạo sao chép
        ConNguoi(const ConNguoi &dt){
            id = dt.id;
            ho_ten = dt.ho_ten;
        }

        // hàm hủy
        ~ConNguoi(){
            cout << "Huy doi tuong\n\n";
        }

        // hàm nhập dữ liệu
        void Nhap_DuLieu(){
            cout << "Nhap id: ";
            cin >> id;
            cin.ignore();

            cout << "Nhap ho ten: ";
            getline(cin, ho_ten, '\n');
        }

        // hàm hiển thị
        void HienThi(){
            cout << "[" << id << ", " << ho_ten << "]\n";
        }
};

int main(){
    // tạo đối tượng
    ConNguoi dt1 = ConNguoi(1, "Nguyen Van A");
    
    ConNguoi dt2;
    dt2 = ConNguoi(dt1);

    ConNguoi dt3;

    // gọi phương thức nhập dữ liệu
    dt3.Nhap_DuLieu();

    // gọi phương thức hiển thị
    cout << "\ndt1: ";
    dt1.HienThi();

    cout << "dt2: ";
    dt2.HienThi();

    cout << "dt3: ";
    dt3.HienThi();

    cout << "\n";

    return 0;
}