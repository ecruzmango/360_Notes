// ! SIGNALS 

/**
 * * Signals are numbers that can be sent to a proccess
 * Think of signals as messages to a program to notify it that a specific event has occurred.
 * they are sent to your program when "problems" arrive and can be use as a form of communication
 * 
 * As always, do not forget to include @headerfile <signal.h>, all of the signals are defined in that header file
 * 
 * @category: signal numbers:
 * Signals are numbers for the OS to understand, @example number 1 means SIGHUP while @example 2 means SIGINT
 * 1) SIGHUP 2) SIGINT 3) SIGQUIT 4) SIGILL 5) SIGTRAP
 * 6) SIGABRT 7) SIGBUS 8) SIGFPE 9) SIGKILL* 10) SIGUSR1
 * 11) SIGSEGV 12) SIGUSR2 13) SIGPIPE 14) SIGALRM 15) SIGTERM
 * 16) SIGSTKFLT 17) SIGCHLD 18) SIGCONT 19) SIGSTOP* 20) SIGTSTP
 * 
 * @note SIGKILL and SIGSTOP cannot be captured or redirected by a program
 * 
 * 
 * @category: the defualt/fundamental signals are:
 * SIG_IGN: ignores the signal @example signal(SIGINT, SIG_IGN) @note this will ignore the command CTRL+C
 * SIG_DFL: default signal handling @note signal(SIGINT, SIG_IGN) @note this will restore the command CTRL+C
 * SIG_ERR: returns an error from signal()
 * 
 */

/**
 * TODO: FUNCTIONS
 * 
 * ->CREATE A SIGNAL:
 * * signal(int signal, void(*handler)(int signum)); 
 * FUNCTION-EXAMPLE: signal(SIGHUP, mycallback);
 * @note signal () is known as the traditional signal type
 * 
 * ->SENDING SIGNALS:
 * * int raise(int signum) || returns 0 on success
 * raise() is a function that allows a program to send a signal to itself. 
 * It's like a "self-signal" mechanism.
 * 
 * * int kill(int pid, int signum) || returns 0 on success
 * The main difference between raise() and kill() is that raise() always sends the signal 
 * to the current process, while kill() can send signals to any process.
 * 
 * ->OTHER SIGNALS:
 * * unsigned int alarm(unsigned int seconds); 
 * notifes SIGALARM within seconds, if seconds == 0, kilss any pending alarms
 * 
 * 
 * 
 * 
 *
*/

/** 
 * !The "MODERN" POSIX SIGNALS:
 * 
 * * int sigaction(int sig, struct sigaction *act, struct sigaction *oact);
 * @struct:
 *     struct sigaction
 * {
 *  *Signal handler. 
 * __sighandler_t sa_handler;
 *  *Additional set of signals to be blocked. 
 *  __sigset_t sa_mask;
 * *Special flags. 
 * int sa_flags;
 * *Restore handler. 
 * void (*sa_restorer) (void);
 * };
 * 
 * @note this creates a signal, sigaction is more modern and reliable compared to the older signal() function
 * sigaction provides more control and FEATURES:
 * 1. Getting information about who sent the signal
 * 2. More precise control over signal handling
 * 3. Better portability across different Unix systems
 * 4. The ability to specify flags for signal handling behavior
 * 
 * FLAGS:
 * Think of signal masks like an umbrella that blocks certain signals from reaching your program:
 * 1. They determine which signals are blocked (temporarily ignored) during execution
 * 2. Used to prevent signals from interrupting critical sections of code
 * 
 * * int sigaltstack(const old_stack_t *ss, stack_t *oss);
 * @note Think of this as providing an "emergency backup space" for signal handling:
 * Used when:
 * The main program stack might overflow
 * You need to handle stack overflow signals
 * 
 * CLEANING:
 *  The atexit function registers a cleanup handler
 * * int atexit(void(*function)(void));
 * 
 * 
 * 
 * MASKS:
 * A signal mask is like a filter that determines which signals can be delivered to a process or thread. 
 * Think of it as a "Do Not Disturb" sign for specific signals.
 * 
 * A masked signal is not heard
 * A unmasked signal is heard
 * @example


/** 
 * ? General notes and thoughts
 * IMPORTANT SIGNALS:
    SIGABRT - Abnormal termination
    SIGFPE  - Floating-point exception
    SIGILL  - Illegal instruction
    SIGINT  - Interactive attention signal (Ctrl+C)
    SIGSEGV - Segmentation violation
    SIGTERM - Termination request
    SIGCHLD - Child process terminated, stopped, or resumed
    SIGALRM - Timer signal from alarm(2)

 * 
 */
//~SIGNAL HANDLER IMPLEMENT (Traditional):
/*
LAB 1: Traditional Signal Handling

Task: Create a program that:
1. Sets up a SIGINT handler (Ctrl+C)
2. Counts number of times Ctrl+C was pressed
3. Exits after 3 SIGINTs
4. Uses NO global variables
5. Prints remaining attempts after each SIGINT

Hint: Use signal() and pass necessary data through function parameters
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct context {
    int counter;
    int max_signals;
};

void signal_handler(int signum) {
    // just Reset signal handler
    signal(SIGINT, signal_handler); // SIGINT is the ctrl+c command
}

int main(void) {
    struct context ctx = {0, 3};  // Initialize counter and max signals
    
    // TODO: Set up signal handler
    if (signal(SIGINT, signal_handler)== SIG_ERR){
        perror("signal");
    }

    printf("Press Ctrl+C three times to exit\n");
    
    // TODO: Main loop to keep program running
    while (ctx.counter < ctx.max_signals){
        pause();
        ctx.counter++;
        int remaining = ctx.max_signals - ctx.counter;
        if(remaining > 0){
            printf("\n%d more attempts left \n", remaining);
        } else{
            printf("\n exiting");
        }
    }
    
    // TODO: Track number of signals received
    
    // TODO: Print remaining attempts
    // TODO: Exit after 3 signals
    
    return 0;
}

/* Expected output:
Press Ctrl+C three times to exit
^C2 more attempts remaining
^C1 more attempt remaining
^CExiting program
*/
