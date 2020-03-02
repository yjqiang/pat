#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
	int N;
	char a[] = "0123456789ABC";

	int i;
	int c_1, c_0;
	int i_1, i_0;

	printf("#");
	for (i = 0; i < 3; ++i) {
		scanf("%d", &N);
		i_1 = N / 13;
		i_0 = N % 13;
		c_1 = a[i_1];
		c_0 = a[i_0];
		printf("%c%c", c_1, c_0);
	}


	system("pause");
	return 0;
}