//
//  main.c
//  UVA10055
//
//  Created by Leo Ho on 2022/2/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    long long a, b;
    while (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", llabs(a-b));
    }
    return 0;
}
