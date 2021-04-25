class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        for (int i = 1; i < len; ++i) {
            left[i] = left[i-1] * A[i-1];
        }
        for (int j = len-2; j >= 0; --j) {
            right[j] = right[j+1] * A[j+1];
        }
        vector<int> B;
        B.reserve(len);  // reserve是容器预留空间(capacity)，在空间内不真正创建元素对象，所以在没有添加新对象之前，不能引用容器内的元素。加入新元素时，要调用push_back()/insert()函数。
        for (int i = 0; i < len; ++i) {
            B.push_back(left[i] * right[i]);
        }
        return B;
    }
};