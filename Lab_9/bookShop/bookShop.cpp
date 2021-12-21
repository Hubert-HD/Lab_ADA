// Ejercicio 2
// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
  IOS
  int n, x, a, b;
  cin >> n >> x;
  vector<int> page(n),price(n);
  for(int&i : price) cin>>i;
  for(int&i : page) cin>>i;
  vector<vector<int>> dp(n + 1,vector<int>(x + 1, 0));
  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= x; j++){
      dp[i][j] = dp[i-1][j];
      if(j >= price[i-1])
        dp[i][j] = max (dp[i][j],dp[i - 1][j - price[i - 1]] + page[i - 1]);
    }
  cout<< dp[n][x] <<endl;
  return 0;
}