#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <climits>
#include <queue>
#include <set>

using namespace std;

#define N_MAX 40000
#define M_MAX 100
#define K_MAX 5

struct Application {
	int app_id;  // �����л����ԭ����˳��
	int rank;
	int G_E;
	int G_I;
	double G_final;
	int choices[K_MAX];
};

Application applications[N_MAX];
int quotas[M_MAX];

// ÿ��ѧУ������������
vector <int> results[M_MAX];
// ÿ��ѧУ�����һ���˵�rank������rank���
int ranks[M_MAX];

int cmp(const void* p0, const void* p1) {
	Application* a = (Application*)p0;
	Application* b = (Application*)p1;

	if (a->G_final != b->G_final) {
		if (a->G_final > b->G_final)
			return -1;
		else
			return 1;
	}
	return b->G_E - a->G_E;
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	int i, h;
	for (i = 0; i < M; ++i)
		scanf("%d", quotas + i);
	for (i = 0; i < N; ++i) {
		scanf("%d %d", &(applications[i].G_E), &(applications[i].G_I));
		applications[i].G_final = ((double)applications[i].G_E + applications[i].G_I) / 2.0;
		applications[i].app_id = i;
		for (h = 0; h < K; ++h)
			scanf("%d", applications[i].choices + h);

	}
	
	qsort(applications, N, sizeof(Application), cmp);

	// ��index 1 ��ʼ�������ε�������ǰһ��һ�����������˵�rankһ��
	applications[0].rank = 1;
	for (i = 1; i < N; ++i) {
		if (applications[i].G_final == applications[i - 1].G_final && applications[i].G_E == applications[i - 1].G_E)
			applications[i].rank = applications[i - 1].rank;
		else
			applications[i].rank = i + 1;
	};

	//printf("\n");
	//for (i = 0; i < N; ++i) {
	//	printf("%d  %d %lf %d %d \n", applications[i].rank, applications[i].app_id, applications[i].G_final, applications[i].G_E, applications[i].G_I);
	//}
	//printf("\n\n");

	int wanted;
	// results��Ӧ��ÿ��ѧУ�����һ���ˣ�����rank��͡�����һ����ѡ�ߣ��� quotaδ���� ���� ��һ����ѡ�ߵ�rank�����һ��һ��������¼ȡ
	for (i = 0; i < N; ++i)
		for (h = 0; h < K; ++h) {
			wanted = applications[i].choices[h];
			// assert quotas[wanted] > 0
			if (results[wanted].size() < quotas[wanted] || 
				applications[i].rank == ranks[wanted]) {

				results[wanted].push_back(applications[i].app_id);
				ranks[wanted] = applications[i].rank;  // �������rank
				break;
			}
		}

	int n_size;
	for (i = 0; i < M; ++i) {
		sort(results[i].begin(), results[i].end());

		n_size = results[i].size();
		if (n_size) {
			printf("%d", results[i][0]);
			for (h = 1; h < n_size; ++h)
				printf(" %d", results[i][h]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}