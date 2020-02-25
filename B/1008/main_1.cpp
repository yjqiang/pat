# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

void myReverse(int* a, int left, int right) {
	int i, k;
	for (i = left, k = right; i < k; ++i, --k) {
		swap(a[i], a[k]);
	}
}


int main() {
	int N, M;
	int a[100];
	scanf("%d%d", &N, &M);
	
	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", a + i);

	M = M % N;
	
	myReverse(a, 0, N - 1);
	myReverse(a, 0, M - 1);
	myReverse(a, M, N - 1);

	printf("%d", a[0]);
	for (i = 1; i < N; ++i)
		printf(" %d", a[i]);
	system("pause");
	return 0;
}