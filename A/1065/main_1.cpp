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


int main() {
	int T;
	long long A, B, C;
	scanf("%d", &T);

	int i;
	long long result;
	for (i = 1; i <= T; ++i) {
		// ����Ӧ���� ABC ���� [-2^63, 2^63)
		scanf("%lld %lld %lld", &A, &B, &C);
		result = A + B;
		// �����
		if (A > 0 && B > 0 && result < 0)
			printf("Case #%d: true\n", i);
		// �����
		else if (A < 0 && B < 0 && result >= 0)
			printf("Case #%d: false\n", i);
		else if (result > C)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}

	system("pause");
	return 0;
}