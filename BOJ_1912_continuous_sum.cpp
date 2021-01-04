#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int d[N]; // d[i] = i번째 수로 끝나는 가장 큰 연속합
  int a[N];
  for(int i = 0; i < N; i++)
    cin >> a[i];

  d[0] = a[0];
  for(int i = 1; i < N; i++){
    if(a[i] < a[i] + d[i-1])
      d[i] = a[i] + d[i-1];
    else
      d[i] = a[i];
  }

  int max = d[0];
  for(int i = 1; i < N; i++)
    if(d[i] > max)  max = d[i];

  cout << max;
}
