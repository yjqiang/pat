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
map<int, bool> result;
int a[101];

void func(int n) {
	int orig = n;

	if (cache.find(orig) != cache.end())
		return;

	cache[orig] = true;
	while (n != 1){
		if (n % 2)
			n = n * 3 + 1;
		n /= 2;
		

		if (cache.find(n) != cache.end()) {
			if (result.find(n) != result.end())
			{
				result.erase(n);
			}
			break;
			
		}
		cache[n] = true;
	}
	result[orig] = true;
}

int main() {
	int K;
	int i;
	int tmp;
	scanf("%d", &K);
	for (i = 0; i < K; ++i) {
		scanf("%d", a + i);
	}
	for (i = 0; i < K; ++i)
		func(a[i]);

	map<int, bool>::iterator index;
	
	vector<int> t;
	for (index = result.begin(); index != result.end(); ++index) {
		t.push_back(index->first);
	}
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());

	vector<int>::iterator index_vector = t.begin();
	printf("%d", *index_vector);
	for (++index_vector; index_vector != t.end(); ++index_vector) {
		printf(" %d", *index_vector);
	}
	

	system("pause");
	return 0;
}