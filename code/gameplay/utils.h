//Different speed values for the print functions
#define NORMAL 8000
#define FAST   7000
#define SLOW   100000
#define SUPER_SLOW 1000000
#define DIALOG 100000

//Values for the delay function
#define SINGLE_SECOND 1000000
#define NORMAL_DIALOG_DELAY 1.5
#define ANGIE_DIALOG_DELAY 1.2

void printSlow(char* input, char* colour, long speed_microsec);
void delay(long microsec);
void replaceLine(char* input,char* colour, long speed_microsec);
void printArt(char* art);
void printHint(char* hint);
void printCommand(char* command, char* desc);
void newline();
void printAngieDialog(char* s, long speed);