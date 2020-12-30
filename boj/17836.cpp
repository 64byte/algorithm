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
int visited[251][251][2];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, T;
	cin >> N >> M >> T;

	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cin >> m[i][j];
		}
	}

	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			for (int k=0; k<4; ++k)
			{
				visited[i][j][k] = 987654321;
			}
		}
	}
	
	queue<tuple<int, int, int, int>> q;

	q.push({ 0, 0, 0, 0 });
	visited[0][0][0] = 1;

	int ans = 987654321;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int curr_y = get<0>(node);
		int curr_x = get<1>(node);
		int hasSword = get<2>(node);
		int time = get<3>(node);
		
		if (curr_y == N-1 && curr_x == M-1)
		{
			ans = min(ans, time);
		}

		for (int i=0; i<4; ++i)
		{
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M)
			{
				continue;
			}

			if (hasSword)
			{
				if (visited[next_y][next_x][hasSword] > visited[curr_y][curr_x][hasSword] + 1)
				{
					visited[next_y][next_x][hasSword] = visited[curr_y][curr_x][hasSword] + 1;
					q.push({ next_y, next_x, hasSword, time + 1 });
				}
			}
			else
			{
				if (m[next_y][next_x] != '1') 
				{
					if (m[next_y][next_x] == '0' && visited[next_y][next_x][hasSword] > visited[curr_y][curr_x][hasSword] + 1)
					{
						visited[next_y][next_x][hasSword] = visited[curr_y][curr_x][hasSword] + 1;
						q.push({ next_y, next_x, hasSword, time + 1 });
					}
					else if (m[next_y][next_x] == '2' && visited[next_y][next_x][hasSword] > visited[curr_y][curr_x][hasSword] + 1)
					{
						visited[next_y][next_x][!hasSword] = visited[curr_y][curr_x][hasSword] + 1;
						q.push({ next_y, next_x, !hasSword, time + 1 });
					}
				}
			}
			
			
		}

		
	}

	if (ans <= T)
	{
		cout << ans << endl;
	}
	else
	{
		cout << "Fail" << endl;
	}
}
