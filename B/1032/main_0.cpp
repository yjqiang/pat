#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>

#include <set>
#include <cstring>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;



int main() {
	
	int N;
	scanf("%d", &N);
	
	map<int, int> schools;
	
	int i;
	int id, score;
	for (i = 0; i < N; ++i) {
		scanf("%d%d", &id, &score);
		schools[id] += score;
	}

	int max_element, max_index;
	max_element = INT_MIN;
	for (map<int, int>::iterator i = schools.begin(); i != schools.end(); ++i) {
		if (i->second > max_element) {
			max_element = i->second;
			max_index = i->first;
		}
	}
	printf("%d %d", max_index, max_element);


	system("pause");
	return 0;
}