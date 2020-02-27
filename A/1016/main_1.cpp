# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
# include <climits>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX_NAME 21

struct Record {
	char name[MAX_NAME];
	int mon, day, hour, minute;
	int time; // time from 00:00:00
	bool status;  // true on; false off 
};

Record records[1000];

int cmp(const void* p0, const void* p1) {
	Record* rec0 = (Record*)p0;
	Record* rec1 = (Record*)p1;

	int result;

	result = strcmp(rec0->name, rec1->name);
	if (result)
		return result;

	result = rec0->mon - rec1->mon;
	if (result)
		return result;

	result = rec0->day - rec1->day;
	if (result)
		return result;

	result = rec0->hour - rec1->hour;
	if (result)
		return result;

	result = rec0->minute - rec1->minute;
	if (result)
		return result;

	return 0;
}

double cal(Record& rec, int* tolls) {
	int result = rec.day * tolls[24] * 60 + rec.minute * tolls[rec.hour];
	int index;
	for (index = 0; index < rec.hour; ++index) {
		result += tolls[index] * 60;
	}
	return result / 100.0;
}

int main() {
	int tolls[25];
	int sum = 0, tmp_int;

	int index;
	for (index = 0; index < 24; ++index) {
		scanf("%d", &tmp_int);
		tolls[index] = tmp_int;
		sum += tmp_int;
	}
	tolls[24] = sum;
		

	int N;
	scanf("%d", &N);

	char tmp_status[10];
	char on_line[] = "on-line";
	char off_line[] = "off-line";

	for (index = 0; index < N; ++index) {
		scanf("%s %d:%d:%d:%d %s", 
			records[index].name, 
			&(records[index].mon), 
			&(records[index].day),
			&(records[index].hour),
			&(records[index].minute),
			tmp_status);
		records[index].status = (!strcmp(tmp_status, on_line)) ? true: false;
		records[index].time = records[index].day * 24 * 60 + records[index].hour * 60 + records[index].minute;
	}
	qsort(records, N, sizeof(Record), cmp);

	double charge;
	double sum_charge;  // charge == 0  =>  first time when print one record
	for (index = 1; index < N; ++index) {
		sum_charge = 0;

		while (index < N && !strcmp(records[index].name, records[index - 1].name)) {
			if (!records[index].status && records[index - 1].status) {
				if (sum_charge ==0)
					printf("%s %02d\n", records[index].name, records[index].mon);

				charge = cal(records[index], tolls) - cal(records[index - 1], tolls);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
					records[index - 1].day,
					records[index - 1].hour,
					records[index - 1].minute,
					records[index].day,
					records[index].hour,
					records[index].minute,
					records[index].time - records[index - 1].time,
					charge);
				sum_charge += charge;
			}
			++index;
		}
		if (sum_charge != 0)
			printf("Total amount: $%.2lf\n", sum_charge);
	}

	system("pause");
	return 0;
}