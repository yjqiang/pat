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

using namespace std;

// counts[sum] = n
map<int, int>counts;

int main(){
	int N;
	scanf("%d", &N);

	int i;
	int num;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &num);
		++counts[abs(num - i)];
	}

	int n_size = counts.size();

	// ÓÃÓÚÅÅÐò
	vector<int> result;

	map<int, int>::iterator map_i;
	for (map_i = counts.begin(); map_i != counts.end(); ++map_i)
		if (map_i->second > 1)
			result.push_back(map_i->first);

	for (i = result.size() - 1; i >= 0; --i)
		printf("%d %d\n", result[i], counts[result[i]]);

	system("pause");
	return 0;
}