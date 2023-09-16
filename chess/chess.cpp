#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

enum Pos { TOP, LEFT, RIGHT, BOT };

void printii(ii l) {
  cout << (char)(l.first - 1 + 'A') << " " << (char)(l.second - 1 + '1');
}

ii translate(string loc_x, string loc_y) {
  // translate from [A-H][1-8] to (a,b)

  int x = loc_x[0] - 'A' + 1;
  int y = loc_y[0] - '1' + 1;

  return ii(x, y);
}

ii intersect_pn(ii l, ii r) {
  int x = (l.first - l.second + r.first + r.second) / 2;
  int y = (-l.first + l.second + r.first + r.second) / 2;
  return ii(x, y);
}

ii intersect_pn_edge(ii l, Pos p) {
  int a = l.first, b = l.second;
  switch (p) {
  case TOP:
    return ii(8 + a - b, 8);
  case BOT:
    return ii(1 + a - b, 1);
  case LEFT:
    return ii(1, 1 - a + b);
  case RIGHT:
    return ii(8, 8 - a + b);
  default:
    cout << "unknonwn";
    return ii(0, 0);
  }
}

ii intersect_ny(ii l, ii r) {
  int x = (l.first + l.second + r.first - r.second) / 2;
  int y = (l.first + l.second - r.first + r.second) / 2;
  return ii(x, y);
}

ii intersect_ny_edge(ii l, Pos p) {
  int a = l.first, b = l.second;
  switch (p) {
  case TOP:
    return ii(a + b - 8, 8);
  case BOT:
    return ii(a + b - 1, 1);
  case LEFT:
    return ii(1, -(1 - a) + b);
  case RIGHT:
    return ii(8, -(8 - a) + b);
  default:
    cout << "unknonwn";
    return ii(0, 0);
  }
}

void findpath(ii l, ii r) {

  if ((l.first + l.second + r.first + r.second) % 2 != 0) {
    cout << "Impossible" << endl;
    return;
  }

  queue<ii> q;
  q.push(l);

  int iter = 0, count = 0;
  while (l != r) {
    // cout << "Iter: " << iter << endl;
    ii res = ii(0, 0);
    if (iter % 2 == 0) {
      res = intersect_pn(l, r);
      int res_x = res.first, res_y = res.second;
      if (res_x < 1) {
        res = intersect_pn_edge(l, LEFT);
      } else if (res_x > 8) {
        res = intersect_pn_edge(l, RIGHT);
      } else if (res_y < 1) {
        res = intersect_pn_edge(l, BOT);
      } else if (res_y > 8) {
        res = intersect_pn_edge(l, TOP);
      }
    } else {
      res = intersect_ny(l, r);

      int res_x = res.first, res_y = res.second;
      if (res_x < 1) {
        res = intersect_ny_edge(l, LEFT);
      } else if (res_x > 8) {
        res = intersect_ny_edge(l, RIGHT);
      } else if (res_y < 1) {
        res = intersect_ny_edge(l, BOT);
      } else if (res_y > 8) {
        res = intersect_ny_edge(l, TOP);
      }
    }
    // printii(res);

    if (res != q.back()) {
      q.push(res);
      count++;
      l = res;
    }
    iter++;
  }

  cout << count << " ";
  for (int i = 0; i < count; i++) {
    printii(q.front());
    q.pop();
    cout << " ";
  }
  printii(q.front());
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    string src_x, src_y, dst_x, dst_y;
    cin >> src_x >> src_y >> dst_x >> dst_y;
    ii src = translate(src_x, src_y), dst = translate(dst_x, dst_y);
    findpath(src, dst);
  }

  return 0;
}
