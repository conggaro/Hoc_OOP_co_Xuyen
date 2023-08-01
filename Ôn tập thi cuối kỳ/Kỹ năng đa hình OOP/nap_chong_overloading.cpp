// Yêu cầu:
// 1. sử dụng nạp chồng phương thức

// cụ thể:
// là nạp chồng phương thức HienThi()

#include <iostream>
using namespace std;

// tạo lớp ConNguoi
class ConNguoi{
    private:
        int id;
        string ho_ten;

    public:
        // hàm khởi tạo không tham số
        ConNguoi(){
            id = 1;
            ho_ten = "Nguyen Van A";
        }

        void HienThi(){
            cout << "[" << id << ", " << ho_ten << "]\n";
        }

        void HienThi(int tuoi){
            cout << "[" << id << ", ";
            cout << ho_ten << ", ";
            cout << tuoi << "]\n";
        }

        void HienThi(int tuoi, string que_quan){
            cout << "[" << id << ", ";
            cout << ho_ten << ", ";
            cout << tuoi << ", ";
            cout << que_quan << "]\n";
        }
};

int main(){
    // tạo đối tượng
    ConNguoi dt;

    // gọi phương thức hiển thị
    dt.HienThi();
    dt.HienThi(22);
    dt.HienThi(22, "Ha Noi");

    cout << "\n";

    return 0;
}