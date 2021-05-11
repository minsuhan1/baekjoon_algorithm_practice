#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  while(1) {
    int n;
    double mf;
    cin >> n >> mf;
    int m = (int)(mf * 100 + 0.5);
    if (n == 0 && m == 0)
        break;
    int dp[10001] = {0,};
    for(int i=0; i<n; i++){
        int c;
        double pf;
        cin >> c >> pf;
        int p = (int)(pf * 100 + 0.5);
        for (int j = p; j < m+1; j++){
            dp[j] = max(dp[j], dp[j-p] + c);
        }
    }
    cout << dp[m] <<"\n";
  }
}
