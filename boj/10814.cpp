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

struct Employee
{
	int age;
	std::string name;
};

bool operator<(const Employee& lhs, const Employee& rhs)
{
	return lhs.age < rhs.age;
}

int main(void)
{
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	cin >> N;

	vector<Employee> s;

	int age;
	string name;
	for (int i = 0; i < N; ++i) {
		cin >> age >> name;
		s.push_back({ age, name });
	}

	stable_sort(s.begin(), s.end());

	for (const auto& u : s) {
		cout << u.age << " " << u.name << "\n";
	}
}
