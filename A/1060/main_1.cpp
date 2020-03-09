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

using namespace std;

// 总位数，小数点
#define LEN_MAX 110

char A[LEN_MAX];
char B[LEN_MAX];

// k为0.d[1]...d[N] * 10^k的那个k
// 返回值为0.00xxxx  删掉高位0和.后的位数，即有效位数
int findDecimalPoint(char* p, int n, int& k) {
	int i;

	// 小数点的位置(整数的小数点隐含在'\0'处)
	for (i = 0; i < n && p[i] != '.'; ++i);
	int point = i;

	// 从高位开始，第一个非0的index
	int index = -1;
	for (i = 0; i < n; ++i)
		if (isdigit(p[i]) && p[i] != '0') {
			index = i;
			break;
		}
	// 这个数字就是0
	if (index == -1) {
		k = 0;
		return 0;
	}

	// 删掉index前面的0，以及删掉小数点
	int j;
	for (i = index, j = 0; i < n; ++i)
		if (p[i] != '.') {
			p[j] = p[i];
			++j;
		}
	// 原数为 0.001xxx 格式
	if (index > point)
		k = point - index + 1;
	else // 原数为 10.111 格式
		k = point - index;
	return j;
}

int main() {
	int N;
	scanf("%d %s %s", &N, A, B);

	
	int n_A, n_B;
	int k_A, k_B;
	n_A = findDecimalPoint(A, strlen(A), k_A);
	n_B = findDecimalPoint(B, strlen(B), k_B);

	// 根据N截取，或者添加0
	int i;
	// 查查看是否需要补0
	for (i = 0; i < N; ++i) {
		if (i >= n_A)
			A[i] = '0';
		if (i >= n_B)
			B[i] = '0';
	}
	// 截断加停止符号
	A[N] = '\0';
	B[N] = '\0';

	if (k_A == k_B && !strcmp(A, B))
		printf("YES 0.%s*10^%d", A, k_A);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d", A, k_A, B, k_B);

	system("pause");
	return 0;
}