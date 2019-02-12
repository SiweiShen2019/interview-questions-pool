// This is the brute force solution in O(N^2).
// TODO: Update the smart O(N) solution.
class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    vector<int> diff (len, 0);
    for (int i = 0; i < len; ++i) {
      diff[i] = gas[i] - cost[i];
    }
    for (int j = 0; j < len; ++j) {
      if (diff[j] < 0)
        continue;
      int sum = 0;
      bool find = true;
      for (int k = j; k < j + len; ++k) {
        int real_pos = k % len;
        sum += diff[real_pos];
        if (sum < 0) {
          find = false;
          break;
        }
      }
      if (find)
        return j;
    }
    return -1;
  }
}
