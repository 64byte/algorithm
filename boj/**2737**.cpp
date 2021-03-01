/**
https://www.acmicpc.net/problem/2737

수학 문제


아래 풀이 참고함
https://nnnlog.tistory.com/67

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

using ll = long long;

const ll INF = 987654321;

int main(void) {


	int t;

	cin >> t;
	
	long double n;
	int ans = 0;
	while (t--) {
		cin >> n;

		long double end = ((-1) + sqrt(8 * n + 1)) / 2;
		ans = 0;
		for (long double k = 2; k <= end; ++k) {
			long double a = (n / k) - (k / 2) + 0.5;
			if (static_cast<long long>(a) == a) {
				ans++;
			}
		}

		cout << ans << endl;
	}
}
