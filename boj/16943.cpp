/*
https://www.acmicpc.net/problem/16943

A의 순열을 만들어서 조건에 맞는 C를 구하면 된다.

해당 조건은 A != C && C <= B && (C는 0으로 시작하지 않는다)



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

int main(void) {
	int N;

	string A, B;

	cin >> A >> B;

	string C = A;

	sort(C.begin(), C.end());

	long ans = -1;

	long stolC = 0;
	do {
		stolC = stol(C);

		if (C.length() == to_string(stolC).length() && C != A && stolC <= stol(B)) {
			ans = max(ans, stolC);
		}

	} while (next_permutation(C.begin(), C.end()));


	cout << ans << endl;
}
