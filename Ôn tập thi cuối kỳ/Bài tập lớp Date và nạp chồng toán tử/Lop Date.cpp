// Yeu cau:
// 1. tao lop Date
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. nap chong toan tu nhap du lieu >>
// 6. nap chong toan tu xuat du lieu <<
// 7. ham tra ve ngay mai
// 8. ham tra ve hom qua
// 9. nap chong toan tu +
// 10. nap chong toan tu -
// 11. nap chong toan tu >
// 12. nap chong toan tu <
// 13. nap chong toan tu ==
// 14. ham tinh khoang cach giua 2 ngay

#include <iostream>
#include <string>
using namespace std;

string To_String(int thamSo){
	string ketQua = "";
	
	// tao bien so_du
	int so_du = 0;
	
	// tao bien item
	string item = "";
	
	// tao bien khoi_tao
	// de ghep du lieu
	string khoi_tao = "";
	
	while(thamSo != 0){
		so_du = thamSo % 10;
		
		thamSo = thamSo / 10;
		
		switch(so_du){
			case 0:
				item = "0";
				break;
			case 1:
				item = "1";
				break;
			case 2:
				item = "2";
				break;
			case 3:
				item = "3";
				break;
			case 4:
				item = "4";
				break;
			case 5:
				item = "5";
				break;
			case 6:
				item = "6";
				break;
			case 7:
				item = "7";
				break;
			case 8:
				item = "8";
				break;
			case 9:
				item = "9";
				break;
		}
		
		khoi_tao = khoi_tao + item;
	}
	
	for(int i = khoi_tao.length() - 1; i >= 0; i--){
		ketQua = ketQua + khoi_tao[i];
	}
	
	return ketQua;
}

class Date{
	private:
		int ngay;
		int thang;
		int nam;
		
	public:
		// ham khoi tao khong tham so
		Date(){
			ngay = 0;
			thang = 0;
			nam = 0;
		}
		
		// ham khoi tao co tham so
		Date(int data1, int data2, int data3){
			ngay = data1;
			thang = data2;
			nam = data3;
		}
		
		// ham khoi tao sao chep
		Date(const Date &dt){
			ngay = dt.ngay;
			thang = dt.thang;
			nam = dt.nam;
		}
		
		// ham ban
		// nap chong toan tu nhap du lieu >>
		friend istream &operator>>(istream &dt_cin, Date &dt);
		
		// ham ban
		// nap chong toan tu xuat du lieu <<
		friend ostream &operator<<(ostream &dt_cout, Date &dt);
		
		// ham tra ve ngay mai
		Date ngay_mai(){
			Date ketQua;
			
			// tao mang
			// chua tong so ngay trong thang
			int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
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
		
		// ham tra ve hom qua
		Date hom_qua(){
			Date ketQua;
			
			// tao mang
			// chua tong so ngay trong thang
			int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
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
		friend Date operator+(Date dt, int n);
		
		// ham ban
		// nap chong toan tu -
		friend Date operator-(Date dt, int n);
		
		// ham ban
		// nap chong toan tu >
		friend bool operator>(Date dt1, Date dt2);
		
		// ham ban
		// nap chong toan tu <
		friend bool operator<(Date dt1, Date dt2);
		
		// ham ban
		// nap chong toan tu ==
		friend bool operator==(Date dt1, Date dt2);
		
		// ham ban
		// ham tinh khoang cach giua 2 ngay
		friend int Tinh_KhoangCach(Date dt1, Date dt2);
};

istream &operator>>(istream &dt_cin, Date &dt){
	cout << "Nhap ngay: ";
	dt_cin >> dt.ngay;
	
	cout << "Nhap thang: ";
	dt_cin >> dt.thang;
	
	cout << "Nhap nam: ";
	dt_cin >> dt.nam;
	
	return dt_cin;
}

ostream &operator<<(ostream &dt_cout, Date &dt){
	string data_ngay = To_String(dt.ngay);
	string data_thang = To_String(dt.thang);
	string data_nam = To_String(dt.nam);
	
	if(dt.ngay < 10){
		data_ngay = "0" + data_ngay;
	}
	
	if(dt.thang < 10){
		data_thang = "0" + data_thang;
	}
	
	dt_cout << data_ngay << "/" << data_thang << "/" << data_nam;
	
	return dt_cout;
}

Date operator+(Date dt, int n){
	Date ketQua;
	
	if(n == 0){
		ketQua.ngay = dt.ngay;
		ketQua.thang = dt.thang;
		ketQua.nam = dt.nam;
		
		return ketQua;
	}
	else if(n > 0){
		for(int i = 0; i < n; i++){
			dt = dt.ngay_mai();
		}
		
		ketQua = dt;
	}
	
	return ketQua;
}

Date operator-(Date dt, int n){
	Date ketQua;
	
	if(n == 0){
		ketQua.ngay = dt.ngay;
		ketQua.thang = dt.thang;
		ketQua.nam = dt.nam;
		
		return ketQua;
	}
	else if(n > 0){
		for(int i = 0; i < n; i++){
			dt = dt.hom_qua();
		}
		
		ketQua = dt;
	}
	
	return ketQua;
}

bool operator>(Date dt1, Date dt2){
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

bool operator<(Date dt1, Date dt2){
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

bool operator==(Date dt1, Date dt2){
	bool ketQua = false;
	
	if(dt1.nam > dt2.nam){
		ketQua = false;
	}
	else if(dt1.nam < dt2.nam){
		ketQua = false;
	}
	else if(dt1.nam == dt2.nam){
		if(dt1.thang > dt2.thang){
			ketQua = false;
		}
		else if(dt1.thang < dt2.thang){
			ketQua = false;
		}
		else if(dt1.thang == dt2.thang){
			if(dt1.ngay > dt2.ngay){
				ketQua = false;
			}
			else if(dt1.ngay < dt2.ngay){
				ketQua = false;
			}
			else if(dt1.ngay == dt2.ngay){
				ketQua = true;
			}
		}
	}
	
	return ketQua;
}

int Tinh_KhoangCach(Date dt1, Date dt2){
	int dem = 0;
	
	if(dt1 == dt2){
		return 0;
	}
	else if(dt1 < dt2){
		while(dt1 < dt2){
			dt1 = dt1.ngay_mai();
			
			dem ++;
		}
	}
	else if(dt1 > dt2){
		while(dt1 > dt2){
			dt2 = dt2.ngay_mai();
			
			dem ++;
		}
	}
	
	return dem;
}

int main(){
	// tao doi tuong
	Date dt1 = Date(1, 1, 2000);
	Date dt2 = Date(dt1);
	Date dt3;
	
	// nhap du lieu
	cin >> dt3;
	cout << "\n";
	
	// hien thi du lieu
	cout << dt1 << "\n\n";
	cout << dt2 << "\n\n";
	cout << dt3 << "\n";
	
	// in ra ngay hom sau cua dt3
	cout << "\nNgay hom sau cua " << dt3 << " la: ";
	Date dt_NgayMai = dt3.ngay_mai();
	cout << dt_NgayMai;
	
	// in ra ngay hom truoc cua dt3
	cout << "\nNgay hom truoc cua " << dt3 << " la: ";
	Date dt_HomQua = dt3.hom_qua();
	cout << dt_HomQua;
	
	// cong ngay voi so n
	int n = 31;
	Date tong = dt3 + n;
	cout << "\n\n" << dt3 << " + " << n << " = " << tong;
	
	// tru ngay voi so n
	Date hieu = dt3 - n;
	cout << "\n" << dt3 << " - " << n << " = " << hieu;
	
	// so sanh dt1 va dt3
	bool lon_hon = dt1 > dt3;
	cout << "\n\n" << dt1 << " > " << dt3 << "\t\tket qua: " << lon_hon;
	
	bool nho_hon = dt1 < dt3;
	cout << "\n" << dt1 << " < " << dt3 << "\t\tket qua: " << nho_hon;
	
	bool bang = dt1 == dt3;
	cout << "\n" << dt1 << " == " << dt3 << "\tket qua: " << bang;
	
	// tinh khoang cach
	// giua dt1 va dt3
	cout << "\n\nKhoang cach giua " << dt1 << " va " << dt3 << " la: ";
	int khoang_cach = Tinh_KhoangCach(dt1, dt3);
	cout << khoang_cach << " ngay";
	
	return 0;
}
