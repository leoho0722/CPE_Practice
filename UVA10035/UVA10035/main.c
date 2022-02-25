//
//  main.c
//  UVA10035
//
//  Created by Leo Ho on 2022/2/25.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    long a, b; // 輸入的兩數
    int carry; // 是否進位，1 = 要進位，0 = 不用進位
    int count; // 進位次數
    int sum; // a % 10 + b % 10 + carry 的總和
    
    scanf("%ld %ld", &a, &b);
    while (a || b) {
        carry = count = 0;
        while (a || b) {
            sum = a % 10 + b % 10 + carry;
            carry = sum > 9; // 判斷是否需要進位，要進位 carry = 1，不用進位 carry = 0
            count += carry;
            a /= 10;
            b /= 10;
        }
        if (count == 0) {
            printf("No carry operation.\n");
        } else if (count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", count);
        }
        scanf("%ld %ld", &a, &b);
    }
    return 0;
}
