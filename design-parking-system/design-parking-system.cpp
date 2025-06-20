#include <bits/extc++.h>
#include <bits/stdc++.h>

#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ost;

// Shortcuts for "common" constants
const int INF = 1e9;   // 10^9 = 1B is < 2^31-1
const ll LLINF = 4e18; // 4*10^18 is < 2^63-1
const double EPS = 1e-9;

class ParkingSystem {
private:
  int s = 0, m = 0, b = 0;

public:
  ParkingSystem(int big, int medium, int small) : s(small), m(medium), b(big) {}

  bool addCar(int carType) {
    if (carType == 1) {
      if (b > 0) {
        b--;
        return true;
      }
    } else if (carType == 2) {
      if (m > 0) {
        m--;
        return true;
      }
    } else if (carType == 3) {
      if (s > 0) {
        s--;
        return true;
      }
    }

    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
