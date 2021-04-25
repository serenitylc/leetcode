class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int res = 0;
        bool swapped;
        for (int i = 1; i < data.size(); ++i) {
            swapped = false;
            for (int j = 1; j < data.size() - i + 1; ++j) {
                if (data[j] < data[j-1]) {
                    swap(data[j], data[j-1]);
                    res++;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        return res %= kmod;
    }
};  // 冒泡排序对于10^5的数据超时

class Solution {
public:
    int res = 0;
    int InversePairs(vector<int> data) {
        int len = data.size();
        vector<int> temp(len);
        mergesort(data, temp, 0, len-1);
        return res;
    }
    void mergesort(vector<int>& data, vector<int>& temp, int begin, int end) {
        if (begin < end) {
            int mid = begin + (end - begin) / 2;
            mergesort(data, temp, begin, mid);
            mergesort(data, temp, mid+1, end);
            merge(data, temp, begin, mid, end);
          }
    }
    void merge(vector<int>& data, vector<int>& temp, int begin, int mid, int end) {
        int i = begin, j = mid+1, k = begin;
        while (i <= mid && j <= end) {
            if (data[i] < data[j]) {
                temp[k++] = data[i++];
            } else {
                res = (res + mid - i + 1) % 1000000007;
                temp[k++] = data[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = data[i++];
        }
        while (j <= end) {
            temp[k++] = data[j++];
        }
        for (int i = begin; i <= end; ++i) {
            data[i] = temp[i];
        }
    }

};