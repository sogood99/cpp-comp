#include <bits/stdc++.h>
#include <vector>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class Rect {
public:
  Rect() {}
  Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
  int x = -1, y = -1, w = -1, h = -1;
};

inline bool onLeft(const Rect &a, const Rect &b) { return (a.x + a.w <= b.x); }

inline bool onTop(const Rect &a, const Rect &b) { return a.y + a.h <= b.y; }

bool intersect(const Rect &a, const Rect &b) {
  return !onLeft(a, b) && !onLeft(b, a) && !onTop(a, b) && !onTop(b, a);
}

inline int area(const Rect &a) { return a.w * a.h; }

vector<Rect> vr, cv;

int maxA = 0, currentA = 0;

void backtrack(int j) {
  if (j >= vr.size()) {
    maxA = max(maxA, currentA);
    return;
  }

  bool insec = false;
  for (Rect r : cv) {
    if (intersect(r, vr[j])) {
      insec = true;
      break;
    }
  }

  if (!insec) {
    currentA += area(vr[j]);
    cv.push_back(vr[j]);
    backtrack(j + 1);
    currentA -= area(vr[j]);
    cv.pop_back();
  }

  backtrack(j + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int x, y, w, h;
  while (1) {
    maxA = currentA = 0;
    vr.resize(0);
    cv.resize(0);

    cin >> N;
    if (N == 0)
      break;
    while (N--) {
      cin >> w >> h >> x >> y;
      vr.push_back(Rect(x, y, w, h));
    }

    backtrack(0);
    cout << maxA << endl;
  }

  return 0;
}
