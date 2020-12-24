#include <iostream>
using namespace std;
int d[1001];
int p[1001];

int dmin(int n) {
    if(d[n] != 0)   return d[n];  // memoization
    if(n == 1)  return d[n] = p[1];
    int min = p[n];
    // d[n] = MIN(dmin(i) + dmin(n-i), for 0<i<N)
    for(int i = n-1; i >= n/2; i--){
        int temp = dmin(i) + dmin(n-i);
        if(min > temp)
            min = temp;
    }
    return d[n] = min;
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> p[i];
    }
    cout << dmin(N);
}
