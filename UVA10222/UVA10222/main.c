//
//  main.c
//  UVA10222
//
//  Created by Leo Ho on 2022/3/13.
//

#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; // 鍵盤上的所有文字
    char c; // 輸入的字元
    
    while (scanf("%c", &c) != EOF) {
        if (c == 32 || c == 10) {
            printf("%c", c); // 如果輸入的字元是空格 (ASCII Code = 32) 或是換行 (ASCII Code = 10) 的話，就直接輸出
        } else {
            c = tolower(c); // 將大寫字母轉成小寫，透過 ctype.h 裡面的 tolower() 來轉換
            for (int i = 0; i < keyboard[i]; i++) {
                if (c == keyboard[i]) {
                    printf("%c", keyboard[i-2]); // 輸出 輸入字元左移兩位的字元
                    break; // 跳脫 for 迴圈，繼續下一個字元的處理
                }
            }
        }
    }
    return 0;
}
