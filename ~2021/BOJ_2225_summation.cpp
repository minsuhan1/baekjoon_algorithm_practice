#include <iostream>
using namespace std;
const long long mod = 1000000000LL;

int main(){
  int N, K;
  cin >> N >> K;
  long long d[201][201] = {0,};
  // d[k][n] = k개 수를 더해서 n이 되는 경우의 수
  for(int n=0; n<=N; n++){
      d[1][n] = 1;
  }

  // 점화식
  // d[K][N] = ∑d[K-1][i]  (0 ≤ i ≤ N)
  for(int k=2; k<=K; k++){
      for(int n=0; n<=N; n++){
          for(int i=0; i<=n; i++){
              d[k][n] += d[k-1][i];
          }
          d[k][n] %= mod;
      }
  }

  cout << d[K][N];
}
