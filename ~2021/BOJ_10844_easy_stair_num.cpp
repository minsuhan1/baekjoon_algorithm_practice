#include <iostream>
using namespace std;
long long d[101][10];
const long long mod = 1000000000LL;

int main(){
  for(int i = 1; i <= 100; i++){
    if(i == 1){
      for(int j = 1; j <= 9; j++){
        d[i][j] = 1;  // 길이가 1이고 j(1~9)로 끝나는 수의 개수
      }
      d[i][0] = 0;  // 0은 0으로 끝나지만 동시에 0으로 시작하는 수이므로 카운트하지 않는다.
    }
    if(i > 1){  // 길이가 2 이상인 수의 계단수를 끝나는 수에 따라 나누어 구한다.
      d[i][0] = d[i-1][1] % mod;  // 0으로 끝나려면 이전에 1로 끝나야 한다.
      // 1로 끝나려면 이전에 0이나 2로 끝나야 한다.
      // 2로 끝나려면 이전에 1이나 3으로 끝나야 한다.
      // 이와 같은 방법으로 8로 끝나는 경우까지 구하는 반복문
      for(int j = 1; j <= 8; j++){
        d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod;
      }
      d[i][9] = d[i-1][8] % mod;  // 9로 끝나려면 이전에 8로 끝나야 한다.
    }
  }

  int N;
  cin >> N;
  long long ans = 0;
  for(int i = 0; i <= 9; i++){
    ans = (ans + d[N][i]) % mod;
    // 참고로 ans += d[N][i] % mod 하면 틀린다.
    // ans += d[N][i] % mod 는 ans 에 (d[N][i] % mod) 결과를 더하는 것이다.
  }
  cout << ans;

}
