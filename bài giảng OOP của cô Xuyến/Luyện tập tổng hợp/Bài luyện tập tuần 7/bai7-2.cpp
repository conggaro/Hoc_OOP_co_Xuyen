// Yêu cầu:
// 1. đọc file
// 2. ghi file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    // tạo biến str để lưu dữ liệu
    string str = "";

    // tạo biến item
    string item = "";

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("NEWS.INP", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file NEWS.INP THAT BAI\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file NEWS.INP THANH CONG\n\n";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            file_in >> item;

            str = str + item;
        }        

        file_in.close();
    }

    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("NEWS.OUT", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file NEWS.OUT THAT BAI\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file NEWS.OUT THANH CONG\n\n";

        // tạo biến đếm chữ cái
        int dem_ChuCai = 0;

        // tạo biến đếm chữ số
        int dem_ChuSo = 0;

        // tạo biến đếm ký tự
        int dem_KyTu = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if ((65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122))
            {
                dem_ChuCai ++;
            }
            else if ('0' <= str[i] && str[i] <= '9')
            {
                dem_ChuSo ++;
            }
            else
            {
                dem_KyTu ++;
            }            
        }
        
        file_out << dem_ChuCai << " " << dem_ChuSo << " " << dem_KyTu;

        file_out.close();
    } 
    
    return 0;
}