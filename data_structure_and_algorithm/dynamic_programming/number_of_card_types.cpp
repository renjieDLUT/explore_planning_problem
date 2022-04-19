/**
 * @file   number_of_card_types.cpp
 * @author renjie (renjie_dlut2016@163.com)
 * @brief   计算牌型数量，从13种牌型（每种牌型有4种花色）中选择13张牌，
 *          如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢
 * @version 0.1
 * @date 2022-04-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
using std::vector;

int foo() {
  // 从前j种牌型中，拿到i张牌的组合数
  vector<vector<int>> dp(14, vector<int>(13, 0));

  dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = dp[4][0] = 1;
  for (int j = 0; j < 13; j++) dp[0][j] = 1;

  for (int i = 1; i < 14; i++) {
    for (int j = 1; j < 13; j++) {
      if (j > 0) dp[i][j] += dp[i][j - 1];
      if (i >= 1) dp[i][j] += dp[i - 1][j - 1];
      if (i >= 2) dp[i][j] += dp[i - 2][j - 1];
      if (i >= 3) dp[i][j] += dp[i - 3][j - 1];
      if (i >= 4) dp[i][j] += dp[i - 4][j - 1];
    }
  }
  return dp.back().back();
}

int sum = 0;
int count = 0;
void dfs(int depth) {
  if (depth == 13 && sum == 13) {
    count++;
    return;
  }
  if (depth >= 13) return;

  for (int i = 0; i <= 4; i++) {
    sum += i;
    dfs(++depth);
    sum -= i;
    depth--;
  }
}

int main() {
  std::cout << foo() << std::endl;
  dfs(0);
  std::cout << count;
}