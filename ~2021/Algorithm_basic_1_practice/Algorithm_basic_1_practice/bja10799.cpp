#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);
	str += '\n';

	stack<int> s;	// 괄호 인덱스 스택
	int ans = 0;
	int index = 1;	// 괄호의 인덱스(1부터 시작)

	for (char ch : str) {
		if (ch == '(') {
			s.push(index);
			index++;
		}
		else if (ch == ')' && (index - s.top() == 1)) {	// 레이저
			s.pop();
			ans += s.size();	// s.size()개의 조각이 생김
		}
		else if (ch == ')' && (index - s.top() != 1)) {	// 쇠막대기의 오른쪽 끝
			s.pop();
			ans += 1;	// 1개의 조각이 생김
		}
		if (ch == '\n') {
			break;
		}
	}// 문자열 끝에 도달
	
	cout << ans;
	return 0;
}