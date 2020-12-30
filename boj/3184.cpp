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

using namespace std;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };

char m[251][251];
bool visited[251][251];

void dfs(int y, int x, int N, int M, int& wolf, int& sheep)
{
	visited[y][x] = true;

	
	for (int i=0; i<4; ++i)
	{
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M)
		{
			continue;
		}

		if (!visited[next_y][next_x] && m[next_y][next_x] != '#')
		{
			if (m[next_y][next_x] == 'o')
			{
				sheep++;
			}
			else if (m[next_y][next_x] == 'v')
			{
				wolf++;
			}

			dfs(next_y, next_x, N, M, wolf, sheep);
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

	int total_wolf = 0;
	int total_sheep = 0;
	
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			int wolf = 0;
			int sheep = 0;
			
			if (!visited[i][j] && m[i][j] != '#')
			{
				if (m[i][j] == 'o')
				{
					sheep++;
				}
				else if (m[i][j] == 'v')
				{
					wolf++;
				}

				dfs(i, j, N, M, wolf, sheep);

				if (wolf >= sheep)
				{
					sheep = 0;
				}
				else
				{
					wolf = 0;
				}

				total_sheep += sheep;
				total_wolf += wolf;
			}
		}
	}

	cout << total_sheep << " " << total_wolf << endl;
	
}
