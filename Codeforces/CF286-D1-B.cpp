#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

deque<int> ans;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    ans.push_back(i + 1);

  for (int i = 2; i <= n; i++) {
    int now = 0;
    for (int j = 0; j < n; j += i) {
      swap(now, ans[j]);
    }
    ans.pop_front();
    ans.push_back(now);
  }

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
}
