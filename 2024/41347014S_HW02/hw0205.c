#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t width = 0, height = 0;
    int32_t panel_number = 0, job = 0;
    printf("please input the window size (width)x(height): ");
    scanf("%dx%d", &width, &height);
    while(width < 0 || height < 0){
        printf("Invalid value entered, please input the window size again (width)x(height): ");
        scanf("%dx%d", &width, &height);
    }
}