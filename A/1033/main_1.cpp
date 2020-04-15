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
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define N_MAX 502

struct GasStation {
	double Pi;  // 汽油的单价
	int Di;  // 距离起点的距离
};

GasStation gas_stations[N_MAX];

// 按照距离远近排序
int cmp(const void* p0, const void* p1) {
	GasStation* a = (GasStation*)p0;
	GasStation* b = (GasStation*)p1;
	return a->Di - b->Di;
}

int main() {
	int C_max, D, D_avg, N;
	scanf("%d %d %d %d", &C_max, &D, &D_avg, &N);

	// 装满油箱后最远跑多少距离
	int D_max = C_max * D_avg;

	int i, h;
	int num;
	for (i = 1; i <= N; ++i)
		scanf("%lf %d", &gas_stations[i].Pi, &gas_stations[i].Di);

	// 按照距离远近排序
	qsort(gas_stations + 1, N, sizeof(GasStation), cmp);
	// 终止符号
	++N;
	gas_stations[N].Pi = -1;
	gas_stations[i].Di = D;


	// 当前gas的量
	double cur_gas = 0;

	double cost = 0;

	int max_Di = 0;
	int next_station_index;
	double next_station_Pi;


	if (gas_stations[1].Di != 0) {

		printf("The maximum travel distance = %.2lf", (double)max_Di);
		system("pause");
		return 0;
	}

	// i 开始是选中了 1号加油站，当i到达N（人为添加了 GasStation{-1, D} 后）时，说明到达终点
	for (i = 1; i < N;) {
		next_station_index = -1;
		next_station_Pi = INT_MAX;


		// 在最大范围（油箱加满跑路距离）内寻找next station
		max_Di = gas_stations[i].Di + D_max;
		for (h = i + 1; h <= N && gas_stations[h].Di <= max_Di; ++h) {
			// 有加油站更便宜，加一点油正好去这个加油站
			if (gas_stations[h].Pi < gas_stations[i].Pi) {
				next_station_index = h;
				next_station_Pi = gas_stations[h].Pi;
				break;
			}
			// 否则尽量找一个最便宜的加油站，加满油，到这里去(等于号不能去掉，两加油站价格一样，选远的，因为i处便宜，尽量跑远一点划算)
			else if (gas_stations[h].Pi <= next_station_Pi) {
				next_station_index = h;
				next_station_Pi = gas_stations[h].Pi;
			}
		}

		// 方圆十里没有加油站，到不了终点了
		if (next_station_index == -1) {
			printf("The maximum travel distance = %.2lf", (double)max_Di);
			system("pause");
			return 0;
		}
		// 有加油站更便宜，加一点油正好去这个加油站（两加油站Pi相等即 next_station_Pi == gas_stations[i].Pi 的时候，加到满/加一点均可）
		if (next_station_Pi < gas_stations[i].Pi) {
			// (距离差 / 单位油耗 - 邮箱剩余) * 单价
			cost += (((double)gas_stations[next_station_index].Di - gas_stations[i].Di) / D_avg - cur_gas) * gas_stations[i].Pi;
			// 到达该加油站后，无余量了
			cur_gas = 0;
		}
		// 加满去该地
		else {
			cost += ((double)C_max - cur_gas) * gas_stations[i].Pi;
			cur_gas = C_max - ((double)gas_stations[next_station_index].Di - gas_stations[i].Di) / D_avg;
		}

		i = next_station_index;
		// printf("%d\n", i);
	}
	printf("%.2lf", cost);
	system("pause");
	return 0;
}