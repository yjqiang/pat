// https://www.liuchuo.net/archives/4216
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

// 个位在0处
void revert(char* s, int n) {
	int i, j;
	for (i = 0, j = n - 1; i < j; ++i, --j)
		swap(s[i], s[j]);
}

// 返回result的size
int myAdd(char* base, char* A, char* B, int n_A, int n_B, char* result) {
	int i;
	int sum = 0;
	int a, b, cur_base;
	for (i = 0; i < n_A || i < n_B; ++i) {
		a = i < n_A ? A[i] - '0' : 0;
		b = i < n_B ? B[i] - '0' : 0;
		// 题目示例中 0 表示十进制
		cur_base = base[i] == '0'? 10: base[i] - '0';

		
		sum += a + b;
		// printf("%d %d %d\n", a, b, sum);
		result[i] = sum % cur_base + '0';
		sum /= cur_base;
	}
	if (sum != 0) {
		result[i] = sum % (base[i] - '0') + '0';
		++i;
	}
	result[i] = '\0';
	// 反转
	revert(result, i);
	return i;

}

int main() {
	char base[31], A[32], B[31], result[31];
	int n_base, n_A, n_B, n_result;
	scanf("%s%s%s", base, A, B);

	n_base = strlen(base);
	n_A = strlen(A);
	n_B = strlen(B);

	revert(base, n_base);
	revert(A, n_A);
	revert(B, n_B);

	n_result = myAdd(base, A, B, n_A, n_B, result);
	int i;
	for (i = 0; i < n_result; ++i)
		// 去除高位的0
		if (result[i] != '0') {
			printf("%s", result + i);
			break;
		}

	// 结果为0
	if (i == n_result)
		printf("0");
	
	system("pause");
	return 0;
}