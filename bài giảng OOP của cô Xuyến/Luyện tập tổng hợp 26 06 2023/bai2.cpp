// Tác giả: Nguyễn Chí Công

// Yêu cầu:
// 1. đọc file
// hãy đọc từng dòng trong file đó ra
// đếm xem dòng đó có bao nhiêu từ?
// "từ"
// --> được định nghĩa là các ký tự liền nhau không chứa dấu cách
// 2. ghi file

// FILE INPUT
// 1. dòng đầu ghi số nguyên n
// 2. n dòng tiếp theo
// mỗi dòng ghi 1 xâu
// gồm: chữ cái, chữ số, dấu cách

// FILE OUTPUT
// 1. dòng đầu ghi số 0
// nếu tổng các từ trong file là số chẵn

// 2. dòng đầu ghi số 1
// nếu tổng các từ trong file là số lẻ

// n dòng tiếp theo là đếm số từ
// bên trái có 3 từ thì bên phải ghi số 3

#include <iostream>
#include <fstream>
#include <string>
#define SIZE 50
using namespace std;

// hàm xóa khoảng trắng
string Xoa_Khoang_Trang(string &str){
    // việc 1:
    // xóa khoảng trắng ở đầu
    for (int i = 0; i < str.length();)
    {
        if (str[0] == ' ')
        {
            str.erase(0, 1);
        }
        else if (str[0] != ' ')
        {
            break;
        }                
    }    
    
    // việc 2:
    // xóa khoảng trắng ở cuối
    for (int i = str.length() - 1; i > 0; i--)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
        }
        else if (str[i] != ' ')
        {
            break;
        }
    }

    // việc 3:
    // xóa khoảng trắng ở giữa
    int index = 0;
    for (; index < str.length();)
    {
        if (str[index] == str[index + 1])
        {
            if (str[index] == ' ')
            {
                str.erase(index, 1);
            }
            else if (str[index] != ' ')
            {
                index ++;
            }            
        }
        else if (str[index] != str[index + 1])
        {
            index ++;
        }        
    }

    return str;
}

// hàm đếm số lượng từ
int Dem_Tu(string str){
    int dem = 0;

    // duyệt lần lượt từng phần tử
    // nếu gặp khoảng trắng
    // thì dem = dem + 1
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            dem = dem + 1;
        }
        
        // nếu đọc đến ký tự cuối cùng của xâu
        // thì dem = dem + 1
        else if (i == str.length() - 1)
        {
            dem = dem + 1;
        }        
    }

    return dem;
}

int main(){
    // tạo n
    int n = 0;

    // tạo mảng để lưu số lượng
    // từ đếm được
    int arr[SIZE];

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("STRING.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file STRING.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file STRING.INP THANH CONG\n\n";
        file_in >> n;
        file_in.ignore();

        // tạo item để hứng dữ liệu
        string item = "";

        // tạo biến dem
        // để hứng dữ liệu
        int dem = 0;

        // tạo biến index cho mảng
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            // ghi dữ liệu vào item
            getline(file_in, item, '\n');
            
            // gọi hàm xóa khoảng trắng
            Xoa_Khoang_Trang(item);

            // gọi hàm đếm từ
            dem = Dem_Tu(item);

            arr[index] = dem;

            // làm xong hết việc rồi 
            // thì tăng index lên 1
            index = index + 1;
        }
        
        file_in.close();
    }
    
    // tạo đối tượng mở file
    ofstream file_out;
    file_out.open("STRING.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file STRING.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file STRING.OUT THANH CONG\n\n";

        // việc 1:
        // tính tổng
        // nếu tổng chẵn        --> in ra 0
        // nếu tổng lẻ          --> in ra 1
        int tong = 0;
        for (int i = 0; i < n; i++)
        {
            tong = tong + arr[i];
        }
        
        if (tong % 2 == 0)
        {
            file_out << 0 << "\n";
        }
        else if (tong % 2 != 0)
        {
            file_out << 1 << "\n";
        }

        // việc 2:
        // ghi số lượng từ đếm được
        // vào file output
        for (int i = 0; i < n; i++)
        {
            file_out << arr[i] << "\n";
        }

        file_out.close();
    }

    return 0;
}