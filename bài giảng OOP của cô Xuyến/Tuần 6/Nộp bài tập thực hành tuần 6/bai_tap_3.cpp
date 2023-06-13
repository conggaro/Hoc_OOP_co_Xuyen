// Yêu cầu:
// 1. nhập 1 chuỗi bất kỳ từ bàn phím
// 2. loại bỏ khoảng trắng ở đầu, cuối chuỗi
// 3. đếm số lượng từ trong chuỗi
// 4. thực hiện chức năng như Capitalize Each Word của MS Word

#include <iostream>
#include <string>
using namespace std;

// hàm xóa khoảng trắng ở đầu, cuối chuỗi
string Xoa_KhoangTrang_O_Dau_Cuoi_Chuoi(string thamSo){
    string khoi_tao = thamSo;

    int index = 0;

    // việc 1:
    // xóa khoảng trắng ở đầu
    while (index < khoi_tao.length())
    {
        if (khoi_tao[index] == ' ')
        {
            khoi_tao.erase(index, 1);
        }
        else if (khoi_tao[index] != ' ')
        {
            break;
        }
    }
    
    // việc 2:
    // xóa khoảng trắng ở cuối
    index = khoi_tao.length() - 1;
    while (index >= 0)
    {
        if (khoi_tao[index] == ' ')
        {
            khoi_tao.erase(index, 1);
            index = index - 1;
        }
        else if (khoi_tao[index] != ' ')
        {
            break;
        }
    }

    return khoi_tao;
}

// hàm đếm số lượng từ trong chuỗi
// nếu str[0] khác khoảng trắng
// str[0] nằm trong khoảng [65, 90] hoặc [97, 122]
// thì dem ++

// thứ nhất ký tự str[i] nằm trong khoảng [65, 90] hoặc [97, 122]
// thứ hai là str[i - 1] == ' '

int Dem_Tu(string str){
    string data = str;
    int dem = 0;

    char kyTu;
    int soTP;

    int index = 0;

    kyTu = data[0];
    soTP = (int)kyTu;
    bool kiemTra1 = soTP >= 65 && soTP <= 90 ? true : false;
    bool kiemTra2 = soTP >= 97 && soTP <= 122 ? true : false;
    bool kiemTra3 = kiemTra1 || kiemTra2 ? true : false;

    if (kiemTra3 == true)
    {
        dem = dem + 1;
    }

    while (index < data.length())
    {
        kyTu = data[index];
        soTP = (int)kyTu;

        kiemTra1 = soTP >= 65 && soTP <= 90 ? true : false;
        kiemTra2 = soTP >= 97 && soTP <= 122 ? true : false;
        kiemTra3 = kiemTra1 || kiemTra2 ? true : false;
        
        if (kiemTra3 == true && data[index - 1] == ' ')
        {
            dem = dem + 1;
        }     

        index = index + 1;   
    }

    return dem;
}

// hàm chuẩn hóa chuỗi
string Ham_Chuan_Hoa_Chuoi(string thamSo){

    // việc 1:
    // chuyển tất cả chữ hoa thành chữ thường
    int kyTu;
    int soTP;
    
    for (int i = 0; i < thamSo.length(); i++)
    {
        kyTu = thamSo[i];
        soTP = (int)kyTu;

        // tiền xử lý những chữ in hoa
        bool kiemTra1 = soTP >= 65 && soTP <= 90 ? true : false;

        if (kiemTra1 == true)
        {
            soTP = soTP + 32;
            kyTu = (char)soTP;
            thamSo[i] = kyTu;
        }        
    }

    // việc 2:
    // xóa khoảng trắng ở đầu
    int index = 0;
    while (index < thamSo.length())
    {
        // nếu phần tử thứ index là khoảng trắng
        // thì gọi .erase() để xóa nó
        if(thamSo[index] == ' '){
            thamSo.erase(index, 1);
        }
        else if(thamSo[index] != ' '){
            break;
        }
    }

    // việc 3:
    // xóa khoảng trắng ở cuối
    int index_2 = thamSo.length() - 1;
    while (index_2 >= 0)
    {
        if (thamSo[index_2] == ' ')
        {
            thamSo.erase(index_2, 1);
            index_2 = index_2 - 1;
        }
        else if(thamSo[index_2] != ' '){
            break;
        }        
    }
    
    // việc 4:
    // xóa khoảng trắng ở giữa
    // bản chất là xóa 2 phần tử trùng nhau
    int index_4 = 0;

    while(index_4 < thamSo.length()){
        if(thamSo[index_4] == thamSo[index_4 + 1]){ // dòng này cực kỳ quan trọng luôn
            if(thamSo[index_4] == ' '){
                thamSo.erase(index_4, 1);
            }
        }
        else if(thamSo[index_4] != thamSo[index_4 + 1]){
            index_4 = index_4 + 1;
        }
    }
    
    // việc 5: 
    // chữ cái đầu tiên của các từ thì viết hoa
    for (int i = 0; i < thamSo.size(); i++)
    {
        if(thamSo[i] == ' ' && thamSo[i+1] != ' '){
            thamSo[i+1] = thamSo[i+1] - 32;
        }
    }

    // chuyển chữ thường sang chữ hoa thì trừ 32
    thamSo[0] = thamSo[0] - 32;

    return thamSo;
}

int main(){
    cout << "Nhap vao 1 chuoi: ";
    string str;
    getline(cin, str, '\n');

    // chuỗi ban đầu
    cout << "\nChuoi ban dau:\n";
    cout << "=> \"" + str + "\"\n";

    // xóa khoảng trắng ở đầu, cuối chuỗi
    cout << "\nXoa khoang trang o dau, cuoi chuoi:\n";
    cout << "=> \"" << Xoa_KhoangTrang_O_Dau_Cuoi_Chuoi(str) << "\"\n";

    // đếm số lượng từ trong chuỗi
    // từ phải bắt đầu bằng chữ cái hoa, hoặc chữ cái thường
    // chữ đầu tiên của từ phải đứng sau ký tự cách ' '
    cout << "\nSo luong tu trong chuoi:\n";
    cout << "=> " << Dem_Tu(str) << "\n";

    cout << "\nChuoi sau khi chuan hoa la:\n";
    cout << "=> \"" << Ham_Chuan_Hoa_Chuoi(str) << "\"\n\n";

    return 0;
}