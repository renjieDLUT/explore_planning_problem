#include <iostream>
#include <vector>
using std::vector;
bool check(vector<vector<int>>& data) {
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[0].size(); j++) {
      if (i + 1 <= 1) {
        if (data[i][j] >= data[i + 1][j]) return false;
      }
      if (j + 1 <= 4) {
        if (data[i][j] >= data[i][j + 1]) return false;
      }
    }
  }
  return true;
}

int foo() {
  vector<vector<int>> a(2, vector<int>(5, 0));
  a[0][0] = 1;
  a[1][4] = 10;
  vector<bool> flag(11, false);
  flag[1] = flag[10] = true;
  int sum = 0;
  for (int i_1 = 2; i_1 <= 9; i_1++) {
    flag[i_1] = true;
    for (int i_2 = 2; i_2 <= 9; i_2++) {
      if (flag[i_2] == true) continue;
      flag[i_2] = true;
      for (int i_3 = 2; i_3 <= 9; i_3++) {
        if (flag[i_3] == true) continue;
        flag[i_3] = true;
        for (int i_4 = 2; i_4 <= 9; i_4++) {
          if (flag[i_4] == true) continue;
          flag[i_4] = true;
          for (int i_5 = 2; i_5 <= 9; i_5++) {
            if (flag[i_5] == true) continue;
            flag[i_5] = true;
            for (int i_6 = 2; i_6 <= 9; i_6++) {
              if (flag[i_6] == true) continue;
              flag[i_6] = true;
              for (int i_7 = 2; i_7 <= 9; i_7++) {
                if (flag[i_7] == true) continue;
                flag[i_7] = true;
                for (int i_8 = 2; i_8 <= 9; i_8++) {
                  if (flag[i_8] == true) continue;
                  a[0][1] = i_1;
                  a[0][2] = i_2;
                  a[0][3] = i_3;
                  a[0][4] = i_4;
                  a[1][0] = i_5;
                  a[1][1] = i_6;
                  a[1][2] = i_7;
                  a[1][3] = i_8;
                  if (check(a)) sum++;
                }
                flag[i_7] = false;
              }
              flag[i_6] = false;
            }
            flag[i_5] = false;
          }
          flag[i_4] = false;
        }
        flag[i_3] = false;
      }
      flag[i_2] = false;
    }
    flag[i_1] = false;
  }
  return sum;
}

vector<bool> flag(11, false);
vector<vector<int>> a(2, vector<int>(5, 0));
int count = 0;

void dfs(int depth) {
  if (depth == 10 && check(a)) {
    count++;
  }
  if (depth >= 10) return;

  for (int i = 1; i <= 10; i++) {
    if (flag[i] == true) continue;
    flag[i] = true;
    int r = depth / 5;
    int c = depth % 5;
    a[r][c] = i;
    dfs(++depth);
    depth--;
    flag[i] = false;
  }
}

int main() {
  std::cout << foo() << std::endl;
  dfs(0);
  std::cout << count << std::endl;
}