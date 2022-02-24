//
//  main.c
//  UVA10041
//
//  Created by Leo Ho on 2022/2/24.
//

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    int totalCase; // 總共的測資筆數
    int member; // 該筆測資的成員數量
    int street[500]; // 成員居住的街道位置
    int medium; // 街道的中位數
    int sum = 0; // 距離總和
    
    scanf("%d", &totalCase); // 輸入總共的測資筆數
    printf("總共的測資筆數：%d\n", totalCase);
    for (int i = 0; i < totalCase; i++) {
        scanf("%d", &member); // 輸入該筆測資的成員數量
        printf("該筆測資的成員數量：%d\n", member);
        for (int j = 0; j < member; j++) {
            scanf("%d", &street[j]); // 輸入該筆測資每個成員居住的街道位置
            printf("該筆測資每個成員居住的街道位置：%d\n", street[j]);
        }
        // qsort(要排序的陣列, 有幾筆資料, 每筆資料的大小, 比較函數)，要 #include <stdlib.h> 才能用
        qsort(street, member, sizeof(int), comp); // 將每個成員居住的街道位置由小到大排序
        medium = street[member/2]; // 尋找成員居住街道的中位數
        for (int k = 0; k < member; k++) {
            sum += abs(street[k] - medium); // 計算每個成員與中位數的距離總和
        }
        printf("每個成員與中位數的距離總和：%d\n", sum);
        printf("=============第%d筆測資結束===============\n", i+1);
    }
    return 0;
}
