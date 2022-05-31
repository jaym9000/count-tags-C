#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htags.h"


char* readString(char* html, int htmlMax){
    FILE* stream;
    int ch= htmlMax;
    int counter =0;
    char text[htmlMax];

    stream = fopen(html, "r");
    if(stream == (FILE*) NULL){
        printf("file %s not found\n", html);
		return NULL;
    }

    do{
      ch = fgetc(stream);
      if (ch != EOF)
	{
    printf("%c", ch);
	  counter ++;
	}
    } while (ch != EOF);
    printf("\n");
  fclose(stream);

  return html;
}


char* findTagStart(char* html){
    for(int i=0; i<strlen(html); i++){
        if(strcmp(&html[i], "<") && strcmp(&html[i], "</") == 0 && strcmp(&html[i], "<!")){
            i++;
             printf("%s\n",&html[i]);
        }
    }
    return "";
}


char* findTagEnd(char* html);


int addTag(char* start, char* end, char* tags[][2], int tagMax, int* nTags, int tagCount);


void reportTags(char* tags[][2], int nTags, int* tagCount);

