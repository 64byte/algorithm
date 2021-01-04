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

long long A, B;
long long ans = 0;

void rec(long long C) {

	if (C > B) {
		return;
	}

	if (C >= A && C <= B) {
		ans++;
	}

	rec(C * 10 + 4);
	rec(C * 10 + 7);

}

int main(void) {

	cin >> A >> B;

	rec(4);
	rec(7);

	cout << ans << endl;
}
