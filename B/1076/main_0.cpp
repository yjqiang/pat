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
	// 收掉\n
	getchar();

	int i, k;
	char choice, T_F;
	for (i = 0; i < N; ++i)
		for (k = 0; k < 4; ++k) {
			scanf("%c-%c", &choice, &T_F);
			// printf("%c%c\n", choice, T_F);
			if (T_F == 'T')
				printf("%d", choice - 'A' + 1);
			// 收掉空白符或者\n
			getchar();
		}
	
	system("pause");
	return 0;
}