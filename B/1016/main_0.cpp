# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;


int main() {

	char A[11], B[11];
	int Da, Db;
	int i;
	int count_a = 0, count_b = 0;

	scanf("%s%d%s%d", A, &Da, B, &Db);
	for (i = 0; A[i] != '\0'; ++i)
		if (A[i] - '0' == Da)
			count_a = count_a * 10 + Da;

	for (i = 0; B[i] != '\0'; ++i)
		if (B[i] - '0' == Db)
			count_b = count_b * 10 + Db;

	printf("%d", count_a + count_b);
	
	system("pause");
	return 0;
}