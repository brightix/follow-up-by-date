int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i] += 1;
            break;
        } else {
            digits[i] = 0;
        }
    }
    if (digits[0] == 0) {
        int* temp = (int*)malloc((digitsSize + 1) * sizeof(int));
        temp[0] = 1;
        for (int i = 1; i < digitsSize + 1; i++) {
            temp[i] = 0;
        }
        *returnSize = digitsSize + 1;
        return temp;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}