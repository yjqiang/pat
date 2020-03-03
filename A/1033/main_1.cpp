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

	gas_stations[N].Pi = 0; 
	gas_stations[N].Di = D;  //将最后一个加油站距离定为D，油价设为0，作为终点
	qsort(gas_stations, N, sizeof(GasStation), cmp);

	double lowest_price;
	int lowest_index;


	double cost = 0;

	int max_dis = C_max * D_avg;

	if (gas_stations[0].Di != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	int cur_gas_station_index;
	double remain_tank;

	double double_tmp;
	for (cur_gas_station_index = 0, remain_tank = 0; cur_gas_station_index < N; ) {
		lowest_price = -1;
		lowest_index = -1;
		for (i = cur_gas_station_index + 1; i <= N && gas_stations[i].Di <= gas_stations[cur_gas_station_index].end; ++i) {
			if (lowest_price == -1 || gas_stations[i].Pi <= lowest_price) {
				lowest_price = gas_stations[i].Pi;
				lowest_index = i;
			}
			if (gas_stations[i].Pi < gas_stations[cur_gas_station_index].Pi)
				break;
		}

		if (lowest_index == -1) {
			printf("The maximum travel distance = %.2lf", (double)gas_stations[cur_gas_station_index].end);
			return 0;
		}

		double_tmp = ((double)gas_stations[lowest_index].Di - gas_stations[cur_gas_station_index].Di) / D_avg;
		if (lowest_price < gas_stations[cur_gas_station_index].Pi) {
			cost += gas_stations[cur_gas_station_index].Pi * (double_tmp - remain_tank);
			remain_tank = 0;

		}
		else {
			cost += gas_stations[cur_gas_station_index].Pi * (C_max - remain_tank);
			remain_tank = C_max - double_tmp;
		}
		cur_gas_station_index = lowest_index;
	}

	printf("%.2lf", cost);

	system("pause");
	return 0;
}