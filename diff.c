#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    if(argc==3){
        FILE* fp1 = fopen(argv[1], "r");
        FILE* fp2 = fopen(argv[2], "r");

        char line1[100000];
        char line2[100000];
        char* read1;
        char* read2;
        
        if(!fp1 || !fp2)
            exit(EXIT_FAILURE);
        
        do{
            read1 = fgets(line1, sizeof(line1), fp1);
            read2 = fgets(line2, sizeof(line2), fp2);
            if(strcmp(line1,line2)!=0){
                printf(">----\n");
                printf("%s",line1);
                printf("%s",line2);
                printf("<----\n\n");
            }
        }while (read1 && read2);

        printf("file1-->\n");
        while (fgets(line1, sizeof(line1), fp1)) {
            printf("%s",line1);
        }
        printf("<--\n"); 

        printf("file2-->\n");
        while (fgets(line2, sizeof(line2), fp2)) {
            printf("%s",line2);
        }
        printf("<--\n"); 

        fclose(fp1);
        fclose(fp2);

        return EXIT_SUCCESS;
    }else{
        return EXIT_FAILURE;
    }
}
