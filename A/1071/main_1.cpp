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
	// 转为小写
	for (i = 0; i < n; ++i)
		s[i] = tolower(s[i]);

	int start;
	// 单词
	string word;
	for (i = 0; i < n;) {
		// 找到新的单词
		if (isalnum(s[i])) {
			// 找到单词结尾
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
		// map本身按照key排序

		//else if (map_i->second == count && map_i->first < result) {
		//	result = map_i->first;
		//}
	}
	printf("%s %d", result.c_str(), count);


	system("pause");
	return 0;
}