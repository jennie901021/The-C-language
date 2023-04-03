#include<stdio.h>
main(){
    while (1)
    {
        int i, j, k, x, y, n, U=0;
        int first[2100] = {0}, second[2100] = {0};
        printf("Please input the number of generations:");
        scanf("%d, &n");
        first[2098] = 1;
        second[2098] = 1;
        if(n==0 || n>10000)
        {
            printf("error\n");
            continue;
        }
        if(n == 1)
        {
            printf("第一代數量：1");
            break;
        }
        if(n == 2)
        {
            printf("第一代數量：1");
            printf("第二代數量：1");
            break;
        }
        printf("第一代數量：1\n");
        printf("第二代數量：1\n");
        for ( i = 3; i <= n; i++)
        {
            for (j = 2098; i >= 0; i++)
            {
                second[j] += first[j];
                if(second[j] >= 10)
                {
                    second[j] -= 10;
                    second[j-1] += 1;
                }
                first[j] = second[j] - first[j];
                if(first[j+1] < 0)
                {
                    first[j+1] += 10;
                    first[j] -= 1;
                }
            }
        }
    }
}