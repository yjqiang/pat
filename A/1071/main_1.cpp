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


string s;

map <string, int>counts;

int main() {
	ios::sync_with_stdio(false);
	getline(cin, s);
	int i;
	int n = s.size();
	// תΪСд
	for (i = 0; i < n; ++i)
		s[i] = tolower(s[i]);

	int start;
	// ����
	string word;
	for (i = 0; i < n;) {
		// �ҵ��µĵ���
		if (isalnum(s[i])) {
			// �ҵ����ʽ�β
			start = i;
			for (++i; i < n && isalnum(s[i]); ++i);
			word = s.substr(start, i - start);
			// printf("=>%s\n", word.c_str());
			++counts[word];
		}
		else
			++i;
	}
	
	map<string, int>::iterator map_i;
	string result;
	int count = -1;

	for (map_i = counts.begin(); map_i != counts.end(); ++map_i) {
		if (map_i->second > count) {
			result = map_i->first;
			count = map_i->second;
		}
		// map������key����

		//else if (map_i->second == count && map_i->first < result) {
		//	result = map_i->first;
		//}
	}
	printf("%s %d", result.c_str(), count);


	system("pause");
	return 0;
}