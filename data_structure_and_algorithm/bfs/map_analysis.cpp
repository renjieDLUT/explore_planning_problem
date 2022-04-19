#include <iostream>
#include <queue>
#include <vector>

#include "math.h"
using std::vector, std::queue, std::cout;
struct Node {
  int i;
  int j;
  int step;
};
int bfs(vector<vector<int>>& grid, int i, int j) {
  Node start{i, j, 0};
  vector<vector<int>> flag(grid.size(), vector<int>(grid[0].size(), 0));
  queue<Node> q;
  q.push(start);
  flag[i][j] = true;
  while (!q.empty()) {
    Node n = q.front();
    q.pop();
    if (n.i - 1 >= 0 && !flag[n.i - 1][n.j]) {
      if (grid[n.i - 1][n.j] == 0) {
        q.push(Node{n.i - 1, n.j, n.step + 1});
        flag[n.i - 1][n.j] = true;
      } else
        return n.step + 1;
    }
    if (n.i + 1 < grid.size() && !flag[n.i + 1][n.j]) {
      if (grid[n.i + 1][n.j] == 0) {
        q.push(Node{n.i + 1, j, n.step + 1});
        flag[n.i + 1][j] = true;
      } else
        return n.step + 1;
    }
    if (n.j - 1 >= 0 && !flag[n.i][n.j - 1]) {
      if (grid[n.i][n.j - 1] == 0) {
        q.push(Node{n.i, n.j - 1, n.step + 1});
        flag[n.i][n.j - 1] = true;
      } else
        return n.step + 1;
    }
    if (n.j + 1 < grid[0].size() && !flag[n.i][n.j + 1]) {
      if (grid[n.i][n.j + 1] == 0) {
        q.push(Node{n.i, n.j + 1, n.step + 1});
        flag[n.i][n.j + 1] = true;
      } else
        return n.step + 1;
    }
  }
  return -1;
}
int maxDistance(vector<vector<int>>& grid) {
  int res = -1;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 0) res = std::max(res, bfs(grid, i, j));
    }
  }
  return res;
}

int main() {
  vector<vector<int>> grid;
  grid.push_back(vector<int>{1, 0, 1});
  grid.push_back(vector<int>{0, 0, 0});
  grid.push_back(vector<int>{1, 0, 1});
  cout << maxDistance(grid);
}