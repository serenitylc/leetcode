/* 函数原型:
 * void *memcpy(void *dst, const void *src, size_t n)
 * 从存储区 src 复制 n 个字节到存储区 dst
 * 1.不要破坏传进来的形参，定义新的临时变量来操作
 * 2.考虑指针类型，不同类型指针不能直接 ++ 赋值
 * 3.overlap情况下需要从高地址处向前copy
 */
#include <iostream>
#include <cstring>
using namespace std;

void *mymemcpy(void *dst, const void *src, size_t size) {
    if (NULL == dst || NULL == src) return NULL;
    if (dst == src) return dst;
    char *d;
    const char *s;
    int n = static_cast<int>(size);
    if (dst < src || (char *)dst >= ((char *)src + n)) {
        d = (char *)dst;
        s = (char *)src;
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d = (char *)dst + n - 1;
        s = (char *)src + n - 1;
        while (n--) {
            *d-- = *s--;
        }
    }
    return dst;
}

int main() {
    const char src[] = "www.tencent.com";
    char dst[32];
    mymemcpy(dst, src, strlen(src) + 1);
    cout << dst << endl;
    system("pause");
    return 0;
}