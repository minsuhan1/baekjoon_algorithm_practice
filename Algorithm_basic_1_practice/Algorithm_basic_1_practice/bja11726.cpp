#include <iostream>
using namespace std;

int d[1001];

int cal(int n) {
	if (d[n] > 0) return d[n];	// memorization
	
	// 2x2까지는 답이 n과 같다.
	if (n <= 2) {
		d[n] = n;
		return n;
	}
	// d[n] : 2xn 크기의 직사각형을 타일로 채우는 방법의 수
	// 2x(n-1) 직사각형에 1x2 타일을 붙여 2xn 직사각형을 만들 수 있다.
	// 2x(n-2) 직사각형에 2x1 타일 2개를 붙여 2xn 직사각형을 만들 수 있다.
	// 따라서 점화식은 d[n] = d[n-1] + d[n-2];

	// 재귀 중간에 오버플로우가 발생할 수 있기 때문에
	// 계산할 때마다 10007을 나누어 준다.
	// 계산 중에 %10007을 하는 것과 마지막에 %10007을 하는 것의 결과가 같다.
	d[n] = (cal(n - 1) + cal(n - 2)) % 10007;
	return d[n];
}

int main() {
	int n;
	cin >> n;
	cout << cal(n);	
	// cout << cal(n) % 10007 라고 하면
	// n이 큰 수일때 cal(n)의 값이 이미 수많은 오버플로우를 거쳐서 나온 틀린 값이 되어 답도 틀리게 된다.
}