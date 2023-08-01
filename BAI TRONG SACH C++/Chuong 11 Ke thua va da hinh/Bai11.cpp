// Yeu cau:
// 1. tao lop TPoint
// 2. ham khoi tao khong tham so TPoint
// 3. ham khoi tao co tham so TPoint
// 4. ham khoi tao sao chep TPoint
// 5. ham nhap du lieu
// 6. ham hien thi

// 7. tao lop doan thang TSegment (ke thua lop TPoint)
// 8. ham khoi tao khong tham so TSegment
// 9. ham khoi tao co tham so TSegment
// 10. ham khoi tao sao chep TSegment
// 11. ghi de ham nhap du lieu
// 12. ghi de ham hien thi

// nhap x, y, z
// la nhap trung diem cua doan thang (TSegment)

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
		float goc_SoVoi_Truc_Ox;
		float do_dai;
		
	public:
		// ham khoi tao khong tham so
		TCircle() : TPoint(){
			goc_SoVoi_Truc_Ox = 0;
			do_dai = 0;
		}
		
		// ham khoi tao co tham so
		TCircle(double data1, double data2,
					double data3, float data4, float data5) :
						TPoint(data1, data2, data3){
		
			goc_SoVoi_Truc_Ox = data4;
			do_dai = data5;
		}
		
		// ham khoi tao sao chep
		TCircle(const TCircle &dt) : TPoint(dt){
			goc_SoVoi_Truc_Ox = dt.goc_SoVoi_Truc_Ox;
			do_dai = dt.do_dai;
		}
		
		// ghi de ham nhap du lieu
		void NhapDuLieu(){
			TPoint::NhapDuLieu();
			
			cout << "Nhap goc so voi truc Ox: ";
			cin >> goc_SoVoi_Truc_Ox;
			
			cout << "Nhap do dai: ";
			cin >> do_dai;
		}
		
		// ghi de ham hien thi
		void HienThi(){
			TPoint::HienThi();
			
			cout << " goc = " << goc_SoVoi_Truc_Ox << ", do dai = ";
			cout << do_dai << "]";
		}
};

int main(){
	
	
	return 0;
}
