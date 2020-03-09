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

// �������������primes���飬���ж�ĳ���Ƿ�Ϊ����ʱ������С�ڸ�������ȻҲ���Ը�С��ȡ<= sqrt(x)���������������Լ���
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
	// ����������С��50000������
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

	// NΪ1���⴦��
	if (N == 1) {
		printf("1");
		return 0;
	}
		
	// �ҵ���һ������
	for (i = 0; N != 1; ++i) {
		ki = primes[i];
		// ������ͼ����ki���õ���Ӧpi
		for (pi = 0; N % ki == 0; ++pi)
			N /= ki;
		// piΪ0˵����ki�������ӣ�����д��
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