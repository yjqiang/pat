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
#define N_MAX 100005

struct Node {
	int Data;
	int Next;
};

// �������ڴ�ֲ������ݣ�iΪ�ڴ��ַ��Node���Ƕ�Ӧ����
Node nodes[N_MAX];
// next�����ӣ�˳���������ӣ�Ԫ��Ϊnodes���±꣨�ڴ��ַ��
int indexes[N_MAX];

int new_indexes[N_MAX];


int main() {
	int head, N, K;

	scanf("%d%d%d", &head, &N, &K);

	int i;
	int Address, Data, Next;
	for (i = 0; i < N; ++i) {
		scanf("%d%d%d", &Address, &Data, &Next);
		nodes[Address].Data = Data;
		nodes[Address].Next = Next;
	}
	
	int  p = head;
	for (i = 0; p != -1; p = nodes[p].Next, ++i)
		indexes[i] = p;
	indexes[i] = -1;
	// �й����㲻��������
	N = i;

	// �����ε������ֱ�ѡ��������[0, K]������K�ĵ�ַ
	int i_new = 0;
	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data < 0) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}
	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data >= 0 && nodes[indexes[i]].Data <= K) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}

	for (i = 0; i < N; ++i)
		if (nodes[indexes[i]].Data > K) {
			new_indexes[i_new] = indexes[i];
			++i_new;
		}
	// printf("%d==%d\n", i_new, N);
	for (i = 0; i < N - 1; ++i)
		printf("%05d %d %05d\n", new_indexes[i], nodes[new_indexes[i]].Data, new_indexes[i + 1]);
	printf("%05d %d -1\n", new_indexes[N -1], nodes[new_indexes[N-1]].Data);


	system("pause");
	return 0;
}