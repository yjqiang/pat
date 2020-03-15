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

char result[3][5] = { "Ping", "Cong", "Gai" };

// 比较a和b，并返回result对应结果的下标
// b是我，a为对方
int cmp(int a, int b) {
	// 比我强应从之
	if (a > b)
		return 1;
	if (a < b)
		return 2;
	return 0;
}

int cmp(double a, int b) {
	// 比我强应从之
	if (a > b)
		return 1;
	if (a < b)
		return 2;
	return 0;
}

int main() {
	int M, X, Y;
	
	scanf("%d%d%d", &M, &X, &Y);

	// 甲乙丙
	int A, B;

	for (A = 99; A >= 10; --A) {

		// 先求B
		B = A / 10 + (A % 10) * 10;
		
		// |A - B| = C * X
		// B = C * Y
		if (abs(A - B) * Y == B * X)
			break;
	}

	if (A == 9)
		printf("No Solution");
	else {
		// C 为整数
		if (B % Y == 0)
			printf("%d %s %s %s", A, result[cmp(A, M)], result[cmp(B, M)], result[cmp(B / Y, M)]);
		else
			printf("%d %s %s %s", A, result[cmp(A, M)], result[cmp(B, M)], result[cmp((double)B / Y, M)]);

	}

	
	system("pause");
	return 0;
}