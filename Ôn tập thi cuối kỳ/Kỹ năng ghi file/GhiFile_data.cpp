// Yêu cầu:
// 1. mở file
// 2. ghi file

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    // tạo biến
    string ho_ten = "Nguyen Van A";
    int tuoi = 20;
    double diemTB = 9.9;

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("data.out", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file data.out that bai\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file data.out thanh cong\n\n";

        file_out << ho_ten << "\n";
        file_out << tuoi << "\n";
        file_out << diemTB;

        file_out.close();
    }

    return 0;
}