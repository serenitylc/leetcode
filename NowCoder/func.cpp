
vector<int> func(vector<int> input, int min, int max) {
    vector<int> res;
    int totalSum = 0;
    int totalMult = 1;
    int a, b, tmp;
    for (int i = min; i <= max; ++i) {
        totalSum += input[i];
        totalMult *= input[i];
    }
    for (int i = 0; i < inupt.size(); ++i) {
        tmp *= i;
    }

    int aSUMB = totalSum - (min + max) * (max - min) / 2;
    int aMultB = totalMult - tmp;
    // pair({})¡£¡£¡£
}