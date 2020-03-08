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

using namespace std;

#define N_p_MAX 1000

int weights[N_p_MAX];
int ranks[N_p_MAX];


int main() {
	int N_p, N_g;
	
	scanf("%d%d", &N_p, &N_g);
	
	int i,h, int_tmp;
	for (i = 0; i < N_p; ++i)
		scanf("%d", weights + i);

	// ����
	queue<int> q;

	for (i = 0; i < N_p; ++i) {
		scanf("%d", &int_tmp);
		q.push(int_tmp);
	}

	int size_q, n_groups;
	int count_group;
	int max_weight, max_index;
	while (q.size()!=1) {
		// ���ִεĲ�������
		size_q = q.size();
		// ��������ȡ��
		n_groups = (size_q + N_g - 1) / N_g;

		count_group = 0;
		i = 0;
		// ÿ��ѭ�����Ǵ�����ÿ����б���
		for (count_group = 0; count_group < n_groups; ++count_group) {
			max_weight = -1;
			// h����ĳһ�������������i��������queue�ļ���
			for (h = 0; h < N_g && i < size_q; ++h, ++i) {
				int_tmp = q.front();
				// ����ʤ��Ҳ�ᱻ��Ϊ���rank����Ҫ���ģ�֮����ִΣ�ranks[int_tmp]�ᱻ���ǵ������߳�Ϊ�ھ�����ʱ������Ҫ�ֶ�����
				ranks[int_tmp] = n_groups + 1;
				if (max_weight < weights[int_tmp]) {
					max_weight = weights[int_tmp];
					max_index = int_tmp;
				}
				q.pop();

			}
			q.push(max_index);
		}
	}
	// �ھ��ֶ�����rank
	ranks[q.front()] = 1;
	printf("%d", ranks[0]);
	for (int i = 1; i < N_p; ++i)//���
		printf(" %d", ranks[i]);
	

	system("pause");
	return 0;
}