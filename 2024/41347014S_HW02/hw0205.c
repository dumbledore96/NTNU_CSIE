#include<stdio.h>
#include<stdint.h>

int main(){
    int32_t width = 0, height = 0;
    int32_t panel_number = 0, job = 0;
    uint8_t temp;
    printf("please input the window size (width)x(height): ");
    while(!scanf("%dx%d", &width, &height) || width <= 0 || height <= 0){
        scanf("%c",&temp);
        printf("Error, please input the window size again (width)x(height): ");
    }
    printf("please input the total pane number: ");
    while(!scanf("%d", &panel_number) || panel_number <= 0){
        scanf("%c",&temp);
        printf("Error, please input the total pane number again: ");
    }
    printf("please input the pane for the job (0=all,-1=none): ");
    while(!scanf("%d", &job) || job < -1 || job > panel_number){
        scanf("%c",&temp);
        printf("Error, please input the pane for the job again (0=all,-1=none): ");
    }
    int32_t row = 0, col = 0, last_row = 0;
    while(row * row < panel_number){
        row++;
    }
    row--;
    if(panel_number - row * row > row){
        col = row + 1;
    }
    else{
        col = row;
    }
    last_row = panel_number - row * col;
    // printf("%dx%d+%d\n", row, col, last_row);

    int32_t panel_width = (width - col + 1) / col;
    int32_t panel_height = (height - row - 1) / (row + 1) - 1;
    printf("%dx%d\n", panel_width, panel_height);

    int32_t job_row = 0, job_col = 0;
    if(job > 0){
        job_row = (job - 1)/col;
        job_col = (job - 1)%col;
        printf("%d,%d\n", job_row, job_col);
    }

    int32_t fastfetch_size = 0;
    if(panel_height < panel_width/2){
        fastfetch_size = panel_height;
    }
    else{
        fastfetch_size = panel_width/2;
    }

    for(int32_t i = 0 ; i < row - 1 ; i++){
        for(int32_t j = 0 ; j < col ; j++){
            printf("$");
            if(job == 0 || (job_row == i && job_col == j)){
                printf(" fastfetch");
                for(int32_t jw = 11 ; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 1 ; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            if(j == col-1)printf("\n");
            else printf("\u2502");
        }

        for(int32_t ih = 0, fast_empty = 0-fastfetch_size/3*2 ; ih < panel_height ; ih++, fast_empty++){
            for(int32_t j = 0 ; j < col ; j++){
                if(job == 0 || (job_row == i && job_col == j)){
                    int32_t jw = 0;
                    for(jw = 0 ; jw < fastfetch_size - ih -1 ; jw++){
                        printf(" ");
                    }
                    printf("/");
                    jw++;
                    if(fast_empty>=0){
                        for(; jw < fastfetch_size - fast_empty -1 ; jw++){
                            printf("o");
                        }
                        printf("/");
                        jw++;
                        for(; jw < fastfetch_size + fast_empty ; jw++){
                            printf(" ");
                        }
                        printf("\\");
                        jw++;
                    }
                    else{
                        for(; jw < fastfetch_size + ih ; jw++){
                            printf("o");
                        }
                    }
                    for(; jw < fastfetch_size + ih ; jw++){
                        printf("o");
                    }
                    printf("\\");
                    jw++;
                    for(; jw < panel_width ; jw++){
                        printf(" ");
                    }
                }
                else{
                    for(int32_t jw = 0 ; jw < panel_width ; jw++){
                        printf(" ");
                    }
                }
                if(j == col-1)printf("\n");
                else printf("\u2502");
            }
        }

        for(int32_t j = 0 ; j < col ; j++){
            for(int32_t jw = 0 ; jw < panel_width ; jw++){
                printf("\u2500");
            }
            if(j == col-1)printf("\n");
            else printf("\u253C");
        }
    }

    //-2 row
    for(int32_t j = 0 ; j < col ; j++){
        printf("$");
        if(job == 0 || (job_row == row - 1 && job_col == j)){
            printf(" fastfetch");
            for(int32_t jw = 11 ; jw < panel_width ; jw++){
                printf(" ");
            }
        }
        else{
            for(int32_t jw = 1 ; jw < panel_width ; jw++){
                printf(" ");
            }
        }
        if(j == col-1)printf("\n");
        else printf("\u2502");
    }

    for(int32_t ih = 0, fast_empty = 0-fastfetch_size/3*2 ; ih < panel_height ; ih++, fast_empty++){
        for(int32_t j = 0 ; j < col ; j++){
            if(job == 0 || (job_row == row - 1 && job_col == j)){
                int32_t jw = 0;
                for(jw = 0 ; jw < fastfetch_size - ih -1 ; jw++){
                    printf(" ");
                }
                printf("/");
                jw++;
                if(fast_empty>=0){
                    for(; jw < fastfetch_size - fast_empty -1 ; jw++){
                        printf("o");
                    }
                    printf("/");
                    jw++;
                    for(; jw < fastfetch_size + fast_empty ; jw++){
                        printf(" ");
                    }
                    printf("\\");
                    jw++;
                }
                else{
                    for(; jw < fastfetch_size + ih ; jw++){
                        printf("o");
                    }
                }
                for(; jw < fastfetch_size + ih ; jw++){
                    printf("o");
                }
                printf("\\");
                jw++;
                for(; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 0 ; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            if(j == col-1)printf("\n");
            else printf("\u2502");
        }
    }

    for(int32_t j = 0 ; j < col ; j++){
        for(int32_t jw = 0 ; jw < panel_width ; jw++){
            printf("\u2500");
        }
        if(j == col-1)printf("\n");
        else if(j < last_row-1)printf("\u253C");
        else printf("\u2534");
    }

    //-1 row
    for(int32_t j = 0 ; j < last_row ; j++){
        printf("$");
        if(job == 0 || (job_row == row && job_col == j)){
            printf(" fastfetch");
            for(int32_t jw = 11 ; jw < panel_width ; jw++){
                printf(" ");
            }
        }
        else{
            for(int32_t jw = 1 ; jw < panel_width ; jw++){
                printf(" ");
            }
        }
        if(j == last_row-1)printf("\n");
        else printf("\u2502");
    }

    for(int32_t ih = 0, fast_empty = 0-fastfetch_size/3*2 ; ih < panel_height ; ih++, fast_empty++){
        for(int32_t j = 0 ; j < last_row ; j++){
            if(job == 0 || (job_row == row && job_col == j)){
                int32_t jw = 0;
                for(jw = 0 ; jw < fastfetch_size - ih -1 ; jw++){
                    printf(" ");
                }
                printf("/");
                jw++;
                if(fast_empty>=0){
                    for(; jw < fastfetch_size - fast_empty -1 ; jw++){
                        printf("o");
                    }
                    printf("/");
                    jw++;
                    for(; jw < fastfetch_size + fast_empty ; jw++){
                        printf(" ");
                    }
                    printf("\\");
                    jw++;
                }
                else{
                    for(; jw < fastfetch_size + ih ; jw++){
                        printf("o");
                    }
                }
                for(; jw < fastfetch_size + ih ; jw++){
                    printf("o");
                }
                printf("\\");
                jw++;
                for(; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 0 ; jw < panel_width ; jw++){
                    printf(" ");
                }
            }
            if(j == last_row-1)printf("\n");
            else printf("\u2502");
        }
    }

    printf("\033[30;42m[0] 0:bash*");
    for(int32_t i = 0 ; i < width - 11 ; i++){
        printf(" ");
    }
    printf("\033[0m\n");
    return 0;
}