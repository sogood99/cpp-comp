#include <bits/stdc++.h>
#include <cmath>
#include <deque>
#include <vector>

using namespace std;

void shuffle(vector<short> &deck, string type) {
  int n = deck.size(), counter = 0;
  deque<int> l, r;

  if (type == "out") {
    for (int i = 0; i < ceil(n / 2.); i++) {
      l.push_back(deck[i]);
    }
    for (int i = ceil(n / 2.); i < n; i++) {
      r.push_back(deck[i]);
    }
  } else {
    for (int i = 0; i < floor(n / 2.); i++) {
      r.push_back(deck[i]);
    }
    for (int i = floor(n / 2.); i < n; i++) {
      l.push_back(deck[i]);
    }
  }

  while (!r.empty()) {
    deck[counter] = l.front();
    counter++;
    deck[counter] = r.front();
    counter++;

    l.pop_front();
    r.pop_front();
  }

  if (!l.empty()) {
    deck[counter] = l.front();
    counter++;
    l.pop_front();
  }
}

int main() {

  short n;
  string shuffle_type;
  cin >> n >> shuffle_type;

  vector<short> inital_deck(n), deck(n);
  for (int i = 0; i < n; i++) {
    inital_deck[i] = i;
    deck[i] = i;
  }

  int count = 1;
  shuffle(deck, shuffle_type);

  while (deck != inital_deck) {
    shuffle(deck, shuffle_type);
    count++;
  }
  cout << count << endl;

  return 0;
}
