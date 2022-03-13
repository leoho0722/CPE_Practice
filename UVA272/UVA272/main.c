//
//  main.c
//  UVA272
//
//  Created by Leo Ho on 2022/3/13.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char word; // 輸入的字元
    char count = 0; // 計算雙引號的個數
    
    while (scanf("%c", &word) != EOF) {
        if (word != '"') {
            printf("%c", word);
        } else if (++count % 2) {
            printf("``");
        } else {
            printf("''");
        }
    }
    return 0;
}
