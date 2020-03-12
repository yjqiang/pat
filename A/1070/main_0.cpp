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

#define N_MAX 1000

struct MoonCake {
	// 坑：不一定为int
	double nums;
	// 单价
	double unit_price;
};

// 从大到小
int cmp(const void* p0, const void* p1) {
	MoonCake* moon_cake0 = (MoonCake*)p0;
	MoonCake* moon_cake1 = (MoonCake*)p1;
	if (moon_cake0->unit_price > moon_cake1->unit_price)
		return -1;
	if (moon_cake0->unit_price == moon_cake1->unit_price)
		return 0;
	return 1;
}

MoonCake moon_cakes[N_MAX];


int main() {
	int N, D;
	scanf("%d%d", &N, &D);

	int i;
	double price;
	for (i = 0; i < N; ++i)
		scanf("%lf", &(moon_cakes[i].nums));

	for (i = 0; i < N; ++i) {
		scanf("%lf", &price);
		moon_cakes[i].unit_price = price / moon_cakes[i].nums;
	}

	qsort(moon_cakes, N, sizeof(MoonCake), cmp);

	double result = 0;
	for (i = 0; D > 0 && i < N; ++i) {
		// 备货不足
		if (moon_cakes[i].nums < D) {
			result += moon_cakes[i].nums * moon_cakes[i].unit_price;
			D -= moon_cakes[i].nums;
		}
		else {
			result += D * moon_cakes[i].unit_price;
			break;
		}
	}
	printf("%.2lf", result);

	system("pause");
	return 0;
}