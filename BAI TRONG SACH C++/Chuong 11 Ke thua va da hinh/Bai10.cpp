// Yeu cau:
// 1. tao lop TPoint
// 2. ham khoi tao khong tham so TPoint
// 3. ham khoi tao co tham so TPoint
// 4. ham khoi tao sao chep TPoint
// 5. ham nhap du lieu
// 6. ham hien thi

// 7. tao lop TCircle (ke thua lop TPoint)
// 8. ham khoi tao khong tham so TCircle
// 9. ham khoi tao co tham so TCircle
// 10. ham khoi tao sao chep TCircle
// 11. ghi de ham nhap du lieu
// 12. ghi de ham hien thi
// 13. ham kiem tra vi tri tuong doi (giao nhau/khong giao nhau)
// 14. ham tinh chu vi
// 15. ham tinh dien tich

#include <iostream>
#include <cmath>
using namespace std;

// tao lop TPoint
class TPoint{
	protected:
		double x;
		double y;
		double z;
		
	protected:
		// ham khoi tao khong tham so
		TPoint(){
			x = 0;
			y = 0;
			z = 0;
		}
		
		// ham khoi tao co tham so
		TPoint(double data1, double data2, double data3){
			x = data1;
			y = data2;
			z = data3;
		}
		
		// ham khoi tao sao chep
		TPoint(const TPoint &dt){
			x = dt.x;
			y = dt.y;
			z = dt.z;
		}
		
		// ham nhap du lieu
		void virtual NhapDuLieu(){
			cout << "Nhap x: ";
			cin >> x;
			
			cout << "Nhap y: ";
			cin >> y;
			
			cout << "Nhap z: ";
			cin >> z;
		}
		
		// ham hien thi
		void virtual HienThi(){
			cout << "[(" << x << ", ";
			cout << y << ", ";
			cout << z << ")";
		}
};

class TCircle : public TPoint{
	private:
		float ban_kinh;
		
	public:
		// ham khoi tao khong tham so
		TCircle() : TPoint(){
			ban_kinh = 0;
		}
		
		// ham khoi tao co tham so
		TCircle(double data1, double data2,
					double data3, float data4) :
						TPoint(data1, data2, data3){
		
			ban_kinh = data4;
		}
		
		// ham khoi tao sao chep
		TCircle(const TCircle &dt) : TPoint(dt){
			ban_kinh = dt.ban_kinh;
		}
		
		// ghi de ham nhap du lieu
		void NhapDuLieu(){
			TPoint::NhapDuLieu();
			
			cout << "Nhap ban kinh: ";
			cin >> ban_kinh;
		}
		
		// ghi de ham hien thi
		void HienThi(){
			TPoint::HienThi();
			
			cout << " r = " << ban_kinh << "]";
		}
		
		// ham ban
		// ham kiem tra vi tri tuong doi
		friend bool KiemTra_ViTri_TuongDoi(TCircle dt1, TCircle dt2);
		
		// ham tinh chu vi
		float Tinh_ChuVi(){
			float chu_vi = 2 * ban_kinh * 3.14;
			
			return chu_vi;
		}
		
		// ham tinh dien tich
		float Tinh_DienTich(){
			float dien_tich = 3.14 * ban_kinh * ban_kinh;
			
			return dien_tich;
		}
};

bool KiemTra_ViTri_TuongDoi(TCircle dt1, TCircle dt2){
	bool ketQua = false;
	
	// goi A la tam cua duong tron dt1
	// goi B la tam cua duong tron dt2
	// AB la khoang cach giua 2 tam duong tron
	
	float data1 = pow(dt2.x - dt1.x, 2);
	float data2 = pow(dt2.y - dt1.y, 2);
	float AB = sqrt(data1 + data2);
	
	if(dt1.ban_kinh + dt2.ban_kinh < AB){
		// khong giao nhau
		ketQua = false;
	}
	else if(dt1.ban_kinh + dt2.ban_kinh == AB){
		// giao nhau tai 1 diem
		// giao nhau ben ngoai
		ketQua = true;
	}
	else if(dt1.ban_kinh == dt2.ban_kinh && AB == 0){
		// 2 hinh tron trung nhau
		// giao nhau tai moi diem
		ketQua = true;
	}
	else if(min(dt1.ban_kinh, dt2.ban_kinh) + AB == max(dt1.ban_kinh, dt2.ban_kinh)){
		// giao nhau tai 1 diem
		// giao nhau ben trong
		ketQua = true;
	}
	else if(min(dt1.ban_kinh, dt2.ban_kinh) + AB < max(dt1.ban_kinh, dt2.ban_kinh)){
		// trong nhau
		// khong giao nhau
		ketQua = false;
	}
	else{
		// giao nhau tai 2 diem
		ketQua = true;
	}
	
	return ketQua;
}

int main(){
	// tao doi tuong
	TCircle dt1 = TCircle(0, 0, 0, 2);
	TCircle dt2 = TCircle(dt1);
	TCircle dt3;
	
	// goi phuong thuc nhap du lieu
	cout << "\n---------- NHAP DU LIEU dt3 ----------\n";
	dt3.NhapDuLieu();
	
	// goi phuong thuc hien thi
	cout << "\n---------- HIEN THI DU LIEU ----------\n";
	cout << "Doi tuong dt1:\n";
	dt1.HienThi();
	
	cout << "\n\nDoi tuong dt2:\n";
	dt2.HienThi();
	
	cout << "\n\nDoi tuong dt3:\n";
	dt3.HienThi();
	
	// kiem tra hinh tron
	// co giao nhau khong
	cout << "\n\n---------- KIEM TRA GIAO NHAU ----------\n";
	if(KiemTra_ViTri_TuongDoi(dt1, dt3) == true){
		dt1.HienThi();
		cout << " va ";
		dt3.HienThi();
		cout << "\n=> Giao nhau";
	}
	else if(KiemTra_ViTri_TuongDoi(dt1, dt3) == false){
		dt1.HienThi();
		cout << " va ";
		dt3.HienThi();
		cout << "\n=> Khong giao nhau";
	}
	
	// tao mang
	TCircle arr[3] = {dt1, dt2, dt3};
	
	// tao bien temp
	TCircle temp;
	
	// sap xep tang dan
	// theo dien tich
	for(int i = 0; i <= 3-2; i++){
		for(int j = i + 1; j <= 3-1; j++){
			if(arr[i].Tinh_DienTich() > arr[j].Tinh_DienTich()){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout << "\n\n---------- SAP XEP TANG DAN (THEO DIEN TICH) ----------\n";
	for(int i = 0; i < 3; i++){
		arr[i].HienThi();
		cout << "\n";
	}
	
	// tinh tong chu vi
	// cac hinh tron
	float tong = 0;
	for(int i = 0; i < 3; i++){
		tong = tong + arr[i].Tinh_ChuVi();
	}
	
	cout << "\nTong chu vi cac hinh tron = " << tong << "\n";
	
	return 0;
}
