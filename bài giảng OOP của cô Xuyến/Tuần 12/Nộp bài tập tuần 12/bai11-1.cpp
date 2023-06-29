// Yêu cầu:
// 1. tạo lớp TDate
// 2. tạo đối tượng d1
// 3. tạo đối tượng d2
// 4. nhập dữ liệu
// 5. hiển thị dữ liệu

// 6. giữa 2 ngày nhập vào
// in ra [ngày/tháng/năm] sớm hơn

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// tạo lớp TDate
class TDate{
    private:
        short ngay;
        short thang;
        short nam;

    public:
        // hàm khởi tạo có tham số mặc định
        TDate(short data1 = 0, short data2 = 0, short data3 = 0){
            ngay = data1;
            thang = data2;
            nam = data3;
        }

        // hàm khởi tạo sao chép
        TDate(TDate &dt){
            ngay = dt.ngay;
            thang = dt.thang;
            nam = dt.nam;
        }

        // hàm nhập dữ liệu từ bàn phím
        void NhapDuLieu(){
            cout << "Nhap ngay: ";
            cin >> ngay;

            cout << "Nhap thang: ";
            cin >> thang;

            cout << "Nhap nam: ";
            cin >> nam;
        }

        // hàm hiển thị
        void HienThi(){
            string data_ngay = to_string(ngay);
            string data_thang = to_string(thang);
            
            if (ngay < 10)
            {
                data_ngay = "0" + data_ngay;
            }
            
            if (thang < 10)
            {
                data_thang = "0" + data_thang;
            }

            cout << data_ngay << "/" << data_thang << "/" << nam << "\n";
        }

        // hàm so sánh hai ngày tháng
        // hàm bạn
        friend int SoSanh(TDate dt1, TDate dt2);

        // hàm tính khoảng cách giữa 2 ngày tháng
        friend int Tinh_KhoangCach(TDate dt1, TDate dt2);
};

// nếu dt1 sớm hơn dt2          --> ketQua = 1
// nếu dt1 muộn hơn dt2         --> ketQua = -1
// nếu dt1 bằng dt2             --> ketQua = 0

int SoSanh(TDate dt1, TDate dt2){
    int ketQua;

    if (dt1.nam < dt2.nam)
    {
        ketQua = 1;        
    }
    else if (dt1.nam > dt2.nam)
    {
        ketQua = -1;
    }
    else if (dt1.nam == dt2.nam)
    {
        if (dt1.thang < dt2.thang)
        {
            ketQua = 1;
        }
        else if (dt1.thang > dt2.thang)
        {
            ketQua = -1;
        }
        else if (dt1.thang == dt2.thang)
        {
            if (dt1.ngay < dt2.ngay)
            {
                ketQua = 1;
            }
            else if (dt1.ngay > dt2.ngay)
            {
                ketQua = -1;
            }
            else if (dt1.ngay == dt2.ngay)
            {
                ketQua = 0;
            }
            
        }
        
    }

    return ketQua;
}

int Tinh_KhoangCach(TDate dt1, TDate dt2){
    int ketQua;

    // tạo mảng tổng số ngày trong năm
    int arr_nam1[1] = {365};
    int arr_nam2[1] = {365};

    // tạo mảng tổng số ngày trong tháng
    int arr_thang1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int arr_thang2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // nếu là năm nhuận
    // thì tháng 2 là 29 ngày
    // còn 1 năm có 366 ngày
    if (dt1.nam % 400 == 0 || (dt1.nam % 4 == 0 && dt1.nam % 100 != 0))
    {
        arr_nam1[0] = 366;
        arr_thang1[dt1.thang - 1] = 29;         // dt1.thang chính là tháng 2
    }

    if (dt2.nam % 400 == 0 || (dt2.nam % 4 == 0 && dt2.nam % 100 != 0))
    {
        arr_nam2[0] = 366;
        arr_thang2[dt2.thang - 1] = 29;         // d2.thang chính là tháng 2
    }

    int tong_dt1 = 0;
    int tong_dt2 = 0;

    if (dt1.nam == dt2.nam)
    {
        for (int i = 0; i < dt1.thang - 1; i++)
        {
            tong_dt1 = tong_dt1 + arr_thang1[i];
        }
        tong_dt1 = tong_dt1 + dt1.ngay;
        
        for (int i = 0; i < dt2.thang - 1; i++)
        {
            tong_dt2 = tong_dt2 + arr_thang2[i];
        }
        tong_dt2 = tong_dt2 + dt2.ngay;
    }
    cout << "\ntong 1: " << tong_dt1 << "\n\n";
    cout << "\ntong 2: " << tong_dt2 << "\n\n";
    ketQua = abs(tong_dt1 - tong_dt2);

    return ketQua;
}

int main(){
    // tạo đối tượng d1 và d2
    TDate d1;
    TDate d2;

    // gọi phương thức nhập dữ liệu
    cout << "-------------------- NHAP DU LIEU --------------------\n";
    d1.NhapDuLieu();
    cout << "\n";

    d2.NhapDuLieu();
    cout << "\n";

    // gọi phương thức hiển thị
    cout << "-------------------- HIEN THI DU LIEU --------------------\n";
    d1.HienThi();
    cout << "\n";

    d2.HienThi();
    cout << "\n";

   // in ra ngày sớm hơn
   cout << "-------------------- IN RA NGAY SOM HON --------------------\n";
    if (SoSanh(d1, d2) == 1)
    {
        d1.HienThi();
    }
    else if (SoSanh(d1, d2) == -1)
    {
        d2.HienThi();
    }
    else if (SoSanh(d1, d2) == 0)
    {
        // hai ngày bằng nhau
        // nên in luôn d1
        d1.HienThi();
    }

    // in ra khoảng cách của d1 và d2
    cout << "\nKhoang cach cua d1 va d2 la: ";
    cout << Tinh_KhoangCach(d1, d2) << "\n\n";

    return 0;
}