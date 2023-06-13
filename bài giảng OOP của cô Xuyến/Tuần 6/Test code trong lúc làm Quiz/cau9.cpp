#include <iostream>
#include <string.h>
using namespace std;

int main(){
    struct student
    {
        int num;
        char name[25];
    };
    
    student stu;

    stu.num = 123;

    strcpy(stu.name, "John");

    cout << stu.num << endl;
    cout << stu.name << endl;

    return 0;
}