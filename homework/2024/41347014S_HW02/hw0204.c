#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t width = 0, height = 0;
    int32_t top_left_r = 0,     top_left_g = 0,     top_left_b = 0;
    int32_t top_right_r = 0,    top_right_g = 0,    top_right_b = 0;
    int32_t bottom_left_r = 0,  bottom_left_g = 0,  bottom_left_b = 0;
    int32_t bottom_right_r = 0, bottom_right_g = 0, bottom_right_b = 0;
    uint8_t temp = 0;
    while(1){
        printf("Please enter the width (10-80):    ");
        if(scanf("%d", &width) != 1 || width < 10 || width > 80){
            printf("Invaild input\n");
            continue;
        }

        printf("Please enter the height (10-20):   ");
        if(scanf("%d", &height) != 1 || height < 10 || height > 20){
            printf("Invaild input\n");
            continue;
        }

        printf("Please enter the top left RGB:     ");
        if(scanf("%d,%d,%d", &top_left_r, &top_left_g, &top_left_b) != 3 || top_left_r < 0 || top_left_r > 255 || top_left_g < 0 || top_left_g > 255 || top_left_b < 0 || top_left_b > 255){
            printf("Invaild input\n");
            continue;
        }
        
        printf("Please enter the top right RGB:    ");
        if(scanf("%d,%d,%d", &top_right_r, &top_right_g, &top_right_b) != 3 || top_right_r < 0 || top_right_r > 255 || top_right_g < 0 || top_right_g > 255 || top_right_b < 0 || top_right_b > 255){
            printf("Invaild input\n");
            continue;
        }
        
        printf("Please enter the bottom left RGB:  ");
        if(scanf("%d,%d,%d", &bottom_left_r, &bottom_left_g, &bottom_left_b) != 3 || bottom_left_r < 0 || bottom_left_r > 255 || bottom_left_g < 0 || bottom_left_g > 255 || bottom_left_b < 0 || bottom_left_b > 255){
            printf("Invaild input\n");
            continue;
        }
        
        printf("Please enter the bottom right RGB: ");
        if(scanf("%d,%d,%d", &bottom_right_r, &bottom_right_g, &bottom_right_b) != 3 || bottom_right_r < 0 || bottom_right_r > 255 || bottom_right_g < 0 || bottom_right_g > 255 || bottom_right_b < 0 || bottom_right_b > 255){
            printf("Invaild input\n");
            continue;
        }
        break;
    }
    
    int32_t left_r_d = (bottom_left_r - top_left_r)/(height - 1), right_r_d = (bottom_right_r - top_right_r)/(height - 1);
    int32_t left_g_d = (bottom_left_g - top_left_g)/(height - 1), right_g_d = (bottom_right_g - top_right_g)/(height - 1);
    int32_t left_b_d = (bottom_left_b - top_left_b)/(height - 1), right_b_d = (bottom_right_b - top_right_b)/(height - 1);
    for(int32_t i = 0  ; i < height ; i++){
        int32_t left_r = top_left_r + i*left_r_d, right_r = top_right_r + i*right_r_d, dr = (right_r - left_r)/(width - 1);
        int32_t left_g = top_left_g + i*left_g_d, right_g = top_right_g + i*right_g_d, dg = (right_g - left_g)/(width - 1);
        int32_t left_b = top_left_b + i*left_b_d, right_b = top_right_b + i*right_b_d, db = (right_b - left_b)/(width - 1);
        for(int32_t j = 0 ; j < width-1 ; j++){
            printf("\033[38;2;%d;%d;%dm+", left_r + j*dr, left_g + j*dg, left_b + j*db);
        }
        printf("\033[38;2;%d;%d;%dm+\n", right_r, right_g, right_b);
    }

    return 0;
}
