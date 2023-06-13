// Yêu cầu:
// 1. nhập số nguyên n

// 2. nhập thông tin cho n nhân viên
// gồm:
// họ tên
// số lượng máy tính bán được

// 3. in ra những nhân viên
// bán được số lượng máy tính
// lớn hơn số lượng trung bình của các nhân viên trong cửa hàng

// 4. in ra nhân viên tên "Trung" hoặc "Huyền"
// nhưng số lượng bán ra phải trên trung bình

// 5. tính toán các cặp đôi có tổng là số nguyên tố
// nhưng chỉ chọn ra số nguyên tố lớn nhất thôi
// rồi in ra cặp đôi có tổng là SNT lớn nhất

// gợi ý: Sử dụng quy hoạch động

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// tạo kiểu bản ghi nhân viên
struct NhanVien{
    string hoTen;
    int so_luong; // số lượng máy tính bán được
};

// hàm nhập dữ liệu
void NhapDuLieu(vector<NhanVien> &v, int do_dai){
    cout << "\n-------------------- NHAP DU LIEU --------------------\n";

    NhanVien item;

    for (int i = 0; i < do_dai; i++)
    {
        cout << "\nNhan vien index = " << i << "\n";
        
        cout << "Nhap ten: ";
        getline(cin, item.hoTen, '\n');

        cout << "Nhap so luong may tinh ban duoc: ";
        cin >> item.so_luong;
        cin.ignore();

        v.push_back(item);
    }
    
    cout << "\n";
}

// hàm hiển thị thông tin nhân viên đã nhập
void HienThi(vector<NhanVien> v){
    cout << "\n----------------- HIEN THI NHAN VIEN -----------------\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << "\nNhan vien index = " << i << "\n";
        
        cout << "Ten: " << v[i].hoTen << "\n";

        cout << "So luong may tinh ban duoc: " << v[i].so_luong << "\n";
    }
    
    cout << "\n";
}

// hàm in ra nhân viên bán được nhiều máy tính
// hơn số lượng trung bình máy tính bán được của tất cả mọi người
void Ham_In_Ra_Ban_Duoc_MayTinh_NhieuHonTB(vector<NhanVien> v){
    int trung_binh = 0;
    int tong = 0;

    for (int i = 0; i < v.size(); i++)
    {
        tong = tong + v[i].so_luong;
    }
    
    trung_binh = tong / v.size();

    cout << "\n----------------- NHAN VIEN TREN TRUNG BINH -----------------\n";

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].so_luong > trung_binh)
        {
            cout << "\n" << v[i].hoTen << "\n";
        }
    }
    
    cout << "\n";
}

// hàm tìm nhân viên tên "Trung" hoặc tên "Huyền"
// nhưng số lượng máy tính bán được phải trên trung bình
void Ham_TrenTB_Trung_hoac_Huyen(vector<NhanVien> v){
    int trung_binh = 0;
    int tong = 0;

    for (int i = 0; i < v.size(); i++)
    {
        tong = tong + v[i].so_luong;
    }
    
    trung_binh = tong / v.size();

    cout << "\n----------------- TRUNG (HOAC HUYEN) -----------------\n";

    for (int i = 0; i < v.size(); i++)
    {
        // lấy tên
        int vi_tri_DauCach = v[i].hoTen.rfind(' ', v[i].hoTen.length() - 1);
        string ten = v[i].hoTen.substr(vi_tri_DauCach + 1, v[i].hoTen.length() - 1 - vi_tri_DauCach);

        if (v[i].so_luong > trung_binh)
        {
            if (ten == "Trung" || ten == "Huyen")
            {
                cout << "\n" << v[i].hoTen << ", " << v[i].so_luong << "\n";
            }
        }
    }
    
    cout << "\n";
}

// hàm kiểm tra số nguyên tố
bool KiemTra_SNT(int thamSo){
    bool ketQua;

    int dem = 0;

    for (int i = 1; i <= thamSo; i++)
    {
        if (thamSo % i == 0)
        {
            dem = dem + 1;
        }        
    }
    
    if (dem == 2)
    {
        ketQua = true;
    }
    else if (dem != 2)
    {
        ketQua = false;
    }

    return ketQua;
}

// hàm trả ra 2 nhân viên có tổng là số nguyên tố
// và cái tổng đó lớn nhất
vector<NhanVien> Ham_2_NhanVien(vector<NhanVien> v){
    // tạo chỗ để chứa 2 cái nhân viên có tổng là số nguyên tố
    // tổng đấy lại còn lớn nhất
    vector<NhanVien> ketQua(0);

    int do_dai = v.size();

    // tạo bảng để làm cái trò quy hoạch động
    // bảng này sẽ chứa tổng
    // tổng số lượng mặt hàng bán được của 2 nhân viên bất kỳ
    vector<vector<int>> Data_Table(do_dai, vector<int>(do_dai, 0));

    int tong = 0;

    for (int i = 0; i < do_dai - 1; i++)
    {
        for (int j = i + 1; j < do_dai; j++)
        {
            tong = v[i].so_luong + v[j].so_luong;
            Data_Table[i][j] = tong;
        }
        
    }

    int max = Data_Table[0][0];

    // tạo biến để lưu i
    int luu_i = 0;

    // tạo biến để lưu j
    int luu_j = 0;

    for (int i = 0; i < do_dai; i++)
    {
        for (int j = 0; j < do_dai; j++)
        {
            if (KiemTra_SNT(Data_Table[i][j]) == true)
            {
                if (max < Data_Table[i][j])
                {
                    max = Data_Table[i][j];
                    
                    // còn phải lưu cái giá trị của i và j nữa
                    luu_i = i;
                    luu_j = j;
                }
            }
            
        }
        
    }
    
    if (luu_i != 0 && luu_j != 0)
    {
        ketQua.push_back(v[luu_i]);
        ketQua.push_back(v[luu_j]);
    }

    return ketQua;
}

// hàm in ra 2 nhân viên có tổng là số nguyên tố lớn nhất
void In_Ra_2_NhanVien_Co_Tong_La_SNT_LonNhat(vector<NhanVien> v){
    if (v.empty() == true)
    {
        cout << "\nKhong co 2 nhan vien nao thoa man dieu kien.\n";
    }
    else if (v.empty() == false)
    {
        cout << "\n---------- HAI NHAN VIEN CO TONG LA SO NGUYEN TO LON NHAT ----------\n";
        for (int i = 0; i < v.size(); i++)
        {
            cout << "\n" << v[i].hoTen << "\t\t" << v[i].so_luong << "\n";
        }
        
    }
    
}

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;
    cin.ignore();

    // tạo vector nhân viên
    vector<NhanVien> v_NhanVien(0);

    // gọi hàm nhập dữ liệu
    NhapDuLieu(v_NhanVien, n);

    // gọi hàm hiển thị
    HienThi(v_NhanVien);

    // gọi hàm in ra nhân viên bán được nhiều máy tính
    // hơn số lượng trung bình máy tính bán được của tất cả mọi người
    Ham_In_Ra_Ban_Duoc_MayTinh_NhieuHonTB(v_NhanVien);

    // gọi hàm tìm nhân viên tên "Trung" hoặc tên "Huyền"
    // nhưng số lượng máy tính bán được phải trên trung bình
    Ham_TrenTB_Trung_hoac_Huyen(v_NhanVien);

    // hứng kết quả của 2 nhân viên có tổng là số nguyên tố lớn nhất
    vector<NhanVien> hung_data;
    hung_data = Ham_2_NhanVien(v_NhanVien);

    // hàm in ra 2 nhân viên có tổng là số nguyên tố lớn nhất
    In_Ra_2_NhanVien_Co_Tong_La_SNT_LonNhat(hung_data);

    return 0;
}