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

using namespace std;

set<int> results;

int main() {
	int N;
	scanf("%d", &N);

	int i;
	int sum;
	int num;
	for (i = 0; i < N; ++i) {
		sum = 0;
		scanf("%d", &num);
		while (num) {
			sum += num % 10;
			num /= 10;
		}

		results.insert(sum);
	}

	printf("%d\n", results.size());
	set<int>::iterator set_i = results.begin();
	printf("%d", *set_i);
	++set_i;
	for (; set_i != results.end(); ++set_i)
		printf(" %d", *set_i);

	system("pause");
	return 0;
}