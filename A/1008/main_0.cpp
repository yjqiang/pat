# define _CRT_SECURE_NO_WARNINGS
# include <cstdlib>
# include <cstdio>
# include <vector>
# include <ctime>
# include <iostream>
# include <cstring>
# include <climits>
# include <cmath>

using namespace std;

int main() {
	int N, req, step;

	scanf("%d", &N);

	int i;
	int cur_floor = 0;
	int sum = 0;
	for (i = 0; i < N; ++i){
		scanf("%d", &req);
		step = req - cur_floor;
		if (step < 0)
			sum += (-step) * 4 + 5;
		else if (step > 0)
			sum += step * 6 + 5;
		else
			sum += 5;

		cur_floor = req;

	}
	printf("%d", sum);

	system("pause");
	return 0;
}