#include <iostream>
using namespace std;
long long d[91][2];

int main(){
  for(int i = 1; i <= 90; i++){
    if(i == 1){
      d[i][1] = 1;
      d[i][0] = 0;  //이친수는 0으로 시작할 수 없다.
    }
    if(i > 1){  // 길이가 2 이상인 수의 이친수 구하기
      // 마지막 자리 숫자가 0이면
      // 그 전 숫자는 0 또는 1
      d[i][0] = d[i-1][1] + d[i-1][0]; 
      // 마지막 자리 숫자가 1이면
      // 그 전 숫자로 1은 올 수 없다.
      d[i][1] = d[i-1][0]; 
    }
  }

  int N;
  cin >> N;
  cout << d[N][0] + d[N][1];

}
