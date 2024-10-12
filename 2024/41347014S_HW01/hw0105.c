#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t hex = 0;
    printf("Please input a hex:");
    int32_t result = scanf("%x", &hex);
    if(!result){
        printf("Error: Input error.\n");
        return 0;
    }
    // printf("%d %d %x\n", result, hex, hex);

    int8_t out_type = 0;
    printf("Please choose the output type(1:integer ,2:unsigned integer ,3:float):");
    result  = scanf("%hhd", &out_type);
    if(!result || out_type > 3 || out_type < 1){
        printf("Error: The type you selected does not exist.\n");
        return 0;
    }

    if(hex / 4096) printf("Binary of %x is: ", hex);
    else if(hex / 256) printf("Binary of 0%x is: ", hex);
    else if(hex / 16) printf("Binary of 00%x is: ", hex);
    else printf("Binary of 000%x is: ", hex);
    printf("%d%d%d%d ", hex/32768, hex/16384%2, hex/8192%2, hex/4096%2);
    printf("%d%d%d%d ", hex/2048%2, hex/1024%2, hex/512%2, hex/256%2);
    printf("%d%d%d%d ", hex/128%2, hex/64%2, hex/32%2, hex/16%2);
    printf("%d%d%d%d\n", hex/8%2, hex/4%2, hex/2%2, hex%2);

    // integer
    if(out_type == 1){
        if(hex/32768){
            int32_t ans = 0, temp = 1;
            hex -= 1;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            ans -= (!(hex%2))*temp; hex /= 2; temp *= 2;
            printf("Converted integer is: %d\n", ans);
        }
        else{
            printf("Converted integer is: %d\n", hex);
        }
    }

    // unsigned integer
    else if(out_type == 2){
        printf("Converted unsigned integer is: %d\n", hex);
    }

    // float
    else{
        printf("Converted float is: ");
        int8_t sign = hex/32768; 
        float f = 0, t = 0.0009765625;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;
        f += hex%2*t; hex /= 2; t *= 2;

        int32_t exp = hex % 32;
        if(exp == 0 && f == 0){
            if(sign){
                printf("-0.0\n");
            }
            else{
                printf("+0.0\n");
            }
        }
        else if(exp == 31){
            if(f == 0){
                if(sign){
                    printf("-INF\n");
                }
                else{
                    printf("+INF\n");
                }
            }
            else printf("NAN\n");
        }
        else if(exp == 0){
            if(sign)printf("-");
            printf("%f*2^-14\n", f);
        }
        else{
            if(sign)printf("-");
            f += 1;
            printf("%f*2^%d\n", f, exp - 15);
        }
        // printf("exp:%d f:%f t:%f\n", exp, f, t);
    }

    return 0;
}