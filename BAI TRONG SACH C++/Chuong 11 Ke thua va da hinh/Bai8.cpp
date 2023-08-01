// Yeu cau:
// 1. tao lop DongVat
// 2. tao lop Cho
// 3. tao lop Meo
// 4. tao lop Bo

#include <iostream>
using namespace std;

class DongVat{
	protected:
		bool co_vu;				// 1 là có vú, 0 là không có vú
		int so_luong_chan;		// so luong chân
	
	public:
		// ham thong bao biet di
		void Ham_ThongBao_BietDi(){
			cout << "Biet di\n";
		}
};

class Cho : public DongVat{
	private:
		string mau_sac;
		
	public:
		// ham thong bao biet sua
		void Ham_ThongBao_BietSua(){
			cout << "Biet sua\n";
		}
};

class Meo : public DongVat{
	private:
		string mau_sac;
		
	public:
		// ham thong bao biet treo cay
		void Ham_ThongBao_BietTreoCay(){
			cout << "Biet treo cay\n";
		}
};

class Bo : public DongVat{
	private:
		string mau_sac;
		bool co_sung;			// 1 la co sung, 0 la khong co sung
		
	public:
		// ham thong bao co the cho sua
		void Ham_ThongBao_CoThe_ChoSua(){
			cout << "Co the cho sua\n";
		}
};

int main(){
	// tao doi tuong
	DongVat dt_DongVat;
	Cho dt_Cho;
	Meo dt_Meo;
	Bo dt_Bo;
	
	// goi phuong thuc
	cout << "Doi tuong dong vat:\n";
	dt_DongVat.Ham_ThongBao_BietDi();
	
	cout << "\nDoi tuong cho:\n";
	dt_Cho.Ham_ThongBao_BietDi();
	dt_Cho.Ham_ThongBao_BietSua();
	
	cout << "\nDoi tuong meo:\n";
	dt_Meo.Ham_ThongBao_BietDi();
	dt_Meo.Ham_ThongBao_BietTreoCay();
	
	cout << "\nDoi tuong bo:\n";
	dt_Bo.Ham_ThongBao_BietDi();
	dt_Bo.Ham_ThongBao_CoThe_ChoSua();
	
	return 0;
}
