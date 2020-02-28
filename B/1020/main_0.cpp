#define _CRT_SECURE_NO_WARNINGS
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

struct MoonCake {
	double num;
	double price;
};

MoonCake mooncakes[1005];

int cmp(const void* p0, const void* p1) {
	MoonCake* mooncake0 = (MoonCake*)p0;
	MoonCake* mooncake1 = (MoonCake*)p1;
	double x = mooncake0->price;
	double y = mooncake1->price;
	if (y < x)
		return -1;
	if (y > x)
		return 1;
	return 0;
}

int main() {
	int N,D;
	scanf("%d%d", &N, &D);

	int index;
	for (index = 0; index < N; ++index)
		scanf("%lf", &(mooncakes[index].num));

	double tmp_double;
	for (index = 0; index < N; ++index) {
		scanf("%lf", &tmp_double);
		mooncakes[index].price = tmp_double / mooncakes[index].num;
	}
	qsort(mooncakes, N, sizeof(MoonCake), cmp);

	double result = 0.0;
	int num;
	for (index = 0; D && index < N; ++index) {
		num = mooncakes[index].num;
		if (num <= D)
			;
		else
			num = D;
		D -= num;
		result += num * mooncakes[index].price;
	}
	printf("%.2lf", result);
	system("pause");


	return 0;
}