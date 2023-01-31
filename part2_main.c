#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ORDER 20 //maximum number of digits in any subarray

//create stack array
char stack[MAX_ORDER] = {' '}; //atof ignores whitespace
int top = -1;

//stack functions
void push(char val);
void clear();
void format_array(char arr[], float formatted_array[], int *index);

//math functions
float calc_mean(float formatted_array[], int len);
float calc_var(float arr_1[], float arr_2[], int len);


int main(int argc, char *argv[]){
    if (argc == 3){
        int len_1 = strlen(argv[1]);
        int len_2 = strlen(argv[2]);

        float covar, var_1, var_2;
        float *arr_1, *arr_2;
        int n_1, n_2;
        int *p_1 = &n_1;
        int *p_2 = &n_2;

        arr_1 = calloc(len_1, sizeof(float)); //this allocates more memory than needed but n_1 and n_2 keep track of the last float entry
        arr_2 = calloc(len_2, sizeof(float));

        format_array(argv[1], arr_1, p_1);
        format_array(argv[2], arr_2, p_2);

        if (n_1 == n_2){
            covar = calc_var(arr_1, arr_2, n_1);
        }

        else{
            printf("Error, vectors must be the same length. Disregard covariance value.\n");
        }

        var_1 = calc_var(arr_1, arr_1, n_1);
        var_2 = calc_var(arr_2, arr_2, n_2);

        printf("The Cov of two input arrays is %.2f, and their own Var are %.2f and %.2f.", covar, var_1, var_2);
    }

    return 0;
}

void push(char val){
    top ++;
    stack[top] = val;
}

void clear(){
    while (top > -1){
        stack[top] = ' ';
        top --;
    }
}

void format_array(char arr[], float formatted_array[], int *ptr){
    *ptr = 0;
    for (int i = 0; i < strlen(arr); i++){
        if ( ((arr[i] >= '0') & (arr[i] <= '9') ) | (arr[i] == '.') | (arr[i] == '-') | (arr[i] == '+') ){ //if element a decimal digit or a decimal point
            push(arr[i]);
        }
        else{
            if (top > -1){ //if stack is not empty
                formatted_array[*ptr] = atof(stack);
                *ptr += 1;
                clear(); //clear stack
            }
            else{
                continue;
            }
        }
    }
}

float calc_mean(float formatted_array[], int len){
    float sum = 0.0;
    for (int i = 0; i < len; i++){
        sum += formatted_array[i];
    }
    return (sum/len);
}

float calc_var(float first[], float second[], int len){
    float mean_1 = calc_mean(first, len);
    float mean_2 = calc_mean(second, len);
    float var = 0.0;

    for (int i = 0; i < len; i++){
        var += (first[i] - mean_1)*(second[i] - mean_2)/(len - 1);
    }
    
    return var;
}