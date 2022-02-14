//uva11078
#include <iostream>

using namespace std;

int counter = 0;

int main() {
  int i, times, grade_num, grade, max_grade, ans;
  cin >> times;
  while (times > 0) {
    cin >> grade_num;
    cin >> max_grade;
    ans = -1000000;
    for (i = 1; i < grade_num; i++) {
      cin >> grade;
      if (max_grade - grade > ans)
        ans = max_grade - grade;
      if (max_grade < grade)
        max_grade = grade;
        counter++;
    }
    cout << ans << endl;
    times--;
  }

  cout << "Counter: " << counter << endl;
  return 0;
}