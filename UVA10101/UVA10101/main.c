//
//  main.c
//  UVA10101
//
//  Created by Leo Ho on 2022/3/22.
//

#include <stdio.h>

void bangla(long long num) {
    if (num >= 10000000) {
        bangla(num / 10000000); // 超過 7 位數的部分，先透過遞迴處理
        printf(" kuti");
        num %= 10000000; // 取出後 7 位數進行處理
    }
    if (num >= 100000) {
        printf(" %lld lakh", num / 100000); // 輸出第 6、7 位數跟單位
        num %= 100000; // 取出後 5 位數進行處理
    }
    if (num >= 1000) {
        printf(" %lld hajar", num / 1000); // 輸出第 4、5 位數跟單位
        num %= 1000; // 取出後 3 位數進行處理
    }
    if (num >= 100) {
        printf(" %lld shata", num / 100); // 輸出第 3 位數跟單位
        num %= 100; // 取出後 2 位數進行處理
    }
    if (num) {
        printf(" %lld", num); // 輸出後 2 位數
    }
}

int main(int argc, const char * argv[]) {
    long long num; // 輸入的測資
    int testCase = 0; // 輸出結果前面的編號
    
    while (scanf("%lld", &num) == 1) {
        printf("%4lld.", ++testCase);
        if (num) {
            bangla(num); // 如果 num > 0 的話，就執行 func bangla() 進行計算
        } else {
            printf(" 0"); // 否則就輸出 0
        }
        printf("\n"); // 輸出換行
    }
    return 0;
}
