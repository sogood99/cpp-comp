#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

#define LSOne(S) ((S) & -(S))
#define MAXDATE 100112018
#define ISLP(y) ((y % 400 == 0) || (y % 100 != 0) && (y % 4 == 0))

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

vector<int> day31 = {1, 3, 5, 7, 8, 10, 12};
vector<int> day30 = {4, 6, 9, 11};

int mindate = MAXDATE, cnt = 0;

int s_to_date(string s) {
  int day = atoi(s.substr(0, 2).c_str());
  int month = atoi(s.substr(2, 2).c_str());
  int year = atoi(s.substr(4, 4).c_str());

  return year * 10000 + month * 100 + day;
}

bool isvaliddate(int year, int month, int day) {
  if (year < 2000) {
    return false;
  }

  if (month > 12 || month < 1 || day > 31 || day < 1) {
    return false;
  }
  if (find(day30.begin(), day30.end(), month) != day30.end()) {
    if (day > 30) {
      return false;
    }
  }

  if (month == 2) {
    if (ISLP(year)) {
      if (day > 29) {
        return false;
      }
    } else {
      if (day > 28) {
        return false;
      }
    }
  }

  return true;
}

void permute(string &s) {

  sort(s.begin(), s.end());
  do {
    int dt = s_to_date(s);
    int year = dt / 10000;
    int month = (dt / 100) % 100;
    int day = dt % 100;
    if (isvaliddate(year, month, day)) {
      mindate = min(dt, mindate);
      cnt++;
    }
  } while (next_permutation(s.begin(), s.end()));
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int T;
  cin >> T;
  getchar();
  while (T--) {
    string d, m, y;
    cin >> d >> m >> y;
    string s = d + m + y;
    permute(s);
    cout << cnt;
    if (cnt != 0) {
      int year = mindate / 10000;
      int month = (mindate / 100) % 100;
      int day = mindate % 100;
      printf(" %02d %02d %04d", day, month, year);
    }
    cout << endl;
    cnt = 0;
    mindate = MAXDATE;
  }

  return 0;
}
