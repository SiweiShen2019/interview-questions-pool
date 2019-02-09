class Solution {
public:
  void reverse(vector<int> &v, int start, int end) {
    while (start < end) {
      int tmp = v[start];
      v[start] = v[end];
      v[end] = tmp;
      ++start;
      --end;
    }
  }

  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    if (len <= 1 || k == 0)
      return;
    reverse(nums, 0, len - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, len - 1);
  }
};
