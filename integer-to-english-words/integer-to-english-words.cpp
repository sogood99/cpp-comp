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

class Solution {
public:
  string numberToWords(int num) {
    string wordResult = "";

    if (num == 0) {
      return "Zero";
    }

    const static vector<string> ONES = {
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    const static vector<string> TENS = {"",       "Ten",   "Twenty", "Thirty",
                                        "Forty",  "Fifty", "Sixty",  "Seventy",
                                        "Eighty", "Ninety"};
    const static vector<string> THOUSANDS = {"", "Thousand", "Million",
                                             "Billion"};

    int d = 0;

    while (num) {
      int value = num % 1000;
      num /= 1000;

      string current = "";

      if (value / 100) {
        current = ONES[value / 100] + " Hundred";
      }

      int tens_value = value % 100;

      if (tens_value) {
        if (!current.empty())
          current += " ";
        if (tens_value < 20) {
          current += ONES[tens_value];
        } else {
          current += TENS[tens_value / 10];
          if (tens_value % 10) {
            current += " " + ONES[tens_value % 10];
          }
        }
      }

      if (value) {
        if (d == 0 || wordResult.empty()) {
          wordResult = current;
          if (d != 0) {
            wordResult += " " + THOUSANDS[d];
          }
        } else {
          wordResult = current + " " + THOUSANDS[d] + " " + wordResult;
        }
      }
      d++;
    }

    return wordResult;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
