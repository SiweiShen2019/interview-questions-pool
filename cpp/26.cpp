#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  int n = nums.size();
  if (n <= 1)
    return n;
  int fstPtr = 0;
  int sndPtr = 0;
  while (++sndPtr < n) {
    if (nums[fstPtr] == nums[sndPtr])
      continue;
    nums[++fstPtr] = nums[sndPtr];
  }
  return fstPtr + 1;
}
