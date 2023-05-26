// Yêu cầu:
// 1. Nhập vào 2 số tháng và năm
// 2. In ra lịch của tháng đó

#include <iostream>
using namespace std;

// tạo 1 cái hàm để cho biết ngày trong tuần là thứ mấy
int Days_Of_Week(int day, int month, int year){
    if(month < 3){
		month = month + 12;
		year = year - 1;
	}

	int c = year / 100;
	int k = year % 100;

	int DOW = (day + 26*(month+1)/10 + k + k/4 + c/4 + c*5) % 7;

    // thứ 7 thì DOW = 0
    // chủ nhật thì DOW = 1
    // thứ 2 thì DOW = 2
    return DOW;
}

int main(){
    int thang, nam;
    cin >> thang >> nam;

    cout << "CN\tT2\tT3\tT4\tT5\tT6\tT7" << endl;
    
    int ngay = 0;

    int tongSoNgay = 0;

    switch(thang){
        case 1:
            tongSoNgay = 31;
            break;
        case 2:
            if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0){
                tongSoNgay = 29;
            }else{
                tongSoNgay = 28;
            }
            break;
        case 3:
            tongSoNgay = 31;
            break;
        case 4:
            tongSoNgay = 30;
            break;
        case 5:
            tongSoNgay = 31;
            break;
        case 6:
            tongSoNgay = 30;
            break;
        case 7:
            tongSoNgay = 31;
            break;
        case 8:
            tongSoNgay = 31;
            break;
        case 9:
            tongSoNgay = 30;
            break;
        case 10:
            tongSoNgay = 31;
            break;
        case 11:
            tongSoNgay = 30;
            break;
        case 12:
            tongSoNgay = 31;
            break;
    }
    
    int i = 1;

    while(ngay < tongSoNgay){
        if(i == 1){
            // tức là với cái ngày 1 thì cần bao nhiêu cái "\t"
            // ví dụ ngày 1 rơi vào chủ nhật --> thì không có "\t"
            // ví dụ ngày 1 rơi vào thứ 2 --> thì có 1 cái "\t"

            switch (Days_Of_Week(1, thang, nam)){
                case 0:
                    cout << "\t\t\t\t\t\t";
                    for(int j = 1; j <= 1; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                case 1:
                    for(int j = 1; j <= 7; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }          
                    cout << endl;      
                    break;
                case 2:
                    cout << "\t";
                    for(int j = 1; j <= 6; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                case 3:
                    cout << "\t\t";
                    for(int j = 1; j <= 5; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                case 4:
                    cout << "\t\t\t";
                    for(int j = 1; j <= 4; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                case 5:
                    cout << "\t\t\t\t";
                    for(int j = 1; j <= 3; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                case 6:
                    cout << "\t\t\t\t\t";
                    for(int j = 1; j <= 2; j++){
                        ngay = ngay + 1;
                        cout << ngay << "\t";
                    }
                    cout << endl;
                    break;
                default:
                    break;
            }
        }

        for(int j = 1; j <= 7; j++){
            ngay = ngay + 1;
            if(ngay < tongSoNgay){
                cout << ngay << "\t";
            }

            if(ngay == tongSoNgay){
                cout << ngay;
                break;
            }
        }
        cout << endl;
        i = i + 1;
    }
    
    return 0;
}