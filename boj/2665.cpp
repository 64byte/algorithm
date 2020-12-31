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

int main(void) {
	int N;
	cin >> N;

	char ch;
	
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<N; ++j)
		{
			cin >> ch;
			if (ch == '1')
			{
				m[i][j] = 0;
			}
			else
			{
				m[i][j] = 1;
			}
			
			visited[i][j] = INF;
		}
	}

	priority_queue<pair<pair<int, int>, int>> pq;

	pq.push({ { 0, 0 }, 0 });

	while (!pq.empty())
	{
		auto node = pq.top();
		int curr_y = node.first.first;
		int curr_x = node.first.second;
		int curr_dist = -node.second;
		pq.pop();

		for (int i=0; i<4; ++i)
		{
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];
			int next_dist = curr_dist + m[next_y][next_x];
			
			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N)
			{
				continue;
			}

			if (next_dist < visited[next_y][next_x])
			{
				visited[next_y][next_x] = next_dist;
				pq.push({ {next_y, next_x,}, -next_dist });
			}
			
		}
		
	}

	cout << visited[N - 1][N - 1] << endl;
	
}
