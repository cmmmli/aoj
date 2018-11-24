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

struct Card { char suit, value; };

void printArray(struct Card c[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << c[i].suit << c[i].value;
    if (i == n - 1) break;
    cout << " ";
  }
  cout << endl;
}

void bubbleSort(struct Card c[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; --j) {
      if (c[j].value < c[j - 1].value) {
        swap(c[j], c[j - 1]);
      }
    }
  }
  printArray(c, n);
  cout << "Stable" << endl;
}

void selectionSort(struct Card c[], int n) {
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (c[j].value < c[minj].value) {
        minj = j;
      }
    }
    swap(c[i], c[minj]);
  }
  printArray(c, n);
}

bool isStable(struct Card c1[], struct Card c2[], int n) {
  for (int i = 0; i < n; ++i) {
    if (c1[i].suit != c2[i].suit) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  Card c1[n], c2[n];
  for (int i = 0; i < n; ++i) {
    cin >> c1[i].suit >> c1[i].value;
    c2[i].suit = c1[i].suit;
    c2[i].value = c1[i].value;
  }

  bubbleSort(c1, n);
  selectionSort(c2, n);
  bool res = isStable(c1, c2, n);
  if (res) cout << "Stable" << endl;
  else cout << "Not stable" << endl;

  return 0;
}
