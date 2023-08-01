// Yêu cầu:
// 1. sử dụng ghi đè phương thức

// loại này gọi là đa hình COMPILE TIME

// cụ thể:
// là ghi đè phương thức TiengKeu()

#include <iostream>
using namespace std;

class ConVat{
    public:
        void TiengKeu(){
            cout << "Con vat: tieng keu con vat\n\n";
        }
};

class ConCho : public ConVat{
    public:
        void TiengKeu(){
            cout << "Con cho: gau gau\n\n";
        }
};

class ConMeo : public ConVat{
    public:
        void TiengKeu(){
            cout << "Con meo: meo meo\n\n";
        }
};

int main(){
    // tạo đối tượng
    ConVat dt1 = ConVat();
    ConCho dt2 = ConCho();
    ConMeo dt3 = ConMeo();

    // gọi phương thức tiếng kêu
    dt1.TiengKeu();
    dt2.TiengKeu();
    dt3.TiengKeu();

    return 0;
}