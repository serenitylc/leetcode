class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long n1 = LONG_MIN;  
        long n2 = LONG_MIN;
        long n3 = LONG_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > n1) {
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            }else if(nums[i] > n2 && nums[i] != n1) {
                n3 = n2;
                n2 = nums[i];
            }else if(nums[i] > n3 && nums[i] != n1 && nums[i] != n2) {
                n3 = nums[i];
            }
        }
        return n3 == LONG_MIN ? n1 : n3;
    }
};
// [1,2,-2147483648]

// 相比于C++98标准，C++11整型的最大改变就是多了 long long。
// 分为两种：long long 和 unsigned long long。在C++11中，标准要求 long long 整型可以在不同平台上有不同的长度，但至少有64位。
// 与 long long 整型相关的一共有3个：LONG_MIN、LONG_MAX、ULONG_MAX
// 分别代表平台上最小的 long long 值、最大的 long long 值，以及最大的 unsigned long long 值。