#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char special = '#';
char s[1005];
char T[2005];
int P[2005];

int main() {
	cin.getline(s, 1001);
	int n = strlen(s);

	int size_T = n * 2 + 1;
	int i;
	// 填充# 特殊符号
	for (i = 0; i < n; ++i) {
		T[2 * i] = special;
		T[2 * i + 1] = s[i];
	}
	T[size_T - 1] = special;

	// 当前所有回文串的右端点中，最右端
	int R = 0;
	// 对应的中心点
	int C = 0;

	int cur_R;

	int max_R = -1;
	int start = -1;

	for (i = 0; i < size_T; ++i) {
		// i < R时，i关于C的对称点i'一定存在(>=0)
		// 若P[i']对应的半径超过了C的范围，则cur_R从R-i处开始搜索；否则从P[i']开始搜索
		if (i < R)
			cur_R = min(P[2 * C - i], R - i);
		else  // 没有信息，从0开始搜索
			cur_R = 0;

		++cur_R;
		for (; i - cur_R >= 0 && i + cur_R < size_T && T[i - cur_R] == T[i + cur_R]; ++cur_R);
		--cur_R;

		// 更新最右端
		if (i + cur_R > R) {
			R = i + cur_R;
			C = i;
		}
		// 更新最大回文串（cur_R 这个填充后的半径就是原回文串的整个长度）
		if (cur_R > max_R) {
			max_R = cur_R;
			// 回文串左端点一定是 # 这里
			start = (i - cur_R) / 2;
		}

	}
	//for (i = start; i < start + max_R; ++i)
	//	printf("%c", s[i]);
	//printf("\n");
	printf("%d", max_R);

	system("pause");
	return 0;
}