// ==========================================================
// 43. Multiply Strings
// Difficulty : Medium
// Language   : C
// Solution   : #1
// Runtime    : 0 ms (Beats 100%)
// Memory     : 9.3 MB (Beats 6%)
// Link       : https://leetcode.com/problems/multiply-strings/
// ==========================================================

char* multiply(char* num1, char* num2) {    
    int i, i1, j = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result[205] = {0};
    static char str[205];
    int temp, temp1;

    if ((len1 == 1 && num1[0] == '0') ||
        (len2 == 1 && num2[0] == '0')) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    for (i = len1 - 1; i >= 0; i--) {
        for (i1 = len2 - 1; i1 >= 0; i1--) {
            temp = (num1[i] - '0') * (num2[i1] - '0');
            temp1 = temp + result[i + i1 + 1];

            result[i + i1 + 1] = temp1 % 10;
            result[i + i1] += temp1 / 10;
        }
    }

    i = 0;

    while (i < len1 + len2 && result[i] == 0) {
        i++;
    }

    while (i < len1 + len2) {
        str[j] = result[i] + '0';
        j++;
        i++;
    }

    str[j] = '\0';

    return str;

}
