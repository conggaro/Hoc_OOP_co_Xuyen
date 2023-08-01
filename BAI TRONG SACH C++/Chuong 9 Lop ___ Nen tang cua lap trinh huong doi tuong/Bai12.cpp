// Yeu cau:
// 1. tao lop TRectangle
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham huy
// 6. ham nhap du lieu
// 7. ham hien thi
// 8. ham tinh chu vi
// 9. ham tinh dien tich
// 10. ham kiem tra hinh chu nhat co phai hinh vuong khong
// 11. nhap n
// 12. nhap n hinh chu nhat
// 13. hien thi n hinh chu nhat

#include <iostream>
#define SIZE 100
using namespace std;

class TRectangle{
	private:
		float chieu_dai;
		float chieu_rong;
		
	public:
		// ham khoi tao khong tham so
		TRectangle(){
			chieu_dai = 0;
			chieu_rong = 0;
		}
		
		// ham khoi tao co tham so
		TRectangle(float data1, float data2){
			chieu_dai = data1;
			chieu_rong = data2;
		}
		
		// ham khoi tao sao chep
		TRectangle(const TRectangle &dt){
			chieu_dai = dt.chieu_dai;
			chieu_rong = dt.chieu_rong;
		}
		
		// ham huy
		~TRectangle(){
			// cout << "Huy doi tuong\n\n";
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap chieu dai: ";
			cin >> chieu_dai;
			
			cout << "Nhap chieu rong: ";
			cin >> chieu_rong;
		}
		
		// ham hien thi
		void HienThi(){
			cout << "[" << chieu_dai << ", ";
			cout << chieu_rong << "]";
		}
		
		// ham tinh chu vi
		float Ham_TinhChuVi(){
			return (chieu_dai + chieu_rong) * 2;
		}
		
		// ham tinh dien tich
		float Ham_TinhDienTich(){
			return chieu_dai * chieu_rong;
		}
		
		// ham kiem tra hinh vuong
		bool Ham_KiemTra_HinhVuong(){
			bool ketQua = false;
			
			if(chieu_dai == chieu_rong){
				ketQua = true;
			}
			
			return ketQua;
		}
};

int main(){
	// nhap n
	cout << "Nhap n: ";
	int n = 0;
	cin >> n;
	
	// tao mang
	TRectangle arr[SIZE];
	
	cout << "\n-------------------- NHAP DU LIEU --------------------\n";
	for(int i = 0; i < n; i++){
		arr[i].NhapDuLieu();
		cout << "\n";
	}
	
	cout << "-------------------- HIEN THI DU LIEU --------------------\n";
	for(int i = 0; i < n; i++){
		arr[i].HienThi();
		cout << "\n";
	}
	
	// kiem tra canh dong hinh vuong
	int dem_hinh_vuong = 0;
	
	for(int i = 0; i < n; i++){
		if(arr[i].Ham_KiemTra_HinhVuong() == true){
			dem_hinh_vuong ++;
		}
	}
	
	cout << "\nCo " << dem_hinh_vuong;
	cout << " manh dat hinh vuong\n";
	
	if(dem_hinh_vuong != 0){
		cout << "\n-------------------- DANH SACH HINH VUONG --------------------\n";
		for(int i = 0; i < n; i++){
			if(arr[i].Ham_KiemTra_HinhVuong() == true){
				arr[i].HienThi();
				cout << "\n";
			}
		}
	}
	
	// in ra chu vi
	cout << "\n-------------------- IN RA CHU VI --------------------\n";
	for(int i = 0; i < n; i++){
		cout << arr[i].Ham_TinhChuVi() << "\n";
	}
	
	cout << "\n-------------------- IN RA DIEN TICH --------------------\n";
	for(int i = 0; i < n; i++){
		cout << arr[i].Ham_TinhDienTich() << "\n";
	}
	
	// in ra canh dong co dien tich nho nhat
	float min = arr[0].Ham_TinhDienTich();
	
	// tao dt_min
	TRectangle dt_min;
	
	for(int i = 0; i < n; i++){
		if(min >= arr[i].Ham_TinhDienTich()){
			min = arr[i].Ham_TinhDienTich();
			dt_min = arr[i];
		}
	}
	
	cout << "\nCanh dong co dien tich nho nhat la: ";
	dt_min.HienThi();
	
	// in ra canh dong co dien tich lon nhat
	float max = arr[0].Ham_TinhDienTich();
	
	// tao dt_max
	TRectangle dt_max;
	
	for(int i = 0; i < n; i++){
		if(max <= arr[i].Ham_TinhDienTich()){
			max = arr[i].Ham_TinhDienTich();
			dt_max = arr[i];
		}
	}
	
	cout << "\n\nCanh dong co dien tich lon nhat la: ";
	dt_max.HienThi();
	
	// tinh tong dien tich tat ca canh dong
	float tong_dien_tich = 0;
	
	for(int i = 0; i < n; i++){
		tong_dien_tich = tong_dien_tich + arr[i].Ham_TinhDienTich();
	}
	
	cout << "\n\nTong dien tich la: " << tong_dien_tich << "\n";
	
	return 0;
}
