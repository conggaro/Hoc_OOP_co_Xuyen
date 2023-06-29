// Yêu cầu:
// 1. tạo lớp HOCSINH

// 2. thuộc tính:
// họ tên
// điểm toán
// điểm lý
// điểm hóa
// điểm trung bình

#include <iostream>
using namespace std;

// tạo lớp HOCSINH
class HOCSINH{
    private:
        string ho_ten;
        float diemToan;
        float diemLy;
        float diemHoa;
        float diemTB;
    
    public:
        // hàm khởi tạo không tham số
        HOCSINH(){
            ho_ten = "";
            diemToan = 0;
            diemLy = 0;
            diemHoa = 0;
            diemTB = 0;
        }

        // hàm khởi tạo có tham số
        HOCSINH(string data1, float data2, float data3, float data4){
            ho_ten = data1;
            diemToan = data2;
            diemLy = data3;
            diemHoa = data4;
            diemTB = 0;
        }

        // hàm hủy
        ~HOCSINH(){
            cout << "Huy doi tuong\n";
        }

        // hàm nhập dữ liệu
        void NhapDuLieu(string data1, float data2, float data3, float data4){
            ho_ten = data1;
            diemToan = data2;
            diemLy = data3;
            diemHoa = data4;
        }

        // hàm tính điểm trung bình
        float Tinh_DiemTB(){
            diemTB = (diemToan + diemLy + diemHoa) / 3;

            return diemTB;
        }

        // hàm xếp loại
        string Xep_Loai(){
            string ketQua = "";
            float diem = Tinh_DiemTB();

            if (8.0 <= diem && diem <= 10)
            {
                ketQua = "Loai Gioi";
            }
            else if (6.5 <= diem && diem < 8.0)
            {
                ketQua = "Loai Kha";
            }
            else if (5.0 <= diem && diem < 6.5)
            {
                ketQua = "Loai Trung binh";
            }
            else if (0.0 <= diem && diem < 5.0)
            {
                ketQua = "Loai Yeu";
            }   

            return ketQua;         
        }

        // hàm hiển thị thông tin học sinh
        void HienThi(){
            cout << "Thong tin hoc sinh:\n";
            cout << "Ho va ten:\t\t\t" << ho_ten << "\n";
            cout << "Diem toan:\t\t\t" << diemToan << "\n";
            cout << "Diem ly:\t\t\t" << diemLy << "\n";
            cout << "Diem hoa:\t\t\t" << diemHoa << "\n";
            cout << "Diem trung binh:\t\t" << Tinh_DiemTB() << "\n";
            cout << "Xep loai:\t\t\t" << Xep_Loai() << "\n\n";
        }
};

int main(){
    // tạo đối tượng
    HOCSINH dt1;
    dt1.NhapDuLieu("Nguyen Van A", 9, 9.5, 10);

    HOCSINH dt2 = HOCSINH("Nguyen Van B", 8, 9, 10);
    HOCSINH dt3 = HOCSINH("Nguyen Van C", 10, 10, 10);

    // gọi hàm hiển thị
    dt1.HienThi();
    dt2.HienThi();
    dt3.HienThi();

    return 0;
}