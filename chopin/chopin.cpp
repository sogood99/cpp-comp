#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, m;
  int c = 1;
  bool b = true;
  while (cin >> s >> m) {
    if (s == "A#") {
      s = "Bb";
    } else if (s == "Bb") {
      s = "A#";
    } else if (s == "C#") {
      s = "Db";
    } else if (s == "Db") {
      s = "C#";
    } else if (s == "D#") {
      s = "Eb";
    } else if (s == "Eb") {
      s = "D#";
    } else if (s == "F#") {
      s = "Gb";
    } else if (s == "Gb") {
      s = "F#";
    } else if (s == "G#") {
      s = "Ab";
    } else if (s == "Ab") {
      s = "G#";
    } else {
      b = false;
    }

    if (b) {
      printf("Case %d: %s %s\n", c, s.c_str(), m.c_str());
    } else {
      printf("Case %d: UNIQUE\n", c);
    }
    c++;
    b = true;
  }

  return 0;
}
