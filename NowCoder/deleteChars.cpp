#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

// 删除first中所有出现在second中的字符
char *deleteChars(char *first, char *second) {
	assert((NULL != first) && (NULL != second));
	// 标记字符是否在字符串second中出现过
	const int tableSize = 256;
	bool hashTable[tableSize];
	memset(hashTable, 0, sizeof(hashTable));
	while (*second != '\0') {
		if (!hashTable[*second]) {
			hashTable[*second] = true;
		}
		second ++;
	}
	char *fast = first;
	char *slow = first;
	while (*fast != '\0') {
		if (!hashTable[*fast]) {
			*slow = *fast;
			++ slow;
		}
		++ fast;
	}
	*slow = '\0';
	return first;
}

void test1() { // second中的字符没有出现在first中的
	cout << "*****test1 second中的字符没有出现在first中的:*****";
	char text[] = "abcdbbad";
	char *first = text;
	char second[] = "lmni";
	first = deleteChars(first, second);
	cout << first << endl;
}

void test2() { // second中的字符有出现在first中的
	cout << "*****test1 second中的字符有出现在first中的:*****";
	char text[] = "abcdbbad";
	char *first = text;
	char second[] = "adfghb";
	first = deleteChars(first, second);
	cout << first << endl;
}

int main() {
	test1();
	test2();
    system("pause");
	return 0;
}