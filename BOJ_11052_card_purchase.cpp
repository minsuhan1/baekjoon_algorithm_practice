#include <iostream>
using namespace std;
int d[1001];
int p[1001];

int dmax(int n) {
    if(d[n] != 0)   return d[n];  // memoization
    if(n == 1)  return d[n] = p[1];
    int max = p[n];
    // d[n] = MAX(dmax(i) + dmax(n-i), for 0<i<N)
    for(int i = n-1; i >= n/2; i--){
        int temp = dmax(i) + dmax(n-i);
        if(max < temp)
            max = temp;
    }
    return d[n] = max;
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> p[i];
    }
    cout << dmax(N);
}
