#include "script.h"
#include "utils.h"
#include "creatures.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "colours.h"

void test_color(){
    printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN); 
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG); //Nicky
    printf("%scyan\n", KCYN);   //Angie
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KNRM);
}

void boot_game(){
    printf("%s",LOGO);
    printSlow(INTRO,KNRM,NORMAL);
}

void start_game(){
    printSlow(REMINDER_COMMANDS,KGRY,FAST);
    delay(SINGLE_SECOND);
    printSlow("ENTERING WORLD",KNRM,SLOW);
    printSlow("...\n",KNRM,SUPER_SLOW);
    delay(2*SINGLE_SECOND);
    printArt(START_MOUNTAINS);
    delay(2*SINGLE_SECOND);
    newline();
    printSlow(START_NARRATIVE_1,KNRM,DIALOG);
    delay(NORMAL_DIALOG_DELAY*SINGLE_SECOND);
    replaceLine(START_NARRATIVE_2,KNRM,DIALOG);
    newline();
    delay(NORMAL_DIALOG_DELAY*SINGLE_SECOND);
}

void first_appearance_angie(){
    printSlow(WELCOME,KCYN,DIALOG);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
    replaceLine(ANGIE_INTRODUCTION_1,KCYN,DIALOG);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
    replaceLine(ANGIE_INTRODUCTION_2,KCYN,DIALOG);
    printSlow("...",KCYN,SUPER_SLOW);
    printSlow("hehe",KCYN,DIALOG);
    newline();
    delay(SINGLE_SECOND);
}

void angie_please_insert_name(){
    printSlow(INSERT_NAME_0,KCYN,DIALOG);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
    printAngieDialog(INSERT_NAME_1,DIALOG);
    printAngieDialog(INSERT_NAME_2,DIALOG);
    printAngieDialog(INSERT_NAME_3,DIALOG);
    newline();
    delay(SINGLE_SECOND);
    printHint("Please say your name with the command: \"My name is (name)\"");
}

void angie_adventurer_name(char* adventurer_name){
    printSlow(adventurer_name,KCYN,DIALOG);
    printSlow("? A m a z i n g name! Truly!",KCYN,DIALOG);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
    replaceLine("Well I would've picked something more",KCYN,DIALOG);
    printSlow("...you know",KCYN,SLOW);
    printSlow("...",KCYN,SUPER_SLOW);
    printSlow("badass\n",KCYN,DIALOG);
    delay(ANGIE_DIALOG_DELAY*SINGLE_SECOND);
    printSlow("But don't worry! It suits you very well!",KCYN,DIALOG);
    printSlow("...",KCYN,SLOW);
    printSlow("hehe",KCYN,DIALOG);
    delay(NORMAL_DIALOG_DELAY*SINGLE_SECOND);
}

void first_appearance_horsey(){
    printArt(HORSE);
    printSlow("Horsey says hello!",KNRM,DIALOG);
    delay(1.5*SINGLE_SECOND);
    replaceLine("Horsey wants you to give it a name!",KNRM,DIALOG);
}