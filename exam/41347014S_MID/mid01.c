#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

bool isabcd(char c){
    if(c=='a' || c=='b' || c=='c' || c=='d'){
        return true;
    }
    return false;
}

int main(){
    char n1[10] = "";
    char n2[10] = "";
    char n3[10] = "";
    int32_t solution = 0;
    printf("Please enter the first  operand: ");
    for(int32_t i = 0 ; i<4 ; i++){
        scanf("%c", &n1[i]);
    }
    if(n1[3]!='\n'){
        printf("error\n");
        return 0;
    }
    printf("Please enter the second operand: ");
    for(int32_t i = 0 ; i<4 ; i++){
        scanf("%c", &n2[i]);
    }
    if(n2[3]!='\n'){
        printf("error\n");
        return 0;
    }
    printf("Please enter the product       : ");
    for(int32_t i = 0 ; i<6 ; i++){
        scanf("%c", &n3[i]);
    }
    if(n3[5]!='\n'){
        printf("error\n");
        return 0;
    }
    
    //printf("n1:%s, n2:%s, n3:%s\n", n1, n2, n3);
    for(int32_t i = 0 ; i<10 ; i++){
        for(int32_t j = 0 ; j<10 ; j++){
            char a1[10]={}, a2[10]={}, a3[10]={};
            int32_t number1 = 0, number2 = 0;
            for(int32_t k = 0 ; k<3 ; k++){
                number1*=10;
                if(isabcd(n1[k])){
                    number1+=i;
                    a1[k] = '0'+i;
                }
                else{
                    number1+=n1[k]-'0';
                    a1[k] = n1[k];
                }
            }
            for(int32_t k = 0 ; k<3 ; k++){
                number2*=10;
                if(isabcd(n2[k])){
                    number2+=j;
                    a2[k] = '0'+j;
                }
                else{
                    number2+=n2[k]-'0';
                    a2[k] = n2[k];
                }
            }
            int32_t result = number1*number2, temp = result;
            //printf("n1:%d, n2:%d, result:%d\n", number1, number2, result);
            bool check = 1;
            if(result/100000)check=0;
            else{
                for(int32_t k = 4 ; k>=0 ; k--){
                    a3[k] = '0' + temp%10;
                    temp/=10;
                    if(!isabcd(n3[k])){
                        if(n3[k]!=a3[k]){
                            check=0;
                            break;
                        }
                    }
                }
                if(check){
                    if(!solution){
                        printf("Solutions:\n");
                    }
                    solution++;
                    printf("%d. %s x %s = %d\n",solution, a1, a2, result);
                    
                }
            }
        }
    }
    if(solution==0){
        printf("No solutions\n");
    }
    return 0;
}