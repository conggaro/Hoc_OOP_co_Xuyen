// Yeu cau:
// 1. tao lop TDate
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham nhap du lieu
// 6. ham hien thi
// 7. nap chong toan tu >
// 8. nap chong toan tu <
// 9. nap chong toan tu ==
// 10. ham tra ve ngay tiep theo Ngay_TiepTheo()
// 11. ham tra ve ngay hom qua Ngay_HomQua()
// 12. nap chong toan tu +
// 13. nap chong toan tu -

// 14. nap chong toan tu -
// de tinh khoang cach giua 2 ngay

// 15. nhap ngay sinh cho nguoi thu nhat
// 16. nhap ngay sinh cho nguoi thu hai
// 17. hien thi ngay sinh nguoi thu nhat
// 18. hien thi ngay sinh nguoi thu hai
// 19. tim ra nguoi gia hon

// 20. tinh so ngay song duoc den hom nay
// cua nguoi_1

// 21. tinh so ngay song duoc den hom nay
// cua nguoi_2

// 22. tinh so ngay tuoi ma nguoi gia hon sinh truoc nguoi tre hon

#include <iostream>
using namespace std;

class TDate{
	private:
		unsigned int ngay;
		unsigned int thang;
		unsigned int nam;
		
	public:
		// ham khoi tao khong tham so
		TDate(){
			ngay = 0;
			thang = 0;
			nam = 0;
		}
		
		// ham khoi tao co tham so
		TDate(unsigned int data1, unsigned int data2, unsigned int data3){
			ngay = data1;
			thang = data2;
			nam = data3;
		}
		
		// ham khoi tao sao chep
		TDate(const TDate &dt){
			ngay = dt.ngay;
			thang = dt.thang;
			nam = dt.nam;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap ngay: ";
			cin >> ngay;
			
			cout << "Nhap thang: ";
			cin >> thang;
			
			cout << "Nhap nam: ";
			cin >> nam;
		}
		
		// ham hien thi
		void HienThi(){
			cout << ngay << "/" << thang << "/" << nam;
		}
		
		// ham ban
		// nap chong toan tu >
		friend bool operator>(TDate dt1, TDate dt2);
		
		// ham ban
		// nap chong toan tu <
		friend bool operator<(TDate dt1, TDate dt2);
		
		// ham ban
		// nap chong toan tu ==
		friend bool operator==(TDate dt1, TDate dt2);
		
		// ham tra ve
		// ngay tiep theo
		TDate Ngay_TiepTheo(){
			TDate ketQua;
			
			// tao mang
			// chua tong so ngay trong 1 thang
			unsigned int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
			// kiem tra nam nhuan
			if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)){
				arr[1] = 29;
			}
			
			if(ngay == 31 && thang == 12){
				ketQua.ngay = 1;
				ketQua.thang = 1;
				ketQua.nam = nam + 1;
			}
			else if(ngay == arr[thang - 1] && thang != 12){
				ketQua.ngay = 1;
				ketQua.thang = thang + 1;
				ketQua.nam = nam;
			}
			else if(ngay != arr[thang - 1]){
				ketQua.ngay = ngay + 1;
				ketQua.thang = thang;
				ketQua.nam = nam;
			}
			
			return ketQua;
		}
		
		// ham tra ve
		// ngay hom qua
		TDate Ngay_HomQua(){
			TDate ketQua;
			
			// tao mang
			// chua tong so ngay trong 1 thang
			unsigned int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
			// kiem tra nam nhuan
			if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)){
				arr[1] = 29;
			}
			
			if(ngay == 1 && thang == 1){
				ketQua.ngay = 31;
				ketQua.thang = 12;
				ketQua.nam = nam - 1;
			}
			else if(ngay == 1 && thang != 1){
				ketQua.ngay = arr[thang - 2];
				ketQua.thang = thang - 1;
				ketQua.nam = nam;
			}
			else if(ngay != 1){
				ketQua.ngay = ngay - 1;
				ketQua.thang = thang;
				ketQua.nam = nam;
			}
			
			return ketQua;
		}
		
		// ham ban
		// nap chong toan tu +
		friend TDate operator+(TDate dt, int n);
		
		// ham ban
		// nap chong toan tu -
		friend TDate operator-(TDate dt, int n);
		
		// ham ban
		// nap chong toan tu -
		// de tinh khoang cach giua 2 ngay
		friend int operator-(TDate dt1, TDate dt2);
};

bool operator>(TDate dt1, TDate dt2){
	bool ketQua = false;
	
	if(dt1.nam > dt2.nam){
		ketQua = true;
	}
	else if(dt1.nam < dt2.nam){
		ketQua = false;
	}
	else if(dt1.nam == dt2.nam){
		if(dt1.thang > dt2.thang){
			ketQua = true;
		}
		else if(dt1.thang < dt2.thang){
			ketQua = false;
		}
		else if(dt1.thang == dt2.thang){
			if(dt1.ngay > dt2.ngay){
				ketQua = true;
			}
			else if(dt1.ngay < dt2.ngay){
				ketQua = false;
			}
			else if(dt1.ngay == dt2.ngay){
				ketQua = false;
			}
		}
	}
	
	return ketQua;
}

bool operator<(TDate dt1, TDate dt2){
	bool ketQua = false;
	
	if(dt1.nam < dt2.nam){
		ketQua = true;
	}
	else if(dt1.nam > dt2.nam){
		ketQua = false;
	}
	else if(dt1.nam == dt2.nam){
		if(dt1.thang < dt2.thang){
			ketQua = true;
		}
		else if(dt1.thang > dt2.thang){
			ketQua = false;
		}
		else if(dt1.thang == dt2.thang){
			if(dt1.ngay < dt2.ngay){
				ketQua = true;
			}
			else if(dt1.ngay > dt2.ngay){
				ketQua = false;
			}
			else if(dt1.ngay == dt2.ngay){
				ketQua = false;
			}
		}
	}
	
	return ketQua;
}

bool operator==(TDate dt1, TDate dt2){
	bool ketQua = false;
	
	if(dt1.nam == dt2.nam){
		if(dt1.thang == dt2.thang){
			if(dt1.ngay == dt2.ngay){
				ketQua = true;
			}
			else if(dt1.ngay != dt2.ngay){
				ketQua = false;
			}
		}
		else if(dt1.thang != dt2.thang){
			ketQua = false;
		}
	}
	else if(dt1.nam != dt2.nam){
		ketQua = false;
	}
	
	return ketQua;
}

TDate operator+(TDate dt, int n){
	TDate ketQua = TDate(dt);
	
	if(n == 0){
		return ketQua;
	}
	
	for(int i = 1; i <= n; i++){
		ketQua = ketQua.Ngay_TiepTheo();
	}
	
	return ketQua;
}

TDate operator-(TDate dt, int n){
	TDate ketQua = TDate(dt);
	
	if(n == 0){
		return ketQua;
	}
	
	for(int i = 1; i <= n; i++){
		ketQua = ketQua.Ngay_HomQua();
	}
	
	return ketQua;
}

int operator-(TDate dt1, TDate dt2){
	int khoang_cach = 0;
	
	if(dt1 == dt2){
		return khoang_cach;
	}
	else if(dt1 < dt2){
		// tao bien temp
		TDate temp = TDate(dt1);
		
		while(temp < dt2){
			khoang_cach ++;
			temp = temp.Ngay_TiepTheo();
		}
	}
	else if(dt2 < dt1){
		// tao bien temp
		TDate temp = TDate(dt2);
		
		while(temp < dt1){
			khoang_cach ++;
			temp = temp.Ngay_TiepTheo();
		}
	}
	
	return khoang_cach;
}

int main(){
	// tao doi tuong
	TDate dt1 = TDate(1, 1, 2000);
	TDate dt2 = TDate(dt1);
	TDate dt3;
	
	// goi phuong thuc nhap du lieu
	cout << "-------------------- NHAP DU LIEU --------------------\n";
	dt3.NhapDuLieu();
	cout << "\n";
	
	// goi phuong thuc hien thi du lieu
	cout << "-------------------- HIEN THI DU LIEU --------------------\n";
	dt1.HienThi();
	cout << "\n";
	
	dt2.HienThi();
	cout << "\n";
	
	dt3.HienThi();
	cout << "\n";
	
	// so sanh dt1 va dt3
	cout << "\n-------------------- SO SANH --------------------\n";
	dt1.HienThi();
	cout << " > ";
	dt3.HienThi();
	cout << "\t\t\tket qua: " << (dt1 > dt3) << "\n";
	
	dt1.HienThi();
	cout << " < ";
	dt3.HienThi();
	cout << "\t\t\tket qua: " << (dt1 < dt3) << "\n";
	
	dt1.HienThi();
	cout << " == ";
	dt3.HienThi();
	cout << "\t\t\tket qua: " << (dt1 == dt3) << "\n";
	
	// goi phuong thuc Ngay_TiepTheo
	cout << "\nNgay tiep theo cua ";
	dt3.HienThi();
	cout << " la: ";
	dt3.Ngay_TiepTheo().HienThi();
	cout << "\n";
	
	// goi phuong thuc Ngay_HomQua
	cout << "\nNgay hom qua cua ";
	dt3.HienThi();
	cout << " la: ";
	dt3.Ngay_HomQua().HienThi();
	cout << "\n\n";
	
	// fake nhap n
	int n = 365;
	
	// su dung toan tu +
	dt3.HienThi();
	cout << " + " << n << " = ";
	TDate tong = dt3 + n;
	tong.HienThi();
	cout << "\n\n";
	
	// su dung toan tu +
	dt3.HienThi();
	cout << " - " << n << " = ";
	TDate hieu = dt3 - n;
	hieu.HienThi();
	cout << "\n\n";
	
	// in ra khoang cach giua 2 ngay
	// dt1 va dt3
	cout << "Khoang cach ";
	dt1.HienThi();
	cout << " va ";
	dt3.HienThi();
	cout << " la: ";
	int khoang_cach = dt1 - dt3;
	cout << khoang_cach << "\n";
	
	// nhap ngay sinh
	// cua nguoi thu nhat
	cout << "\nNhap ngay sinh cua nguoi thu nhat:\n";
	TDate nguoi_1;
	nguoi_1.NhapDuLieu();
	
	cout << "\nNhap ngay sinh cua nguoi thu hai:\n";
	TDate nguoi_2;
	nguoi_2.NhapDuLieu();
	
	cout << "\nHien thi ngay sinh cua nguoi thu nhat:\n";
	nguoi_1.HienThi();
	
	cout << "\n\nHien thi ngay sinh cua nguoi thu hai:\n";
	nguoi_2.HienThi();
	
	if(nguoi_1 > nguoi_2){
		cout << "\n\nnguoi_2 gia hon\n";
	}
	else if(nguoi_1 < nguoi_2){
		cout << "\n\nnguoi_1 gia hon\n";
	}
	else if(nguoi_1 == nguoi_2){
		cout << "\n\nHai nguoi bang tuoi nhau\n";
	}
	
	// nhap ngay hom nay
	cout << "\nNhap ngay hom nay:\n";
	TDate hom_nay;
	hom_nay.NhapDuLieu();
	
	// so ngay song duoc den hom nay cua nguoi_1
	cout << "\nSo ngay song duoc den hom nay cua nguoi_1: ";
	cout << (hom_nay - nguoi_1) << " ngay tuoi\n";
	
	// so ngay song duoc den hom nay cua nguoi_2
	cout << "\nSo ngay song duoc den hom nay cua nguoi_2: ";
	cout << (hom_nay - nguoi_2) << " ngay tuoi\n";
	
	// tinh so ngay tuoi ma nguoi gia hon sinh truoc nguoi tre hon
	cout << "\nSo ngay tuoi ma nguoi gia hon sinh truoc nguoi tre hon: ";
	cout << (nguoi_1 - nguoi_2) << " ngay tuoi\n";
	
	return 0;
}
