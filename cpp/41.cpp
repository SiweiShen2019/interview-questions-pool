#include <cstdio>
#include <vector>
using namespace std;

void move(vector<int> &nums, int pos, int val) {
  int len = nums.size();
  if (nums[pos] == val)
    nums[pos] = 0;
  if (val > len || val < 0)
    return;
  int new_pos = val - 1;
  int new_val = nums[new_pos];
  nums[new_pos] = val;
  if (new_val > 0 && new_val <= len)
    move(nums, new_pos, new_val);
}

int firstMissingPositive(vector<int>& nums) {
  int len = nums.size();
  if (len == 0)
    return 1;
  for (int i = 0; i < len; ++i) {
    int val = nums[i];
    if (val == i + 1)
      continue;
    else if (val > len || val < 0)
      nums[i] = 0;
    else
      move(nums, i, val);
  }
  for (int i = 0; i < len; ++i) {
    if (nums[i] == 0)
      return i + 1;
  }
  return len + 1;
}
