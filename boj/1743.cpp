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

int N, M, K;
int m[101][101];
bool visited[101][101];

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1 ,0, 0};

void dfs(int y, int x, int& count) {

    visited[y][x] = true;

    for (int i=0; i<4 ;++i) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if (!visited[next_y][next_x] && m[next_y][next_x] == 1) {
            count++;
            dfs(next_y, next_x, count);
        }
    }


}

int main(void) {

    cin >> N >> M >> K;

    int a = 0, b = 0;
    for (int i=0; i<K; ++i) {
        cin >> a >> b;
        m[a-1][b-1] = 1;
    }

    int ans = 0;

    int c = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {

            if (!visited[i][j] && m[i][j] == 1) {
                c++;
                dfs(i, j, c);

                ans = max(ans, c);

                c = 0;
            }
        }
    }


    cout << ans << endl;
    return 0;
}
