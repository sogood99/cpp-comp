#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

int conv(const vii &img, const vii &k, int x, int y) {
  int N = k.size(), M = k[0].size();

  int s = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      s += img[x + i][y + j] * k[N - i - 1][M - j - 1];
    }
  }
  return s;
}

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;

  vii img(H, vi(W)), k(N, vi(M));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> img[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> k[i][j];
    }
  }

  int res;
  for (int i = 0; i < H - N + 1; i++) {
    for (int j = 0; j < W - M + 1; j++) {
      res = conv(img, k, i, j);
      cout << res << " ";
    }
    cout << endl;
  }

  return 0;
}
