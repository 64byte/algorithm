/*
https://www.acmicpc.net/problem/11048

DP 기초

m[i][j]가 최대값이 되는 경우는

m[i][j] += m[i][[j-1] ( i == 0 && j > 0 )
m[i][j] += m[i-1][j] ( j == 0 && i > 0 )
m[i][j] += max(m[i-1][j], m[i][j-1]) (i > 0 && j > 0)

점화식에 따라 코드를 작성하면 된다.

*/

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

int N, M;
int m[1001][1001];

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i == 0 && j > 0) {
				m[i][j] += m[i][j - 1];
			}
			else if (j == 0 && i > 0) {
				m[i][j] += m[i - 1][j];
			}
			else if (i > 0 && j > 0) {
				m[i][j] += max(m[i - 1][j], m[i][j - 1]);
			}


		}
	}

	cout << m[N-1][M-1] << endl;

}
