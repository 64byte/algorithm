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
	cin >> N;

	int y = 1;
	int x = 2 * N - 1;
	for (int i = 1; i <= 2 * N - 1; ++i) {
		
		for (int j = 0; j < 2 * N; ++j) {

			if (y <= j && j < x) {
				cout << " ";
			}
			else {
				cout << "*";
			}

		}
		cout << "\n";

		if (i > N) {
			y--;
			x++;
		}
		else if (i == N) {
			swap(y, x);
				y--;
				x++;
		}
		else if (i < N) {
			y++;
			x--;
		}


	}

}
