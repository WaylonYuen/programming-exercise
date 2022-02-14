//uva1260
#include <iostream>

using namespace std;

int main() {
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    int A[1005] = {0};
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      cin >> A[i];
      for (int j = 0; j < i; ++j) {
        if (A[j] <= A[i]) {
          ++ans;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}