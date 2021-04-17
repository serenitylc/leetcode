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

-------------------------------------------
Vscode
行移动：Alt + ↑/↓
行复制：Shift + Alt + ↑/↓
块注释：Shit + Alt + A
向右/左缩进：Ctrl + ]/[
切换到下一个/上一个文件编辑点：Alt + → / ←
跳转到相应括号位置：Ctrl + Shift + \
打开/折叠代码区域：Ctrl + Shift + [/]
代码定义以浮窗形式覆盖在当前页面上：Alt + F12
跳转到代码定义位置：F12
文件内查找/替换：Ctrl + F / H
工作区内查找/替换：Ctrl + Shift + F / H
打开调试面板：Ctrl + Shift + D