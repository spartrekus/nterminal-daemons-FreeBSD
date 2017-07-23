

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

// Global 
int rows, cols;  
int posy, posx ;
int drawit_blink_pos=0;

void drawit()
{
        int foo;
        erase(); 
	color_set( 0, NULL );
        mvprintw( 5 , 5 , "- Terminal Daemon (System) -");	
	foo = 0;
        if( drawit_blink_pos == 0 )  
	{
	   color_set( 0, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "." );
           drawit_blink_pos = 1 ;
	}
	else
	{
	   color_set( 0, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
	   color_set( foo, NULL );
	   mvprintw( 6, 5+(foo++)*5,   "o" );
           drawit_blink_pos = 0 ;
	}
	color_set( 0, NULL );
}


int main()
{	
       int ch, star_gameover = 0;
       initscr();			
       curs_set( 0 );

  keypad( stdscr, TRUE ); 
  start_color();
  init_pair(0,  COLOR_WHITE,     COLOR_BLACK);
  init_pair(1,  COLOR_RED,     COLOR_BLACK);
  init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
  init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
  init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
  init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
  init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
  init_pair(8,  COLOR_WHITE,   COLOR_RED);
  init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
  init_pair(10, COLOR_BLUE,  COLOR_YELLOW   );
  init_pair(11, COLOR_WHITE,   COLOR_BLUE);
  init_pair(12, COLOR_YELLOW,   COLOR_BLUE);
  init_pair(13, COLOR_BLACK,   COLOR_CYAN);
  init_pair(14, COLOR_BLUE,   COLOR_GREEN);
  init_pair(15, COLOR_BLUE, COLOR_CYAN );
  init_pair(16, COLOR_CYAN, COLOR_WHITE );
  init_pair(17, COLOR_CYAN, COLOR_YELLOW );
  init_pair(18, COLOR_CYAN, COLOR_BLUE);
  init_pair( 19, COLOR_MAGENTA , COLOR_BLUE);
  init_pair( 20 , COLOR_RED , COLOR_BLUE);
  init_pair( 21 , COLOR_BLUE , COLOR_YELLOW);
  init_pair( 22, COLOR_YELLOW,   COLOR_CYAN);
  init_pair( 23, COLOR_WHITE, COLOR_BLUE);

       getmaxyx( stdscr, rows, cols);
       posy = rows-1;
       posx = cols-1;
       nodelay( stdscr , TRUE ); 

       while( star_gameover == 0 )
       {
             attroff( A_REVERSE ); 
             nodelay( stdscr, TRUE);
             curs_set( 0 );
             drawit();
             ch = getch(); 
             usleep( 10 * 1e5 );
             refresh();
             if ( ch == 'Q' )      star_gameover =1 ;
        }
	endwin();
	printf("Starfield: Bye! \n" );
	return 0;
}



