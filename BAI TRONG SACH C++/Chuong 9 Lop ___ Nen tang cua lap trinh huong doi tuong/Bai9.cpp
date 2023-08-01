// Yeu cau:
// 1. tao lop TPoint
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep (copy)
// 5. ham nhap du lieu
// 6. ham hien thi du lieu
// 7. ham tinh khoang cach giua 2 diem
// 8. ham kiem tra 2 diem trung nhau
// 9. ham kiem tra 3 diem co phai la 3 dinh cua 1 tam giac khong

#include <iostream>
#include <cmath>
using namespace std;

class TPoint{
	private:
		float x;			// hoanh do
		float y;			// tung do
		
	public:
		// ham khoi tao khong tham so
		TPoint(){
			x = 0;
			y = 0;
		}
		
		// ham khoi tao co tham so
		TPoint(float data1, float data2){
			x = data1;
			y = data2;
		}
		
		// ham khoi tao sao chep
		TPoint(const TPoint &dt){
			x = dt.x;
			y = dt.y;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap x: ";
			cin >> x;
			
			cout << "Nhap y: ";
			cin >> y;
		}
		
		// ham hien thi
		void HienThi(){
			cout << "(" << x << ", " << y << ")";
		}
		
		// ham ban
		// tinh khoang cach giua 2 diem
		friend float Tinh_KhoangCach_2_Diem(TPoint dt1, TPoint dt2);
		
		// ham ban
		// kiem tra 2 diem trung nhau
		friend bool KiemTra_2_Diem_TrungNhau(TPoint dt1, TPoint dt2);
		
		// ham ban
		// kiem tra 3 diem la 3 dinh cua 1 tam giac
		friend bool KiemTra_3_Diem_La_3_Dinh_TamGiac(TPoint dt1, TPoint dt2, TPoint dt3);
};

float Tinh_KhoangCach_2_Diem(TPoint dt1, TPoint dt2){
	float tong1 = pow(dt2.x - dt1.x, 2);
	float tong2 = pow(dt2.y - dt1.y, 2);
			
	float khoang_cach = sqrt(tong1 + tong2);
			
	return khoang_cach;
}

bool KiemTra_2_Diem_TrungNhau(TPoint dt1, TPoint dt2){
	bool ketQua = false;
	
	if(Tinh_KhoangCach_2_Diem(dt1, dt2) == 0){
		ketQua = true;
	}
	else{
		ketQua = false;
	}
	return ketQua;
}

bool KiemTra_3_Diem_La_3_Dinh_TamGiac(TPoint dt1, TPoint dt2, TPoint dt3){
	bool ketQua = false;
	
	float canh_a = Tinh_KhoangCach_2_Diem(dt1, dt2);
	float canh_b = Tinh_KhoangCach_2_Diem(dt1, dt3);
	float canh_c = Tinh_KhoangCach_2_Diem(dt2, dt3);
	
	bool kiemTra1 = canh_a > 0 ? true : false;
	bool kiemTra2 = canh_b > 0 ? true : false;
	bool kiemTra3 = canh_c > 0 ? true : false;
	
	bool kiemTra4 = canh_a + canh_b > canh_c ? true : false;
	bool kiemTra5 = canh_a + canh_c > canh_b ? true : false;
	bool kiemTra6 = canh_b + canh_c > canh_a ? true : false;
	
	if(kiemTra1 && kiemTra2 && kiemTra3 && kiemTra4 && kiemTra5 && kiemTra6){
		ketQua = true;
	}
	else{
		ketQua = false;
	}
	
	return ketQua;
}

int main(){
	// tao doi tuong
	TPoint dt1 = TPoint(5, 5);
	TPoint dt2 = TPoint(dt1);
	TPoint dt3;
	TPoint dt4 = TPoint(0, 5);
	TPoint dt5 = TPoint(0, 0);
	
	// goi phuong thuc nhap du lieu
	dt3.NhapDuLieu();
	
	// goi phuong thuc hien thi
	cout << "\n";
	dt1.HienThi();
	cout << "\n";
	
	dt2.HienThi();
	cout << "\n";
	
	dt3.HienThi();
	cout << "\n";
	
	dt4.HienThi();
	cout << "\n";
	
	dt5.HienThi();
	cout << "\n\n";
	
	// goi ham ban tinh khoang cach
	// de tinh khoang cach giua dt1 va dt3
	float khoang_cach = Tinh_KhoangCach_2_Diem(dt1, dt3);
	cout << "Khoang cach giua ";
	dt1.HienThi();
	cout << " va ";
	dt3.HienThi();
	cout << " la: " << khoang_cach << "\n\n";
	
	// goi ham ban kiem tra 2 diem trung nhau
	if(KiemTra_2_Diem_TrungNhau(dt1, dt3) == true){
		cout << "Ket qua:\n";
		dt1.HienThi();
		cout << " va ";
		dt3.HienThi();
		cout << " trung nhau\n\n";
	}
	else if(KiemTra_2_Diem_TrungNhau(dt1, dt3) == false){
		cout << "Ket qua:\n";
		dt1.HienThi();
		cout << " va ";
		dt3.HienThi();
		cout << " khong trung nhau\n\n";
	}
	
	// goi ham ban
	// kiem tra 3 diem la 3 dinh cua 1 tam giac
	if(KiemTra_3_Diem_La_3_Dinh_TamGiac(dt1, dt4, dt3) == true){
		cout << "Ba diem ";
		dt1.HienThi();
		cout << ", ";
		dt4.HienThi();
		cout << ", ";
		dt3.HienThi();
		cout << " la 3 dinh cua 1 tam giac\n\n";
	}
	else{
		cout << "Ba diem dt1, dt2, dt3 khong la 3 dinh cua 1 tam giac\n\n";
	}
	
	// kiem tra 3 diem thang hang
	if(KiemTra_3_Diem_La_3_Dinh_TamGiac(dt1, dt5, dt3) == false){
		cout << "Ba diem ";
		dt1.HienThi();
		cout << ", ";
		dt5.HienThi();
		cout << ", ";
		dt3.HienThi();
		cout << " la 3 diem thang hang\n";
	}
	else{
		cout << "Ba diem ";
		dt1.HienThi();
		cout << ", ";
		dt5.HienThi();
		cout << ", ";
		dt3.HienThi();
		cout << " la 3 diem khong thang hang\n";
	}
	
	return 0;
}
