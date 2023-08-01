// Yeu cau:
// 1. tao lop TVector
// 2. ham khoi tao khong tham so
// 3. ham khoi tao co tham so
// 4. ham khoi tao sao chep
// 5. ham huy
// 6. nap chong toan tu xuat <<
// 7. nap chong toan tu nhap >>
// 8. ham tinh do lon vector
// 9. nap chong toan tu >
// 10. nap chong toan tu >=
// 11. nap chong toan tu <
// 12. nap chong toan tu <=
// 13. nap chong toan tu ==
// 14. nap chong toan tu !=
// 15. nap chong toan tu +
// 16. nap chong toan tu -
// 17. nap chong toan tu *
// 18. nap chong toan tu /
// 19. nap chong toan tu + (voi float n)
// 20. nap chong toan tu - (voi float n)
// 21. nap chong toan tu * (voi float n)
// 22. nap chong toan tu / (voi float n)

#include <iostream>
#include <cmath>
using namespace std;

class TVector{
	private:
		float x;
		float y;
		float z;
		
	public:
		// ham khoi tao khong tham so
		TVector(){
			x = 0;
			y = 0;
			z = 0;
		}
		
		// ham khoi tao co tham so
		TVector(float data1, float data2, float data3){
			x = data1;
			y = data2;
			z = data3;
		}
		
		// ham khoi tao sao chep
		TVector(const TVector &dt){
			x = dt.x;
			y = dt.y;
			z = dt.z;
		}
		
		// ham huy
		~TVector(){
			// cout << "Huy doi tuong\n";
		}
		
		// ham ban
		// nap chong toan tu xuat <<
		friend ostream &operator<<(ostream &dt_cout, TVector &dt);
		
		// ham ban
		// nap chong toan tu nhap >>
		friend istream &operator>>(istream &dt_cin, TVector &dt);
		
		// ham tinh do lon vector
		float Tinh_Do_Lon_Vector(){
			float ketQua = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
			
			return ketQua;
		}
		
		// ham ban
		// nap chong toan tu >
		friend bool operator>(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu >=
		friend bool operator>=(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu <
		friend bool operator<(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu <=
		friend bool operator<=(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu ==
		friend bool operator==(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu !=
		friend bool operator!=(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu +
		friend TVector operator+(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu -
		friend TVector operator-(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu *
		friend TVector operator*(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu /
		friend TVector operator/(TVector dt1, TVector dt2);
		
		// ham ban
		// nap chong toan tu + (voi float n)
		friend TVector operator+(TVector dt1, float n);
		friend TVector operator+(float n, TVector dt1);
		
		// ham ban
		// nap chong toan tu - (voi float n)
		friend TVector operator-(TVector dt1, float n);
		friend TVector operator-(float n, TVector dt1);
		
		// ham ban
		// nap chong toan tu * (voi float n)
		friend TVector operator*(TVector dt1, float n);
		friend TVector operator*(float n, TVector dt1);
		
		// ham ban
		// nap chong toan tu / (voi float n)
		friend TVector operator/(TVector dt1, float n);
		friend TVector operator/(float n, TVector dt1);
};

ostream &operator<<(ostream &dt_cout, TVector &dt){
	dt_cout << "(" << dt.x << ", ";
	dt_cout << dt.y << ", ";
	dt_cout << dt.z << ")";
	
	return dt_cout;
}

istream &operator>>(istream &dt_cin, TVector &dt){
	cout << "Nhap x: ";
	dt_cin >> dt.x;

	cout << "Nhap y: ";
	dt_cin >> dt.y;

	cout << "Nhap z: ";
	dt_cin >> dt.z;
}

bool operator>(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() > dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator>=(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() >= dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator<(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() < dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator<=(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() <= dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator==(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() == dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

bool operator!=(TVector dt1, TVector dt2){
	bool ketQua = false;
	
	if(dt1.Tinh_Do_Lon_Vector() != dt2.Tinh_Do_Lon_Vector()){
		ketQua = true;
	}
	
	return ketQua;
}

TVector operator+(TVector dt1, TVector dt2){
	TVector ketQua;

	ketQua.x= dt1.x + dt2.x;
	ketQua.y= dt1.y + dt2.y;
	ketQua.z= dt1.z + dt2.z;

	return ketQua;
}

TVector operator-(TVector dt1, TVector dt2){
	TVector ketQua;

	ketQua.x= dt1.x - dt2.x;
	ketQua.y= dt1.y - dt2.y;
	ketQua.z= dt1.z - dt2.z;

	return ketQua;
}

TVector operator*(TVector dt1, TVector dt2){
	TVector ketQua;

	ketQua.x= dt1.x * dt2.x;
	ketQua.y= dt1.y * dt2.y;
	ketQua.z= dt1.z * dt2.z;

	return ketQua;
}

TVector operator/(TVector dt1, TVector dt2){
	TVector ketQua;

	ketQua.x= dt1.x / dt2.x;
	ketQua.y= dt1.y / dt2.y;
	ketQua.z= dt1.z / dt2.z;

	return ketQua;
}

TVector operator+(TVector dt1, float n){
	TVector ketQua;

	ketQua.x= dt1.x + n;
	ketQua.y= dt1.y + n;
	ketQua.z= dt1.z + n;

	return ketQua;
}

TVector operator+(float n, TVector dt1){
	TVector ketQua;

	ketQua.x= n + dt1.x;
	ketQua.y= n + dt1.y;
	ketQua.z= n + dt1.z;

	return ketQua;
}

TVector operator-(TVector dt1, float n){
	TVector ketQua;

	ketQua.x= dt1.x - n;
	ketQua.y= dt1.y - n;
	ketQua.z= dt1.z - n;

	return ketQua;
}

TVector operator-(float n, TVector dt1){
	TVector ketQua;

	ketQua.x= n - dt1.x;
	ketQua.y= n - dt1.y;
	ketQua.z= n - dt1.z;

	return ketQua;
}

TVector operator*(TVector dt1, float n){
	TVector ketQua;

	ketQua.x= dt1.x * n;
	ketQua.y= dt1.y * n;
	ketQua.z= dt1.z * n;

	return ketQua;
}

TVector operator*(float n, TVector dt1){
	TVector ketQua;

	ketQua.x= n * dt1.x;
	ketQua.y= n * dt1.y;
	ketQua.z= n * dt1.z;

	return ketQua;
}

TVector operator/(TVector dt1, float n){
	TVector ketQua;

	ketQua.x= dt1.x / n;
	ketQua.y= dt1.y / n;
	ketQua.z= dt1.z / n;

	return ketQua;
}

TVector operator/(float n, TVector dt1){
	TVector ketQua;

	ketQua.x= n / dt1.x;
	ketQua.y= n / dt1.y;
	ketQua.z= n / dt1.z;

	return ketQua;
}

int main(){
	// tao doi tuong
	TVector dt1;
	TVector dt2;
	TVector dt3;
	
	// nhap du lieu
	cout << "Nhap vector d1:\n";
	cin >> dt1;
	
	cout << "\nNhap vector d2:\n";
	cin >> dt2;
	
	cout << "\nNhap vector d3:\n";
	cin >> dt3;
	
	// hien thi du lieu
	cout << "\nd1: " << dt1 << "\n";
	cout << "d2: " << dt2 << "\n";
	cout << "d3: " << dt3 << "\n";
	
	// tinh gia tri cac bieu thuc
	cout << "\nTinh gia tri cac bieu thuc:\n";
	cout << "v1 = (d1 + d2) * d3^2\n";
	cout << "v1 = (" << dt1 << " + " << dt2 << ") * " << dt3 << "^2\n";
	TVector v1 = (dt1 + dt2) * (dt3 * dt3);
	cout << "v1 = " << v1 << "\n\n";
	
	cout << "v2 = 2*d1 + 3*d2 - 3\n";
	cout << "v2 = 2*" << dt1 << " + 3*" << dt2 << " - 3\n";
	TVector v2 = 2*dt1 + 3*dt2 - 3;
	cout << "v2 = " << v2 << "\n\n";
	
	cout << "v3 = (d1 + d2)/3 - d3\n";
	cout << "v3 = (" << dt1 << " + " << dt2 << ")/3 - " << dt3 << "\n";
	TVector v3 = (dt1 + dt2)/3 - dt3;
	cout << "v3 = " << v3 << "\n\n";
	
	cout << "v4 = d1^2 - 4 * d2 * d3\n";
	cout << "v4 = " << dt1 << "^2 - 4 * " << dt2 << " * " << dt3 << "\n";
	TVector v4 = (dt1*dt1) - 4 * dt2 * dt3;
	cout << "v4 = " << v4 << "\n";
	
	// tao mang
	TVector arr[3] = {dt1, dt2, dt3};
	
	// tao bien temp
	TVector temp;
	
	// sap xep
	for(int i = 0; i <= 3 - 2; i++){
		for(int j = i + 1; j <= 3 - 1; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout << "\nvector lon nhat: " << arr[2] << "\n";
	cout << "vector nho nhat: " << arr[0] << "\n";
	
	return 0;
}
