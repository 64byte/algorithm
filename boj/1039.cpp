#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

char m[251][251];
bool visited[1000001][10];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int T;
	cin >> s >> T;

	queue<pair<string, int>> q;
	
	q.push({ s, T });
	
	long long ans = -1;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		string curr_s = node.first;
		int time = node.second;
		
		if (time == 0)
		{
			ans = max(ans, stoll(curr_s));
			continue;
		}

		int sSize = curr_s.length();
		string ss = "";
		for (int i = 0; i < sSize; ++i)
		{
			for (int j = i+1; j < sSize; ++j)
			{
				if (i < j) {
					if (i == 0 && curr_s[j] == '0')
					{
						continue;
					}
					
					if (time > 0) {
						ss = curr_s;
						swap(ss[i], ss[j]);
						long long nextValue = stoll(ss);
						if (!visited[nextValue][time - 1]) {
							visited[nextValue][time - 1] = true;
							q.push({ ss, time - 1 });
						}
					}
				}
			}
		}


	}

	cout << ans << endl;
}
