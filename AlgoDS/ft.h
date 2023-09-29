
#ifndef FENWICK_TREE
#define FENWICK_TREE
#include <vector>
#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;

class FenwickTree {
private:
  vll ft;

public:
  FenwickTree(int m) { ft.assign(m + 1, 0); }
  void build(const vll &f) {
    int m = f.size() - 1;
    ft.assign(m + 1, 0);
    for (int i = 1; i <= m; i++) {
      ft[i] += f[i];
      if (i + LSOne(i) <= m) {
        ft[i + LSOne(i)] += ft[i];
      }
    }
  }
  FenwickTree(const vll &f) { build(f); }
  ll rsq(int j) {
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];

    return sum;
  }
  ll rsq(int i, int j) { return rsq(j) - rsq(i); }
  void update(int i, int v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
  int select(ll k) {
    int lo = 1, hi = ft.size() - 1;

    for (int i = 0; i < 30; i++) {
      int mid = (lo + hi) / 2;
      (rsq(1, mid) < k) ? lo = mid : hi = mid;
    }
    return hi;
  }
};

class RUPQ {
private:
  FenwickTree ft;

public:
  RUPQ(int m) : ft(FenwickTree(m)) {}
  void range_update(int ui, int uj, int v) {
    ft.update(ui, v);
    ft.update(uj + 1, -v);
  }
  ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
private:
  RUPQ rupq;
  FenwickTree purq;

public:
  RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}
  void range_update(int ui, int uj, int v) {
    rupq.range_update(ui, uj, v);
    purq.update(ui, v * (ui - 1));
    purq.update(uj + 1, -v * uj);
  }
  ll rsq(int j) { return rupq.point_query(j) * j - purq.rsq(j); }
  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};

#endif
