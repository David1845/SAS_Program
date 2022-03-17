//
//  main.c
//  S.A.S_Program
//
//  Created by David Giampa on 2022-03-15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#define SIZE 256
#define MAX_CARDINALITY 100000
#define MAX_INTEGER_SIZE 100000

/*
 inserts a random amount number of intergers,and those intergers are randomly generated.
 */

void InsertRandomAmountOfNumbers(FILE *fp){
    fpos_t position;
    // set file postion to first entry
    fgetpos(fp, &position);
    
    // the number of intergers in the file
    int Cardinality = rand()%MAX_CARDINALITY;
    char str[SIZE];
    
    memset(str,'\0',sizeof(char)*SIZE);
    // insert intergers into a file
    for(int i =0;i<Cardinality;i++){
        sprintf(str, "%d",rand()%MAX_INTEGER_SIZE);
        strncat(str,"\n",2);
        fputs(str,fp);
        memset(str,'\0',sizeof(char)*SIZE);
    }
    
    // set file postion back to the first entry.
    fsetpos(fp, &position);
    
    
}

int main(int argc, const char * argv[]) {
   
    srand((unsigned int )time(NULL));
    FILE *fp;
    
    char str[256];
    // open file and provide error handleing
    if((fp = fopen("file.txt", "w+"))==NULL){
        perror("error");
        return -1;
    }
    
    InsertRandomAmountOfNumbers(fp);
    
    long long total =0;
    long count = 0;
    // Calculate Average
    while(fgets(str, 256, fp)){
        total = total + atoi(str);
        count++;
    }
    
    printf("the Average is: %.2f",(float)total/count);

    fclose(fp);
    return 0;
}
