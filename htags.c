#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CHARACTERS 100000
#define TAGS 100
#define TAG_SIZE 30

void reportTags(char** html, int* htmlCount){
    int i=0;

    for(i=0; i<TAGS; i++){
        if(htmlCount[i] != -1)
            printf("%-6s %d\n", html[i], htmlCount[i]);
    }
}

void freeHeapMemory(char* inputBuff, char** html, int* htmlCount){
    int i=0;

    // To free the input buffer
    free(inputBuff);

    // To free all of the HTML tags
    for(int i=0; i<TAGS; i++){
        free(html[i]);
    }
    free(html);

    // To free the count of the HTML tags
    free(htmlCount);
}

void updateTagCount(char* tag, char** html, int* htmlCount){
    int i=0;
    int htmlFound = 0;

    for(i=0; i<TAGS; i++){
        if(html[i] == NULL){
            break;
        }else if(strncmp(tag, html[i], strlen(tag)) == 0){
            htmlFound=1;
            break;
        }
    }

    if(htmlFound){
        //To already found the tag so we increment tag count
        htmlCount[i] = htmlCount[i]+1;
    }else{
        // To just add a new tag
        html[i] = tag;
        htmlCount[i] = 1;
    }
}

int readFile(char* inputBuffer, char** html, int* htmlCount){
    int i=0;
    int len = 0;
    int htmlFound = 0;
    char *tag = NULL;
    int htmlIndex = 0;

    // To read input file to inputbuffer
    if((len = read(0, inputBuffer, CHARACTERS))){
        for(i=0; i<len; i++){
            if(htmlFound == 0){
                /* To check the closing tags and find out
                all the tags available in HTML file*/
                if(inputBuffer[i] == '<' && inputBuffer[i+1] != '!' && inputBuffer[i] != '/'){
                    tag = (char*) malloc(TAG_SIZE);
                    memset(tag, '\0', TAG_SIZE);
                    htmlFound = 1;
                }
            }else{
                // To read tag until '>'. This means tag is found
                if(inputBuffer[i] == '>' || inputBuffer[i] == ' ' || inputBuffer[i] == '/'){
                    htmlFound = 0;
                    htmlIndex = 0;
                    if(inputBuffer[i] != '/')
                        updateTagCount(tag, html, htmlCount);
                    else
                        free(tag);
                }else{
                    /* To update tag name in local heap allocated variable
                    and copy to tags variable */
                    tag[htmlIndex++] = inputBuffer[i];
                }
            }
        }
    }else
        printf("File has no contents\n");
        return 1;
    
}