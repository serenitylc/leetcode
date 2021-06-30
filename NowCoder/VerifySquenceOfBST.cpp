class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
    }
    bool VerifySquenceOfBST(vector<int>& sequence, int left, int right) {
        if (left >= right) return true;
        int l = left;
        int root = sequence[right];
        while (sequence[l] < root) ++l;
        int tmp = l;
        while (tmp < right) {
            if (sequence[tmp] <= root) return false;
            ++tmp;
        }
        return VerifySquenceOfBST(sequence, left, l - 1) && VerifySquenceOfBST(sequence, l, right - 1);
    }
};