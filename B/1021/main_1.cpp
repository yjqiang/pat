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

int my_count[10] = { 0 };

int main() {
	int i;
	int n;
	char c;
	while ((c = getchar())!='\n') {
		n = c - '0';
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