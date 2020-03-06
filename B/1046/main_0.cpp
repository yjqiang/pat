#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;



int main() {
	int N, sum;
	// ¼×º°£¬¼×»®
	int A_yell, A_show;
	// ÒÒº°£¬ÒÒ»®
	int B_yell, B_show;
	scanf("%d", &N);

	int i;
	int A_count = 0, B_count = 0;

	for (i = 0; i < N; ++i) {
		scanf("%d%d%d%d", &A_yell, &A_show, &B_yell, &B_show);
		sum = A_yell + B_yell;
		if (A_show == sum && B_show != sum)
			++B_count;
		else if (A_show != sum && B_show == sum)
			++A_count;
	}
		
	printf("%d %d", A_count, B_count);


	system("pause");
	return 0;
}