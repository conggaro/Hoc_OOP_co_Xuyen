// Mô tả:
// cho ma trận biểu diễn 1 cái ảnh đa mức xám
// kích thước m*n
// m dòng
// n cột

// giá trị của điểm ảnh nằm trong khoảng [0, 255]
// biểu thị cường độ sáng tăng dần

// từ màu đen       (giá trị là 0)
// đến màu trắng    (giá trị là 255)

// Yêu cầu:
// viết chương trình sử dụng kiểu lưu trữ phù hợp để biểu diễn bức ảnh
// và thực hiện các công việc sau

// 1. đọc ma trận điểm ảnh từ file "anh.dat"
// file này gồm:

// dòng 1: lưu 2 giá trị tương ứng với m và n
// để chỉ kích thước của ảnh

// m dòng sau đó:
// mỗi dòng lưu n số nguyên tương ứng với các giá trị điểm ảnh

// 2. tìm điểm ảnh tối nhất

// 3. tìm điểm ảnh sáng nhất

// 4. viết hàm thống kê số điểm ảnh có giá trị nhỏ hơn 70

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    // tạo vector 2 chiều
    vector<vector<int>> v(0, vector<int>(0, 0));

    // tạo item
    // bên trong item thì chứa n cột
    vector<int> item(0);

    // tạo m
    int m;

    // tạo n
    int n;

    // biến hứng dữ liệu
    int data = 0;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("anh.dat", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file anh.dat THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file anh.dat THANH CONG\n\n";

        // đọc dòng
        file_in >> m;

        // đọc cột
        file_in >> n;
        
        // tạo vector hứng dữ liệu đọc được
        vector<int> du_lieu;
        int item_duLieu = 0;
        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> item_duLieu;
            du_lieu.push_back(item_duLieu);
        }        
        
        // thêm dòng
        // và thêm dữ liệu toàn là số 0 cho cột
        int index_duLieu = 0;      
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                item.push_back(0);
            }
            v.push_back(item);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = du_lieu[index_duLieu];
                index_duLieu = index_duLieu + 1;
            }
        }

        file_in.close();
    }

    // in ra điểm ảnh tối nhất, sáng nhất
    // điểm ảnh tối nhất là giá trị min của ảnh
    // hoặc gọi là mảng 2 chiều
    // hoặc gọi là ma trận
    int min = v[0][0];
    int max = v[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > v[i][j])
            {
                min = v[i][j];
            }

            if (max < v[i][j])
            {
                max = v[i][j];
            }            
        }
    }
    
    cout << "Diem anh toi nhat: " << min << "\n\n";

    cout << "Diem anh sang nhat: " << max << "\n\n";

    // số điểm ảnh nhỏ hơn 70 là:
    int dem_pixel_NhoHon_70 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i][j] < 70)
            {
                dem_pixel_NhoHon_70 = dem_pixel_NhoHon_70 + 1;
            }            
        }        
    }
    cout << "So diem anh nho hon 70: " << dem_pixel_NhoHon_70 << "\n\n";

    return 0;
}