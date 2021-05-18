/* 给定一个无序数组arr，求出需要排序的最短子数组的长度，对子数组排序后能使得整个数组有序，即为需要排序的数组。
例如：arr=[1,5,3,4,2,6,7]返回4，因为只有[5,3,4,2]需要排序。 */

int getMinLength(int *arr) {
    if (!arr || arr.size() < 2) return 0;
    int minValue = arr[arr.size() - 1];
    int noMinIndex = -1;
    for (int i = arr.size() - 2; i != -1; i--) {
        if (arr[i] > minValue) {
            noMinIndex = i;
        } else {
            minValue = min(minValue, arr[i]);
        }
    }
    if (noMinIndex == -1) return 0;
    int maxValue = arr[0];
    int noMaxIndex = -1;
    for (int i = 1; i != arr.size(); i++) {
        if (arr[i] < maxValue) {
            noMaxIndex = i;
        } else {
            maxValue = max(maxValue, arr[i]);
        }
    }
    return noMaxIndex - noMinIndex + 1;
}