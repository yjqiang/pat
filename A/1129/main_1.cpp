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
#include <unordered_set>

using namespace std;

#define N_MAX 50001

// num为1,2...N
// count就是counts[num]
struct Record {
	int num;
	int count;

	// 注意！！！！！！！！！！！！！！！！！！！！！！！！！！！
	bool operator<(const Record& b) const{
		if (count != b.count)
			return count > b.count;
		return num < b.num;
	}
};

// records存储的Record，num一定不重复的
set<Record> records;

// 统计
int counts[N_MAX] = { 0 };


int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int i;
	int num;
	int count_K;
	set<Record>::iterator set_i;
	for (i = 0; i < N; ++i) {
		scanf("%d", &num);
		// 第一个元素之前没有统计数据，不打印
		if (i > 0) {
			printf("%d:", num);

			for (set_i = records.begin(), count_K = 0; set_i != records.end() && count_K < K; ++set_i, ++count_K)
				printf(" %d", set_i->num);
			printf("\n");
		}
		// 刷新records
		// 有num这个记录了，删掉老的，刷入新记录
		// 没有num记录，刷入Record{num, 1}
		set_i = records.find(Record{ num, counts[num] });
		if (set_i != records.end())
			records.erase(set_i);
		++counts[num];
		records.insert(Record{ num, counts[num] });
	}


	system("pause");
	return 0;
}