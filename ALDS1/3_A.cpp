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

int top, S[1000];

void push(int x) {
  S[++top] = x;
}

int pop () {
  --top;
  return S[top + 1];
}

int main() {
  int a, b;
  top = 0;
  char s[100];
  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      a = pop();
      b = pop();
      push(a + b);
    } else if (s[0] == '-') {
      a = pop();
      b = pop();
      push(b - a);
    } else if (s[0] == '*') {
      a = pop();
      b = pop();
      push(b * a);
    } else {
      push(atoi(s));
    }
  }

  cout << pop() << endl;
  return 0;
}
