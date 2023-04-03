#include <stdio.h>
int main(){
    while (1)
    {
        int i, error=0, id=0, symbol=0, sum=0;
        char sym, n1, n2, n3, n4, n5, n6, n7, n8, n9;
        printf("請輸入要檢查的統一編號:");
        scanf("%c%c%c%c%c%c%c%c%c%c",&sym, &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9);
        char N[10] = {n1, n2, n3, n4, n5, n6, n7, n8, n9};
        for(i=0; i<9; i++)
        {
            if((int)N[i]<48 || (int)N[i]>57){
                error=1;
                break;
            }else{

                id = (id*10) + (int)N[i] - 48;
            }
        }
        if((int)sym>90 || (int)sym<65)
        {
            printf("%c%s",sym, N);
            printf("格式錯誤，第一馬須為大寫英文字母\n");

        }else if(error = 1)
        {
            printf("%c%s",sym, N);
            printf("格式錯誤，後九碼須為數字");

        }else
        {
            switch (sym)
            {
                case'A': symbol = 10; break;
                case'B': symbol = 11; break;
                case'C': symbol = 12; break;
                case'D': symbol = 13; break;
                case'R': symbol = 25; break;
                case'S': symbol = 26; break;
                case'T': symbol = 27; break;
                case'U': symbol = 28; break;
                case'V': symbol = 29; break;
                case'W': symbol = 32; break;
                case'X': symbol = 30; break;
                case'Y': symbol = 31; break;
                case'Z': symbol = 33; break;
            }
            sum = ((symbol%10)*9)%10 + (symbol/10);
            sum = sum + (id%10);
            id = id / 10;
            for(i=1; i<9; i++)
            {
                sum = sum + (((id%10)*i)%10);
                id = id / 10;
            }
            if(sum%10 == 0)
            {
                printf("合法");
            }else
            {
                printf("不合法");
            }
        }
    }
    
}