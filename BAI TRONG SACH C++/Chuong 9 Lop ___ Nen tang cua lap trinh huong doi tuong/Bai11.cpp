// Yeu cau:
// 1. tao lop TPho
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham nhap du lieu
// 6. ham hien thi
// 7. ham tinh tien

// 8. tinh tien tat ca bat pho

#include <iostream>
#define SIZE 100
using namespace std;

class TPho{
	private:
		float so_luong_ThitBo;		// tinh theo gram
		float banh_pho;				// tinh theo gram
		float hanh;					// tinh theo gram
		float nuoc;					// tinh theo lit
	
	public:
		// ham khoi tao khong tham so
		TPho(){
			so_luong_ThitBo = 0;
			banh_pho = 0;
			hanh = 0;
			nuoc = 0;
		}
		
		// ham khoi tao co tham so
		TPho(float data1, float data2, float data3, float data4){
			so_luong_ThitBo = data1;
			banh_pho = data2;
			hanh = data3;
			nuoc = data4;
		}
		
		// ham khoi tao sao chep
		TPho(const TPho &dt){
			so_luong_ThitBo = dt.so_luong_ThitBo;
			banh_pho = dt.banh_pho;
			hanh = dt.hanh;
			nuoc = dt.nuoc;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap so luong thit bo: ";
			cin >> so_luong_ThitBo;
			
			cout << "Nhap so luong banh pho: ";
			cin >> banh_pho;
			
			cout << "Nhap so luong hanh: ";
			cin >> hanh;
			
			cout << "Nhap so luong nuoc: ";
			cin >> nuoc;
		}
		
		void HienThi(){
			cout << "[" << so_luong_ThitBo << ", ";
			cout << banh_pho << ", ";
			cout << hanh << ", ";
			cout << nuoc << "]";
		}
		
		double Ham_TinhTien(){
			double tien = so_luong_ThitBo*5 + banh_pho*2 + hanh*0.5 + nuoc*1;
			
			return tien;
		}
};

int main(){
	// tao doi tuong
	TPho dt1 = TPho(1, 1, 1, 1);
	TPho dt2 = TPho(dt1);
	TPho dt3;
	
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
	
	cout << "\nNhap n: ";
	int n = 0;
	cin >> n;
	
	cin.ignore();
	
	// tao mang
	TPho arr[SIZE];
	
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
	
	cout << "\n";
	
	// tinh tien tat ca bat pho
	double tong_tien = 0;
	for(int i = 0; i < n; i++){
		tong_tien = tong_tien + arr[i].Ham_TinhTien();
	}
	
	cout << "Tong tien = " << tong_tien << " (gia don vi)\n";
	
	return 0;
}
