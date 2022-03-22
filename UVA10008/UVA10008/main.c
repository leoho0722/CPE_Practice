//
//  main.c
//  UVA10008
//
//  Created by Leo Ho on 2022/3/22.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int testCase; // 輸入的測資筆數
    char line[1000];
    char c; // 出現的字母
    char freq; // 出現頻率
    int count[127] = {0}; // 儲存每個字母出現的註標
    
    int i, j;
    int max = 0;
    
    scanf("%d\n", &testCase);
    
    for (i = 0; i < testCase; i++) {
        gets(line); // 一次讀取一行
        for (j = 0; j < strlen(line); j++) {
            // 統計每個字元的頻率
            c = line[j]; // 每個字元逐一取出來看
            if (c >= 'a' && c <= 'z') {
                c -= 32; // 將小寫字母轉大寫字母
            }
            if (c >= 'A' && c <= 'Z') {
                ++count[c]; // 大寫字母，累計字元出現的次數，以 ASCII 做註標
            }
        }
    }
    for (c = 'A'; c <= 'Z'; c++) {
        if (count[c] > max) {
            max = count[c]; // 找到最大頻率 max
        }
    }
    freq = max;
    while (freq > 0) {
        max = 0; // 先將下一次輸出的最大頻率歸 0
        for (c = 'A'; c <= 'Z'; c++) {
            if (count[c] == freq) {
                printf("%c %d\n", c, freq);
            } else if (count[c] < freq) {
                if (count[c] > max) {
                    max = count[c]; // 找到次一個的最大頻率 max
                }
            }
        }
        freq = max;
    }
    return 0;
}
