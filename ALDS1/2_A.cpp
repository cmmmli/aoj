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

int bubbleSort(vector<int>& a, int n) {
  int count = 0;
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j = n - 1; j > 0; --j) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        flag = 1;
        ++count;
      }
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int res = bubbleSort(arr, n);
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i == n - 1) break;
    cout << " ";
  }
  cout << endl << res << endl;
  return 0;
}
