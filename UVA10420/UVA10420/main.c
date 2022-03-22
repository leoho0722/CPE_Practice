//
//  main.c
//  UVA10420
//
//  Created by Leo Ho on 2022/3/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main(int argc, const char * argv[]) {
    char county[2000][80]; // 存放國家跟人名
    int testCase; // 輸入的測資筆數
    int i, j;
    int index; // 計算國家出現的次數
    
    scanf("%d\n", &testCase);

    for (i = 0; i < testCase; i++) {
        gets(county[i]); // 讀取輸入的字串
        for (j = 0; county[i][j] != ' '; j++); // 如果沒有空白的話，就繼續執行
        county[i][j] = '\0'; // 將空白的地方換成 '\0'
    }
    qsort(county, testCase, 80, comp); // 進行排序，將相同國家名稱的排在一起
    index = 0; // 初始化，從第一個國家開始檢查
    for (i = 0; i < testCase; i++) {
        // 如果兩個國家名稱不相同的話，就輸出前一個國家名稱跟出現次數
        if (strcmp(county[i], county[index]) != 0) {
            printf("%s %d\n", county[index], i - index);
            index = i; // 移到新國家出現的位置
        }
    }
    printf("%s %d\n", county[index], i - index); // 輸出最後一個國家名稱跟出現次數
    return 0;
}
