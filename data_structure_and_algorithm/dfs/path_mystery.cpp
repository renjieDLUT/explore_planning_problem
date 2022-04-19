#include <iostream>
#include <vector>
using std::cout, std::vector, std::endl;

bool check(vector<int> &north, vector<int> &west, vector<vector<bool>> &flag) {
  for (int i = 0; i < flag.size(); i++) {
    int count = 0;
    for (int j = 0; j < flag[0].size(); j++) {
      if (flag[i][j] == true) count++;
    }
    if (count != west[i]) return false;
  }

  for (int j = 0; j < flag[0].size(); j++) {
    int count = 0;
    for (int i = 0; i < flag.size(); i++) {
      if (flag[i][j] == true) count++;
    }
    if (count != north[j]) return false;
  }
  return true;
}

bool dfs(vector<int> &north, vector<int> &west, vector<vector<bool>> &flag,
         int step, int r, int c, vector<int> &res) {
  if (step == 0 && check(north, west, flag) == true && r == 3 && c == 3) {
    return true;
  }
  if (step == 0) return false;
  if (r - 1 >= 0 && flag[r - 1][c] == false) {
    flag[r - 1][c] = true;
    res.push_back((r - 1) * north.size() + c);
    if (dfs(north, west, flag, --step, r - 1, c, res)) return true;
    step++;
    res.pop_back();
    flag[r - 1][c] = false;
  }
  if (r + 1 < west.size() && flag[r + 1][c] == false) {
    flag[r + 1][c] = true;
    res.push_back((r + 1) * north.size() + c);
    if (dfs(north, west, flag, --step, r + 1, c, res)) return true;
    step++;
    res.pop_back();
    flag[r + 1][c] = false;
  }
  if (c - 1 >= 0 && flag[r][c - 1] == false) {
    flag[r][c - 1] = true;
    res.push_back((r)*north.size() + c - 1);
    if (dfs(north, west, flag, --step, r, c - 1, res)) return true;
    step++;
    res.pop_back();
    flag[r][c - 1] = false;
  }
  if (c + 1 < north.size() && flag[r][c + 1] == false) {
    flag[r][c + 1] = true;
    res.push_back((r)*north.size() + c + 1);
    if (dfs(north, west, flag, --step, r, c + 1, res)) return true;
    step++;
    res.pop_back();
    flag[r][c + 1] = false;
  }
  return false;
}

int foo(vector<int> &north, vector<int> &west, vector<vector<bool>> &flag,
        vector<int> &res) {
  int step = 0;
  for (auto p : north) step += p;
  flag[0][0] = true;
  return dfs(north, west, flag, --step, 0, 0, res);
}

int main() {
  vector<int> north{2, 4, 3, 4};
  vector<int> west{4, 3, 3, 3};
  int N = 4;
  vector<vector<bool>> flag(N, vector<bool>(N, false));
  vector<int> res;
  res.push_back(0);
  cout << foo(north, west, flag, res) << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}