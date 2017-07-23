

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include <dirent.h> //
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  
#include <time.h>
#include <ncurses.h>


void drawit()
{
    printf(  "- Terminal Daemon (Wait) - \n" );
}


int main()
{	
       int star_gameover = 0;
       while( star_gameover == 0 )
       {
             drawit();
             usleep( 10 * 5 * 1e5 );
       }
       printf("Starfield: Bye! \n" );
       return 0;
}



