#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "colours.h"

void printSlow(char* input, char* colour, long speed_microsec){
    for(int i=0; i<strlen(input);i++){
        usleep(speed_microsec);
        //putchar(input[i]);
        printf("%s%c",colour,input[i]);
        fflush(stdout);
    }
}

void delay(long microsec){
    usleep(microsec);
}

void replaceLine(char* input,char* colour, long speed_microsec){
    printf("\33[2K\r"); //delete current line content for linux xterm
    printSlow(input,colour, speed_microsec);
}

void printArt(char* art){
    printf("\n");
    printf("%s",art);
    printf("\n");
}

void printHint(char* hint){
    char* colour = KGRY;
    printf("%sHint: ",colour);
    printf("%s%s\n",colour,hint);
}

void printCommand(char* command, char* desc){
    printf("COMMAND: ");
    printf("%s ",command);
    if(desc!=NULL||desc!="")
        printf("(%s)\n",desc);
}

void newline(){
    printf("\n");
}

void printAngieDialog(char* s, long speed){
    replaceLine(s,KCYN,speed);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
}