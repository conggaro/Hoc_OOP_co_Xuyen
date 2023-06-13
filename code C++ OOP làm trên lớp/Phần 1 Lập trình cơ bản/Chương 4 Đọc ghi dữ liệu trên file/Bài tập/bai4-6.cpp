// Mô tả:
// một công ty sản xuất n mặt hàng

// mỗi mặt hàng gồm các thông tin:
// mã mặt hàng
// tên mặt hàng
// số lượng
// giá bán

// Yêu cầu:
// 1. lập trình đọc dữ liệu về các mặt hàng

// 2. sắp xếp các mặt hàng theo chiều giảm dần của số lượng
// nếu hai mặt hàng bằng nhau về số lượng 
// thì sắp xếp theo chiều giảm dần của giá bán

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct MatHang{
    string ma_MatHang;
    string ten_MatHang;
    int so_luong;       // số lượng
    int gia_ban;        // giá bán
};

// hàm sắp theo theo giá tiền
// trong trường hợp số lượng bị trùng nhau
// sắp xếp giảm dần
void Sap_Xep_Theo_Gia_Tien(vector<MatHang> &v){
    MatHang temp;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].gia_ban < v[j].gia_ban)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }            
        }        
    }    
}

// hàm sắp xếp giảm dần
// giảm theo số lượng
void Sap_Xep_Giam_Dan(vector<MatHang> &v){
    MatHang temp;

    // gọi hàm sắp xếp giảm dần theo giá tiền
    Sap_Xep_Theo_Gia_Tien(v);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].so_luong < v[j].so_luong)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }        
    }    
}

int main(){
    // tạo đối tượng để đọc dữ liệu
    ifstream file_in;

    // tạo vector mặt hàng
    vector<MatHang> v_mh(0);

    // tạo item cho mặt hàng
    MatHang item;

    int n; // n là số lượng mặt hàng

    // mở file
    file_in.open("mathang.inp", ios::in);

    // kiểm tra mở có thành công không
    if (file_in.fail() == true)
    {
        cout << "\nMo file mathang.inp THAT BAI\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "\nMo file mathang.inp THANH CONG\n";

        // việc 1:
        // hứng dữ liệu đọc được bằng vector mặt hàng

        // đọc được phát thứ nhất là số lượng mặt hàng
        file_in >> n;
        file_in.ignore();

        int dem = 1; // đếm số lượng mặt hàng

        for (; dem <= n;)
        {
            getline(file_in, item.ma_MatHang, '\n');    // dòng 1: mã mặt hàng
            getline(file_in, item.ten_MatHang, '\n');   // dòng 2: tên mặt hàng
            file_in >> item.so_luong;                   // dòng 3: số lượng
            file_in >> item.gia_ban;                    // dòng 4: giá bán
                
            file_in.ignore();

            v_mh.push_back(item);
            
            dem = dem + 1;
        }

        // việc 2:
        // hứng xong dữ liệu
        // thì đóng file

        file_in.close();
    }

    // thử in ra màn hình
    cout << "\n";
    for (int i = 0; i < v_mh.size(); i++)
    {
        cout << i << ". " << v_mh[i].ma_MatHang << ", ";
        cout << v_mh[i].ten_MatHang << ", ";
        cout << v_mh[i].so_luong << ", ";
        cout << v_mh[i].gia_ban << "\n";
    }

    // gọi hàm sắp xếp giảm dần theo số lượng
    Sap_Xep_Giam_Dan(v_mh);

    // tạo đối tượng để ghi file
    ofstream file_out;
    file_out.open("mathang.out", ios::out);

    // kiểm tra có mở file thành công không
    if (file_out.fail() == true)
    {
        cout << "\nMo file mathang.out THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "\nMo file mathang.out THANH CONG\n\n";

        int index_mh = 0;

        for (; index_mh < n;)
        {
            file_out << v_mh[index_mh].ten_MatHang << " ";
            file_out << v_mh[index_mh].so_luong << " ";
            file_out << v_mh[index_mh].gia_ban;

            if (index_mh < n - 1)
            {
                file_out << "\n";
            }
            else if (index_mh == (n - 1))
            {
                // thì không làm gì 
            }

            index_mh = index_mh + 1;
        }

        file_out.close();
    }

    return 0;
}