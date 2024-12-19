#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <direct.h>
#include <errno.h> //For EEXIST
#include <time.h> //For clock_t,clock() & CLOCKS_PER_SEC
#include <stdio.h>
#include <string.h> // for strcmp
#include "Generate_matrix.c"
int test_count=1;
int main(){
    while(1){
        //get the inputs from the user
        int A_row,A_col,B_row,B_col;
        printf("Enter the Row and col size of A: ");
        scanf("%d %d",&A_row,&A_col);
        printf("Enter the Row and col size of B: ");
        scanf("%d %d",&B_row,&B_col);
        // Print the values to verify correctness
        printf("Matrix A dimensions: %d x %d \n", A_row, A_col);
        printf("Matrix B dimensions: %d x %d \n", B_row, B_col);
        if(A_row != B_col){
            printf("dimensional mismatch! cant produce results for matrix multiplication");
            // return 1;
        }
        int C_row=A_row,C_col=B_col;
        char folder[256];
        snprintf(folder, sizeof(folder), "%s/Unit_%02d", base_folder, test_count++);
        printf("Folder path: %s\n",folder);
        generate_test_case(A_row,A_col,B_row,B_col);

        // Pass the folder as const char * to execute_test_case
        execute_test_case(folder, A_row, B_row, A_col, B_col);
    }
}