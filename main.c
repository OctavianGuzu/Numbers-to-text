#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>



void units(int x){
    if(x==1) printf("one");
    if(x==2) printf("two");
    if(x==3) printf("three");
    if(x==4) printf("four");
    if(x==5) printf("five");
    if(x==6) printf("six");
    if(x==7) printf("seven");
    if(x==8) printf("eight");
    if(x==9) printf("nine");

}

void tens(int x){
    if(x<10){ units(x); return;}
    if(x==10) printf("ten");
    if(x==11) printf("eleven");
    if(x==12) printf("twelve");
    if(x==13) printf("thirteen");
    if(x==14) printf("fourteen");
    if(x==15) printf("fifteen");
    if(x==16) printf("sixteen");
    if(x==17) printf("seventeen");
    if(x==18) printf("eighteen");
    if(x==19) printf("nineteen");
    if(x==20) printf("twenty");
    if(x==30) printf("thirty");
    if(x==40) printf("forty");
    if(x==50) printf("fifty");
    if(x==60) printf("sixty");
    if(x==70) printf("seventy");
    if(x==80) printf("eighty");
    if(x==90) printf("ninety");
    if(x/10==2 && x!=20){ printf("twenty-"); units(x%10); }
    if(x/10==3 && x!=30){ printf("thirty-"); units(x%10); }
    if(x/10==4 && x!=40){ printf("forty-"); units(x%10); }
    if(x/10==5 && x!=50){ printf("fifty-"); units(x%10); }
    if(x/10==6 && x!=60){ printf("sixty-"); units(x%10); }
    if(x/10==7 && x!=70){ printf("seventy-"); units(x%10); }
    if(x/10==8 && x!=80){ printf("eighty-"); units(x%10); }
    if(x/10==9 && x!=90){ printf("ninety-"); units(x%10); }

}

void simple_hundreds(int x){
    if(x==100){ units(1); printf(" hundred");}
    if(x==200){ units(2); printf(" hundred");}
    if(x==300){ units(3); printf(" hundred");}
    if(x==400){ units(4); printf(" hundred");}
    if(x==500){ units(5); printf(" hundred");}
    if(x==600){ units(6); printf(" hundred");}
    if(x==700){ units(7); printf(" hundred");}
    if(x==800){ units(8); printf(" hundred");}
    if(x==900){ units(9); printf(" hundred");}
}

void hundreds(int x){
    if(x<100){ tens(x); return;}
    simple_hundreds(x);
    if(x/100==1 && x!=100){ simple_hundreds(100); printf(" and "); tens(x%100); }
    if(x/100==2 && x!=200){ simple_hundreds(200); printf(" and "); tens(x%100); }
    if(x/100==3 && x!=300){ simple_hundreds(300); printf(" and "); tens(x%100); }
    if(x/100==4 && x!=400){ simple_hundreds(400); printf(" and "); tens(x%100); }
    if(x/100==5 && x!=500){ simple_hundreds(500); printf(" and "); tens(x%100); }
    if(x/100==6 && x!=600){ simple_hundreds(600); printf(" and "); tens(x%100); }
    if(x/100==7 && x!=700){ simple_hundreds(700); printf(" and "); tens(x%100); }
    if(x/100==8 && x!=800){ simple_hundreds(800); printf(" and "); tens(x%100); }
    if(x/100==9 && x!=900){ simple_hundreds(900); printf(" and "); tens(x%100); }

}

void thousands(int x){
    if(x<1000){ hundreds(x); return;}
    if(x/1000>=1 && x/1000<10){ units(x/1000); printf(" thousand"); if(x%1000!=0){ printf(", "); hundreds(x%1000); } }
    if(x/1000>=10 && x/1000<100){ tens(x/1000); printf(" thousand"); if(x%1000!=0){ printf(", "); hundreds(x%1000); } }
    if(x/1000>=100 && x/1000<1000){ hundreds(x/1000); printf(" thousand"); if(x%1000!=0){ printf(", "); hundreds(x%1000); } }


}

void millions(int x){
    if(x<1000000){thousands(x); return; }
    if(x/1000000>=1 && x/1000000<10){ units(x/1000000); printf(" million"); if(x%1000000!=0){ printf(", "); thousands(x%1000000); } }
    if(x/1000000>=10 && x/1000000<100){ tens(x/1000000); printf(" million"); if(x%1000000!=0){ printf(", "); thousands(x%1000000); } }
    if(x/1000000>=100 && x/1000000<1000){ hundreds(x/1000000); printf(" million"); if(x%1000000!=0){ printf(", "); thousands(x%1000000); } }
}

void billions(int x){
    if(x/1000000000>=1 && x/1000000000<10){
        units(x/1000000000);
        printf(" billion");
        if(x%1000000000!=0){
            printf(", ");
            millions(x%1000000000);
        }
    }

}
void afisare(int x){
    if(x==0){ printf("zero"); return; }
    if(x>=1 && x<10) units(x);
    if(x>=10 && x<100) tens(x);
    if(x>=100 && x<1000) hundreds(x);
    if(x>=1000 && x<1000000) thousands(x);
    if(x>=1000000 && x<1000000000) millions(x);
    if(x>=1000000000) billions(x);

}
void afisare_principala(int x){
    if(x>=0) afisare(x);
    else{
        printf("minus ");
        afisare(-x);
    }
    printf("\n");
}
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{	WINDOW *my_win;
	int startx, starty, width, height;
	int ch,x;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);
	echo();		/* I need that nifty F1 	*/
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	height = 1000;
	width = 1000;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	attron(COLOR_PAIR(1));
	move(3,12);
	printw("Type a number: ");
	refresh();
	my_win = create_newwin(height, width, starty, startx);
	destroy_win(my_win);
	nodelay(my_win,TRUE);
	while(1)
	{	
		if(scanf("%d",&x)){
			destroy_win(my_win);
			move(3,12);
			attron(COLOR_PAIR(1));
			afisare_principala(x);
			my_win = create_newwin(height, width, starty, startx);
			wclear(my_win);
			refresh();
			wrefresh(my_win);
		}
	}
		
	endwin();			/* End curses mode		  */
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	/*box(local_win, 0 , 0);*/		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}
