class Solution {
    public int search(int[] nums, int target) {
        int peek = peekIndex(nums);
        System.out.println(peek);
        int ans = Math.max(search(nums, 0, peek, target), search(nums, peek+1, nums.length-1, target));
        
        return ans;
    }
    private int search (int[] nums, int i, int j, int target) {
        while (i <= j) {
            int m = i +(j-i)/2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                j = m-1;
            }
            else {
                i = m+1;
            }
        }
        return -1;
    }
    private int peekIndex (int[] nums) {
        int n = nums.length;
        int i = 0;
        int j = n-1;
        int ans = -1;
        if (n <= 1) {
            return 0;
        }
        else if (n == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            }
            else {
                return 1;
            }
        }
        while (i <= j) {
            System.out.println(i + " " +j);
            int m = i + (j-i)/2;
            if (i == j) {
                ans = m;
                break;
            }
            else if (j-i == 1) {
                if (nums[i] > nums[j]) {
                    ans = i;
                }
                else {
                    ans = j;
                }
                break;
            }
            else if (nums[m] > nums[i]) {
                // potentian peek
                if (m != n-1) {
                    if (nums[m] > nums[m+1]) {
                        ans = m;
                        break;
                    }
                }
                else {
                    ans = m;
                    break;
                }
                
                i = m+1;
            }
            else {
                j = m-1;
            }
        }
        return ans;
    }
}