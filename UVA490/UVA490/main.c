//
//  main.c
//  UVA490
//
//  Created by Leo Ho on 2022/3/22.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char line[101][101];
    int num = 0; // 行數
    int length[101]; // 儲存各行的長度
    int maxLen = 0; // 儲存最長的長度
    int upBound; // 字串下限

    int i, j;

    while (gets(line[num])) {
        length[num] = (int)strlen(line[num]); // 儲存該筆資料的長度
        if (length[num] > maxLen) {
            maxLen = length[num]; // 尋找最長的字串長度 maxLen
        }
        num++;
    }

    // 將各行字串順時針轉 90 度輸出
    for (i = 0; i < maxLen; i++) {
        // 找出第 i 個字元，印到那一行 (upBound) 就結束
        upBound = 0;
        while (i >= length[upBound]) upBound++;
        for (j = num-1; j >= upBound; j--) {
            if (j < length[j]) {
                putchar(line[j][i]); // 如果還沒超過字串尾巴的話，就直接輸出
            } else {
                putchar(' '); // 如果超出字串尾巴的話，補一個空格
            }
        }
        printf("\n");
    }
    return 0;
}
