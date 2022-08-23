#include <iostream>
using namespace std;
long long d[100001][4];
const long long mod = 1000000009LL;

int main(){
  for(int i = 1; i < 100001; i++){
    if(i > 1){  // i를 마지막 숫자가 1인 합으로 나타내는 방법의 수는
    // i-1를 마지막 숫자가 각각 2,3인 합으로 나타내는 방법 수와 같다.
    // 1을 연속하여 더할 수 없기 때문이다.
      d[i][1] = d[i-1][2] + d[i-1][3];  
    }else if(i == 1){ // d[1][1] 은 예외적인 case
      d[i][1] = 1;
    }
    // 마지막 숫자가 각각 2,3인 합으로 나타내는 방법의 수도 같은 방법으로 구한다.
    if(i > 2){
      d[i][2] = d[i-2][1] + d[i-2][3];
    }else if(i == 2){
      d[i][2] = 1;
    }

    if(i > 3){
      d[i][3] = d[i-3][1] + d[i-3][2];
    }else if(i == 3){
      d[i][3] = 1;
    }

    d[i][1] %= mod;
    d[i][2] %= mod;
    d[i][3] %= mod;
  }

  int N;
  cin >> N;
  while(N--){
    int n;
    cin >> n;
    cout << (d[n][1] + d[n][2] + d[n][3]) % mod << endl;
  }
}
