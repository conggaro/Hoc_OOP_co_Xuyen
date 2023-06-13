#include <iostream>
#define SIZE 10
using namespace std;

void QuyHoachDong(int arr[SIZE], int n, int Data_Table[SIZE][SIZE]){
    
    int tong = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            tong = arr[i] + arr[j];
            Data_Table[i][j] = tong;
        }
        
    }
    
}

int main(){
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = 10;

    int Data_Table[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Data_Table[i][j] = 0;
        }
        
    }

    QuyHoachDong(arr, n, Data_Table);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << Data_Table[i][j] << "\t";
        }
        cout << "\n";
    }
    
    return 0;
}