class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; //so yaha pe jab k=1 hoga toh subaaray hoga hi nhi kyunki 1 se chota 0 hota hai...;)
        int n=nums.size();
        int i=0, j=0;
        int product=1;
        int cnt=0;
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
           cnt+=j-i+1;
           j++;
        }
        return cnt;
    }
};

//// bhai mera sar dard ho rha hai mujhe samajh nhi aaraha hai mai kya karu dp ke code nhi hote  bye bye... shivangi dp padha do :) // 