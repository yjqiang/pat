# define _CRT_SECURE_NO_WARNINGS
# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <climits>
# include <queue>
# include <map>

using namespace std;

map<int, bool> cache;
vector<int> a;

void func(int n) {
	while (n != 1){
		if (n % 2)
			n = n * 3 + 1;
		n /= 2;

		if (cache.find(n) != cache.end())
			return;
		cache[n] = true;
	}
}

int main() {
	int K;
	int i;
	int tmp;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	for (i = 0; i < K; ++i)
		func(a[i]);

	map<int, bool>::iterator index;

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	vector<int>::iterator index_vector;
	bool is_first = true;
	for (index_vector=a.begin(); index_vector != a.end(); ++index_vector) {
		if (cache.find(*index_vector) == cache.end()) {
			if (!is_first)
				printf(" %d", *index_vector);
			else {
				is_first = false;
				printf("%d", *index_vector);
			}
		}
		
	}
	

	system("pause");
	return 0;
}