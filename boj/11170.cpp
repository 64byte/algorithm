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

int main(void) {
	int T;
	cin >> T;
	
	int N, M;
	while (T--) {
		cin >> N >> M;

		int ans = 0;
		for (int i = N; i <= M; ++i) {

			int num = i;
			do {
				if (num % 10 == 0) {
					ans++;
				}
				
				num /= 10;
			} while (num);

		}
		cout << ans << "\n";
	}
}
