# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>

using namespace std;

int main() {
	int T;
	long long A, B, C;
	int i;

	scanf("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf("%lld%lld%lld", &A, &B, &C);
		if (A + B > C)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	system("pause");
	return 0;
}