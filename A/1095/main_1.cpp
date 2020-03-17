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
	int seconds; // ����00��00��00������
	bool is_in;
};

// ���������
vector<Record> records;
// ƥ���in/out������
vector<Record> valid_records;
// counts[i] ��ʾ valid_records[i].secondsʱ�̣�ͣ��������
int counts[N_MAX];

// park_times[plate_num] = park_time
map<string, int> park_times;


// ����ɸѡvalid recordsʹ�ã���ͬ�û���������һ�Ѷ���ͬһ���ڰ���ʱ������
bool cmp(Record& record0, Record& record1) {
	int result = (record0.plate_num).compare(record1.plate_num);
	if (result != 0)
		return result < 0;
	return record0.seconds < record1.seconds;
}

// ��װʱ������
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


	// ���ƺ�һ��������һ��Ȼ���ٰ���ʱ��˳��
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



	// ����in/outƥ�䣬ɸѡ���Ϸ�������
	int n_size = records.size();
	int max_park_time = -1;  // ˳�ֵõ����ͣ��ʱ��
	for (i = 0; i < n_size;) {
		if (i + 1 < n_size &&
			records[i].plate_num == records[i + 1].plate_num &&
			records[i].is_in && !records[i + 1].is_in) {

			valid_records.push_back(records[i]);
			valid_records.push_back(records[i + 1]);

			// �õ����ͣ��ʱ��
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
		

	// ��ʱ������
	sort(valid_records.begin(), valid_records.end(), cmp1);
	// ��counts
	n_size = valid_records.size();
	counts[0] = 1;
	for (i = 1; i < n_size; ++i)
		// ���ϸ�ʱ�����½�/��
		counts[i] = (valid_records[i].is_in) ? counts[i - 1] + 1 : counts[i - 1] - 1;

	int cur = 0;  // ָʾcounts���±�
	for (i = 0; i < K; ++i) {
		cin >> hh >> c >> mm >> c >> ss;
		seconds = hh * 3600 + mm * 60 + ss;
		// query�ǰ���ʱ��˳��ģ���counts���ҵ�һ������Ŀ��ʱ���λ��
		for (; cur < n_size && valid_records[cur].seconds <= seconds; ++cur);
		if (cur == 0)
			printf("0\n");
		else
			printf("%d\n", counts[cur - 1]);
	}

	// map �ǰ���key�����
	map<string, int>::iterator map_i;
	for (map_i = park_times.begin(); map_i != park_times.end(); ++map_i)
		if (map_i->second == max_park_time)
			printf("%s ", map_i->first.c_str());

	printf("%02d:%02d:%02d\n", max_park_time / 3600, (max_park_time / 60) % 60, max_park_time % 60);

	system("pause");
	return 0;
}