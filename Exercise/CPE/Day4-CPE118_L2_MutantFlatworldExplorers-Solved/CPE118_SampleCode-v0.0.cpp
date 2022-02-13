//uva118
#include <iostream>

using namespace std;

int main() {
  bool scent[55][55] = {0};
  int bound_x, bound_y;
  int init_x, init_y;
  char init_ori;
  int curr_x, curr_y, curr_ori = 0;
  bool if_lost = false;
  string ins;

  cin >> bound_x >> bound_y;
  while (cin >> init_x >> init_y >> init_ori) {
    cin >> ins;
    curr_x = init_x;
    curr_y = init_y;
    if_lost = false;
    switch (init_ori) {
    case 'N':
      curr_ori = 0;
      break;
    case 'E':
      curr_ori = 1;
      break;
    case 'S':
      curr_ori = 2;
      break;
    case 'W':
      curr_ori = 3;
      break;
    }

    for (auto i : ins) {
      int next_x = curr_x, next_y = curr_y;

      if (i == 'L') {
        curr_ori = (curr_ori + 3) % 4;
      } else if (i == 'R') {
        curr_ori = (curr_ori + 1) % 4;
      } else if (i == 'F') {
        switch (curr_ori) {
        case 0:
          next_y = curr_y + 1;
          break;
        case 1:
          next_x = curr_x + 1;
          break;
        case 2:
          next_y = curr_y - 1;
          break;
        case 3:
          next_x = curr_x - 1;
          break;
        }
        if (next_x < 0 || next_x > bound_x || next_y < 0 || next_y > bound_y) {
          if (scent[curr_x][curr_y])
            continue;
          else {
            if_lost = true;
            scent[curr_x][curr_y] = true;
            break;
          }
        }
        curr_x = next_x;
        curr_y = next_y;
      }
    }
    cout << curr_x << " " << curr_y << " ";
    switch (curr_ori) {
    case 0:
      cout << "N";
      break;
    case 1:
      cout << "E";
      break;
    case 2:
      cout << "S";
      break;
    case 3:
      cout << "W";
      break;
    }
    if (if_lost)
      cout << " LOST";
    cout << endl;
  }
  return 0;
}