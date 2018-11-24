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

ll cnt = 0;
vector<int> g;

void insertionSort(int a[], int n, int g) {
  for (int i = g; i < n; ++i) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      ++cnt;
    }
    a[j + g] = v;
  }
}

void shellSort(int a[], int n) {
  for (int h = 1; ;) {
    if (h > n) break;
    g.push_back(h);
    h = 3 * h + 1;
  }
  cout << g.size() << endl;
  for (int i = g.size() - 1; i >= 0; --i) {
    cout << g[i];
    if (i == 0) break;
    cout << " ";
  }
  cout << endl;
  for (int i = g.size() - 1; i >= 0; --i) {
    insertionSort(a, n, g[i]);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  shellSort(arr, n);
  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << endl;
  }
  return 0;
}
