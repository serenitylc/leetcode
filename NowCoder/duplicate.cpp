class Solution {
public:
    int duplicate(vector<int>& numbers) {
        for (int i = 0; i < numbers.size(); ++i) {
            while (i != numbers[i]) {
                if (numbers[i] == numbers[numbers[i]]) return numbers[i];
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return -1;
    }
};