#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t a = 0, b = 0, c = 0, d = 0, e = 0;
    printf("Please enter 5 cards: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    if(a < 0 || a > 52 || b < 0 || b > 52 || c < 0 || c > 52 || d < 0 || d > 52 || e < 0 || e > 52){
        printf("Error, Some cards doesn't exist.\n");
        return 0;
    }

    if(a == b || a == c || a == d || a == e || b == c || b == d || b == e || c == d || c == e || d == e){
        printf("There are duplicate cards\n");
        return 0;
    }

    int32_t sa = (a-1)/13, na = (a-1)%13;
    int32_t sb = (b-1)/13, nb = (b-1)%13;
    int32_t sc = (c-1)/13, nc = (c-1)%13;
    int32_t sd = (d-1)/13, nd = (d-1)%13;
    int32_t se = (e-1)/13, ne = (e-1)%13;
    int32_t temp = 0;
    //1
    if(na>nb){
        temp = na; na = nb; nb = temp;
    }
    if(nb>nc){
        temp = nb; nb = nc; nc = temp;
    }
    if(nc>nd){
        temp = nc; nc = nd; nd = temp;
    }
    if(nd>ne){
        temp = nd; nd = ne; ne = temp;
    }
    //2
    if(na>nb){
        temp = na; na = nb; nb = temp;
    }
    if(nb>nc){
        temp = nb; nb = nc; nc = temp;
    }
    if(nc>nd){
        temp = nc; nc = nd; nd = temp;
    }
    //3
    if(na>nb){
        temp = na; na = nb; nb = temp;
    }
    if(nb>nc){
        temp = nb; nb = nc; nc = temp;
    }
    //4
    if(na>nb){
        temp = na; na = nb; nb = temp;
    }
    // printf("%d %d %d %d %d\n", a, b, c, d, e );
    // printf("%d %d %d %d %d\n", na, nb, nc, nd, ne );
    // printf("%d %d %d %d %d\n", sa, sb, sc, sd, se );

    if( sa == sb && sb == sc && sc == sd && sd == se && ((na+1 == nb && nb+1 == nc && nc+1 == nd && nd+1 == ne) ||
    (na == 0 && nb == 9 && nc == 10 && nd == 11 && ne == 12))){
        printf("Straight Flush\n");
    }

    else if((na == nb && nb == nc && nc == nd) || // abcd e
    (nb == nc && nc == nd && nd == ne)){  // a bcde
        printf("Four of a Kind\n");
    }

    else if((na == nb && nc == nd && nd == ne) || // ab cde
    (na == nb && nb == nc && nd == ne)){  // abc de
        printf("Full house\n");
    }

    else if((sa == sb && sb == sc && sc == sd && sd == se)){
        printf("Flush\n");
    }

    else if((na+1 == nb && nb+1 == nc && nc+1 == nd && nd+1 == ne) ||
    (na == 0 && nb == 9 && nc == 10 && nd == 11 && ne == 12)){
        printf("Straight\n");
    }

    else if((na == nb && nb == nc) || // abc
    (nb == nc && nc == nd) || // bcd
    (nc == nd && nd == ne) ){ // cde
        printf("Three of a kind\n");
    }

    else if((na == nb && nc == nd) || // ab cd
    (na == nb && nd == ne) || // ab de
    (nb == nc && nd == ne) ){// bc de
        printf("Two Pairs\n");
    }
    
    else if((na == nb) ||
    (nb == nc) ||
    (nc == nd) ||
    (nd == ne) ){
        printf("One Pair\n");
    }

    else{
        printf("High card\n");
    }

    return 0;
}