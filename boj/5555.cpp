#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

const int INF = 987654321;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };

int m[51][51];
int visited[51][51];

bool hasString(string& s1, string& s2)
{
	
	string s3 = s2 + s2;

	return s3.find(s1) != -1;
}

int main(void) {
	string s;
	cin >> s;

	int N;

	string s2;
	cin >> N;

	int count = 0;
	for (int i=0; i<N; ++i)
	{
		cin >> s2;
		if (hasString(s, s2))
		{
			count++;
		}
	}

	cout << count << endl;
	
}
