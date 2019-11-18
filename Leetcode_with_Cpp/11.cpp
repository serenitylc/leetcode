class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) 
            return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) 
                ++i;
            else 
                --j;
        }
        return res;
    }
};
// 长度从n依次下降，通过比较左右挡板长度，每次保留较长者，减小搜索空间


// 采用冒泡排序思想，两两比较取最大值
// int area(int a, int b, int h1, int h2)
// {
//     int h = (h2 > h1 ? h1 : h2);
//     int result = (b - a) * h;
//     return result;
// }

// int maxArea(int* height, int heightSize){
//     int max = 0;
//     int temp = 0;
//     for (int i = 0; i < heightSize - 1; i++) {
//         for (int j = i + 1; j < heightSize; j++) {
//             temp = area(i + 1, j + 1, height[i], height[j]);
//             max = max > temp ? max : temp;
//         }
//     }
//     return max;
// }