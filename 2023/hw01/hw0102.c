#include<stdio.h>
#include<stdint.h>
int main(){
    int32_t a = 0 ,b = 0;
    printf("Please enter the first number: ");
    scanf("%d", &a);
    if(a<0 || a>99){
        printf("The input number is out of range from 0 to 99\n");
        return 0;
    }
    printf("Please enter the second number: ");
    scanf("%d", &b);
    if(b<0 || b>99){
        printf("The input number is out of range from 0 to 99\n");
        return 0;
    }

    //a
    printf("  ");
    if(a/10) printf("  %d %d\n", a/10, a%10);
    else printf("    %d\n", a);
    
    //b
    printf("*)");
    if(b/10)printf("  %d %d\n", b/10, b%10);
    else printf("    %d\n", b);

    printf("-------\n");

    int32_t c = a * ( b % 10 );
    if(c/100)printf("  %d %d %d\n", c/100, (c/10)%10, c%10);
    else if(c/10)printf("    %d %d\n", c/10, c%10);
    else printf("      %d\n", c);

    int32_t d = a * ( b / 10 );
    if(d/100)printf("%d %d %d\n", d/100, (d/10)%10, d%10);
    else if(d/10)printf("  %d %d\n", d/10, d%10);
    else printf("    %d\n", d);

    printf("-------\n");

    int32_t e = c + d * 10;
    if(e/1000)printf("%d %d %d %d\n", e/1000, (e/100)%10, (e/10)%10, e%10);
    else if(e/100)printf("  %d %d %d\n", e/100, (e/10)%10, e%10);
    else if(e/10)printf("    %d %d\n", e/10, e%10);
    else printf("      %d\n", e);

    return 0;
}