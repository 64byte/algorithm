/*
https://www.acmicpc.net/problem/1251

brute force 문제

3등분할 수 있게 i, j를 나눈다. i < j < 문자열 길이를 항상 유지하도록 부분 문제를 만든다.

생성한 문자열을 비교한다. (굳이 set을 쓸 필요는 없다, 문제에서 사전순으로 첫번째 문자열만 구하는 것이니)

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

set<string> sss;

bool visited[51][51];

void dfs(int i, int j, string s) {
	const int sSize = s.length();

	if (visited[i][j]) {
		return;
	}

	string a1 = s.substr(0, i);
	reverse(a1.begin(), a1.end());
	string a2 = s.substr(i, j - i);
	reverse(a2.begin(), a2.end());
	string a3 = s.substr(j, sSize - j);
	reverse(a3.begin(), a3.end());

	string curr = a1 + a2 + a3;

	sss.insert(curr);

	visited[i][j] = true;

	if (i >= sSize || j >= sSize) {
		return;
	}

	if (i+1 < j) {
		dfs(i + 1, j, s);
	}

	if (j + 1 < sSize) {
		dfs(i, j + 1, s);
	}


}

int main(void) {

	string ss;

	cin >> ss;

	dfs(1, 2, ss);

	cout << (*sss.begin()) << endl;

}
