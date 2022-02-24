//
//  main.c
//  UVA10929
//
//  Created by Leo Ho on 2022/2/24.
//

#include <stdio.h>
#include "string.h"

int main(int argc, const char * argv[]) {
    char num[1001]; // 存放輸入的數字
    int oddSum; // 奇數位的加總
    int evenSum; // 偶數位的加總
    
    scanf("%s", num);
    printf("輸入的數字：%s\n", num);
    while (strlen(num) > 1 || num[0] != '0') {
        oddSum = evenSum = 0;
        for (int i = 0; i < strlen(num); i++) {
            if (i % 2 == 0) {
                // 偶數
                evenSum += (num[i] - '0');
            } else {
                // 奇數
                oddSum += (num[i] - '0');
            }
        }
        
        if (oddSum % 11 == evenSum % 11) {
            printf("%s is a multiple of 11.\n", num);
        } else {
            printf("%s is not a multiple of 11.\n", num);
        }
        scanf("%s", num);
        printf("下一筆輸入的數字：%s\n", num);
    }
    return 0;
}
