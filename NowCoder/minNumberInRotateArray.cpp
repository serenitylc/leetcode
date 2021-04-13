class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) return 0;
        int left = 0, right = rotateArray.size() - 1;
        while (left < right) {
            if (rotateArray[left] < rotateArray[right]) break;
            int mid = left + (right - left) / 2;
            if (rotateArray[left] < rotateArray[mid])
                left = mid + 1;
            else if (rotateArray[left] > rotateArray[mid])
                right = mid;
            else
                ++left;
        }
        return rotateArray[left];
    }
};