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

#define N_MAX 3000
char a[N_MAX], b[N_MAX], result[N_MAX];

// a 逆转得到 b，不去掉高位0（样例2）
void myReverse(int n) {
	int i, k;
	for (i = 0, k = n - 1; i < n; ++i, --k)
		b[i] = a[k];
	// 终止符号
	b[n] = '\0';
}

// 输入的a的最高位非0
// 返回的是求和，以及结果的字符串长度
int add(int n) {
	// a + b => 从a[n-1] + a[0] 开始得到result的个位，其中a[n-1]为a的个位，a[0]为逆a的个位
	int i, k;
	int sum = 0;
	for (i = 0, k = n - 1; i < n; ++i, --k) {
		sum += a[k] - '0' + a[i] - '0';
		result[i] = sum % 10 + '0';
		sum /= 10;
	}
	// 高位进位
	if (sum) {
		result[i] = sum + '0';
		++i;
	}

	n = i;
	for (i = 0, k = n - 1; i < k; ++i, --k)
		swap(result[i], result[k]);

	// result的最高位result[0]一定非0，因为a的最高位非0且sum有额外判定
	return n;
}

int main() {
	scanf("%s", a);

	int n = strlen(a); // a b互为逆转，位数一样（高位0也考虑在内，不去掉高位0（样例2））
	int i;

	// 逆转数(额外写在外面一次是因为逆转和回文判断逻辑顺序问题)
	myReverse(n);
	// 回文判定（判断原输入是否就是回文数）
	if (strcmp(a, b) == 0) {
		printf("%s is a palindromic number.", a);
		system("pause");
		return 0;
	}

	// 加法=>对本结果判断=>下一个加法
	for (i = 0; i < 10; ++i) {
		// 求结果
		n = add(n);
		printf("%s + %s = %s\n", a, b, result);

		strcpy(a, result);

		// 逆转result
		myReverse(n);

		// 回文判定
		if (strcmp(a, b) == 0) {
			printf("%s is a palindromic number.", a);
			system("pause");
			return 0;
		}
			
	}
	printf("Not found in 10 iterations.");
	
	system("pause");
	return 0;
}