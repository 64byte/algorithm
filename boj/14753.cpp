/*
https://www.acmicpc.net/problem/14753

N 중에 2개 or 3개를 택해서 가장 큰 곱을 구하는 문제

3 <= N <= 10,000

-1000 <= A[i] <= 1000

N이 10,000까지니까 단순 brute force로 풀긴 힘들다. ( O(10,000 C 3) )

가장 큰 곱을 구하기 위해선 결국 가장 큰 수만 곱하면 된다.

정렬 후, 3가지만 택해서 곱한 큰 수를 반환한다.

음수 3개와, 양수 3개, 그리고 음수 2개, 양수 1개를 택해서 그 중에서 2개 or 3개를 택해 큰 곱셈수를 반환한다.

시간 복잡도는
O (10,000 * (log 10,000))

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

int N;
vector<long long> v;

long long ans = LLONG_MIN;

long long mxA(long long a, long long b, long long c) {

	long long aa = a * b;
	long long bb = a * c;
	long long cc = b * c;
	long long dd = a * b * c;

	return max(max(aa, bb), max(cc, dd));
}

int main(void) {

	cin >> N;
	long long value = 0;
	for (int i = 0; i < N; ++i) {
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());

	long long a = max(mxA(v[0], v[1], v[2]), mxA(v[N - 1], v[N - 2], v[N - 3]));
	long long b = mxA(v[0], v[1], v[N - 1]);

	cout << max(a, b) << endl;

}
