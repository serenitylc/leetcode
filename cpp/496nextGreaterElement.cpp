class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    for (int k = j + 1; k < n2; k++)
                        if (nums2[k] > nums1[i]) { res[i] = nums2[k]; break; }
                    if (res[i] == 0) res[i] = -1;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1);
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < n1; i++) res[i] = mp[nums1[i]];
        return res;
    }
};