#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int d[N+1];

  d[0] = 0;
  for(int i = 1; i <= N; i++){
    d[i] = i;
    for(int j = 1; j*j <= i; j++){
      if(d[i] > d[i-j*j]+1)
        d[i] = d[i-j*j]+1;
    }
  }

  cout << d[N];
}
