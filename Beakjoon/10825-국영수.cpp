#include <bits/stdc++.h>
using namespace std;

/*
*/


class Student {
public:
	string name;
	int a;
	int b;
	int c;
	Student(string name, int a, int b, int c) :name(name), a(a), b(b), c(c) {}

};

bool compare(Student input1, Student input2) {
	if (input1.a == input2.a) {
		if (input1.b == input2.b) {
			if (input1.c == input2.c) {
				return input1.name < input2.name;
			}
			else {
				return input1.c > input2.c;
			}
		}
		else {
			return input1.b < input2.b;
		}
	}
	else {
		return input1.a > input2.a;
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string name;
	int a, b, c;

	vector<Student> input;

	for (int i = 0; i < N; i++) {
		cin >> name >> a >> b >> c;
		input.push_back(Student(name, a, b, c));
	}

	sort(input.begin(), input.end(), compare);


	for (int i = 0; i < N; i++) {
		cout << input[i].name << "\n";
	}

	return 0;
}