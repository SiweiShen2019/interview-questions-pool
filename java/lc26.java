import java.util.*;

public class lc26 {
  public static int removeDuplicates(int[] nums) {
    int n = nums.length;
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

  public static void main(String[] args) {
    int[] test = {0,0,1,1,1,2,2,3,3,4};
    int result = removeDuplicates(test);
    System.out.println(Arrays.toString(test));
    System.out.println(result);
  }
}
