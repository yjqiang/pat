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

// �Ƚ�a��b��������result��Ӧ������±�
// b���ң�aΪ�Է�
int cmp(int a, int b) {
	// ����ǿӦ��֮
	if (a > b)
		return 1;
	if (a < b)
		return 2;
	return 0;
}

int cmp(double a, int b) {
	// ����ǿӦ��֮
	if (a > b)
		return 1;
	if (a < b)
		return 2;
	return 0;
}

int main() {
	int M, X, Y;
	
	scanf("%d%d%d", &M, &X, &Y);

	// ���ұ�
	int A, B;

	for (A = 99; A >= 10; --A) {

		// ����B
		B = A / 10 + (A % 10) * 10;
		
		// |A - B| = C * X
		// B = C * Y
		if (abs(A - B) * Y == B * X)
			break;
	}

	if (A == 9)
		printf("No Solution");
	else {
		// C Ϊ����
		if (B % Y == 0)
			printf("%d %s %s %s", A, result[cmp(A, M)], result[cmp(B, M)], result[cmp(B / Y, M)]);
		else
			printf("%d %s %s %s", A, result[cmp(A, M)], result[cmp(B, M)], result[cmp((double)B / Y, M)]);

	}

	
	system("pause");
	return 0;
}