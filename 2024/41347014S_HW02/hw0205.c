#include<stdio.h>
#include<stdint.h>

int arch_size_f(int, int);

int main(){
    int32_t width = 0, height = 0;
    int32_t panel_number = 0, job = 0;
    uint8_t temp;
    printf("please input the window size (width)x(height): ");
    if(!scanf("%dx%d", &width, &height) || width <= 0 || height <= 0){
        printf("Error\n");
        return 0;
    }
    printf("please input the total pane number: ");
    if(!scanf("%d", &panel_number) || panel_number <= 0){
        printf("Error\n");
        return 0;
    }
    printf("please input the pane for the job (0=all,-1=none): ");
    if(!scanf("%d", &job) || job < -1 || job > panel_number){
        printf("Error\n");
        return 0;
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
    int32_t ex_width = (width - col + 1) % col;
    int32_t ex_height = (height - row - 1) % (row + 1);
    // printf("%dx%d\n", panel_width, panel_height);

    int32_t job_row = -1, job_col = -1;
    if(job > 0){
        job_row = (job - 1)/col;
        job_col = (job - 1)%col;
        // printf("%d,%d\n", job_row, job_col);
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
            int32_t pw = panel_width + (j < ex_width ?1 :0);
            printf("$");
            if(job == 0 || (job_row == i && job_col == j)){
                printf(" fastfetch");
                for(int32_t jw = 11 ; jw < pw ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 1 ; jw < pw ; jw++){
                    printf(" ");
                }
            }
            if(j == col-1)printf("\n");
            else printf("\u2502");
        }

        int32_t ph = panel_height + (i < ex_height ?1 :0);
        for(int32_t ih = 0, arch_empty = 0-ph+ph/3 ; ih < ph ; ih++, arch_empty++){
            for(int32_t j = 0 ; j < col ; j++){
                int32_t pw = panel_width + (j < ex_width ?1 :0);
                if(job == 0 || (job_row == i && job_col == j)){
                    int32_t jw = 0;
                    for(jw = 0 ; jw < ph - ih -1 ; jw++){
                        printf(" ");
                    }
                    printf("\033[38;2;23;147;209m/");
                    jw++;
                    if(arch_empty>=0){
                        for(; jw < ph - arch_empty -1 ; jw++){
                            printf("o");
                        }
                        printf("/");
                        jw++;
                        for(; jw < ph + arch_empty ; jw++){
                            printf(" ");
                        }
                        printf("\\");
                        jw++;
                    }
                    for(; jw < ph + ih ; jw++){
                        printf("o");
                    }
                    printf("\\\033[0m");
                    jw++;
                    for(; jw < pw ; jw++){
                        printf(" ");
                    }
                }
                else{
                    for(int32_t jw = 0 ; jw < pw ; jw++){
                        printf(" ");
                    }
                }
                if(j == col-1)printf("\n");
                else printf("\u2502");
            }
        }

        for(int32_t j = 0 ; j < col ; j++){
            int32_t pw = panel_width + (j < ex_width ?1 :0);
            for(int32_t jw = 0 ; jw < pw ; jw++){
                printf("\u2500");
            }
            if(j == col-1)printf("\n");
            else printf("\u253C");
        }
    }

    //-2 row
    if(row >= 1){

        for(int32_t j = 0 ; j < col ; j++){
            int32_t pw = panel_width + (j < ex_width ?1 :0);
            printf("$");
            if(job == 0 || (job_row == row - 1 && job_col == j)){
                printf(" fastfetch");
                for(int32_t jw = 11 ; jw < pw ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 1 ; jw < pw ; jw++){
                    printf(" ");
                }
            }
            if(j == col-1)printf("\n");
            else printf("\u2502");
        }

        int32_t ph = panel_height + (col - 1 < ex_height ?1 :0);
        for(int32_t ih = 0, arch_empty = 0-ph+ph/3 ; ih < ph ; ih++, arch_empty++){
            for(int32_t j = 0 ; j < col ; j++){
                int32_t pw = panel_width + (j < ex_width ?1 :0);
                if(job == 0 || (job_row == row - 1 && job_col == j)){
                    int32_t jw = 0;
                    for(jw = 0 ; jw < ph - ih -1 ; jw++){
                        printf(" ");
                    }
                    printf("\033[38;2;23;147;209m/");
                    jw++;
                    if(arch_empty>=0){
                        for(; jw < ph - arch_empty -1 ; jw++){
                            printf("o");
                        }
                        printf("/");
                        jw++;
                        for(; jw < ph + arch_empty ; jw++){
                            printf(" ");
                        }
                        printf("\\");
                        jw++;
                    }
                    for(; jw < ph + ih ; jw++){
                        printf("o");
                    }
                    printf("\\\033[0m");
                    jw++;
                    for(; jw < pw ; jw++){
                        printf(" ");
                    }
                }
                else{
                    for(int32_t jw = 0 ; jw < pw ; jw++){
                        printf(" ");
                    }
                }
                if(j == col-1)printf("\n");
                else printf("\u2502");
            }
        }

        for(int32_t j = 0 ; j < col ; j++){
            int32_t pw = panel_width + (j < ex_width ?1 :0);
            for(int32_t jw = 0 ; jw < pw ; jw++){
                printf("\u2500");
            }
            if(j == col-1)printf("\n");
            else if(j < last_row-1)printf("\u253C");
            else printf("\u2534");
        }
    }

    //-1 row
    for(int32_t j = 0 ; j < last_row ; j++){
        int32_t pw = panel_width + (j < ex_width ?1 :0);
        printf("$");
        if(job == 0 || (job_row == row && job_col == j)){
            printf(" fastfetch");
            for(int32_t jw = 11 ; jw < pw ; jw++){
                printf(" ");
            }
        }
        else{
            for(int32_t jw = 1 ; jw < pw ; jw++){
                printf(" ");
            }
        }
        if(j == last_row-1)printf("\n");
        else printf("\u2502");
    }

    for(int32_t ih = 0, arch_empty = 0-panel_height+panel_height/3 ; ih < panel_height ; ih++, arch_empty++){
        for(int32_t j = 0 ; j < last_row ; j++){
            int32_t pw = panel_width + (j < ex_width ?1 :0);
            if(job == 0 || (job_row == row && job_col == j)){
                int32_t jw = 0;
                for(jw = 0 ; jw < panel_height - ih -1 ; jw++){
                    printf(" ");
                }
                printf("\033[38;2;0;255;0m/");
                jw++;
                if(arch_empty>=0){
                    for(; jw < panel_height - arch_empty -1 ; jw++){
                        printf("o");
                    }
                    printf("/");
                    jw++;
                    for(; jw < panel_height + arch_empty ; jw++){
                        printf(" ");
                    }
                    printf("\\");
                    jw++;
                }
                for(; jw < panel_height + ih ; jw++){
                    printf("o");
                }
                printf("\\\033[0m");
                jw++;
                for(; jw < pw ; jw++){
                    printf(" ");
                }
            }
            else{
                for(int32_t jw = 0 ; jw < pw ; jw++){
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
