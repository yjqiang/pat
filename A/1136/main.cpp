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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 2000

char A[N_MAX];
char B[N_MAX];
char result[N_MAX];

// A[n_A - 1] 为 A 的个位
// B[n_A - 1] 为 B 的个位
// A[i] = B[n-1-i]
// 实际计算时候，没用B，这俩对称的
// 返回result的位数
int mySum(int n_A) {
	int i;
	int sum = 0;
	for (i = 0; i < n_A; ++i) {
		// A[0] 就是B的个位
		// A[n_A - 1 - 0]就是A的个位
		sum += (A[n_A - 1 - i] - '0') + (A[i] - '0');
		result[i] = sum % 10 + '0';
		sum /= 10;
	}
	if (sum != 0) {
		result[i] = sum + '0';
		++i;
	}
	result[i] = '\0';
	// 反转
	reverse(result, result + i);
	return i;
}

// 反转A得到B，注意样例里面的10755470 + 07455701 = 18211171
void getB(int n_A) {
	int i;
	for (i = 0; i < n_A; ++i)
		B[n_A - 1 - i] = A[i];
	B[n_A] = '\0';
}

bool isPalindrome(int n_result) {
	int i, j;
	for (i = 0, j = n_result - 1; i < j; ++i, --j)
		if (result[i] != result[j])
			return false;
	return true;
}

int main() {
	scanf("%s", result);
	int n_A;
	if (isPalindrome(strlen(result))) {
		printf("%s is a palindromic number.", result);
		return 0;
	}

	int i;
	bool is_ok = false;
	for (i = 0; i < 10; ++i) {
		// 把result赋值给A
		strcpy(A, result);
		n_A = strlen(A);

		getB(n_A);

		mySum(n_A);	
		printf("%s + %s = %s\n", A, B, result);

		if (isPalindrome(strlen(result))) {
			is_ok = true;
			printf("%s is a palindromic number.", result);
			break;
		}	
	}

	if (!is_ok)
		printf("Not found in 10 iterations.");

	system("pause");
	return 0;
}