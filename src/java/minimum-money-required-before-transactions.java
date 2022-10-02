class Solution {
    public long minimumMoney(int[][] transactions) {
        long i = 0;
        long j = sum(transactions)+1;
        long ans = j;
        
        Arrays.sort(transactions, new Comparator<int[]> () {
            @Override
            public int compare (int[] a, int[] b) {
                // if (a[0] != b[0]) {
                //     return a[1] - b[1];
                // }
                // else {
                //     return b[0] - a[0];
                // }
                
                // return (a[1] - a[0]) - (b[1] - b[0]);
                if (a[0] < a[1] && b[0] < b[1]) {
                    return b[0] - a[0];
                }
                else if (b[0] < b[1]) {
                    return Integer.MIN_VALUE;
                }
                else if (a[0] < a[1]) {
                    return Integer.MAX_VALUE;
                }
                else if (a[1] == b[1]) {
                    return b[0] - a[0];
                }
                else {
                    return a[1] - b[1];
                }
            }
        });
        // print(transactions);
        while (i <= j) {
            long m = i + (j-i)/2;
            if (ans (transactions, m)) {
                ans = m;
                j = m-1;
            }
            else {
                i = m+1;
            }
        }
        return ans;
    }
    private boolean ans (int[][] trans, long cost) {
        for (int[] arr: trans) {
            if ( cost < arr[0]) {
                return false;
            }
            else {
                cost = cost - arr[0] + arr[1];
            }
        }
        return true;
    }
    private void print (int[][] arr) {
        String s = "";
        for (int[] a: arr) {
            s += a[0]+"-"+a[1]+" ";
        }
        System.out.println(s);
    }
    private long sum (int[][] arr) {
        long sum = 0;
        for (int[] a: arr) {
            sum += a[0];
        }
        return sum;
    }
}
// Submission Link: https://leetcode.com/problems/minimum-money-required-before-transactions/submissions/802093285/