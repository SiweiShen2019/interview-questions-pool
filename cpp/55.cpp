class Solution {
public:
  bool canJump(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) // edge case
      return false;
    vector<bool> reach(len, false);
    reach[len - 1] = true;
    for (int i = len - 2; i >= 0; --i) {
      for (int j = 0; j <= nums[i] && i + j < len; ++j) {
        if (reach[i + j]) {
          reach[i] = true;
          break;
        }
      }
    }
    return reach[0];
  }
};
