// Yêu cầu:
// 1. tạo lớp FRACTION
// 2. hàm tạo 2 tham số
// 3. hàm tạo sao chép
// 4. nạp chồng toán tử >>
// 5. nạp chồng toán tử <<
// 6. hàm rút gọn phân số simplify()
// 7. nạp chồng toán tử +

#include <iostream>
using namespace std;

// hàm tìm ước chung lớn nhất
// UCLN(a, b)
int Ham_Tim_UCLN(int thamSo1, int thamSo2){
    int UCLN = 0;

    while (thamSo1 != thamSo2)
    {
        if (thamSo1 > thamSo2)
        {
            thamSo1 = thamSo1 - thamSo2;
        }
        else if (thamSo2 > thamSo1)
        {
            thamSo2 = thamSo2 - thamSo1;
        }
    }
    
    UCLN = thamSo1;

    return UCLN;
}

// tạo lớp FRACTION
class FRACTION{
    private:
        int n;              // tử số
        int d;              // mẫu số

    public:
        // hàm khởi tạo 2 tham số
        FRACTION(int data1 = 0, int data2 = 1){
            if (data2 == 0)
            {
                n = 0;
                d = 1;
            }
            else if (data2 != 0)
            {
                n = data1;
                d = data2;
            }            
        }

        // hàm khởi tạo sao chép
        FRACTION(const FRACTION &dt){
            n = dt.n;
            d = dt.d;
        }

        // hàm toán tử nhập phân số
        // nạp chồng toán tử >>
        friend istream &operator>>(istream &dt_cin, FRACTION &dt);

        // hàm toán tử hiển thị phân số
        // nạp chồng toán tử <<
        friend ostream &operator<<(ostream &dt_cout, FRACTION &dt);

        // hàm rút gọn phân số
        // về phân số tối giản
        // simplify()
        void simplify(){
            // tìm ước chung lớn nhất
            // của tử và mẫu
            int UCLN = Ham_Tim_UCLN(n, d);

            // rút gọn tử
            n = n / UCLN;

            // rút gọn mẫu
            d = d / UCLN;
        }

        // hàm toán tử cộng 2 phân số
        // nạp chồng toán tử +
        friend FRACTION operator+(FRACTION dt1, FRACTION dt2);
};

istream &operator>>(istream &dt_cin, FRACTION &dt){
    cout << "Nhap tu so: ";
    dt_cin >> dt.n;

    cout << "Nhap mau so: ";
    dt_cin >> dt.d;

    return dt_cin;
}

ostream &operator<<(ostream &dt_cout, FRACTION &dt){
    dt_cout << dt.n << "/" << dt.d;

    return dt_cout;
}

FRACTION operator+(FRACTION dt1, FRACTION dt2){
    FRACTION ketQua;

    // xử lý tử số
    ketQua.n = (dt1.n * dt2.d) + (dt2.n * dt1.d);

    // xử lý mẫu số
    ketQua.d = dt1.d * dt2.d;

    return ketQua;
}

int main(){
    // tạo đối tượng
    FRACTION dt1;
    FRACTION dt2 = FRACTION(1, 2);
    FRACTION dt3;

    dt1 = FRACTION(dt2);

    // nhập dữ liệu
    cout << "-------------------- NHAP DU LIEU --------------------\n";
    cin >> dt3;

    // hiển thị dữ liệu
    cout << "\n-------------------- HIEN THI DU LIEU --------------------\n";
    cout << dt1 << "\n\n";
    cout << dt2 << "\n\n";
    cout << dt3 << "\n\n";

    // gọi phương thức simplify() để rút gọn
    dt3.simplify();
    cout << "Sau khi rut gon: " << dt3 << "\n\n";

    // cộng 2 phân số
    FRACTION tong = dt1 + dt3;
    tong.simplify();

    cout << dt1 << " + " << dt3 << " = " << tong << "\n\n";

    return 0;
}