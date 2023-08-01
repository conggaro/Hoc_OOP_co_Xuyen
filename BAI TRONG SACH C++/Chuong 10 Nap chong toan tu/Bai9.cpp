// Yeu cau:
// 1. tao lop TFraction
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham huy
// 6. ham toi giam Phan So
// 7. nap chong toan tu xuat <<
// 8. nap chong toan tu nhap >>
// 9. nap chong toan tu >
// 10. nap chong toan tu <
// 11. nap chong toan tu >=
// 12. nap chong toan tu <=
// 13. nap chong toan tu ==
// 14. nap chong toan tu !=
// 15. nap chong toan tu +
// 16. nap chong toan tu -
// 17. nap chong toan tu *
// 18. nap chong toan tu /
// 19. nap chong toan tu ++ (tien to)
// 20. nap chong toan tu ++ (hau to)
// 21. nap chong toan tu -- (tien to)
// 22. nap chong toan tu -- (hau to)

// 23. nhap phan so p1
// 24. nhap phan so p2
// 25. nhap phan so p3

// 26. hien thi p1
// 27. hien thi p2
// 28. hien thi p3

// 29. tinh pa = p1 - p2 - p3 + 3
// 30. tinh pb = (p1 + p2) * 4 * p3
// 31. tinh pc = p1 / p2 / p3
// 32. tinh pd = p1 ++
// 33. tinh pe = --p2
// 34. tinh pf = p1^2 + p2^2 - 2*p1*p2

// 35. nhap x
// 36. nhap y
// 37. nhap z

// 38. tinh Q = p1 * x + p2 / y - z
// 39. tinh S = x * p1 + y / p2 - z

// 40. sap xep p1, p2, p3 theo thu tu tang dan (Ascending)

#include <iostream>
#include <cmath>
using namespace std;

// ham tim uoc chung lon nhat UCLN(a, b)
// cai giai thuat nay
// neu gap so am (-)
// la co bug luon
int Ham_Tim_UCLN(int a, int b){
	int UCLN = 0;
	
	if(a == 0 || b == 0){
		return UCLN;
	}
	
	if(a < 0|| b < 0){
		// tao index bat dau
		int data_a = abs(a);
		int data_b = abs(b);
		
		int index_start = max(data_a, data_b);
		
		// tao index ket thuc
		int index_end = 1;
		
		for(int i = index_start; index_start >= index_end; i--){
			bool kiemTra1 = a % i == 0 ? true : false;
			bool kiemTra2 = b % i == 0 ? true : false;
			
			if(kiemTra1 == true && kiemTra2 == true){
				UCLN = i;
				break;
			}
		}
		
		return UCLN;
	}
	
	while(a != b){
		if(a > b){
			a = a - b;
		}
		else if(b > a){
			b = b - a;
		}
	}
	
	// gan UCLN = a hoac UCLN = b deu duoc	
	UCLN = a;

	return UCLN;
}

class TFraction{
	private:
		int tu;
		int mau;
		
	public:
		// ham khoi tao khong tham so
		TFraction(){
			tu = 0;
			mau = 1;
		}
		
		// ham khoi tao co tham so
		TFraction(int data_tu, int data_mau){
			if(data_mau == 0){
				tu = 0;
				mau = 1;
				cout << "Mau phai khac 0\n";
			}
			else if(data_mau != 0){
				tu = data_tu;
				mau = data_mau;
			}
		}
		
		// ham khoi tao sao chep
		TFraction(const TFraction &dt){
			tu = dt.tu;
			mau = dt.mau;
		}
		
		// ham huy
		~TFraction(){
			// cout << "Huy doi tuong\n";
		}
		
		// ham toi gian phan so
		void Ham_ToiGian_PhanSo(){
			int UCLN = Ham_Tim_UCLN(tu, mau);
			
			// khong the chia cho 0
			// nen return de thoat khoi ham
			if(UCLN == 0){
				return;
			}
			
			tu = tu / UCLN;
			mau = mau / UCLN;
		}

		// ham ban
		// nap chong toan tu xuat <<
		friend ostream &operator<<(ostream &dt_cout, TFraction &dt);
		
		// ham ban
		// nap chong toan tu nhap >>
		friend istream &operator>>(istream &dt_cin, TFraction &dt);
		
		// ham ban
		// nap chong toan tu >
		friend bool operator>(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu <
		friend bool operator<(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu >=
		friend bool operator>=(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu <=
		friend bool operator<=(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu ==
		friend bool operator==(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu !=
		friend bool operator!=(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu +
		friend TFraction operator+(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu -
		friend TFraction operator-(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu *
		friend TFraction operator*(TFraction dt1, TFraction dt2);
		
		// ham ban
		// nap chong toan tu /
		friend TFraction operator/(TFraction dt1, TFraction dt2);
		
		// nap chong toan tu ++ (tien to)
		TFraction operator++(){
			TFraction ketQua;
			
			tu += mau;
			
			ketQua.tu = tu;
			ketQua.mau = mau;
			
			return ketQua;
		}
		
		// nap chong toan tu ++ (hau to)
		TFraction operator++(int){
			TFraction ketQua;
			
			ketQua.tu = tu;
			ketQua.mau = mau;
			
			tu += mau;
			
			return ketQua;
		}
		
		// nap chong toan tu -- (tien to)
		TFraction operator--(){
			TFraction ketQua;
			
			tu -= mau;
			
			ketQua.tu = tu;
			ketQua.mau = mau;
			
			return ketQua;
		}
		
		// nap chong toan tu -- (hau to)
		TFraction operator--(int){
			TFraction ketQua;
			
			ketQua.tu = tu;
			ketQua.mau = mau;
			
			tu -= mau;
			
			return ketQua;
		}
		
		// ham ban
		// nap chong toan tu + (cong voi so nguyen)
		friend TFraction operator+(TFraction dt, int n);
		
		// ham ban
		// nap chong toan tu * (nhan voi so nguyen)
		friend TFraction operator*(TFraction dt, int n);
		
		// ham ban
		// nap chong toan tu * (nhan voi so nguyen)
		friend TFraction operator*(int n, TFraction dt);
		
		// ham ban
		// nap chong toan tu / (chia voi so nguyen)
		friend TFraction operator/(TFraction dt, int n);
		
		// ham ban
		// nap chong toan tu / (chia voi so nguyen)
		friend TFraction operator/(int n, TFraction dt);
		
		// ham ban
		// nap chong toan tu - (tru voi so nguyen)
		friend TFraction operator-(TFraction dt, int n);
};

ostream &operator<<(ostream &dt_cout, TFraction &dt){
	dt_cout << dt.tu << "/" << dt.mau;
	
	return dt_cout;
}

istream &operator>>(istream &dt_cin, TFraction &dt){
	cout << "Nhap tu so: ";
	dt_cin >> dt.tu;
	
	cout << "Nhap mau so: ";
	dt_cin >> dt.mau;
	
	if(dt.mau == 0){
		dt.tu = 0;
		dt.mau = 1;
		cout << "\nMau phai khac 0\n";
	}
	
	return dt_cin;
}

bool operator>(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 > data2){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator<(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 < data2){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator>=(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 >= data2){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator<=(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 <= data2){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator==(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 == data2){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator!=(TFraction dt1, TFraction dt2){
	bool ketQua = false;
	
	float data1 = (float)dt1.tu / dt1.mau;
	float data2 = (float)dt2.tu / dt2.mau;
	
	if(data1 != data2){
		ketQua = true;
	}
	
	return ketQua;
}

TFraction operator+(TFraction dt1, TFraction dt2){
	TFraction tong;
	
	tong.tu = (dt1.tu * dt2.mau) + (dt2.tu * dt1.mau);
	tong.mau = dt1.mau * dt2.mau;
	
	return tong;
}

TFraction operator-(TFraction dt1, TFraction dt2){
	TFraction hieu;
	
	hieu.tu = (dt1.tu * dt2.mau) - (dt2.tu * dt1.mau);
	hieu.mau = dt1.mau * dt2.mau;
	
	return hieu;
}

TFraction operator*(TFraction dt1, TFraction dt2){
	TFraction tich;
	
	tich.tu = dt1.tu * dt2.tu;
	tich.mau = dt1.mau * dt2.mau;
	
	return tich;
}

TFraction operator/(TFraction dt1, TFraction dt2){
	TFraction thuong;
	
	if(dt2.tu == 0){
		cout << "\nKhong co phep chia cho 0 (Undefined)\n";
		
		return thuong;
	}
	
	thuong.tu = dt1.tu * dt2.mau;
	thuong.mau = dt1.mau * dt2.tu;
	
	if(thuong.mau < 0){
		thuong.tu = thuong.tu * (-1);
		thuong.mau = thuong.mau * (-1);
	}
	
	return thuong;
}

TFraction operator+(TFraction dt, int n){
	TFraction tong;
	
	tong.tu = dt.tu + (n * dt.mau);
	tong.mau = dt.mau;
	
	return tong;
}

TFraction operator*(TFraction dt, int n){
	TFraction ketQua;
	
	ketQua.tu = dt.tu * n;
	ketQua.mau = dt.mau;
	
	return ketQua;
}

TFraction operator*(int n, TFraction dt){
	TFraction ketQua;
	
	ketQua.tu = n *  dt.tu;
	ketQua.mau = dt.mau;
	
	return ketQua;
}

TFraction operator/(TFraction dt, int n){
	TFraction ketQua;
	
	ketQua.tu = dt.tu;
	ketQua.mau = dt.mau * n;
	
	return ketQua;
}

TFraction operator/(int n, TFraction dt){
	TFraction ketQua;
	
	ketQua.tu = n * dt.mau;
	ketQua.mau = dt.tu;
	
	return ketQua;
}

TFraction operator-(TFraction dt, int n){
	TFraction ketQua;
	
	ketQua.tu = dt.tu - n * dt.mau;
	ketQua.mau = dt.mau;
	
	return ketQua;
}

int main(){
	// tao doi tuong
	TFraction dt1 = TFraction(3, 9);
	TFraction dt2 = TFraction(dt1);
	TFraction dt3;
	
	// nhap du lie
	cin >> dt3;
	cout << "\n";
	
	// hien thi du lieu
	dt1.Ham_ToiGian_PhanSo();
	dt2.Ham_ToiGian_PhanSo();
	dt3.Ham_ToiGian_PhanSo();
	cout << "dt1: " << dt1 << "\n";
	cout << "dt2: " << dt2 << "\n";
	cout << "dt3: " << dt3 << "\n";
	
	// so sanh dt1 va dt3
	cout << "\n";
	cout << dt1 << " > " << dt3 << "\t\t\t" << "ket qua: " << (dt1 > dt3);
	cout << "\n";
	
	cout << dt1 << " < " << dt3 << "\t\t\t" << "ket qua: " << (dt1 < dt3);
	cout << "\n";
	
	cout << dt1 << " >= " << dt3 << "\t\t\t" << "ket qua: " << (dt1 >= dt3);
	cout << "\n";
	
	cout << dt1 << " <= " << dt3 << "\t\t\t" << "ket qua: " << (dt1 <= dt3);
	cout << "\n";
	
	cout << dt1 << " == " << dt3 << "\t\t\t" << "ket qua: " << (dt1 == dt3);
	cout << "\n";
	
	cout << dt1 << " != " << dt3 << "\t\t\t" << "ket qua: " << (dt1 != dt3);
	cout << "\n";
	
	// thuc hien tinh toan +, -, *, /
	TFraction tong = dt1 + dt3;
	tong.Ham_ToiGian_PhanSo();
	cout << "\n" << dt1 << " + " << dt3 << " = " << tong << "\n";
	
	TFraction hieu = dt1 - dt3;
	hieu.Ham_ToiGian_PhanSo();
	cout << dt1 << " - " << dt3 << " = " << hieu << "\n";
	
	TFraction tich = dt1 * dt3;
	tich.Ham_ToiGian_PhanSo();
	cout << dt1 << " * " << dt3 << " = " << tich << "\n";
	
	TFraction thuong = dt1 / dt3;
	thuong.Ham_ToiGian_PhanSo();
	cout << dt1 << " / " << dt3 << " = " << thuong << "\n";
	
	// su dung toan tu ++ (tien to)
	TFraction tien_to_cong = dt3;
	TFraction data_tong;
	data_tong = data_tong + ++tien_to_cong;
	cout << "\n0 + ++" << dt3 << " = " << data_tong << "\n";
	
	// su dung toan tu ++ (hau to)
	TFraction hau_to_cong = dt3;
	TFraction data_tong2;
	data_tong2 = data_tong2 + hau_to_cong++;
	cout << "\n0 + " << dt3 << "++ = " << data_tong2 << "\n";
	cout << "Luc sau = " << hau_to_cong << "\n";
	
	// su dung toan tu -- (tien to)
	TFraction tien_to_tru = dt3;
	TFraction data_hieu;
	data_hieu = data_hieu + --tien_to_tru;
	cout << "\n0 + --" << dt3 << " = " << data_hieu << "\n";
	
	// su dung toan tu -- (hau to)
	TFraction hau_to_tru = dt3;
	TFraction data_tru2;
	data_tru2 = data_tru2 + hau_to_tru--;
	cout << "\n0 + " << dt3 << "-- = " << data_tru2 << "\n";
	cout << "Luc sau = " << hau_to_tru << "\n";
	
	// nhap du lieu
	cout << "\n-------------------- NHAP DU LIEU --------------------";
	cout << "\nNhap phan so p1:\n";
	TFraction p1;
	cin >> p1;
	
	cout << "\nNhap phan so p2:\n";
	TFraction p2;
	cin >> p2;
	
	cout << "\nNhap phan so p3:\n";
	TFraction p3;
	cin >> p3;
	
	// hien thi du lieu
	cout << "\n-------------------- HIEN THI DU LIEU --------------------\n";
	cout << "p1 = " << p1 << "\n";
	cout << "p2 = " << p2 << "\n";
	cout << "p3 = " << p3 << "\n";
	
	// tinh gia tri bieu thuc
	cout << "\n-------------------- TINH GIA TRI BIEU THUC --------------------\n";
	cout << "pa = p1 - p2 - p3 + 3\n";
	cout << "pa = " << p1 << " - " << p2 << " - " << p3 << " + 3\n";
	TFraction pa = p1 - p2 - p3 + 3;
	pa.Ham_ToiGian_PhanSo();
	cout << "pa = " << pa << "\n\n";
	
	cout << "pb = (p1 + p2) * 4 * p3\n";
	cout << "pb = (" << p1 << " + " << p2 << ") * 4 * " << p3 << "\n";
	TFraction pb = (p1 + p2) * 4 * p3;
	pb.Ham_ToiGian_PhanSo();
	cout << "pb = " << pb << "\n\n";
	
	cout << "pc = p1 / p2 / p3\n";
	cout << "pc = " << p1 << " / " << p2 << " / " << p3 << "\n";
	TFraction pc = p1 / p2 / p3;
	pc.Ham_ToiGian_PhanSo();
	cout << "pc = " << pc << "\n\n";
	
	cout << "pd = p1++\n";
	cout << "pd = " << p1 << "++\n";
	TFraction pd = p1;
	TFraction data_pd = pd++;
	data_pd.Ham_ToiGian_PhanSo();
	cout << "pd = " << data_pd << "\n\n";
	
	cout << "pe = --p2\n";
	cout << "pe = --" << p2 << "\n";
	TFraction pe = p2;
	TFraction data_pe = --pe;
	data_pe.Ham_ToiGian_PhanSo();
	cout << "pe = " << data_pe << "\n\n";
	
	cout << "pf = p1^2 + p2^2 - 2*p1*p2\n";
	cout << "pf = (" << p1 << ")^2 + (" << p2 << ")^2 - 2 * " << p1 << " * " << p2 << "\n";
	TFraction pf = p1*p1 + p2*p2 - 2*p1*p2;
	pf.Ham_ToiGian_PhanSo();
	cout << "pf = " << pf << "\n\n";

	cout << "-------------------- NHAP DU LIEU --------------------\n";
	cout << "Nhap x: ";
	int x = 0;
	cin >> x;

	cout << "Nhap y: ";
	int y = 0;
	cin >> y;

	cout << "Nhap z: ";
	int z = 0;
	cin >> z;
	
	cout << "\n-------------------- TINH GIA TRI BIEU THUC --------------------\n";
	cout << "Q = p1 * x + p2 / y - z\n";
	cout << "Q = " << p1 << " * " << x << " + " << p2 << " / " << y << " - " << z;
	TFraction Q = p1 * x + p2 / y - z;
	Q.Ham_ToiGian_PhanSo();
	cout << "\nQ = " << Q << "\n";
	
	cout << "\nS = x * p1 + y / p2 - z\n";
	cout << "S = " << x << " * " << p1 << " + " << y << " / " << p2 << " - " << z;
	TFraction S = x * p1 + y / p2 - z;
	S.Ham_ToiGian_PhanSo();
	cout << "\nS = " << S << "\n";
	
	// tao mang
	TFraction arr[3] = {p1, p2, p3};
	
	cout << "\nBan dau:\n";
	for(int i = 0; i < 3; i++){
		cout << arr[i] << "\n";
	}
	
	// tao bien temp
	TFraction temp;
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 3; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout << "\nSau khi sap xep (Tang dan):\n";
	for(int i = 0; i < 3; i++){
		cout << arr[i] << "\n";
	}

	return 0;
}
