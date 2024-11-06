
// bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
//     if (target == 0)
//         return true;
//     if (ind == 0)
//         return arr[0] == target;
//     if (dp[ind][target] != -1)
//         return dp[ind][target];
//     bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
//     bool taken = false;
//     if (arr[ind] <= target)
//         taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
//     return dp[ind][target] = notTaken || taken;
// }

// bool canPartition(int n, vector<int>& arr) {
//     int totSum = 0;
//     for (int i = 0; i < n; i++) {
//         totSum += arr[i];
//     }
//     if (totSum % 2 == 1)
//         return false;
//     else {
//         int k = totSum / 2;
//         vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//         return subsetSumUtil(n - 1, k, arr, dp);
//     }
// }


class Solution {
    bool subsetSum(int n, int k, vector<int> &nums) {
        vector<bool> prev(k + 1, false), cur(k + 1, false);
        prev[0] = cur[0] = true;
        
        if (nums[0] <= k) prev[nums[0]] = true;  // Initialize only if within bounds
        
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (nums[ind] <= target) take = prev[target - nums[ind]];
                
                cur[target] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

public:
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) totSum += nums[i];
        
        if (totSum % 2 != 0) return false;  // If total sum is odd...can't partition equally
        
        int target = totSum / 2;
        return subsetSum(n, target, nums);
    }
};
