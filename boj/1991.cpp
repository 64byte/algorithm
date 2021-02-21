/*
https://www.acmicpc.net/problem/1991

트리 기초 문제

배열은 N만 써도 된다

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

int v[26][2];

void tra(int st, string& pre, string& inorder, string& post) {

	if (st == -1)
		return;

	pre += static_cast<char>(st + 'A');

	if (v[st][0] != -1)
		tra(v[st][0], pre, inorder, post);

	inorder += static_cast<char>(st + 'A');

	if (v[st][1] != -1)
		tra(v[st][1], pre, inorder, post);

	post += static_cast<char>(st + 'A');

}

int main(void)
{
	cin >> N;

	char p, l, r;
	for (int i = 0; i < N; ++i) {
		cin >> p >> l >> r;
		
		p -= 'A';

		if (l != '.') {
			l -= 'A';
			v[p][0] = l;
		}
		else {
			v[p][0] = -1;
		}

		if (r != '.') {
			r -= 'A';
			v[p][1] = r;
		}
		else {
			v[p][1] = -1;
		}
	}

	string pre, inorder, post;

	tra(0, pre, inorder, post);
	

	cout << pre << endl;
	cout << inorder << endl;
	cout << post << endl;

}
