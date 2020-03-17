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

#define N_MAX 10000

struct Record {
	string plate_num;
	int seconds; // 距离00：00：00的秒数
	bool is_in;
};

// 输入的数据
vector<Record> records;
// 匹配好in/out的数据
vector<Record> valid_records;
// counts[i] 表示 valid_records[i].seconds时刻，停车的辆数
int counts[N_MAX];

// park_times[plate_num] = park_time
map<string, int> park_times;


// 用于筛选valid records使用，相同用户的数据在一堆儿，同一堆内按照时间排序
bool cmp(Record& record0, Record& record1) {
	int result = (record0.plate_num).compare(record1.plate_num);
	if (result != 0)
		return result < 0;
	return record0.seconds < record1.seconds;
}

// 安装时间排序
bool cmp1(Record& record0, Record& record1) {
	return record0.seconds < record1.seconds;
}

int main() {

	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	int hh, mm, ss, seconds;
	string plate_num, status;
	bool is_in;
	char c;

	int i;
	for (i = 0; i < N; ++i) {
		cin >> plate_num >> hh >> c >> mm >> c >> ss >> status;
		seconds = hh * 3600 + mm * 60 + ss;
		is_in = (status[0] == 'i');  // in/out
		records.push_back(Record{ plate_num, seconds, is_in });
	}


	// 车牌号一样的排在一起，然后再按照时间顺序
	sort(records.begin(), records.end(), cmp);
	//printf("\n");
	//for (i = 0; i < N; ++i)
	//	printf("%s %02d:%02d:%02d %s\n",
	//		records[i].plate_num.c_str(),
	//		records[i].seconds / 3600,
	//		(records[i].seconds / 60) % 60,
	//		records[i].seconds % 60,
	//		records[i].is_in?"in":"out");
	//printf("\n");



	// 根据in/out匹配，筛选出合法的数据
	int n_size = records.size();
	int max_park_time = -1;  // 顺手得到最长的停车时间
	for (i = 0; i < n_size;) {
		if (i + 1 < n_size &&
			records[i].plate_num == records[i + 1].plate_num &&
			records[i].is_in && !records[i + 1].is_in) {

			valid_records.push_back(records[i]);
			valid_records.push_back(records[i + 1]);

			// 得到最长的停车时间
			park_times[records[i].plate_num] += records[i + 1].seconds - records[i].seconds;
			max_park_time = max(max_park_time, park_times[records[i].plate_num]);

			i += 2;
		}
		else
			++i;
	}
	//n_size = valid_records.size();
	//for (i = 0; i < n_size; ++i)
	//	printf("%s %02d:%02d:%02d %s\n",
	//		valid_records[i].plate_num.c_str(),
	//		valid_records[i].seconds / 3600,
	//		(valid_records[i].seconds / 60) % 60,
	//		valid_records[i].seconds % 60,
	//		valid_records[i].is_in ? "in" : "out");
		

	// 按时间排序
	sort(valid_records.begin(), valid_records.end(), cmp1);
	// 算counts
	n_size = valid_records.size();
	counts[0] = 1;
	for (i = 1; i < n_size; ++i)
		// 比上个时间有新进/出
		counts[i] = (valid_records[i].is_in) ? counts[i - 1] + 1 : counts[i - 1] - 1;

	int cur = 0;  // 指示counts的下标
	for (i = 0; i < K; ++i) {
		cin >> hh >> c >> mm >> c >> ss;
		seconds = hh * 3600 + mm * 60 + ss;
		// query是按照时间顺序的，在counts中找第一个大于目标时间的位置
		for (; cur < n_size && valid_records[cur].seconds <= seconds; ++cur);
		if (cur == 0)
			printf("0\n");
		else
			printf("%d\n", counts[cur - 1]);
	}

	// map 是按照key排序的
	map<string, int>::iterator map_i;
	for (map_i = park_times.begin(); map_i != park_times.end(); ++map_i)
		if (map_i->second == max_park_time)
			printf("%s ", map_i->first.c_str());

	printf("%02d:%02d:%02d\n", max_park_time / 3600, (max_park_time / 60) % 60, max_park_time % 60);

	system("pause");
	return 0;
}