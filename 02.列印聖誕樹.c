#include<stdio.h>
int main(){
    while (1)
    {
        int s, i, w, j, l, star, end, times=0;
        printf("請輸入聖誕樹有幾層：");
        scanf("%d", &s);
        if(s%2 == 0 || s>15)
        {
            printf("錯誤，請重新輸入\n");
            continue;
        }
        w = s*3;
        l = s*2 + 3;
        star = s + 2;
        end = s + 2;
        for(i=0; i<=w; i++)
        {
            for(j=1; j<=1; j++)
            {
                if(j>=star && j<=end)
                {
                    printf("*");
                }else
                {
                    printf("-");
                }
            }
            star -= 1;
            end += 1;
            times += 1;
            printf("\n");
            if(times == 3)
            {
                star += 2;
                end -= 2;
                times = 0;
            }
        }
        star = ((l+1) / 2) - (s/2);
        end = ((l+1) / 2) + (s/2);
        s = (s+1) / 2;
        for(i=1; i<=s; i++)
        {
            for(j=1; j<=1; j++)
            {
                if(j>=star && j<=end)
                {
                    printf("*");
                }
                else
                {
                    printf("-");
                }
            }
            printf("\n");
        }
        break;
    }
    
}