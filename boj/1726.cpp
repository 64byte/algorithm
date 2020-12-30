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
int visited[251][251][4];

int turnTo(int dir, int whereTo)
{
	if (whereTo == 0)
	{
		switch (dir)
		{
		case 0:
			return 3;

		case 1:
			return 2;

		case 2:
			return 0;

		case 3:
			return 1;
		}
	}
	else
	{
		switch (dir)
		{
		case 0:
			return 2;

		case 1:
			return 3;

		case 2:
			return 1;

		case 3:
			return 0;
		}
	}

	
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;

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

	int from_y, from_x, from_dir;
	int to_y, to_x, to_dir;

	cin >> from_y >> from_x >> from_dir;
	cin >> to_y >> to_x >> to_dir;

	to_y -= 1;
	to_x -= 1;
	to_dir -= 1;
	
	queue<tuple<int, int, int, int>> q;

	q.push({ from_y-1, from_x-1, from_dir-1, 0 });
	visited[from_y-1][from_x-1][from_dir-1] = 0;

	int ans = 987654321;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int curr_y = get<0>(node);
		int curr_x = get<1>(node);
		int curr_dir = get<2>(node);
		int time = get<3>(node);
		
		if (curr_y == to_y && curr_x == to_x && curr_dir == to_dir)
		{
			ans = min(ans, time);
		}
		
		int next_y = curr_y;
		int next_x = curr_x;
		int next_time = time;
		for (int i=0; i<3; ++i)
		{
			next_y += dy[curr_dir];
			next_x += dx[curr_dir];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || m[next_y][next_x] == '1')
			{
				break;;
			}

			if (visited[next_y][next_x][curr_dir] > visited[curr_y][curr_x][curr_dir] + 1) {
				visited[next_y][next_x][curr_dir] = visited[curr_y][curr_x][curr_dir] + 1;
				q.push({ next_y, next_x, curr_dir, time + 1 });
			}
		}

		for (int i=0; i<2; ++i)
		{
			int next_dir = turnTo(curr_dir, i);

			if (visited[curr_y][curr_x][next_dir] > visited[curr_y][curr_x][curr_dir] + 1)
			{
				visited[curr_y][curr_x][next_dir] = visited[curr_y][curr_x][curr_dir] + 1;
				q.push({ curr_y, curr_x, next_dir, time+1 });
			}
			
		}
		
	}

	cout << ans << endl;
}
