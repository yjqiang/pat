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
	double Pi;  // ���͵ĵ���
	int Di;  // �������ľ���
};

GasStation gas_stations[N_MAX];

// ���վ���Զ������
int cmp(const void* p0, const void* p1) {
	GasStation* a = (GasStation*)p0;
	GasStation* b = (GasStation*)p1;
	return a->Di - b->Di;
}

int main() {
	int C_max, D, D_avg, N;
	scanf("%d %d %d %d", &C_max, &D, &D_avg, &N);

	// װ���������Զ�ܶ��پ���
	int D_max = C_max * D_avg;

	int i, h;
	int num;
	for (i = 1; i <= N; ++i)
		scanf("%lf %d", &gas_stations[i].Pi, &gas_stations[i].Di);

	// ���վ���Զ������
	qsort(gas_stations + 1, N, sizeof(GasStation), cmp);
	// ��ֹ����
	++N;
	gas_stations[N].Pi = -1;
	gas_stations[i].Di = D;


	// ��ǰgas����
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

	// i ��ʼ��ѡ���� 1�ż���վ����i����N����Ϊ����� GasStation{-1, D} ��ʱ��˵�������յ�
	for (i = 1; i < N;) {
		next_station_index = -1;
		next_station_Pi = INT_MAX;


		// �����Χ�����������·���룩��Ѱ��next station
		max_Di = gas_stations[i].Di + D_max;
		for (h = i + 1; h <= N && gas_stations[h].Di <= max_Di; ++h) {
			// �м���վ�����ˣ���һ��������ȥ�������վ
			if (gas_stations[h].Pi < gas_stations[i].Pi) {
				next_station_index = h;
				next_station_Pi = gas_stations[h].Pi;
				break;
			}
			// ��������һ������˵ļ���վ�������ͣ�������ȥ(���ںŲ���ȥ����������վ�۸�һ����ѡԶ�ģ���Ϊi�����ˣ�������Զһ�㻮��)
			else if (gas_stations[h].Pi <= next_station_Pi) {
				next_station_index = h;
				next_station_Pi = gas_stations[h].Pi;
			}
		}

		// ��Բʮ��û�м���վ���������յ���
		if (next_station_index == -1) {
			printf("The maximum travel distance = %.2lf", (double)max_Di);
			system("pause");
			return 0;
		}
		// �м���վ�����ˣ���һ��������ȥ�������վ��������վPi��ȼ� next_station_Pi == gas_stations[i].Pi ��ʱ�򣬼ӵ���/��һ����ɣ�
		if (next_station_Pi < gas_stations[i].Pi) {
			// (����� / ��λ�ͺ� - ����ʣ��) * ����
			cost += (((double)gas_stations[next_station_index].Di - gas_stations[i].Di) / D_avg - cur_gas) * gas_stations[i].Pi;
			// ����ü���վ����������
			cur_gas = 0;
		}
		// ����ȥ�õ�
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