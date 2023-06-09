// Yêu cầu:
// 1. tạo lớp NHANVIEN
// 2. nhập n
// 3. nhập n phần tử
// 4. hiển thị nhân viên có quê ở Hà Nội
// 5. in ra trung bình cộng lương của tất cả nhân viên
// 6. sắp xếp lương tăng dần
// 7. đếm nhân viên có tuổi lớn hơn 30

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

// tạo lớp NHANVIEN
class NHANVIEN{
    private:
        string ho_ten;
        string ngay_sinh;
        bool gioi_tinh;
        string que_quan;
        int luong;
        string trinh_do;
        string chuc_vu;

    public:
        // hàm tạo không tham số
        NHANVIEN(){
            ho_ten = "";
            ngay_sinh = "";
            gioi_tinh = true;
            que_quan = "";
            luong = 0;
            trinh_do = "";
            chuc_vu = "";
        }

        // hàm tạo có tham số
        NHANVIEN(string data1, string data2, bool data3,
                    string data4, int data5, string data6, string data7){
            ho_ten = data1;
            ngay_sinh = data2;
            gioi_tinh = data3;
            que_quan = data4;
            luong = data5;
            trinh_do = data6;
            chuc_vu = data7;
        }

        // hàm hủy
        ~NHANVIEN(){
            // cout << "Huy doi tuong\n";
        }

        // hàm nhập thông tin nhân viên
        void NhapDuLieu(){
            cout << "Nhap ho ten: ";
            getline(cin, ho_ten, '\n');

            cout << "Nhap ngay sinh: ";
            getline(cin, ngay_sinh, '\n');

            cout << "Nhap gioi tinh: ";
            cin >> gioi_tinh;
            cin.ignore();

            cout << "Nhap que quan: ";
            getline(cin, que_quan, '\n');

            cout << "Nhap luong: ";
            cin >> luong;
            cin.ignore();

            cout << "Nhap trinh do: ";
            getline(cin, trinh_do, '\n');

            cout << "Nhap chuc vu: ";
            getline(cin, chuc_vu, '\n');
        }

        // hàm hiển thị
        void HienThi(){
            cout << "[" << ho_ten <<", ";
            cout << ngay_sinh << ", ";
            cout << gioi_tinh << ", ";
            cout << que_quan << ", ";
            cout << luong << ", ";
            cout << trinh_do << ", ";
            cout << chuc_vu << "]";
        }

        // hàm get_QueQuan
        string get_QueQuan(){
            return que_quan;
        }

        // hàm get_Luong
        int get_Luong(){
            return luong;
        }

        // hàm get_Nam
        int get_Nam(){
            string data_nam = "";

            int dem = 0;

            for (int i = ngay_sinh.length() - 1; i >= 0; i--)
            {
                dem ++;

                data_nam = data_nam + ngay_sinh[i];

                if (dem == 4)
                {
                    break;
                }                
            }
            
            string data = "";
            for (int i = data_nam.length() - 1; i >= 0 ; i--)
            {
                data = data + data_nam[i];
            }
            
            int nam = stoi(data);

            return nam;
        }
};

int main(){
    // nhập n
    cout << "Nhap n: ";
    int n = 0;
    cin >> n;
    cin.ignore();

    // tạo mảng
    NHANVIEN arr[SIZE];

    // gọi phương thức nhập dữ liệu
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].NhapDuLieu();
        cout << "\n";
    }
    
    // hiển thị nhân viên có quê ở Hà Nội
    cout << "-------------------- NHAN VIEN QUE O HA NOI --------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (arr[i].get_QueQuan() == "Ha Noi")
        {
            arr[i].HienThi();
            cout << "\n\n";
        }
    }

    // in ra trung bình cộng lương của tất cả nhân viên
    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        tong = tong + arr[i].get_Luong();
    }
    
    cout << "Trung binh cong luong = " << (float)tong / n << "\n\n";

    // sắp xếp nhân viên
    // tăng dần
    // theo lương
    NHANVIEN temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].get_Luong() > arr[j].get_Luong())
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }        
    }

    cout << "-------------------- LUONG TANG DAN --------------------\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].HienThi();
        cout << "\n\n";
    }

    // đếm nhân viên có tuổi
    // lớn hơn 30
    int dem_tuoi = 0;
    for (int i = 0; i < n; i++)
    {
        if (2020 - arr[i].get_Nam() > 30)
        {
            dem_tuoi ++;
        }        
    }
    
    cout << "Co " << dem_tuoi << " nhan vien lon hon 30 tuoi\n\n";

    return 0;
}