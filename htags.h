#ifndef TAGS_H
#define TAGS_H

// To print out the tag names found and the number of occurences
void reportTags(char** html, int* htmlCount);

// To free the heap memory
void freeHeapMemory(char* inputBuff, char** html, int* htmlCount);

// To update the tag count or add new tags when found
void updateTagCount(char* tag, char** html, int* htmlCount);

// to read HTML file and find < to >
int readFile(char* inputBuffer, char** html, int* htmlCount);


#endif