// Yêu cầu:
// 1. đọc file
// 2. ghi file
// 3. tìm số hoàn hảo trong khoảng từ 0 đến M --> [0, M]

// FILE INPUT
// ghi số nguyên dương M

// FILE OUTPUT
// mỗi dòng thì ghi 1 số hoàn hảo tìm được

// Ví dụ:
// 6 là số hoàn hảo vì tổng các ước của nó 
// bằng chính nó
// 6 = 1 + 2+ 3

#include <iostream>
#include <fstream>
using namespace std;

// hàm kiểm tra số hoàn hảo
bool KiemTra_SHH(int thamSo){
    bool ketQua;

    int tong = 0;

    for (int i = 1; i < thamSo; i++)
    {
        if (thamSo % i == 0)
        {
            tong = tong + i;
        }        
    }
    
    if (tong == thamSo)
    {
        ketQua = true;
    }
    else
    {
        ketQua = false;
    }

    return ketQua;
}

int main(){
    // tạo M
    int M;

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("NUMBER.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file NUMBER.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file NUMBER.INP THANH CONG\n\n";

        file_in >> M;

        file_in.close();
    }
    
    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("NUMBER.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file NUMBER.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file NUMBER.OUT THANH CONG\n\n";

        for (int i = 1; i <= M; i++)
        {
            if (KiemTra_SHH(i))
            {
                file_out << i << "\n";
            }            
        }        

        file_out.close();
    }    

    return 0;
}