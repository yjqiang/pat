#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

char str_num[5];

int str2Decimal() {
	int i;
	int sum = 0;
	for (i = 0; str_num[i] != '\0'; ++i)
		sum = sum * 10 + str_num[i] - '0';
	return sum;
}

void myReverse(int n) {
	int i, k;
	char tmp;
	for (i = 0, k = n - 1; i < k; ++i, --k) {
		tmp = str_num[i];
		str_num[i] = str_num[k];
		str_num[k] = tmp;
	}
}

void decimal2Str(int num) {
	int i = 0;
	if (!num) {
		i = 1;
		str_num[0] = '0';
		str_num[1] = '\0';
	}
	while (num) {
		str_num[i++] = num % 10 + '0';
		num /= 10;
	}
	myReverse(i);
}

void fullFill() {
	int index;
	for (index = 0; str_num[index] != '\0'; ++index);
	for (; index < 4; ++index)
		str_num[index] = '0';
	str_num[index] = '\0';
}


int cmp(const void* p0, const void* p1) {
	char* c0 = (char*)p0;
	char* c1 = (char*)p1;
	return (*c0) - (*c1);

}

int main() {
	int int_num0, int_num1, result = -1;
	int n = 4;
	scanf("%d", &result);

	do{
		decimal2Str(result);
		fullFill();
		qsort(str_num, n, sizeof(char), cmp);
		int_num0 = str2Decimal();
		myReverse(n);
		int_num1 = str2Decimal();
		
		result = int_num1 - int_num0;
		printf("%04d - %04d = %04d\n", int_num1, int_num0, result);
	} while (result != 0 && result != 6174);

	system("pause");


	return 0;
}