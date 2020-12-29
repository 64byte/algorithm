#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <tuple>

using namespace std;

int N;
const int NN = 123457 * 2 + 1;
bool prime[NN];

int main(void)
{
	prime[1] = true;
	for (int i = 2; i <= sqrt(NN); ++i) {
		if (!prime[i]) {
			for (int j = i * i; j <= NN; j += i) {
				prime[j] = true;
			}
		}
	}

	while (true) {
		cin >> N;
		if (N == 0) {
			break;
		}

		int count = 0;
		for (int n = N+1; n <= 2 * N; ++n) {
			if (!prime[n]) {
				count++;
			}
		}

		cout << count << "\n";
	}

}
