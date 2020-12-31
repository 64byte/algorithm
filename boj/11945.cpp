#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

char m[11][11];

int main(void) {
	long long N, M;

	cin >> N >> M;

	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cin >> m[i][j];
		}

		for (int a = 0, b = M - 1; a < b; a++, b--)
		{
			swap(m[i][a], m[i][b]);
		}
	}

	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cout << m[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";
	
}

/* m열을 뒤에서부터  받으면 된다.
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

char m[11][11];

int main(void) {
	long long N, M;

	cin >> N >> M;

	for (int i=0; i<N; ++i)
	{
		for (int j=M-1; j>=0; --j)
		{
			cin >> m[i][j];
		}
	}

	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			cout << m[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";
	
}
*/
