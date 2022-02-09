#include "basics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manager(char* parameter, int* list, int N, int T){

    for(int i = 1; i < strlen(parameter); i++){ // Loop to read all parameters
                                                // > it starts with 1 to ignore the '-'
        if(atoi(&parameter[i]) == 1 || atoi(&parameter[i]) == 2 || atoi(&parameter[i]) == 3){ // Only if it's a number
            switch (atoi(&parameter[i])){
            case 1:
                first_print(list, N, T);
                break;

            case 2:
                /* code */
                break;

            case 3:
                /* code */
                break;
            
            default:
                break;
            }
        }
        else{ // Only if it's a letter
            switch (parameter[i]){
            case 'a':
                /* code */
                break;

            case 's':
                /* code */
                break;

            case 'i':
                /* code */
                break;

            case 'e':
                /* code */
                break;

            case 'q':
                /* code */
                break;

            case 'h':
                /* code */
                break;
            
            default:
                break;
            }
        
        }
    
    }

}

void first_print(int* list, int N, int T){
    int count = 0;

    for(int i = N-1; i > -1; i--){ 
        if(count > N){ // It will only happen in the case of 'T' being bigger than 'N'
            return;
        }

        printf("%i\n", list[i]);
        count++;

        if(count == T){ // Ends the loop
            return;
        }
    }

}