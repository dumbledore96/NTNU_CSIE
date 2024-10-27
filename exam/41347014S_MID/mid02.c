#include<stdio.h>
#include<stdint.h>

void print_color(int32_t);
void print_continue(int32_t, char);
void card_line(int32_t, int32_t);

int main(){
    int32_t width = 0, height = 0;
    int32_t number = 0;
    printf("Please enter the card size (width,height): ");
    scanf("%d,%d", &width, &height);
    if(width<7 || width>40 || height<4 || height>10){
        printf("Invalid input\n");
        return 0;
    }
    printf("Please enter the card number: ");
    scanf("%d", &number);
    if(number<1 || number>40){
        printf("Invalid input\n");
        return 0;
    }

    for(int32_t i = 0 ; i < number + height -2 ; i++){
        int32_t j = number-i-1, nc = number-i;
        if(j > 0){
            print_continue(number-i-1, ' ');
            j+=width;
        }
        else{
            j = width;
        }
        if(i<number){
            nc = number-i;
            card_line(nc%4, width);
        }
        else{
            nc = 1;
            print_color(nc);
            printf("|");
            print_continue(width-2 ,' ');
            printf("|");
        }

        int32_t right = 0;
        if(i < height-1){
            right = width + number - 1;
            nc++;
            for(; j<right ; j++, nc++){
                print_color(nc%4);
                printf("|");
            }
        }
        else{
            right = width + number-1 + height-1 - i;
            nc++;
            for(; j<right-1 ; j++, nc++){
                print_color(nc%4);
                printf("|");
            }
            print_color(nc%4);
            printf("+");
        }
        printf("\n");
    }
    card_line(1, width);
    printf("\n");
    return 0;
}

void print_color(int32_t color){
    if(color == 0)printf("\033[34m");
    else if(color == 1)printf("\033[31m");
    else if(color == 2)printf("\033[33m");
    else printf("\033[32m");
}

void print_continue(int32_t n, char c){
    for(int32_t i = 0 ; i < n ; i++){
        printf("%c", c);
    }
}

void card_line(int32_t color, int32_t width){
    print_color(color);
    printf("+");
    print_continue(width-2, '-');
    printf("+");
    printf("\033[0m");
}