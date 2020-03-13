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


int main() {
	int N;

	scanf("%d", &N);
	
	char tmp[4];

	int i, k;
	for (i = 0; i < N; ++i)
		for (k = 0; k < 4; ++k) {
			// 读一个str，直接方便了
			scanf("%s", tmp);
			if (tmp[2] == 'T')
				printf("%d", tmp[0] - 'A' + 1);
		}
	
	system("pause");
	return 0;
}