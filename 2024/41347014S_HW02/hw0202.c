#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t base = -1, state = 0;
    do
    {
        base = -1;
        printf("Please enter DNA base: ");
        int8_t result = scanf("%d", &base);
        while(base < 0 || base > 4){
            printf("Error, please enter DNA base again: ");
            scanf("%d", &base);
        }

        if(state == 0){
            if(base == 1 || base == 3){
                state = 1;
            }
            else if(base == 2 || base == 4){
                state = 2;
            }
        }
        else if(state == 1){
            if(base == 1 || base == 3 || base == 4){
                state = 3;
            }
            else if(base == 2){
                state = 4;
            }
        }
        else if(state == 2){
            if(base == 1 || base == 2 || base == 4){
                state = 4;
            }
            else if(base == 3){
                state = 2;
            }
        }
        else if(state == 3){
            if(base == 1){
                state = 2;
            }
            else if(base == 2){
                state = 3;
            }
            else if(base == 3 || base == 4){
                state = 5;
            }
        }
        else if(state == 4){
            if(base == 1 || base == 4){
                state = 6;
            }
            else if(base == 2 || base == 3){
                state = 5;
            }
        }
        else if(state == 5){
            if(base == 1 || base == 4){
                state = 5;
            }
            else if(base == 2 || base == 3){
                state = 7;
            }
        }
        else if(state == 6){
            if(base == 1){
                state = 3;
            }
            else if(base == 2 || base == 4){
                state = 6;
            }
            else if(base == 3){
                state = 5;
            }
        }
        else{
            if(base > 1 && base < 4){
                state = 7;
            }
        }
    } while(base != 0);
    
    if(state == 7){
        printf("The state is in S7, the sequence satisfies the pattern.\n");
    }
    else{
        printf("The state is in S%d, the sequence does not satisfy the pattern.\n", state);
    }
    
    return 0;
}

//bug: when input is not an int, it will be repeat infinite