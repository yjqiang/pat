# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;


int reverse(int N, int radix) {
	int result = 0;
	int cur;
	while (N) {
		cur = N % radix;
		result = result * radix + cur;
		N /= radix;
	}
	return result;
}

bool isPrime(int n) {
	if (n <= 1)
		return false;
	if (!(n % 2) && (n != 2))
		return false;
	int i;
	for (i = 3; i * i <= n; i += 2) {
		if (!(n % i))
			return false;
	}
	return true;
}



int main() {
	bool result;
	int N, D;
	while (true) {
		scanf("%d", &N);
		if (N < 0)
			return 0;
		scanf("%d", &D);

		isPrime(N) && isPrime(reverse(N, D)) ? printf("Yes\n") : printf("No\n");
	}

	system("pause");
	return 0;
}