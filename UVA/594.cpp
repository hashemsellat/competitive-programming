#include <bits/stdc++.h>
using namespace std;
#define int long long int
string to_binary(int x) {
  string ret = "";
  while (x) {
    if (x % 2) {
      ret = "1" + ret;
    } else {
      ret = "0" + ret;
    }
    x /= 2;
  }
  return ret;
}
string rev(string s) {
  string ret = "";
  for (int i = 0; i < 32; i += 8) {
    string cur = "";
    for (int j = i; j < i + 8; j++) {
      cur += s[j];
    }
    ret = cur + ret;
  }
  return ret;
}
int to_int(string s) {
  int ret = 0;
  for (int i = 0; i < 32; i++) {
    ret += (s[i] - '0') * (1 << (32 - i - 1));
  }
  return ret;
}
string ts(string s) {
  string ret = "";
  for (int i = 0; i < 32; i++)
    if (s[i] == '1')
      ret += '0';
    else
      ret += '1';
  for (int i = 31; i >= 0; i--) {
    if (ret[i] == '1')
      ret[i] = '0';
    else {
      ret[i] = '1';
      break;
    }
  }
  return ret;
}
main() {
  int x;
  while (cin >> x) {
    string ans = to_binary(x);
    while (ans.size() < 32) {
      ans = "0" + ans;
    }
    if(x<0)
    ans = ts(ans);
    cout << x << " converts to " << to_int(rev(ans)) << endl;
  }
}
