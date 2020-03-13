// https://www.liuchuo.net/archives/4216
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

	int start, end;
	int h, g;
	// i + K - 1Ϊ���ν����ػ���end 
	for (i = 0; i + K - 1 < N; i += K) {
		start = i;
		end = i + K - 1;
		for (h = start, g = end; h < g; ++h, --g)
			swap(indexes[h], indexes[g]);  // ����ֻ����index��node��Next����û�ĵ�
	}

	for (i = 0; i < N - 1; ++i)
		printf("%05d %d %05d\n", indexes[i], nodes[indexes[i]].Data, indexes[i + 1]);
	printf("%05d %d -1\n", indexes[N -1], nodes[indexes[N-1]].Data);


	system("pause");
	return 0;
}