#include <stdio.h>
#include <string.h>

int dp[20][2][2];

// 数位DP，定义函数统计 [0, num] 内不包含数字4的数的个数
int digitDP(int pos, int isLimit, int has4, char* digits) {
    if (pos == -1) return has4 ? 0 : 1;  // 如果所有位都处理完毕，且没有出现4，返回1
    if (!isLimit && dp[pos][isLimit][has4] != -1) return dp[pos][isLimit][has4];

    int res = 0;
    int up = isLimit ? digits[pos] - '0' : 9;  // 根据isLimit确定当前位的最大值
    for (int digit = 0; digit <= up; ++digit) {
        res += digitDP(pos - 1, isLimit && (digit == up), has4 || (digit == 4), digits);
    }

    if (!isLimit) dp[pos][isLimit][has4] = res;  // 缓存结果以备下次使用
    return res;
}

// 计算 [0, x] 范围内不包含数字4的整数个数
int countNo4(int x) {
    char digits[20];
    sprintf(digits, "%d", x);
    int len = strlen(digits);

    // 从高位到低位进行数位DP计算
    for (int i = 0; i < len / 2; ++i) {
        char temp = digits[i];
        digits[i] = digits[len - 1 - i];
        digits[len - 1 - i] = temp;
    }

    memset(dp, -1, sizeof(dp));  // 重置缓存
    return digitDP(len - 1, 1, 0, digits);
}

// 计算 [L, R] 范围内不包含数字4的整数个数
int countRange(int L, int R) {
    return countNo4(R) - countNo4(L - 1);
}

int main() {
    int L = 50, R = 100;
    int result = countRange(L, R);
    printf("范围 [%d, %d] 内不包含数字4的整数个数为: %d\n", L, R, result);
    return 0;
}
