#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

char num[1001];
int my_count[10] = { 0 };

int main() {
	scanf("%s", num);
	int i;
	int n;
	for (i = 0; num[i] != '\0'; ++i) {
		n = num[i] - '0';
		++my_count[n];
	}
	for (i = 0; i < 10; ++i) {
		n = my_count[i];
		if (n)
			printf("%d:%d\n", i, n);
	}
		

	system("pause");
	return 0;
}