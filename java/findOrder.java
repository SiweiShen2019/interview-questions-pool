import java.util.*;

public class findOrder {
  public static int[] findOrder1(int[] A) {
    int n = A.length;
    int[] reverse = new int[n];
    int[] ans = new int[n];
    
    int head = -1;
    for (int i = 0; i < n; i++) {
      if (A[i] == -1) {
        head = i;
        continue;
      }
      reverse[A[i]] = i;
    }
    
    int count = -1;
    while(++count < n) {
      ans[count] = head;
      head = reverse[count];
    }
    return ans;
  }

  public static void main(String[] args) {
    int[] test = {-1, 0, 1};
    int[] result = findOrder1(test);
    System.out.println(Arrays.toString(result));
  }
}
