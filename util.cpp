#include <stdio.h>
#include <string.h>
#include "util.h"

int nextInstruction(char *Word, int &index, double &NewKey)
{
    int  returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop")==0)     return 1;
    if (strcmp(Word, "Read")==0)    return 1;
    if (strcmp(Word, "PrintArray")==0)      return 1;
    if (strcmp(Word, "PrintHeap")==0)      return 1;
    if (strcmp(Word, "BuildHeap")==0)      return 1;
    if (strcmp(Word, "Write")==0)      return 1;
    if (strcmp(Word, "ExtractMin")==0)      return 1;
    if (strcmp(Word, "Write")==0)      return 1;

    if (strcmp(Word, "Insert")==0){
        returnV = fscanf(stdin, "%d", &index);
        if (returnV == 1){
            return 1;
        }else{
            return 0;
        }
    }
        

    if (strcmp(Word, "DecreaseKey")==0){
        returnV = fscanf(stdin, "%d %lf", &index, &NewKey);
        if (returnV == 2){
            return 1;
        }else{
            return 0;
        }
    }

    
    fprintf(stdout, "Warning: Invalid instruction\n");
    return 0;
}
