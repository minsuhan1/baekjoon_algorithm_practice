#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_num;
	cin >> test_num;
	cin.ignore();

	int num = 0;	// 스택에 넣을 값 변수
	stack<int> s;
	string result;
	bool v = true;	// 스택 수열 가능/불가능 여부(초기값 true)

	int n;
	cin >> n;
	// 스택 비어 있음
	for (int i = 0; i < n; i++) {	// push 반복횟수 = n
		s.push(++num);
		result += "+\n";
	}
	s.pop();
	result += "-\n";
	test_num--;

	while (test_num--) {
		int n;
		cin >> n;
		if ((!s.empty() && n >= s.top() && v == true) || (s.empty() && v == true)) {
			int rep = n - num;
			for (int i = 0; i < rep; i++) {	
				// push 반복횟수(고정시키기 위해 rep 변수 사용) = n - num
				s.push(++num);
				result += "+\n";
			}
			s.pop();
			result += "-\n";
		}
		else if (!s.empty() && n < s.top() && v == true) {
			// 스택 수열 생성 불가능 : 스택 맨 위 숫자가 n보다 크므로
			// n을 스택에서 바로 빼낼 수 없다 -> n보다 위에 있는 숫자가 pop되므로 NO 출력
			result = "NO";
			v = false;
		}
	}

	std::cout << result;
	return 0;
}