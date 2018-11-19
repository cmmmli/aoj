#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#include <ctype.h>
#include <numeric>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

int dx4[4] = { 0, -1, 1, 0 };
int dy4[4] = { -1, 0, 0, 1 };
int dx8[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int dy8[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };

int main() {
  int n;
  cin >> n;
  int maxv = -MOD;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) cin >> r[i];

  int minv = r[0];
  for (int i = 1; i < n; ++i) {
    maxv = max(maxv, r[i] - minv);
    minv = min(minv, r[i]);
  }

  cout << maxv << endl;
  return 0;
}
