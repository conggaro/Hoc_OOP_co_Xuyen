// Yêu cầu:
// 1. nạp chồng toán tử >>
// 2. nạp chồng toán tử <<
// 3. nạp chồng toán tử +
// 4. nạp chồng toán tử -
// 5. nạp chồng toán tử *
// 6. nạp chồng toán tử /
// 7. nạp chồng toán tử >
// 8. nạp chồng toán tử <
// 9. nạp chồng toán tử ==
// 10. hàm rút gọn phân số Rut_Gon_PhanSo()
// 11. nạp chồng toán tử một ngôi ++ (loại tiền tố)
// 12. nạp chồng toán tử một ngôi ++ (loại hậu tố)
// 13. nạp chồng toán tử một ngôi -- (loại tiền tố)
// 14. nạp chồng toán tử một ngôi -- (loại hậu tố)
// 15. nạp chồng toán tử =
// 16. nạp chồng toán tử +=
// 17. nạp chồng toán tử -=
// 18. chuyển float => PhanSo
// 19. chuyển PhanSo => float

#include <iostream>
using namespace std;

// hàm tìm ước chung lớn nhất
// thuật toán này nó 1 bug là
// nếu a hoặc b bằng 0
// thì cái câu lệnh lặp while nó bị lặp vĩnh cửu luôn
// cái vòng lặp while kia nó chỉ dừng
// khi bạn ra được sản phẩm a == b
int Ham_Tim_UCLN(int a, int b){
    // tạo biến UCLN
    int UCLN = 0;

    // nếu a = 0
    // hoặc b = 0
    // thì ước chung lớn nhất = 1
    if (a == 0 || b == 0)
    {
        return UCLN;
    }

    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else if (b > a)
        {
            b = b - a;
        }
    }

    UCLN = a;

    return UCLN;
}

// tạo lớp PhanSo
class PhanSo{
    private:
        int tu;
        int mau;

    public:
        // hàm khởi tạo không tham số
        PhanSo(){
            int tu = 0;
            int mau = 1;
        }

        // hàm khởi tạo có tham số
        PhanSo(int data1, int data2){
            if(data2 == 0){
                tu = 0;
                mau = 1;
            }
            else if(data2 != 0){
                tu = data1;
                mau = data2;
            }
        }

        // hàm khởi tạo sao chép
        PhanSo(const PhanSo &dt){
            tu = dt.tu;
            mau = dt.mau;
        }

        // hàm hủy
        ~PhanSo(){
            // cout << "Huy doi tuong\n\n";
        }

        // nạp chồng toán tử nhập >>
        friend istream &operator>>(istream &dt_cin, PhanSo &dt);

        // nạp chồng toán tử hiển thị <<
        friend ostream &operator<<(ostream &dt_cout, PhanSo &dt);

        // nạp chồng toán tử +
        friend PhanSo operator+(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử -
        friend PhanSo operator-(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử *
        friend PhanSo operator*(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử /
        friend PhanSo operator/(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử >
        friend bool operator>(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử <
        friend bool operator<(PhanSo dt1, PhanSo dt2);

        // nạp chồng toán tử ==
        friend bool operator==(PhanSo dt1, PhanSo dt2);

        // hàm rút gọn phân số
        void Rut_Gon_PhanSo(){
            int UCLN = Ham_Tim_UCLN(tu, mau);

            if(UCLN == 0){
                return;
            }

            // lấy tử và mẫu
            // chia cho ước chung lớn nhất
            // để rút gọn phân số
            tu = tu / UCLN;
            mau = mau / UCLN;
        }

        // nạp chồng toán tử một ngôi
        // nạp chồng toán tử ++ (loại tiền tố)
        PhanSo operator++(){
            PhanSo ketQua;

            tu += mau;
            ketQua.tu = tu;
            ketQua.mau = mau;

            return ketQua;
        }

        // nạp chồng toán tử một ngôi
        // nạp chồng toán tử ++ (loại hậu tố)
        PhanSo operator++(int){
            PhanSo ketQua;

            ketQua.tu = tu;
            ketQua.mau = mau;
            tu += mau;

            return ketQua;
        }

        // nạp chồng toán tử một ngôi
        // nạp chồng toán tử -- (loại tiền tố)
        PhanSo operator--(){
            PhanSo ketQua;

            tu -= mau;
            ketQua.tu = tu;
            ketQua.mau = mau;

            return ketQua;
        }

        // nạp chồng toán tử một ngôi
        // nạp chồng toán tử -- (loại hậu tố)
        PhanSo operator--(int){
            PhanSo ketQua;

            ketQua.tu = tu;
            ketQua.mau = mau;
            tu -= mau;

            return ketQua;
        }

        // nạp chồng toán tử =
        void operator=(PhanSo dt){
            tu = dt.tu;
            mau = dt.mau;
        }

        // nạp chồng toán tử +=
        void operator+=(PhanSo dt){
            tu = (tu * dt.mau) + (dt.tu * mau);
            mau = mau * dt.mau;
        }

        // nạp chồng toán tử -=
        void operator-=(PhanSo dt){
            tu = (tu * dt.mau) - (dt.tu * mau);
            mau = mau * dt.mau;
        }

        // chuyển float => PhanSo
        // nó giống như nạp chồng hàm khởi tạo vậy
        PhanSo(float n){
            mau = 1;

            while (n - floor(n) > 0)
            {
                mau = mau * 10;
                n = n * 10;
            }
            
            tu = (int)n;
        }

        // chuyển PhanSo => float
        operator float(){
            float ketQua = (float)tu / mau;

            return ketQua;
        }
};

istream &operator>>(istream &dt_cin, PhanSo &dt){
    cout << "Nhap tu: ";
    dt_cin >> dt.tu;

    cout << "Nhap mau: ";
    dt_cin >> dt.mau;

    if(dt.mau == 0){
        dt.tu = 0;
        dt.mau = 1;
    }

    return dt_cin;
}

ostream &operator<<(ostream &dt_cout, PhanSo &dt){
    dt_cout << dt.tu << "/" << dt.mau;

    return dt_cout;
}

PhanSo operator+(PhanSo dt1, PhanSo dt2){
    PhanSo ketQua;

    ketQua.tu = (dt1.tu * dt2.mau) + (dt2.tu * dt1.mau);
    ketQua.mau = dt1.mau * dt2.mau;

    return ketQua;
}

PhanSo operator-(PhanSo dt1, PhanSo dt2){
    PhanSo ketQua;

    ketQua.tu = (dt1.tu * dt2.mau) - (dt2.tu * dt1.mau);
    ketQua.mau = dt1.mau * dt2.mau;

    return ketQua;
}

PhanSo operator*(PhanSo dt1, PhanSo dt2){
    PhanSo ketQua;

    ketQua.tu = dt1.tu * dt2.tu;
    ketQua.mau = dt1.mau * dt2.mau;

    return ketQua;
}

PhanSo operator/(PhanSo dt1, PhanSo dt2){
    PhanSo ketQua;

    if(dt2.tu == 0){
        ketQua.tu = 0;
        ketQua.mau = 1;

        cout << "\nKhong co phep chia cho 0\n\n";

        return ketQua;
    }
    else if(dt2.tu != 0){
        ketQua.tu = dt1.tu * dt2.mau;
        ketQua.mau = dt1.mau * dt2.tu;
    }

    return ketQua;
}

bool operator>(PhanSo dt1, PhanSo dt2){
    bool ketQua = false;

    float data1 = (float)dt1.tu / dt1.mau;
    float data2 = (float)dt2.tu / dt2.mau;

    if (data1 > data2)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }
    
    return ketQua;
}

bool operator<(PhanSo dt1, PhanSo dt2){
    bool ketQua = false;

    float data1 = (float)dt1.tu / dt1.mau;
    float data2 = (float)dt2.tu / dt2.mau;

    if (data1 < data2)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }
    
    return ketQua;
}

bool operator==(PhanSo dt1, PhanSo dt2){
    bool ketQua = false;

    float data1 = (float)dt1.tu / dt1.mau;
    float data2 = (float)dt2.tu / dt2.mau;

    if (data1 == data2)
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
    // tạo đối tượng
    PhanSo dt1 = PhanSo(3, 9);

    PhanSo dt2;
    dt2 = PhanSo(dt1);

    PhanSo dt3;

    // nhập dữ liệu
    cin >> dt3;

    // hiển thị dữ liệu
    dt1.Rut_Gon_PhanSo();
    dt2.Rut_Gon_PhanSo();
    dt3.Rut_Gon_PhanSo();
    cout << "\n";
    cout << "dt1: " << dt1 << "\n";
    cout << "dt2: " << dt2 << "\n";
    cout << "dt3: " << dt3 << "\n\n";

    PhanSo tong = dt1 + dt2;
    tong.Rut_Gon_PhanSo();
    cout << dt1 << " + " << dt2 << " = " << tong << "\n";

    PhanSo hieu = dt1 - dt2;
    hieu.Rut_Gon_PhanSo();
    cout << dt1 << " - " << dt2 << " = " << hieu << "\n";

    PhanSo tich = dt1 * dt2;
    tich.Rut_Gon_PhanSo();
    cout << dt1 << " * " << dt2 << " = " << tich << "\n";

    PhanSo thuong = dt1 / dt2;
    thuong.Rut_Gon_PhanSo();
    cout << dt1 << " / " << dt2 << " = " << thuong << "\n\n";

    // so sánh dt1 và dt3
    cout << dt1 << " > " << dt3 << "\t\t=> ket qua: " << (dt1 > dt3) << "\n";
    cout << dt1 << " < " << dt3 << "\t\t=> ket qua: " << (dt1 < dt3) << "\n";
    cout << dt1 << " == " << dt3 << "\t\t=> ket qua: " << (dt1 == dt3) << "\n\n";

    // sử dụng dt3 ++
    PhanSo gia_tri1 = dt3;
    cout << dt3 << "++ = " << (gia_tri1 ++) << "\n";
    cout << "Luc sau: " <<  gia_tri1 << "\n\n";

    // sử dụng ++ dt3
    PhanSo gia_tri2 = dt3;
    cout << "++" << dt3 << " = " << (++ gia_tri2) << "\n\n";

    // sử dụng dt3 --
    PhanSo gia_tri3 = dt3;
    cout << dt3 << "-- = " << (gia_tri3 --) << "\n";
    cout << "Luc sau: " <<  gia_tri3 << "\n\n";

    // sử dụng -- dt3
    PhanSo gia_tri4 = dt3;
    cout << "--" << dt3 << " = " << (-- gia_tri4) << "\n\n";

    // chuyển PhanSo => float
    cout << "Chuyen PhanSo => float\n";
    float n = (float)dt3;
    cout << dt3 << " => " << n << "\n\n";

    // chuyển float => PhanSo
    cout << "Chuyen float => PhanSo\n";
    PhanSo dt4 = n;
    dt4.Rut_Gon_PhanSo();
    cout << n << " => " << dt4 << "\n\n";

    return 0;
}