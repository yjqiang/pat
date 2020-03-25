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

// Msize_MAX 要上调至最近的质数
#define Msize_MAX 20000
int Msize, N, M;

// 默认为0，表示该位置空缺
int hash_table[Msize_MAX] = { 0 };


bool isPrime(int num) {
	if (num <= 1)
		return false;
	if (num % 2 == 0 && num != 2)
		return false;
	int end = (int)sqrt(num) + 1;
	int i;
	for (i = 3; i <= end; ++i)
		if (num % i == 0)
			return false;
	return true;
}

int sum_search_time = 0;

void mySearch(int num) {
	int i;
	int position;
	for (i = 0; i < Msize; ++i) {
		position = (num + i * i) % Msize;
		// hash_table[position] == 0 位置空缺，则可以说明查询失败了
		// hash_table[position] == num 查询成功
		if (hash_table[position] == 0 || hash_table[position] == num) {
			sum_search_time += i + 1;
			return;
		}
	}

	// 我觉得应该计数Msize的，当然出题人是爹，你说咋加就咋加
	sum_search_time += Msize + 1;
}


int main() {
	
	scanf("%d%d%d", &Msize, &N, &M);
	while (!isPrime(Msize))
		++Msize;

	int num, position;
	int i, h;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);

		// (Msize+x)^2  = Msize*Msize + 2*x*Msize + x^2   与 x^2  效果一样了
		for (h = 0; h < Msize; ++h) {
			position = (num + h * h) % Msize;
			// 位置空缺
			if (hash_table[position] == 0) {
				hash_table[position] = num;
				break;
			}
			
		}
		if (h == Msize)
			printf("%d cannot be inserted.\n", num);
	}

	
	for (i = 0; i < M; ++i) {
		scanf("%d", &num);
		mySearch(num);
		
	}
	printf("%.1lf", (double)sum_search_time / M);


	system("pause");
	return 0;
}