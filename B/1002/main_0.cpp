# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
# include <vector>

using namespace std;

char a[101];

int main(){
	scanf("%s", a);

	int i;
	int sum = 0;
	for (i = 0; a[i] != '\0'; ++i){
		sum += a[i] - '0';
	}

	if (!sum)
	{
		printf("zero");
		return 0;
	}

	vector<string> s;
		
	for (i = 10; sum; sum /= 10) {
		switch (sum % i){
			case 0: s.push_back("ling"); break;
			case 1: s.push_back("yi"); break;
			case 2: s.push_back("er"); break;
			case 3: s.push_back("san"); break;
			case 4: s.push_back("si"); break;
			case 5: s.push_back("wu"); break;
			case 6: s.push_back("liu"); break;
			case 7: s.push_back("qi"); break;
			case 8: s.push_back("ba"); break;
			case 9: s.push_back("jiu"); break;
		}
	}
	while (s.size() != 1){
		printf("%s ", s.back().c_str());
		s.pop_back();
	}
	printf("%s ", s.back().c_str());
	
	system("pause");
	return 0;
}