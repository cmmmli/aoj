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
// typedef pair<int, int> P;
const ll MOD = 1e9 + 7;
const int INF = 1e9;

int dx4[4] = { 0, -1, 1, 0 };
int dy4[4] = { -1, 0, 0, 1 };
int dx8[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int dy8[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };

#define LEN 100005

struct P{
  char name[100];
  int t;
};

P Q[LEN];
int head, tail, n;

void enqueue(P x) {
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main() {
  int elaps = 0, c;
  int q;
  P u;
  scanf("%d %d", &n, &q);

  for (int i = 1; i <= n; ++i) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }
  head = 1, tail = n + 1;

  while (head != tail) {
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    elaps += c;
    if (u.t > 0) enqueue(u);
    else printf("%s %d\n", u.name, elaps);
  }

  return 0;
}
