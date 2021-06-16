#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    const int local = 10;
    int *ptr = (int *)&local;
    printf("%d \n", local);
    cout << local << endl;
    *ptr = 100;
    printf("%d \n", local);
    printf("%d \n", *ptr);
    system("pause");
    return 0;
}