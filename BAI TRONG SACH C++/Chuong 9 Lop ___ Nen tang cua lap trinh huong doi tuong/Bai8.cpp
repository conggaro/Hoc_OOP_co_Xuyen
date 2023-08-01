// Yeu cau:
// 1. tao lop TTime
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham nhap du lieu
// 6. ham hien thi du lieu
// 7. ham so sanh 2 thoi gian
// 8. ham tinh khoang cach 2 thoi gian trong 1 ngay

#include <iostream>
#include <string>
using namespace std;

// ham chuyen kieu short
// sang kieu string
string ToString(short x){
	string ketQua = "";
	
	if(x == 0){
		ketQua = "0";
		return ketQua;
	}
	
	// tao bien item
	string item = "";
	
	// tao bien so du
	short so_du = 0;
	
	// tao bien khoi tao
	string khoi_tao = "";
	
	while(x != 0){
		so_du = x % 10;
		x = x / 10;
		
		if(so_du == 0){
			item = "0";
		}
		else if(so_du == 1){
			item = "1";
		}
		else if(so_du == 2){
			item = "2";
		}
		else if(so_du == 3){
			item = "3";
		}
		else if(so_du == 4){
			item = "4";
		}
		else if(so_du == 5){
			item = "5";
		}
		else if(so_du == 6){
			item = "6";
		}
		else if(so_du == 7){
			item = "7";
		}
		else if(so_du == 8){
			item = "8";
		}
		else if(so_du == 9){
			item = "9";
		}
		
		khoi_tao = khoi_tao + item;
	}
	
	// dao nguoc chuoi string
	for(int i = khoi_tao.length() - 1; i >= 0; i--){
		ketQua = ketQua + khoi_tao[i];
	}
	
	return ketQua;
}

class TTime{
	private:
		short gio;
		short phut;
		short giay;
		bool sang_chieu;			// 1 la sang, 0 la chieu
		
	public:
		// ham khoi tao khong tham so
		TTime(){
			gio = 0;
			phut = 0;
			giay = 0;
			sang_chieu = 1;
		}
		
		// ham khoi tao co tham so
		TTime(short data1, short data2, short data3, bool data4){
			gio = data1;
			phut = data2;
			giay = data3;
			sang_chieu = data4;
		}
		
		// ham khoi tao sao chep (copy)
		TTime(const TTime &dt){
			gio = dt.gio;
			phut = dt.phut;
			giay = dt.giay;
			sang_chieu = dt.sang_chieu;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap gio (0 <= gio <= 11): ";
			cin >> gio;
			
			cout << "Nhap phut (0 <= phut <= 59): ";
			cin >> phut;
			
			cout << "Nhap giay (0 <= giay <= 59): ";
			cin >> giay;
			
			cout << "Nhap sang chieu (1 la AM, 0 la PM): ";
			cin >> sang_chieu;
		}
		
		// ham hien thi du lieu
		void HienThi(){
			string str_gio = ToString(gio);
			string str_phut = ToString(phut);
			string str_giay = ToString(giay);
			string str_sang_chieu = sang_chieu == 1 ? "AM" : "PM";
			
			if(gio < 10){
				str_gio = "0" + str_gio;
			}
			
			if(phut < 10){
				str_phut = "0" + str_phut;
			}
			
			if(giay < 10){
				str_giay = "0" + str_giay;
			}
			
			cout << str_gio << ":" << str_phut << ":";
			cout << str_giay << " " << str_sang_chieu;
		}
		
		// ham so sanh 2 thoi gian
		friend void SoSanh_2_ThoiGian(TTime dt1, TTime dt2);
		
		// ham tinh khoang cach 2 thoi gian trong 1 ngay
		friend void Tinh_KhoangCach_2_ThoiGian(TTime dt1, TTime dt2);
};

void SoSanh_2_ThoiGian(TTime dt1, TTime dt2){
	int data1 = (dt1.gio * 60 * 60) + (dt1.phut * 60) + dt1.giay;
	int data2 = (dt2.gio * 60 * 60) + (dt2.phut * 60) + dt2.giay;

	if(dt1.sang_chieu == 0){
		data1 = (dt1.gio * 60 * 60) + (dt1.phut * 60) + dt1.giay + (12 * 60 * 60);
	}
	
	if(dt2.sang_chieu == 0){
		data2 = (dt2.gio * 60 * 60) + (dt2.phut * 60) + dt2.giay + (12 * 60 * 60);
	}
	
	if(data1 > data2){
		dt1.HienThi();
		cout << " > ";
		dt2.HienThi();
	}
	else if(data1 < data2){
		dt1.HienThi();
		cout << " < ";
		dt2.HienThi();
	}
	else if(data1 == data2){
		dt1.HienThi();
		cout << " == ";
		dt2.HienThi();
	}
}

void Tinh_KhoangCach_2_ThoiGian(TTime dt1, TTime dt2){
	int data1 = (dt1.gio * 60 * 60) + (dt1.phut * 60) + dt1.giay;
	int data2 = (dt2.gio * 60 * 60) + (dt2.phut * 60) + dt2.giay;
		
	if(dt1.sang_chieu == 0){
		data1 = (dt1.gio * 60 * 60) + (dt1.phut * 60) + dt1.giay + (12 * 60 * 60);
	}
			
	if(dt2.sang_chieu == 0){
		data2 = (dt2.gio * 60 * 60) + (dt2.phut * 60) + dt2.giay + (12 * 60 * 60);
	}
			
	if(data1 > data2){
		cout << "Khoang cach ";
		dt1.HienThi();
		cout << " va ";
		dt2.HienThi();
		cout << " la: " << data1 - data2 << " giay";
	}
	else if(data1 < data2){
		cout << "Khoang cach ";
		dt1.HienThi();
		cout << " va ";
		dt2.HienThi();
		cout << " la: " <<data2 - data1<< " giay";
	}
	else if(data1 == data2){
		cout << "Khoang cach ";
		dt1.HienThi();
		cout << " va ";
		dt2.HienThi();
		cout << " la: " << data1 - data2 << " giay";
	}
}

int main(){
	// tao doi tuong
	TTime dt1 = TTime(7, 0, 1, 1);
	TTime dt2 = TTime(dt1);
	TTime dt3;
	
	// goi phuong thuc nhap du lieu
	dt3.NhapDuLieu();
	
	// goi phuong thuc hien thi du lieu
	cout << "\n";
	dt1.HienThi();
	cout << "\n";
	
	dt2.HienThi();
	cout << "\n";
	
	dt3.HienThi();
	cout << "\n";
	
	// goi ham ban so sanh dt1 va dt3
	cout << "\n";
	SoSanh_2_ThoiGian(dt1, dt3);
	
	// goi ham ban tinh khoang cach giua dt1 va dt3
	cout << "\n\n";
	Tinh_KhoangCach_2_ThoiGian(dt1, dt3);
	
	cout << "\n";
	
	return 0;
}
