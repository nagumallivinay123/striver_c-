import java.util.Arrays;
import java.util.PriorityQueue;

public class TestTaker {
    public static Integer[] getFinalState(Integer[] nums, Integer k, Integer multiplier) {
        final int MOD = (int)1e9 + 7;

        // Min-heap to store elements as (value, index) pairs
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        // Insert all elements with their indices into the min-heap
        for (int i = 0; i < nums.length; i++) {
            minHeap.offer(new int[]{nums[i], i});
        }

        // Perform k operations
        for (int i = 0; i < k; i++) {
            // Extract the minimum element from the heap
            int[] minElement = minHeap.poll();
            int minValue = minElement[0];
            int index = minElement[1];

            // Multiply the minimum value by the multiplier
            nums[index] = minValue * multiplier;

            // Add the updated element back into the heap
            minHeap.offer(new int[]{nums[index], index});
        }

        // Apply modulo to each element
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] % MOD;
        }

        return nums;
    }

    public static void main(String[] args) {
        Integer[] nums = {2, 1, 3, 5, 6};
        Integer k = 5;
        Integer multiplier = 2;

        Integer[] result = getFinalState(nums, k, multiplier);
        System.out.println(Arrays.toString(result));
    }
}
