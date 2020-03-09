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

int primes[50002] = {0};

// 这里仅用于生成primes数组，即判断某数是否为素数时，是用小于该数（当然也可以更小，取<= sqrt(x)）的所有素数测试即可
bool isPrime (int x) {
	int i;
	for (i = 0; primes[i] != 0 && primes[i] * primes[i] <= x; ++i)
		if (x % primes[i] == 0)
			return false;
	return true;
}


int main() {
	int i;
	int cur_prime;
	primes[0] = 2;
	primes[1] = 3;
	// 先生成所有小于50000的素数
	for (i = 2, cur_prime = 5; cur_prime <= 50000; ++cur_prime) {
		if (isPrime(cur_prime)) {
			primes[i] = cur_prime;
			++i;
		}
	}


	int N;

	scanf("%d", &N);

	
	int ki, pi;
	bool is_first = true;

	printf("%d=", N);

	// N为1特殊处理
	if (N == 1) {
		printf("1");
		return 0;
	}
		
	// 找到下一个素数
	for (i = 0; N != 1; ++i) {
		ki = primes[i];
		// 不断试图除以ki，得到对应pi
		for (pi = 0; N % ki == 0; ++pi)
			N /= ki;
		// pi为0说明，ki不是因子，不用写出
		if (pi > 0) {
			if (!is_first)
				printf("*");
			else
				is_first = false;

			if (pi == 1)
				printf("%d", ki);
			else
				printf("%d^%d", ki, pi);
		}
	}

	system("pause");
	return 0;
}