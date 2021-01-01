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
int main(void) {

	cin >> N;

	int value = 0;

	vector<int> v;
	for (int i=0; i<N; ++i)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 0)
	{
		cout << v[(N / 2)-1] << endl;
	}
	else if (N % 2 == 1)
	{
		cout << v[N / 2 ] << endl;
	}
}
