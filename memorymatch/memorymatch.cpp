#include <bits/stdc++.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {

  int N, K;

  cin >> N >> K;

  map<string, int> count;
  vector<bool> bmap(N, false);

  int pairable = 0, known = 0, unknown = N;

  int l_idx, r_idx;
  string l_card, r_card;
  for (int i = 0; i < K; i++) {
    cin >> l_idx >> r_idx >> l_card >> r_card;

    // make sure map is initialized
    if (count.count(l_card) == 0)
      count[l_card] = 0;
    if (count.count(r_card) == 0)
      count[r_card] = 0;

    // check if left card has ever been revealed
    if (bmap[l_idx] == false) {
      unknown--;
      bmap[l_idx] = true;

      if (count[l_card] == 0) {
        // first known instance of card type
        known++;
      } else {
        // pairable
        known--;
        pairable++;
      }
      count[l_card]++;
    }

    // check if right card has ever been revealed
    if (bmap[r_idx] == false) {
      unknown--;
      bmap[r_idx] = true;

      if (count[r_card] == 0) {
        // first known instance of card type
        known++;
      } else {
        // pairable
        known--;
        pairable++;
      }
      count[r_card]++;
    }

    // if a pair
    if (l_card == r_card) {
      pairable--;
    }
  }

  int total_points = pairable;
  if (unknown == 0) {
    // known should be size 0
  } else if (known == 0 && unknown <= 2) {
    total_points++;
  } else if (known == unknown) {
    total_points += known;
  }
  // cout << pairable << endl << known << endl << unknown << endl;
  cout << total_points << endl;

  return 0;
}
