// Mô tả:
// trong khu rừng có n cây nấm (n <= 1000)
// một cây nấm thì có 2 thuộc tính là dinh dưỡng, độc tố
// người dân thì phải lấy nấm để ăn

// cây nấm có dinh_dưỡng = 2 * độc_tố
// thì ăn được

// Yêu cầu:
// 1. nhập số nguyên n
// 2. nhập thông tin cho n cây nấm
// 3. in ra màn hình thông tin nấm ăn được
// 4. in ra màn hình danh sách nấm độc nhất

// 5. sắp xếp theo chiều không giảm của mức dinh dưỡng
// tức là chiều tăng dần
// in kết quả sắp xếp ra màn hình

#include <iostream>
#include <vector>
using namespace std;

// tạo kiểu bản ghi Cây_Nấm
struct CayNam{
    int dinh_duong;
    int doc_to;
};

// hàm nhập thông tin
void Nhap_Thong_Tin(vector<CayNam> &v, int n){
    // tạo item nấm
    CayNam item;
    
    cout << "\n----------------- NHAP THONG TIN CAY NAM -----------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nCay nam index = " << i << "\n";
        
        cout << "Dinh duong:\t\t\t";
        cin >> item.dinh_duong;

        cout << "Doc to:\t\t\t\t";
        cin >> item.doc_to;

        v.push_back(item);
    }
}

// hàm hiển thị
void HienThi(vector<CayNam> v){
    cout << "\n----------------- HIEN THI THONG TIN -----------------\n\n";
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].dinh_duong << ", " << v[i].doc_to;
        cout << ")\n";
    }
}

// hàm in ra thông tin nấm có thể ăn được
void Ham_In_Ra_ThongTin_Nam_An_Duoc(vector<CayNam> v){
    cout << "\n-------------- DANH SACH NAM AN DUOC --------------\n\n";
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].dinh_duong >= v[i].doc_to * 2)
        {
            cout << "(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
        }        
    }    
}

// hàm in ra danh sách nấm có độc tố cao nhất
void Ham_In_Ra_DS_Nam_Co_Doc_To_CaoNhat(vector<CayNam> v){
    int max = 0;
    max = v[0].doc_to;

    for (int i = 0; i < v.size(); i++)
    {
        if (max < v[i].doc_to)
        {
            max = v[i].doc_to;
        }
    }

    cout << "\n----------- DANH SACH NAM CO DOC TO CAO NHAT -----------\n\n";

    for (int i = 0; i < v.size(); i++)
    {
        if (max == v[i].doc_to)
        {
            cout << "(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
        }
    }    
}

// hàm in ra màn hình thông tin nấm
// sắp xếp theo mức dinh dưỡng (tăng dần)
void SapXep_DinhDuong(vector<CayNam> &v){
    CayNam temp;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].dinh_duong > v[j].dinh_duong)
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }            
        }        
    }
    
    cout << "\n-------- SAP XEP NAM THEO CHIEU TANG DAN DINH DUONG --------\n\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].dinh_duong << ", " << v[i].doc_to << ")\n";
    }    
}

int main(){
    cout << "Nhap vao so nguyen n: ";
    int n;
    cin >> n;

    // tạo vector nấm
    vector<CayNam> v_nam;

    // gọi hàm nhập thông tin cho vector nấm
    Nhap_Thong_Tin(v_nam, n);

    // gọi hàm hiển thị
    HienThi(v_nam);

    // gọi hàm in ra danh sách nấm ăn được
    Ham_In_Ra_ThongTin_Nam_An_Duoc(v_nam);

    // gọi hàm in ra danh sách nấm có độc tố cao nhất
    Ham_In_Ra_DS_Nam_Co_Doc_To_CaoNhat(v_nam);

    // gọi hàm sắp xếp dinh dưỡng
    // theo chiều không giảm (tức là tăng dần)
    SapXep_DinhDuong(v_nam);

    cout << "\n";

    return 0;
}
