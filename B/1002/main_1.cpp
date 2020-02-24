# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>

using namespace std;

char a[101];

int main(){
	int i, sum = 0;
	char pinyin[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	
	while (scanf("%1d", &i) != EOF)
		sum += i;

	if (!sum)
	{
		printf("ling");
		return 0;
	}

	vector<char*> s;
		
	for (i = 10; sum; sum /= 10) {
		s.push_back(pinyin[sum % 10]);
	}
	while (s.size() != 1){
		printf("%s ", s.back());
		s.pop_back();
	}
	printf("%s", s.back());
	
	system("pause");
	return 0;
}