#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char A[102];
char B[102];
char result[102];

char num13[] = "0123456789JQK";

int main() {
	// 对换后，个位在A[1] B[1]
	scanf("%s %s", A + 1, B + 1);
	int n_A = strlen(A + 1);
	int n_B = strlen(B + 1);

	char char_tmp;
	int i, k;
	// 把个位放在前面
	for (i = 1, k = n_A; i < k; ++i, --k) {
		char_tmp = A[i];
		A[i] = A[k];
		A[k] = char_tmp;
	}
	for (i = 1, k = n_B; i < k; ++i, --k) {
		char_tmp = B[i];
		B[i] = B[k];
		B[k] = char_tmp;
	}


	int n = max(n_A, n_B);
	int Ai, Bi;
	for (i = 1; i <= n; ++i) {
		Ai = i <= n_A ? A[i] - '0' : 0;
		Bi = i <= n_B ? B[i] - '0' : 0;
		if (i % 2)
			result[i] = num13[(Ai + Bi) % 13];
		else
			result[i] = (Bi - Ai + 10) % 10 + '0';
	}

	result[n + 1] = '\0';
	for (i = 1, k = n; i < k; ++i, --k) {
		char_tmp = result[i];
		result[i] = result[k];
		result[k] = char_tmp;
	}

	printf("%s", result + 1);

	

	system("pause");
	return 0;
}