#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define STR_LEN_MAX 300
char a[STR_LEN_MAX], b[STR_LEN_MAX];


void myRevert(char* s, int n) {
	int i, j;
	for (i = 0, j = n - 1; i < j; ++i, --j)
		swap(s[i], s[j]);
}

int main() {
	int n_a, n_b;
	int N;

	cin >> N;
	// 去除\n
	cin.get();

	cin.getline(a, STR_LEN_MAX);
	n_a = strlen(a);
	myRevert(a, n_a);

	int i, k;

	// 最长匹配长度
	int max_same = n_a;
	for (i = 1; i < N; ++i) {
		cin.getline(b, STR_LEN_MAX);
		n_b = strlen(b);
		myRevert(b, n_b);

		// 两两匹配，最终结果长度<=之前的结果长度；且一定小于等于原字符串长度
		for (k = 0; k < n_a && k < n_b && k < max_same && a[k] == b[k]; ++k);
		// printf("%d\n", k);
		max_same = k;
	}
	if (k == 0)
		printf("nai");
	else {
		for (i = k - 1; i >= 0; --i)
			printf("%c", a[i]);
	}
	

	
	system("pause");
	return 0;
}