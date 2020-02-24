# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>
# include <cstring>

using namespace std;


int main(){
	int count, i;
	char min_name[11];
	char min_id[11];
	int min_points = 101;

	char max_name[11];
	char max_id[11];
	int max_points = -1;

	char cur_name[11];
	char cur_id[11];
	int cur_points = -1;

	scanf("%d", &count);
	for (i = 0; i < count; ++i)
	{
		scanf("%s%s%d", cur_name, cur_id, &cur_points);
		if (cur_points < min_points)
		{
			strcpy(min_name, cur_name);
			strcpy(min_id, cur_id);
			min_points = cur_points;
		}
		if (cur_points > max_points)
		{
			strcpy(max_name, cur_name);
			strcpy(max_id, cur_id);
			max_points = cur_points;
		}

	}

	printf("%s %s\n%s %s", max_name, max_id, min_name, min_id);
		
		


	system("pause");
	return 0;
}