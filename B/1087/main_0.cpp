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

set<int> cache;

int main() {
	int N;
	
	scanf("%d", &N);

	int i;
	int num;
	for (i = 1; i <= N; ++i) {
		num = i / 2 + i / 3 + i / 5;
		cache.insert(num);
	}


	printf("%d", cache.size());

	
	system("pause");
	return 0;
}