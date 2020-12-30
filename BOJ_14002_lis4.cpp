#include <iostream>
#include <stack>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N];
  int d[N][2]; 
  // d[i][0] = a[i]를 마지막 숫자로 갖는 LIS 길이
  // d[i][1] = a[i] 직전의 숫자 인덱스
  for(int i = 0; i < N; i++)
    cin >> a[i];  // input 
  
  for(int i = 0; i < N; i++){
    d[i][0] = 1; // 초기 LIS길이
    d[i][1] = -1;
    for(int j = 0; j < i; j++){ // j < i 인 j에 대해 반복
      // j번째 수가 i번째 수(현재 LIS길이를 구하는 수)보다 작아야 하고
      // d[i] < d[j]+1 이어야 d[i]를 update하는 조건이 된다
      if(a[j] < a[i] && d[i][0] < d[j][0]+1){
        d[i][0] = d[j][0] + 1;
        d[i][1] = j;
      }
    }
  }
  
  int max = d[0][0];
  int idx = 0;
  for(int i = 1; i < N; i++){
    if(d[i][0] > max){
      max = d[i][0];
      idx = i;
    }
  }

  cout << max << endl;
  stack<int> s;
  while(idx != -1){
    s.push(a[idx]);
    idx = d[idx][1];
  }
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
}
