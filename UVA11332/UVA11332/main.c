//
//  main.c
//  UVA11332
//
//  Created by Leo Ho on 2022/3/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num; // 輸入的測資
    int sum; // 將拆開的數字進行加總
    
    scanf("%d", &num);
    
    // 當輸入 0 的時候，結束程式
    while (num) {
        // 判斷測資或是加總後的值是否為兩位數
        // 兩位數的話，就將其進行拆解
        while (num > 9) {
            sum = 0;
            while (num) {
                sum += num % 10; // 取測資的每一個數字，並加總
                num /= 10; // 取測資的每一位數
            }
            num = sum; // 將加總後的值，存在 num
        }
        printf("%d\n", num); // 輸出結果
        scanf("%d", &num); // 繼續下一筆測資
    }
    return 0;
}
