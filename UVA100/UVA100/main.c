//
//  main.c
//  UVA100
//
//  Created by Leo Ho on 2022/2/25.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, b; // 後面要用來運算的，a < b
    int a1, b1; // 輸入的兩數
    int num; // 用來計算數字是否為奇數、偶數
    int max; // 儲存長度最長的數字
    int count; // 儲存長度
    
    while (scanf("%d %d", &a1, &b1) == 2) {
        max = 0;
        
        // 讓 a < b
        if (a1 > b1) {
            a = b1; b = a1;
        } else {
            a = a1; b = b1;
        }
        
        // 逐一尋找在 a ~ b 這個範圍內，長度最長的數字
        for (int i = a; i <= b; i++) {
            num = i;
            count = 0;
            while (num != 1) {
                count++;
                if (num % 2 == 1) {
                    num = 3 * num + 1;
                } else {
                    num /= 2;
                }
            }
            count++; // 將最後剩下的 1 也加起來
            if (count > max) max = count;
        }
        printf("%d %d %d\n", a1, b1, max);
    }
    return 0;
}
