#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHARACTERS 100000
#define TAGS 100

void reportTags(char** html, int* htmlCount);
void freeHeapMemory(char* inputBuff, char** html, int* htmlCount);
void updateTagCount(char* tag, char** html, int* htmlCount);
int readFile(char* inputBuffer, char** html, int* htmlCount);

int main(int argc, char* argv[]){
    int i;
    char* inputBuffer; 
    char** html;
    int* htmlCount;

    inputBuffer = (char*) malloc(sizeof(char) * CHARACTERS+1);
    html = (char**) malloc(sizeof(char*) * TAGS);
    htmlCount = (int *) malloc(sizeof(int) * TAGS);

    memset(inputBuffer, '\0', CHARACTERS+1);

    // To initialize all the heap allocated variables
    for(i=0; i<TAGS; i++){
        html[i] =   NULL;
        htmlCount[i] = -1;
    }

    // To read html file
    readFile(inputBuffer, html, htmlCount);

    reportTags(html, htmlCount);

    // To free buffer, tags, and htmlCount
    freeHeapMemory(inputBuffer, html, htmlCount);

    return EXIT_SUCCESS;
}