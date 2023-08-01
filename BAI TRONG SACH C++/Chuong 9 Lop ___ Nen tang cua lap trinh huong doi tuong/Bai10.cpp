// Yeu cau:
// 1. tao lop TCircle
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep (copy)
// 5. ham tinh khoang cach giua 2 tam
// 6. ham kiem tra 2 hinh tron co giao nhau khong
// 7. ham tinh chu vi
// 8. ham tinh dien tich
// 9. in ra danh sach hinh tron tang dan theo dien tich

// tao 3 doi tuong hinh tron

#include <iostream>
#include <cmath>
using namespace std;

class TPoint{
	public:
		float x;
		float y;
};

class TCircle{
	private:
		TPoint dt_diem;
		float ban_kinh;
		
	public:
		// ham khoi tao khong tham so
		TCircle(){
			dt_diem.x = 0;
			dt_diem.y = 0;
			ban_kinh = 0;
		}
		
		// ham khoi tao co tham so
		TCircle(float data1, float data2, float data3){
			dt_diem.x = data1;
			dt_diem.y = data2;
			ban_kinh = data3;
		}
		
		// ham khoi tao sao chep
		TCircle(const TCircle &dt){
			dt_diem.x = dt.dt_diem.x;
			dt_diem.y = dt.dt_diem.y;
			ban_kinh = dt.ban_kinh;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap x: ";
			cin >> dt_diem.x;
			
			cout << "Nhap y: ";
			cin >> dt_diem.y;
			
			cout << "Nhap ban kinh: ";
			cin >> ban_kinh;
		}
		
		// ham hien thi
		void HienThi(){
			cout << "[";
			cout << "(" << dt_diem.x << ", ";
			cout << dt_diem.y << "); ban kinh = ";
			cout << ban_kinh;
			cout << "]";
		}
		
		// ham ban
		// tinh khoang cach giua 2 tam
		friend float Tinh_KhoangCach_Giua_2_Tam(TCircle dt1, TCircle dt2);
		
		// ham ban
		// kiem tra 2 hinh tron co giao nhau hay khong
		friend bool KiemTra_2_HinhTron_GiaoNhau(TCircle dt1, TCircle dt2);
		
		// ham tinh chu vi
		float TinhChuVi(){
			return 2 * 3.14 * ban_kinh;
		}
		
		// ham tinh dien tich
		float TinhDienTich(){
			return 3.14 * ban_kinh * ban_kinh;
		}
};

float Tinh_KhoangCach_Giua_2_Tam(TCircle dt1, TCircle dt2){
	float bien1 = pow(dt2.dt_diem.x - dt1.dt_diem.x, 2);
	float bien2 = pow(dt2.dt_diem.y - dt1.dt_diem.y, 2);
	
	float khoang_cach = sqrt(bien1 + bien2);
	
	return khoang_cach;
}

bool KiemTra_2_HinhTron_GiaoNhau(TCircle dt1, TCircle dt2){
	bool ketQua = false;
	
	// goi A la tam hinh tron thu nhat
	// goi B la tam hinh tron thu hai
	// AB la khoang cach giua hai tam
	
	float AB = Tinh_KhoangCach_Giua_2_Tam(dt1, dt2);
	
	if(dt1.ban_kinh + dt2.ban_kinh < AB){
		ketQua = false;
	}
	else if(dt1.ban_kinh + dt2.ban_kinh == AB){
		// day la loai giao nhau tai 1 diem
		// ben ngoai
		ketQua = true;
	}
	else if(min(dt1.ban_kinh, dt2.ban_kinh) + AB == max(dt1.ban_kinh, dt2.ban_kinh)){
		// day la loai giao nhau tai 1 diem
		// ben trong
		ketQua = true;
	}
	else if(min(dt1.ban_kinh, dt2.ban_kinh) + AB < max(dt1.ban_kinh, dt2.ban_kinh)){
		// day la loai trong nhau
		// va khong giao nhau
		ketQua = false;
	}
	else if(AB == 0 && dt1.ban_kinh == dt2.ban_kinh){
		// day la loai giao nhau tai tat ca cac diem
		ketQua = true;
	}
	else
	{
		// cac truong hop con lai la giao nhau tai 2 diem
		ketQua = true;
	}
	
	return ketQua;
}

int main(){
	// tao doi tuong
	TCircle dt1 = TCircle(0, 0, 2);
	TCircle dt2 = TCircle(dt1);
	TCircle dt3;
	TCircle dt4 = TCircle(9, 5, 1);
	
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
	
	// goi ham ban
	// tinh khoang cach giua 2 tam dt1 va dt3
	float khoang_cach = Tinh_KhoangCach_Giua_2_Tam(dt1, dt3);
	cout << "\nKhoang cach giua ";
	dt1.HienThi();
	cout << " va ";
	dt3.HienThi();
	cout << " la: " << khoang_cach << "\n\n";
	
	// goi ham ban
	// kiem tra 2 hinh tron giao nhau
	if(KiemTra_2_HinhTron_GiaoNhau(dt1, dt3) == true){
		cout << "dt1 va dt3 giao nhau\n\n";
	}
	else{
		cout << "dt1 va dt3 khong giao nhau\n\n";
	}
	
	// in ra danh sach hinh tron
	// sap xep tang dan
	// theo dien tich
	TCircle arr[4] = {dt1, dt2, dt3, dt4};
	cout << "Ban dau:\n";
	for(int i = 0; i < 4; i++){
		arr[i].HienThi();
		cout << "\n";
	}
	
	TCircle temp;
	for(int i = 0; i < 4; i++){
		for(int j = i + 1; j < 4; j++){
			if(arr[i].TinhDienTich() > arr[j].TinhDienTich()){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout << "\nSau khi sap xep:\n";
	for(int i = 0; i < 4; i++){
		arr[i].HienThi();
		cout << "\n";
	}
	
	return 0;
}
