#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct GasStation {
	double Pi;
	int Di;
	int end;
};
#define N_MAX 500
GasStation gas_stations[N_MAX];

int cmp(const void* p0, const void* p1) {
	GasStation* gas_station0 = (GasStation*)p0;
	GasStation* gas_station1 = (GasStation*)p1;

	return gas_station0->Di - gas_station1->Di;
}

int main() {
	int C_max, D, D_avg, N;
	scanf("%d%d%d%d", &C_max, &D, &D_avg, &N);

	int i;
	double Pi;
	int Di;
	for (i = 0; i < N; ++i) {
		scanf("%lf%d", &Pi, &Di);
		gas_stations[i].Pi = Pi;
		gas_stations[i].Di = Di;
		gas_stations[i].end = Di + C_max * D_avg;
	}
	qsort(gas_stations, N, sizeof(GasStation), cmp);

	//printf("\n");
	//for (i = 0; i < N; ++i)
	//	printf("%lf %d %d\n", gas_stations[i].Pi, gas_stations[i].Di, gas_stations[i].end);

	int left;
	int cur;
	double lowest_price;
	int range_end;
	int remain_gas = 0;
	double cost = 0;
	int start;

	for (cur = 0, left = 0; cur < D; ) {
		for (; left < N && gas_stations[left].end <= cur; ++left);
		if (left == N || gas_stations[left].Di > cur) {
			printf("The maximum travel distance = %.2lf", double(cur));
			system("pause");
			return 0;
		}

		start = left;

		lowest_price = -1;
		for (; left < N && gas_stations[left].Di <= cur && cur < gas_stations[left].end; ++left)
			if (lowest_price == -1 || gas_stations[left].Pi < lowest_price) {
				lowest_price = gas_stations[left].Pi;
				range_end = gas_stations[left].end;
			}
		if (left == N) {
			range_end = min(D, range_end);
		}
		else {
			range_end = min(range_end, gas_stations[left].Di);
		}
		
		cost += ((double)range_end - cur) / D_avg * lowest_price;
		// printf("from %d to %d: %.2lf\n", cur, range_end, lowest_price);
		cur = range_end;
		left = start;
		
	}
	printf("%.2lf", cost);

	system("pause");
	return 0;
}