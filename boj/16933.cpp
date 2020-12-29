#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = { 0, 1, 0, -1, 0 };
const int dy[] = { -1, 0, 1, 0, 0 };

char maps[1000][1000];
int visited[1000][1000][10][2];

int main(void)
{
	int n, m, k;

	cin >> n >> m >> k;

	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maps[i][j];
		}
	}

	
	queue<tuple<int, int, int, int, int>> q;
	q.push({ 0, 0, 0, 0, 0 });
	visited[0][0][0][0] = 1;

	while (!q.empty())
	{
		auto node = q.front();

		int N = get<0>(node);
		int M = get<1>(node);
		int canRemove = get<2>(node);
		int day = get<3>(node);
		int time = get<4>(node);
		
		q.pop();
				
		if (N == n - 1 && M == m - 1)
		{
			cout << (time + 1) << endl;
			return 0;
		}

		for (int i = 0; i < 5; ++i)
		{
			int next_y = N + dy[i];
			int next_x = M + dx[i];

			if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n)
			{
				if (canRemove < k && maps[next_y][next_x] == '1' && (visited[next_y][next_x][canRemove + 1][day] == -1) && day == 0)
				{
					visited[next_y][next_x][canRemove + 1][day] = visited[N][M][canRemove][day] + 1;
					q.push({ next_y, next_x, canRemove + 1, !day, time + 1 });
				}

				if ((visited[next_y][next_x][canRemove][day] == -1) && maps[next_y][next_x] == '0')
				{
					visited[next_y][next_x][canRemove][day] = visited[N][M][canRemove][day] + 1;
					q.push({ next_y, next_x, canRemove, !day, time + 1 });
				}

				if ((visited[next_y][next_x][canRemove][day] == -1) && N == next_y && M == next_x)
				{
					visited[next_y][next_x][canRemove][day] = visited[N][M][canRemove][day] + 1;
					q.push({ next_y, next_x, canRemove, !day, time + 1 });
				}

			}
		}
	}

	printf("-1\n");
	return 0;
}
