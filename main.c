#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int *checkForDigit(char *toPass[]){
    //converting string to int.
    int *values = (int*)malloc(2*sizeof(int));
    int value1Error = sscanf(toPass[1], "%d", (values));
    int value2Error = sscanf(toPass[2], "%d", (values + 1));
    //sscanf will return how many numbers were converted or read.
    //checking for errors (no values were converted).
    if(value1Error == 0 || value2Error == 0){exit(EXIT_FAILURE);}
    //checking for values higher or equal to 1 for first argument.
    else if(values[0] < 1){exit(EXIT_FAILURE);}
    //checking for values greater or equal to 1 OR equal to -1 for indefinte loop.
    //returns values if both conditions are true.
    else if(values[1] > 1 || values[1] == -1){return values;}
    //call error if second argument if less than 1 or not equal to -1.
    else{exit(EXIT_FAILURE);}
}

void printOutProgram(int seconds, int runCount, char **command){
    //running loop untill we reach run count, or indefinity for -1.
    for(int i=0; i!=runCount; i++){
        //creating fork.
        pid_t pid = fork();
        //checking for failed fork.
        if(pid < 0){exit(EXIT_FAILURE);}
        //child process
        if(pid == 0){
            printf("%d %d", seconds, runCount);
            execvp(command[0], command);
        }
        //parent process.
        else{
            //waiting for childing process to finish.
            wait(NULL);
            //waiting for "seconds" amount of time before running the program again.
            if(i != (runCount - 1)){sleep(seconds);}
        }
    }
    
}
//main
int main(int argc, char **argv){
    if(argc <= 3){exit(EXIT_FAILURE);}
    //converting strings to ints and checking that values pass conditions (greater or equal to 1).   
    int *values = checkForDigit(argv);
    //printing out the program with given arguments passed.
    printOutProgram(values[0], values[1], (argv+3));
}