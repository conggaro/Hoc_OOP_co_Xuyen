// Yeu cau:
// 1. tao lop TPerson
// 2. ham khoi tao khong tham so TPerson
// 3. ham khoi tao co tham so TPerson
// 4. ham khoi tao sao chep TPerson
// 5. ham nhap du lieu
// 6. ham hien thi

// 7. tao lop TStudent (ke thua TPerson)
// 8. ham khoi tao khong tham so TStudent
// 9. ham khoi tao co tham so TStudent
// 10. ham khoi tao sao chep TStudent
// 11. ghi de ham nhap du lieu
// 12. ghi de ham hien thi
// 13. ham tinh diem trung binh

#include <iostream>
#include <string>
using namespace std;

// tao lop TPerson
class TPerson{
	private:
		string so_bao_hiem;
		string ho_ten;
		string ngay_sinh;
		string que_quan;
		
	protected:
		// ham khoi tao khong tham so
		TPerson(){
			so_bao_hiem = "";
			ho_ten = "";
			ngay_sinh = "";
			que_quan = "";
		}

		// ham khoi tao co tham so
		TPerson(string data1, string data2, string data3, string data4){
			so_bao_hiem = data1;
			ho_ten = data2;
			ngay_sinh = data3;
			que_quan = data4;
		}
		
		// ham khoi tao sao chep
		TPerson(const TPerson &dt){
			so_bao_hiem = dt.so_bao_hiem;
			ho_ten = dt.ho_ten;
			ngay_sinh = dt.ngay_sinh;
			que_quan = dt.que_quan;
		}
		
		// ham nhap du lieu
		void virtual NhapDuLieu(){
			cout << "Nhap so bao hiem: ";
			getline(cin, so_bao_hiem, '\n');
			
			cout << "Nhap ho ten: ";
			getline(cin, ho_ten, '\n');
			
			cout << "Nhap ngay sinh: ";
			getline(cin, ngay_sinh, '\n');
			
			cout << "Nhap que quan: ";
			getline(cin, que_quan, '\n');
		}
		
		// ham hien thi
		void virtual HienThi(){
			cout << "[" << so_bao_hiem << ", ";
			cout << ho_ten << ", ";
			cout << ngay_sinh << ", ";
			cout << que_quan << ", ";
		}
};

class TStudent : public TPerson{
	private:
		string ma_SinhVien;
		float diem_GiuaKy;
		float diem_CuoiKy;
		
	public:
		// ham khoi tao khong tham so
		TStudent() : TPerson(){
			ma_SinhVien = "";
			diem_GiuaKy = 0;
			diem_CuoiKy = 0;
		}
		
		// ham khoi tao co tham so
		TStudent(string data1, string data2,
					string data3, string data4,
					string data5, float data6,
					float data7) : 
						TPerson(data1, data2, data3, data4){
			
			ma_SinhVien = data5;
			diem_GiuaKy = data6;
			diem_CuoiKy = data7;
		}
		
		// ham khoi tao sao chep
		TStudent(const TStudent &dt) : TPerson(dt){
			ma_SinhVien = dt.ma_SinhVien;
			diem_GiuaKy = dt.diem_GiuaKy;
			diem_CuoiKy = dt.diem_CuoiKy;
		}
		
		// ghi de ham nhap du lieu
		void NhapDuLieu(){
			TPerson::NhapDuLieu();
			
			cout << "Nhap ma sinh vien: ";
			getline(cin, ma_SinhVien, '\n');
			
			cout << "Nhap diem giua ky: ";
			cin >> diem_GiuaKy;
			
			cout << "Nhap diem cuoi ky: ";
			cin >> diem_CuoiKy;
		}
		
		// ghi de ham hien thi
		void HienThi(){
			TPerson::HienThi();
			
			cout << ma_SinhVien << ", ";
			cout << diem_GiuaKy << ", ";
			cout << diem_CuoiKy << "]";
		}
		
		// ham tinh diem trung binh
		float Tinh_Diem_TrungBinh(){
			float ketQua = (diem_GiuaKy + diem_CuoiKy*2) / 3;
			
			return ketQua;
		}
};

int main(){
	// tao doi tuong
	TStudent dt1 = TStudent("BH001", "Nguyen Van A",
							"1/1/2000", "Ha Noi",
							"SV001", 8.5, 9.9);
	TStudent dt2 = TStudent(dt1);
	TStudent dt3;
	
	// goi phuong thuc nhap du lieu
	cout << "---------- NHAP DU LIEU CHO dt3 ----------\n";
	dt3.NhapDuLieu();
	
	// goi phuong thuc hien thi
	cout << "\nHien thi dt1:\n";
	dt1.HienThi();
	
	cout << "\n\nHien thi dt2:\n";
	dt2.HienThi();
	
	cout << "\n\nHien thi dt3:\n";
	dt3.HienThi();
	
	// tao mang
	TStudent arr[3] = {dt1, dt2, dt3};
	
	// tao bien temp
	TStudent temp;
	
	// sap xep tang dan
	for(int i = 0; i <= 3 - 2; i++){
		for(int j = i + 1; j <= 3 - 1; j++){
			if(arr[i].Tinh_Diem_TrungBinh() > arr[j].Tinh_Diem_TrungBinh()){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	// sau khi sap xep
	cout << "\n\n---------- SAU KHI SAP XEP ----------\n";
	for(int i = 0; i < 3; i++){
		arr[i].HienThi();
		cout << "\n";
	}
	
	return 0;
}
