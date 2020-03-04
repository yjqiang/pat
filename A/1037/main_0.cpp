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

using namespace std;

#define N_MAX 100001
int positive_product_values[N_MAX];
int n0 = 0;

int positive_coupons[N_MAX];
int n1 = 0;

int negative_product_values[N_MAX];
int n2 = 0;

int negative_coupons[N_MAX];
int n3 = 0;


int cmp(const void* p0, const void* p1) {
	int* a = (int*)p0;
	int* b = (int*)p1;

	return (*a) - (*b);
}

int main() {
	int N_c, N_p;
	int i;

	int int_tmp;
	scanf("%d", &N_c);
	for (i = 0; i < N_c; ++i) {
		scanf("%d", &int_tmp);
		if (int_tmp > 0)
			positive_coupons[n1++] = int_tmp;
		else if (int_tmp < 0)
			negative_coupons[n3++] = -int_tmp;
	}
	
	scanf("%d", &N_p);
	for (i = 0; i < N_p; ++i) {
		scanf("%d", &int_tmp);
		if (int_tmp > 0)
			positive_product_values[n0++] = int_tmp;
		else if (int_tmp < 0)
			negative_product_values[n2++] = -int_tmp;
	}

	qsort(positive_product_values, n0, sizeof(int), cmp);
	qsort(positive_coupons, n1, sizeof(int), cmp);
	qsort(negative_product_values, n2, sizeof(int), cmp);
	qsort(negative_coupons, n3, sizeof(int), cmp);

	long long result = 0;
	int k;
	for (i = n0 - 1, k = n1 - 1; i >= 0 && k >= 0; --i, --k)
		result += (long long)positive_product_values[i] * positive_coupons[k];

	for (i = n2 - 1, k = n3 - 1; i >= 0 && k >= 0; --i, --k)
		result += (long long)negative_product_values[i] * negative_coupons[k];

	printf("%lld", result);

	system("pause");
	return 0;
}