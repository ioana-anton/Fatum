#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "gameplay/script.h"
#include "gameplay/utils.h"
#include "gameplay/gameplay.h"
#include "gameplay/creatures.h"
#include "gameplay/colours.h"
#include "parser/actions.h"

int call_parser(){

    int pid, status;

    if((pid=fork())!=0){
        wait(&status);
    }else{
        execl("./parser/parser","parser",NULL);
        perror("Error executing parser.\n");
    }

    status = WEXITSTATUS(status);

    //printf("Parser exit status: %d\n",status);

    return status;
}

int main(int argc, char* argv[]){

    char input[1000];
    int status=INITIAL_STATUS;
    char adventurer_name[100]="49224";

    while(status!=CODE_BAZINGA){
    
    boot_game();

    /** Beginning of the game **/
    status = call_parser();
    }
    
    
    start_game();
    
    first_appearance_angie();
    angie_please_insert_name();

    status = call_parser();
    while(status!=2){
       printHint("Please say your name with the command: \"My name is (name)\"");
       call_parser();
    }
    
    if(status==CODE_ADVENTURER_NAME){
        FILE* f = fopen("output.txt","r");
        if(f==NULL) {perror("Adventurer Name: Error opening output.txt file "); return 0;}
        fscanf(f,"%s",&adventurer_name);
        fclose(f);
    } 

    angie_adventurer_name(adventurer_name);
    

    return 0;
}