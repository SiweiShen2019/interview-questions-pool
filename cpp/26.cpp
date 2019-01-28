#include <cstdio>
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

int main() {
  vector<int> test = {0,0,1,1,1,2,2,3,3,4};
  int result = removeDuplicates(test);
  printf("%d\n", result);
  for (auto it = test.begin(); it < test.end(); it++)
    printf("%d ", *it);
  printf("\n");
  return 0;
}
