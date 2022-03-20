//
//  main.c
//  UVA10252
//
//  Created by Leo Ho on 2022/3/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比較函數
int compare(const void *a, const void *b) {
    char *pa = (char *)a;
    char *pb = (char *)b;
    return *pa - *pb;
}

int main(int argc, const char * argv[]) {
    char wordA[1001], wordB[1001]; // 每次輸入的兩筆測資
    int i = 0, j = 0;
    
    while (gets(wordA) != NULL && gets(wordB) != NULL) {
        // 先將輸入進來的兩筆測資進行 qsort 由小到大排序
        qsort(wordA, strlen(wordA), sizeof(char), compare);
        qsort(wordB, strlen(wordB), sizeof(char), compare);
        for (i = 0, j = 0; i < strlen(wordA) && j < strlen(wordB);) {
            if (wordA[i] == wordB[j] && wordA[i] != 32 && wordB[j] != 32) {
                // 如果 wordA[i] 跟 wordB[j] 相同且兩者皆非空白的話，就輸出
                printf("%c", wordA[i]);
                i++; j++;
            } else if (wordA[i] > wordB[j]) {
                // 如果 wordA[i] 的字母比 wordB[j] 的大，就先繼續檢查 wordB
                j++;
            } else {
                // 如果 wordA[i] 的字母比 wordB[j] 的小，就先繼續檢查 wordA
                i++;
            }
        }
        printf("\n");
    }
    return 0;
}
