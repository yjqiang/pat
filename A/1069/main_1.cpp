#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

char A[5];

int str2int() {
	int i;
	int result = 0;
	for (i = 0; A[i] != '\0'; ++i)
		result = result * 10 + A[i] - '0';
	return result;
}

// 一定填满4个空间，高位补充0
void int2str(int num) {
	int i;
	for (i = 3; i >= 0; --i) {
		A[i] = num % 10 + '0';
		num /= 10;
	}
}

void myReverse(int n) {
	int i, j;
	for (i = 0, j = n - 1; i < j; ++i, --j)
		swap(A[i], A[j]);
}

// 从大到小
int cmp(const void* p0, const void* p1) {
	char* c0 = (char*)p0;
	char* c1 = (char*)p1;
	return (*c1) - (*c0);
}


int main() {
	int first, second, result;
	scanf("%d", &result);
	// 前面的是单调不减，second reverse即可
	
	while (true) {
		int2str(result);

		qsort(A, 4, sizeof(char), cmp);
		sscanf(A, "%d", &first);
		myReverse(4);
		sscanf(A, "%d", &second);

		result = first - second;
		printf("%04d - %04d = %04d\n", first, second, result);
		if (result == 0 || result == 6174)
			break;

		

	}

	system("pause");
	return 0;
}