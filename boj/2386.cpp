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
	
	char a;
	string b;

	while (true) {
		cin >> a;

		if (a == '#') {
			break;
		}

		getline(cin, b);

		int count = 0;
		for (int i = 0; i < b.size(); ++i) {
			if (a == tolower(b[i])) {
				count++;
			}
		}

		cout << a << " " << count << endl;
	}

}
