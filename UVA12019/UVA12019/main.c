//
//  main.c
//  UVA12019
//
//  Created by Leo Ho on 2022/3/22.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int testCase; // 輸入的測資筆數
    int month, day; // 月、日
    int total; // 總天數
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekday = 5; // 2010/12/31 為星期五
    
    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++) {
        scanf("%d %d", &month, &day);
        total = 0;
        for (int j = 1; j < month; j++) {
            total += month_days[j-1]; // 將前面的月份天數加起來
        }
        total += day; // 將輸入的天數加起來
        printf("%s\n", week[(total + weekday) % 7]);
    }
    return 0;
}
