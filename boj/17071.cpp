#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <tuple>
#include <map>

using namespace std;

int N, K;
int visited[500001][2];

int main(void)
{
	cin >> N >> K;
	queue<tuple<int, int, int>> q;

	memset(visited, -1, sizeof(visited));
	
	q.push({ N, K, 0 });
	visited[N][0] = 1;

	int minTime = 987654321;

	vector<int> whens;
	while (!q.empty()) {
		auto node = q.front();
		q.pop();

		int subin = get<0>(node);
		int sister = get<1>(node);
		int time = get<2>(node);

		//cout << subin << ", " << sister << ", " << time << endl;
		
		if (visited[sister][time%2] != -1) {
			minTime = min(minTime, time);
			break;
			//cout << visited[subin][0] << ", " << visited[subin][1] << endl;
		}
	
		int sisterNext = sister + time + 1;

		if (subin - 1 >= 0 && sisterNext <= 500000 && visited[subin - 1][(time + 1) % 2] == -1) {
			visited[subin - 1][(time + 1) %2] = visited[subin][time%2]+1;
			q.push({ subin - 1, sisterNext, time + 1 });
		}

		if (subin + 1 <= 500000 && sisterNext <= 500000 && visited[subin + 1][(time + 1) % 2] == -1) {
			visited[subin + 1][(time + 1) % 2] = visited[subin][time % 2] + 1;
			q.push({ subin + 1, sisterNext, time + 1 });
		}

		if (subin * 2 <= 500000 && sisterNext <= 500000 && visited[subin * 2][(time + 1) % 2] == -1) {
			visited[subin * 2][(time + 1) % 2] = visited[subin][time % 2] + 1;
			q.push({ subin * 2, sisterNext, time + 1 });
		}
	}

	cout << (minTime == 987654321 ? -1 : minTime) << "\n";
}
