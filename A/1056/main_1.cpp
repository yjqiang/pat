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

	// 队列
	queue<int> q;

	for (i = 0; i < N_p; ++i) {
		scanf("%d", &int_tmp);
		q.push(int_tmp);
	}

	int size_q, n_groups;
	int count_group;
	int max_weight, max_index;
	while (q.size()!=1) {
		// 本轮次的参赛人数
		size_q = q.size();
		// 组数，上取整
		n_groups = (size_q + N_g - 1) / N_g;

		count_group = 0;
		i = 0;
		// 每个循环就是代表了每组进行比赛
		for (count_group = 0; count_group < n_groups; ++count_group) {
			max_weight = -1;
			// h负责某一组的人数计数，i负责整个queue的计数
			for (h = 0; h < N_g && i < size_q; ++h, ++i) {
				int_tmp = q.front();
				// 组内胜者也会被置为这个rank，不要担心，之后的轮次，ranks[int_tmp]会被覆盖掉；或者成为冠军，这时我们需要手动覆盖
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
	// 冠军手动覆盖rank
	ranks[q.front()] = 1;
	printf("%d", ranks[0]);
	for (int i = 1; i < N_p; ++i)//输出
		printf(" %d", ranks[i]);
	

	system("pause");
	return 0;
}