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


bool isPrime (long long x) {
	if (x != 2 && x % 2 == 0)
		return false;
	long long i;
	for (i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}


int main() {
	long long int N;

	scanf("%lld", &N);

	long long cur_prime;
	long long ki, pi;
	bool is_first = true;

	printf("%lld=", N);

	// N为1特殊处理
	if (N == 1) {
		printf("1");
		return 0;
	}
		
	// 找到下一个素数，并测试是否为因子
	for (cur_prime = 2; N != 1; ++cur_prime)
		if (isPrime(cur_prime)) {
			ki = cur_prime;
			// 不断试图除以ki，得到对应pi
			for (pi = 0; N % ki == 0; ++pi)
				N /= ki;
			// pi为0说明，ki不是因之，不用写出
			if (pi > 0) {
				if (!is_first)
					printf("*");
				else
					is_first = false;

				if (pi == 1)
					printf("%lld", ki);
				else
					printf("%lld^%lld", ki, pi);
			}
		}

	system("pause");
	return 0;
}