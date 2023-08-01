// Mô tả:
// Cho 1 cửa hàng kinh doanh máy vi tính
// Bây giờ người ta muốn quản lý thông tin mặt hàng

// Yêu cầu:
// 1. tạo lớp MatHang

// 2. thuộc tính:
// tên mặt hàng
// tên nhà sản xuất
// nước sản xuất
// năm sản xuất
// chủng loại (nguyên chiếc/lắp ráp)
// giá tiền
// số lượng
// hàng giảm giá (có/không)
// số lượng đã bán được

// 3. nhập mặt hàng

// 4. hiển thị danh sách mặt hàng

// 5. in ra mặt hàng đã bán hết (tức là số lượng = 0)

// 6. bổ sung thêm số lượng vào 1 mặt hàng đã có

// 7. in ra danh sách mặt hàng đang giảm giá

// 8. tính tiền của toàn bộ mặt hàng đã được bán

// 9. in ra những mặt hàng còn tồn đọng hơn 100 sản phẩm

// (bạn có thể nghĩ thêm các chức năng khác)

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// thư viện windows.h giúp xóa màn hình console
#include <windows.h>

using namespace std;

// hàm chuyển kiểu string sang bool
bool ToBoolean(string input) {
    if (input == "true" || input == "1") {
        return true;
    }
    else if (input == "false" || input == "0") {
        return false;
    }
}

// tạo lớp MatHang
class MatHang{
    private:
        string ten_MatHang;
        string ten_NhaSanXuat;
        string nuoc_SanXuat;
        int nam_SanXuat;
        bool chung_loai;        // 1 là nguyên chiếc, 0 là lắp ráp
        int gia_tien;
        int so_luong;           // đây là số lượng còn lại trong kho
        bool hang_GiamGia;      // 1 là có, 0 là không
        int soLuong_BanDuoc;

    public:
        // hàm khởi tạo không tham số
        MatHang(){
            ten_MatHang = "";
            ten_NhaSanXuat = "";
            nuoc_SanXuat = "";
            nam_SanXuat = 0;
            chung_loai = true;        // 1 là nguyên chiếc, 0 là lắp ráp
            gia_tien = 0;
            so_luong = 0;
            hang_GiamGia = false;      // 1 là có, 0 là không
            soLuong_BanDuoc = 0;
        }

        // hàm set_TenMatHang
        void set_TenMatHang(string data){
            ten_MatHang = data;
        }

        // hàm set_TenNhaSanXuat
        void set_TenNhaSanXuat(string data){
            ten_NhaSanXuat = data;
        }

        // hàm set_NuocSanXuat
        void set_NuocSanXuat(string data){
            nuoc_SanXuat = data;
        }

        // hàm set_NamSanXuat
        void set_NamSanXuat(int data){
            nam_SanXuat = data;
        }

        // hàm set_ChungLoai
        void set_ChungLoai(bool data){
            chung_loai = data;
        }

        // hàm set_GiaTien
        void set_GiaTien(int data){
            gia_tien = data;
        }

        // hàm set_SoLuong
        void set_SoLuong(int data){
            so_luong = data;
        }

        // hàm set_GiamGia
        void set_GiamGia(bool data){
            hang_GiamGia = data;
        }

        // hàm set_SoLuongBanDuoc
        void set_SoLuongBanDuoc(int data){
            soLuong_BanDuoc = data;
        }

        // hàm get_TenMatHang
        string get_TenMatHang(){
            return ten_MatHang;
        }

        // hàm get_TenNhaSanXuat
        string get_TenNhaSanXuat(){
            return ten_NhaSanXuat;
        }

        // hàm get_NuocSanXuat
        string get_NuocSanXuat(){
            return nuoc_SanXuat;
        }

        // hàm get_NamSanXuat
        int get_NamSanXuat(){
            return nam_SanXuat;
        }

        // hàm get_ChungLoai
        bool get_ChungLoai(){
            return chung_loai;
        }

        // hàm get_GiaTien
        int get_GiaTien(){
            return gia_tien;
        }

        // hàm get_SoLuong
        int get_SoLuong(){
            return so_luong;
        }

        // hàm get_GiamGia
        bool get_GiamGia(){
            return hang_GiamGia;
        }

        // hàm get_SoLuongBanDuoc
        int get_SoLuongBanDuoc(){
            return soLuong_BanDuoc;
        }

        // hàm hiển thị
        // nạp chồng toán tử <<
        friend ostream &operator<<(ostream &dt_cout, MatHang dt);

        // hàm nhập dữ liệu
        void NhapDuLieu(){
            cout << "Nhap ten mat hang: ";
            getline(cin, ten_MatHang, '\n');

            cout << "Nhap ten nha san xuat: ";
            getline(cin, ten_NhaSanXuat, '\n');

            cout << "Nhap nuoc san xuat: ";
            getline(cin, nuoc_SanXuat, '\n');

            cout << "Nhap nam san xuat: ";
            cin >> nam_SanXuat;
            cin.ignore();

            cout << "Nhap chung loai: ";
            cin >> chung_loai;
            cin.ignore();

            cout << "Nhap gia tien: ";
            cin >> gia_tien;
            cin.ignore();

            cout << "Nhap so luong: ";
            cin >> so_luong;
            cin.ignore();

            cout << "Nhap giam gia (1 hoac 0): ";
            cin >> hang_GiamGia;
            cin.ignore();

            cout << "Nhap so luong ban duoc: ";
            cin >> soLuong_BanDuoc;
            cin.ignore();
        }
};

ostream &operator<<(ostream &dt_cout, MatHang dt){
    dt_cout << "[" << dt.ten_MatHang << ", ";
    dt_cout << dt.ten_NhaSanXuat << ", ";
    dt_cout << dt.nuoc_SanXuat << ", ";
    dt_cout << dt.nam_SanXuat << ", ";
    dt_cout << dt.chung_loai << ", ";
    dt_cout << dt.gia_tien << ", ";
    dt_cout << dt.so_luong << ", ";
    dt_cout << dt.hang_GiamGia << ", ";
    dt_cout << dt.soLuong_BanDuoc << "]";

    return dt_cout;
}

// hàm xóa màn hình console
// cái xóa màn hình console này thì copy trên mạng
void Ham_Xoa_Console()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
}

// hàm hiển thị danh sách mặt hàng
void HienThi_DanhSach(){
    // gọi hàm xóa màn hình console
    // xóa cái màn hình console cũ ấy
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong\n\n";

        // tạo item để hứng dữ liệu
        MatHang item;

        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }

            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            // nếu không có bất kỳ mặt hàng nào để hiển thị
            // thì break luôn
            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            // để bỏ qua ký tự "\n"
            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }

    cout << "-------------------- HIEN THI DANH SACH --------------------\n";    
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << ". " << v[i] << "\n";
    }
    
    cout << "\n";
}

// hàm nhập dữ liệu cho mặt hàng
// dùng để thêm mới 1 mặt hàng
void Ham_NhapDuLieu(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai (Doc file)\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong (Doc file)\n\n";

        // tạo biến item để hứng dữ liệu
        MatHang item;

        // tạo biến để hứng kiểu string
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }

            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            // nếu không có bất kỳ mặt hàng nào để hiển thị
            // thì break luôn
            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }
    
    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("CoSoDuLieu.txt");

    if (file_out.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai (Ghi file)\n\n";
    }
    else if (file_out.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong (Ghi file)\n\n";

        // nhập n
        cout << "Nhap so luong mat hang: ";
        int n = 0;
        cin >> n;

        while (n <= 0 || n > 100)
        {
            cout << "Nhap lai so luong mat hang (1 <= n <= 100): ";
            cin >> n;
        }

        // gọi ignore() để bỏ qua ký tự '\n'
        cin.ignore();

        // tạo item để nhập dữ liệu
        // nhập tạm thời vào đấy đã
        MatHang item;

        cout << "\n-------------------- NHAP DU LIEU --------------------\n";
        for (int i = 0; i < n; i++)
        {
            item.NhapDuLieu();
            cout << "\n";

            v.push_back(item);
        }
        
        // bây giờ, bắt đầu ghi dữ liệu vào file
        for (int i = 0; i < v.size(); i++)
        {
            file_out << v[i].get_TenMatHang() << "$";
            file_out << v[i].get_TenNhaSanXuat() << "$";
            file_out << v[i].get_NuocSanXuat() << "$";
            file_out << v[i].get_NamSanXuat() << "$";
            file_out << v[i].get_ChungLoai() << "$";
            file_out << v[i].get_GiaTien() << "$";
            file_out << v[i].get_SoLuong() << '$';
            file_out << v[i].get_GiamGia() << '$';
            file_out << v[i].get_SoLuongBanDuoc() << '$';

            if (i != v.size() - 1)
            {
                file_out << "\n";
            }            
        }

        file_out.close();
    }
}

// hàm hiển thị danh sách
// mặt hàng đã bán hết
void Ham_HienThi_MatHang_BanHet(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong\n\n";

        // tạo biến item để hứng dữ liệu
        MatHang item;

        // tạo biến data_string để hứng dữ liệu
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            // nếu không có bất kỳ mặt hàng nào để hiển thị
            // thì break luôn
            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }
    
    cout << "-------------------- DANH SACH MAT HANG BAN HET --------------------\n";
    int stt = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].get_SoLuong() == 0)
        {
            stt ++;
            cout << stt << ". " << v[i] << "\n";
        }
    }

    cout << "\n";
}

// hàm bổ sung thêm số lượng
// vào mặt hàng đã có
void Ham_BoSung_Them_SoLuong(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc fie
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai (Doc file)\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong (Doc file)\n\n";

        // tạo đối tượng item để hứng dữ liệu
        MatHang item;

        // tạo biến data_string
        // để hứng dữ liệu đọc được
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }

    cout << "-------------------- CHON MAT HANG MUON BO SUNG SO LUONG --------------------\n\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << "[Bam phim " << i + 1 << "]\t\t" << v[i] << "\n";
    }
    
    int lua_chon = 0;

    cout << "\nNhap lua chon: ";
    cin >> lua_chon;
    
    cout << "\nNhap so luong moi cho mat hang ";
    cout << lua_chon << ": ";
    
    // tạo biến số lượng mới
    int so_luong_moi = 0;
    cin >> so_luong_moi;

    // tạo biến để lưu số lượng cũ
    int so_luong_cu = v[lua_chon - 1].get_SoLuong();

    v[lua_chon - 1].set_SoLuong(so_luong_moi);
    
    if (so_luong_cu != so_luong_moi)
    {
        cout << "\nBan da nhap so luong moi thanh cong\n\n";
    }
    else if (so_luong_cu == so_luong_moi)
    {
        cout << "\nBan da nhap so luong moi that bai\n\n";
    }

    // bây giờ phải gửi những cái thay đổi này
    // vào trong cơ sở dữ liệu

    // thì phải ghi file
    // tạo đối tượng ghi file
    ofstream file_out;
    file_out.open("CoSoDuLieu.txt", ios::out);

    if (file_out.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai (Ghi file)\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong (Ghi file)\n\n";

        for (int i = 0; i < v.size(); i++)
        {
            file_out << v[i].get_TenMatHang() << "$";
            file_out << v[i].get_TenNhaSanXuat() << "$";
            file_out << v[i].get_NuocSanXuat() << "$";
            file_out << v[i].get_NamSanXuat() << "$";
            file_out << v[i].get_ChungLoai() << "$";
            file_out << v[i].get_GiaTien() << "$";
            file_out << v[i].get_SoLuong() << "$";
            file_out << v[i].get_GiamGia() << "$";
            file_out << v[i].get_SoLuongBanDuoc() << '$';

            if (i != v.size() - 1)
            {
                file_out << "\n";
            }            
        }

        file_out.close();
    }    
}

// hàm hiển thị danh sách
// mặt hàng đang giảm giá
void Ham_HienThi_MatHang_GiamGia(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong\n\n";

        // tạo đối tượng item để hứng dữ liệu
        MatHang item;

        // tạo biến data_string để hứng dữ liệu đọc được
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }

    cout << "-------------------- DANH SACH MAT HANG DANG GIAM GIA --------------------\n";
    int index = 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].get_GiamGia() == 1)
        {
            index ++;
            cout << index << ". " << v[i] << "\n";
        }
    }
    
    cout << "\n";
}

// hàm tính tiền mặt hàng
// của tất cả mặt hàng đã được bán
void Ham_TinhTien_MatHang_DaDuocBan(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong\n\n";

        // tạo đối tượng item để hứng dữ liệu
        MatHang item;

        // tạo biến data_string
        // để hứng dữ liệu đọc từ file
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }

    // tính tiền
    long long tong = 0;

    for (int i = 0; i < v.size(); i++)
    {
        tong = tong + v[i].get_SoLuongBanDuoc() * v[i].get_GiaTien();
    }

    cout << "Tien cua tat ca mat hang duoc ban ra:\nTien = ";
    cout << tong << " VND\n\n";
}

// hàm hiển thị danh sách
// những mặt hàng tồn đọng hơn 100 sản phẩm
void Ham_HienThi_DanhSach_TonDong_Hon_100_SanPham(){
    // gọi hàm xóa màn hình console cũ
    Ham_Xoa_Console();

    // tạo vector để hứng dữ liệu
    vector<MatHang> v(0);

    // tạo đối tượng đọc file
    ifstream file_in;
    file_in.open("CoSoDuLieu.txt", ios::in);

    if (file_in.fail() == true)
    {
        cout << "Mo file CoSoDuLieu.txt that bai\n\n";
    }
    else if (file_in.fail() == false)
    {
        cout << "Mo file CoSoDuLieu.txt thanh cong\n\n";

        // tạo đối tượng item để hứng dữ liệu
        MatHang item;

        // tạo biến data_string
        // để hứng dữ liệu đọc từ file
        string data_string = "";

        while (file_in.eof() == false)
        {
            if (file_in.eof() == true)
            {
                break;
            }
            
            // đây là lấy tên mặt hàng
            getline(file_in, data_string, '$');
            item.set_TenMatHang(data_string);

            if (item.get_TenMatHang() == "")
            {
                break;
            }

            // đây là lấy tên nhà sản xuất
            getline(file_in, data_string, '$');
            item.set_TenNhaSanXuat(data_string);

            // đây là lấy nước sản xuất
            getline(file_in, data_string, '$');
            item.set_NuocSanXuat(data_string);

            // đây là lấy năm sản xuất
            getline(file_in, data_string, '$');
            int nam = stoi(data_string);
            item.set_NamSanXuat(nam);

            // đây là lấy chủng loại
            getline(file_in, data_string, '$');
            int chung_loai = ToBoolean(data_string);
            item.set_ChungLoai(chung_loai);

            // đây là lấy giá tiền
            getline(file_in, data_string, '$');
            int gia_tien = stoi(data_string);
            item.set_GiaTien(gia_tien);

            // đây là lấy số lượng
            getline(file_in, data_string, '$');
            int so_luong = stoi(data_string);
            item.set_SoLuong(so_luong);

            // đây là lấy giảm giá
            getline(file_in, data_string, '$');
            bool giam_gia = ToBoolean(data_string);
            item.set_GiamGia(giam_gia);

            // đây là lấy số lượng bán được
            getline(file_in, data_string, '$');
            int so_luong_BanDuoc = stoi(data_string);
            item.set_SoLuongBanDuoc(so_luong_BanDuoc);

            file_in.ignore();

            v.push_back(item);
        }

        file_in.close();
    }

    // tìm những sản phẩm
    // có số lượng > 100
    // rồi in ra
    int stt = 0;
    cout << "--------------- DANH SACH MAT HANG TON DONG HON 100 SAN PHAM ---------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].get_SoLuong() > 100)
        {
            stt ++;

            cout << stt << ". " << v[i] << "\n";
        }        
    }
    cout << "\n";
}

// hàm giao diện lựa chọn chức năng
void Ham_GiaoDien(){
    int lua_chon = 0;
    
    cout << "------------------------- HE THONG QUAN LY MAT HANG -------------------------\n";
    cout << "1. Nhap mat hang" << "\t\t\t\t\t\t" << "[Bam phim 1]\n";
    cout << "2. Hien thi danh sach mat hang" << "\t\t\t\t\t" << "[Bam phim 2]\n";
    cout << "3. Hien thi danh sach mat hang (DA BAN HET)" << "\t\t\t" << "[Bam phim 3]\n";
    cout << "4. Bo sung them so luong vao mat hang da co" << "\t\t\t" << "[Bam phim 4]\n";
    cout << "5. Hien thi danh sach mat hang dang giam gia" << "\t\t\t" << "[Bam phim 5]\n";
    cout << "6. Tinh tien cua toan bo mat hang da duoc ban" << "\t\t\t" << "[Bam phim 6]\n";
    cout << "7. Hien thi danh sach mat hang ton dong hon 100 san pham" << "\t" << "[Bam phim 7]\n";

    cout << "\nNhap lua chon: ";
    cin >> lua_chon;
    cin.ignore();

    if (lua_chon == 1)
    {
        // gọi hàm nhập dữ liệu mặt hàng
        Ham_NhapDuLieu();
    }
    else if (lua_chon == 2)
    {
        // gọi hàm hiển thị danh sách mặt hàng
        HienThi_DanhSach();
    }
    else if (lua_chon == 3)
    {
        // gọi hàm hiển thị danh sách
        // mặt hàng bán hết
        Ham_HienThi_MatHang_BanHet();
    }
    else if (lua_chon == 4)
    {
        // gọi hàm bổ sung thêm số lượng
        Ham_BoSung_Them_SoLuong();
    }
    else if (lua_chon == 5)
    {
        // gọi hàm hiển thị danh sách
        // mặt hàng đang giảm giá
        Ham_HienThi_MatHang_GiamGia();
    }
    else if (lua_chon == 6)
    {
        // gọi hàm tính tiền
        // của tất cả mặt hàng đã được bán
        Ham_TinhTien_MatHang_DaDuocBan();
    }
    else if (lua_chon == 7)
    {
        // gọi hàm hiển thị danh sách
        // những mặt hàng tồn đọng hơn 100 sản phẩm
        Ham_HienThi_DanhSach_TonDong_Hon_100_SanPham();
    }
}

int main(){
    // gọi hàm hiển thị giao diện
    Ham_GiaoDien();

    return 0;
}