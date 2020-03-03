#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>

#include <climits>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdlib>

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

	// ������ֹ����
	gas_stations[i].Pi = -1;
	gas_stations[i].Di = D;
	qsort(gas_stations, N, sizeof(GasStation), cmp);


	double cost = 0;
	int cur_gas_station_index;
	if (gas_stations[0].Di != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	int min_index;
	double min_element;
	double tank_needed_from_cur2next;
	double remain_tank;

	for (cur_gas_station_index = 0, remain_tank = 0; cur_gas_station_index < N; ) {
		min_element = -1;
		min_index = -1;
		// ע�� i <= N ���ں�
		for (i = cur_gas_station_index + 1; i <= N && gas_stations[cur_gas_station_index].end >= gas_stations[i].Di; ++i) {
			// <= ���ںŲ���ȥ���������м���վ�۸񶼱����ڹ�Ҫ�ڴ˴�������֮�󵽴�۸���ʹ����������ʹ��ĵص㣬Ҫ����Զ��
			if (min_element == -1 || gas_stations[i].Pi <= min_element) {
				min_element = gas_stations[i].Pi;
				min_index = i;
			}
			if (min_element < gas_stations[cur_gas_station_index].Pi)
				break;
		}

		if (min_index == -1) {
			printf("The maximum travel distance = %.2lf", (double)gas_stations[cur_gas_station_index].end);
			return 0;
		}
		tank_needed_from_cur2next = ((double)gas_stations[min_index].Di - gas_stations[cur_gas_station_index].Di) / D_avg;
		if (min_element < gas_stations[cur_gas_station_index].Pi) {

			// tank_needed_from_cur2next - remain_tank һ�����ڵ���0����һ����վ�ӵ��͵�min_indexһ��������
			// ����min_index������һ���end��Χ�ڣ��ͻ������һ��ĵ����Ƚϲ�������cur���ͼ�С����һ��������һ������ǡ�õ�cur��
			// ������һ����վ�ĵ���ѡ���У�Ӧ��ѡmin_index��������cur_gas_station_index
			cost += (tank_needed_from_cur2next - remain_tank) * gas_stations[cur_gas_station_index].Pi;
			remain_tank = 0;
		}
		else {
			cost += (C_max - remain_tank) * gas_stations[cur_gas_station_index].Pi;
			remain_tank = C_max - tank_needed_from_cur2next;
		}

		cur_gas_station_index = min_index;

	}


	printf("%.2lf", cost);

	system("pause");
	return 0;
}