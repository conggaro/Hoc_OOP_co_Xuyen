// Yêu cầu:
// 1. đọc file
// 2. ghi file

// ĐỌC FILE
// dòng 1       --> là số lượng thiết bị
// dòng 2       --> là giá tiền của từng loại thiết bị
// dòng 3       --> là số lượng của từng loại thiết bị

// GHI FILE
// dòng 1       --> đếm số lượng thiết bị có giá >= 100
// dòng 2       --> ghi số lượng của các thiết bị có giá nhỏ nhất

// Chú ý:
// hai số cách nhau bởi 1 dấu cách

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// tạo kiểu bản ghi cho thiết bị
struct ThietBi{
    int gia;        // giá
    int so_luong;   // số lượng
};

int main(){
    // tạo vector thiết bị
    vector<ThietBi> v_ThietBi(0);

    // tạo bản ghi item
    ThietBi item;

    // tạo biến để hứng số lượng item
    int n;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("thietbi.inp", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file thietbi.inp THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file thietbi.inp THANH CONG\n\n";

        // hứng số lượng
        file_in >> n;

        // tiền xử lý
        // tạo trước 8 cái chỗ trống
        // để chút nữa hứng dữ liệu thiết bị
        for (int i = 1; i <= n; i++)
        {
            v_ThietBi.push_back(item);
        }
        
        for (int i = 0; i < n; i++)
        {
            file_in >> v_ThietBi[i].gia;
        }
        
        for (int i = 0; i < n; i++)
        {
            file_in >> v_ThietBi[i].so_luong;
        }

        file_in.close();
    }

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("thietbi.out", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file thietbi.out THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file thietbi.out THANH CONG\n\n";

        // đếm số lượng thiết bị có giá >= 100
        int dem_ThietBi = 0;
        for (int i = 0; i < v_ThietBi.size(); i++)
        {
            if (v_ThietBi[i].gia >= 100)
            {
                dem_ThietBi = dem_ThietBi + 1;
            }            
        }
        file_out << dem_ThietBi << "\n";

        // tìm giá trị nhỏ nhất của giá thiết bị
        int min = v_ThietBi[0].gia;
        for (int i = 0; i < v_ThietBi.size(); i++)
        {
            if (min > v_ThietBi[i].gia)
            {
                min = v_ThietBi[i].gia;
            }            
        }
        
        // tìm xong giá nhỏ nhất
        // thì in số lượng ra file
        for (int i = 0; i < v_ThietBi.size(); i++)
        {
            if (min == v_ThietBi[i].gia)
            {
                file_out << v_ThietBi[i].so_luong << " ";
            }
        }
        

        file_out.close();
    }
    

    return 0;
}