#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

// 这里存hash[position] = value
map<int, int> hash_table;

bool isPrime(int n) {
	if (n <= 1 || n % 2 == 0 && n != 2)
		return false;

	int i;
	int max_i = (int)sqrt(n) + 1;
	for (i = 3; i <= max_i; i += 2)
		if (n % i == 0)
			return false;
	return true;
}


int main() {
	int Msize, N;
	scanf("%d%d", &Msize, &N);

	int T;  // >= Msize的最小prime
	//  re-define the table size
	for (T = Msize; !isPrime(T); ++T);
	
	int i, k;
	int result, num;
	bool isOK;

	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		
		if (i != 0)
			printf(" ");

		isOK = false;
		for (k = 0; k < T; ++k) {
			result = (num + k * k) % T;
			if (hash_table.find(result) == hash_table.end()) {
				printf("%d", result);
				hash_table[result] = num;
				isOK = true;
				break;
			}
		}
		
		if (!isOK)
			printf("-");

	}
	
	system("pause");
	return 0;
}