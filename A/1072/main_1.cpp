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

#define N_MAX 1001
#define M_MAX 11
// SUM_MAX = N_MAX + M_MAX
#define SUM_MAX 1012

int N, M, K, D_s;

// �ڽӾ���Gi => N + i����Gi���ڷ��ӱ�ź���  
int edges[SUM_MAX][SUM_MAX];

// ÿ������վ��ѡ�㶼Ҫ����һ��dijkstra
int dists[SUM_MAX];
// dijkstra�Ƿ��ڼ���������
bool is_in_set[SUM_MAX];

// Gi => N + i����Gi���ڷ��ӱ�ź��� 
int strP2intP(char* s) {
	int result;
	if (s[0] == 'G') {
		sscanf(s, "G%d", &result);
		result += N;
	}
	else
		sscanf(s, "%d", &result);
	return result;
}

void dijkstra(int start) {
	int i, h;
	// ȫ�����ɴ�
	for (i = 0; i < SUM_MAX; ++i)
		dists[i] = INT_MAX;
	// ȫ��δ�ڼ���
	for (i = 0; i < SUM_MAX; ++i)
		is_in_set[i] = false;

	// ��Դ�����set
	is_in_set[start] = true;
	dists[start] = 0;
	int cur = start;

	int min_element, min_index;
	// �ܽڵ���
	int size_vex = N + M;

	// ��� n - 1 �Σ�start�Ѿ���������
	for (i = 1; i < size_vex; ++i) {
		// ��cur�����еļ������ھӽ����ɳڲ���
		for (h = 1; h <= size_vex; ++h)
			if (!is_in_set[h] && edges[h][cur] != INT_MAX)
					dists[h] = min(dists[h], dists[cur] + edges[h][cur]);

		// ��ѡdist��С��
		min_element = INT_MAX;
		min_index = -1;
		for (h = 1; h <= size_vex; ++h)
			if (!is_in_set[h] && dists[h] < min_element) {
				min_index = h;
				min_element = dists[h];
			}

		// ��������set
		is_in_set[min_index] = true;
		cur = min_index;
	}
}

int main() {
	
	scanf("%d%d%d%d", &N, &M, &K, &D_s);


	int i, h;

	// edgeȫ����Ϊ���ɴ�
	for (i = 0; i < SUM_MAX; ++i)
		for (h = 0; h < SUM_MAX; ++h)
			edges[i][h] = INT_MAX;

	char str_P1[5], str_P2[5];
	int int_P1, int_P2, edge;
	for (i = 0; i < K; ++i) {
		scanf("%s %s %d", str_P1, str_P2, &edge);
		int_P1 = strP2intP(str_P1);
		int_P2 = strP2intP(str_P2);
		edges[int_P1][int_P2] = edge;
		edges[int_P2][int_P1] = edge;
		// printf("%d-%d=%d\n", int_P1, int_P2, edge);
	}

	int sum_cost;

	// ��С�뷿�ӵľ���֮�� �Լ���Ӧ��index
	int min_element, min_index;
	// ÿ����ѡ�㶼����ĳ���ӵ�������ҵ���Щ��������һ����Ķ�Ӧ���루����վΣ�գ����������ҪԶһ�㣩
	int max_min_dist;

	min_element = INT_MAX;
	min_index = -1;
	max_min_dist = -1;

	// ����ѡ�����ĸ������������Ӧ�������
	int cur_min_dist;
	for (i = 1; i <= M; ++i) {
		dijkstra(N + i);

		sum_cost = 0;
		cur_min_dist = INT_MAX;
		for (h = 1; h <= N; ++h) {
			if (dists[h] > D_s) {
				sum_cost = -1; // �������ã���ʾ�������վ������Ҫ��(����סլ���ľ����Ƿ��ڷ���Χ��)
				break;
			}
			else {
				sum_cost += dists[h];
				if (dists[h] < cur_min_dist)
					cur_min_dist = dists[h];
			}
		}
		
		// ��ѡ����Ч
		if (sum_cost != -1) {
			if (cur_min_dist > max_min_dist || cur_min_dist == max_min_dist && sum_cost < min_element) {
				min_element = sum_cost;
				min_index = i;
				max_min_dist = cur_min_dist;
			}
		}

	}
	if (min_index == -1)
		printf("No Solution");
	else {
		printf("G%d\n%.1lf %.1lf", min_index, (double)max_min_dist, (double)min_element / N);
	}
	

	system("pause");
	return 0;
}