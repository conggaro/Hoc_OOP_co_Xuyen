// Yeu cau:
// 1. tao lop TPerson
// 2. ham tao khong tham so
// 3. ham tao co tham so
// 4. ham tao sao chep
// 5. ham nhap du lieu
// 6. ham hien thi du lieu

#include <iostream>
#include <string>
using namespace std;

// tao lop TPerson
class TPerson{
	private:
		string so_CMT;
		string ho_ten;
		unsigned int nam_sinh;
		bool gioi_tinh;				// 1 la nam, 0 la nu
		string que_quan;
		
	public:
		// ham khoi tao khong tham so
		TPerson(){
			so_CMT = "";
			ho_ten = "";
			nam_sinh = 0;
			gioi_tinh = 1;
			que_quan = "";
		}
		
		// ham khoi tao co tham so
		TPerson(string data1, string data2, unsigned int data3, bool data4, string data5){
			so_CMT = data1;
			ho_ten = data2;
			nam_sinh = data3;
			gioi_tinh = data4;
			que_quan = data5;
		}
		
		// ham tao sao chep
		TPerson(const TPerson &dt){
			so_CMT = dt.so_CMT;
			ho_ten = dt.ho_ten;
			nam_sinh = dt.nam_sinh;
			gioi_tinh = dt.gioi_tinh;
			que_quan = dt.que_quan;
		}
		
		// ham nhap du lieu
		void NhapDuLieu(){
			cout << "Nhap so CMT: ";
			getline(cin, so_CMT, '\n');

			cout << "Nhap ho ten: ";
			getline(cin, ho_ten, '\n');
			
			cout << "Nhap nam sinh: ";
			cin >> nam_sinh;
			
			cout << "Nhap gioi tinh: ";
			cin >> gioi_tinh;
			cin.ignore();
			
			cout << "Nhap que quan: ";
			getline(cin, que_quan, '\n');
		}
		
		// ham hien thi
		void HienThi(){
			cout << "[" << so_CMT << ", ";
			cout << ho_ten << ", ";
			cout << nam_sinh << ", ";
			cout << gioi_tinh << ", ";
			cout << que_quan << "]\n";
		}
};

int main(){
	// tao doi tuong
	TPerson dt1 = TPerson("A000", "Nguyen Van A", 1999, 1, "Ha Noi");
	TPerson dt2 = TPerson(dt1);
	TPerson dt3;
	
	// goi phuong thuc nhap du lieu
	dt3.NhapDuLieu();
	
	// goi phuong thuc hien thi
	cout << "\n";
	dt1.HienThi();
	dt2.HienThi();
	dt3.HienThi();
	
	return 0;
}
