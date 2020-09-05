#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
#define N 12
#define M 12
bool game;
const int width=12;
const int height=12;
int x,y,fx,fy,i,j,xx,yy;
int a[N][M];
enum direct{STOP=0,LEFT,RIGHT,UP,DOWN};
enum direct dir;
void Setup(){
   	game=false;
   	dir=STOP;
   	x=width/10-1;
   	y=height/10-1;
   	fx=rand()%width;
   	fy=rand()%height;
   	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			a[i][j]=rand()%2;
		}
		printf("\n");
	}
};

void Drow(){
	system("cls");
	for(i=0;i<width;i++){
		printf
		("#");
	}
	printf("\n");
    for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
    		if(j==0||j==M-1){
    			printf("#");
			}
			
			if(i==y && j==x){
				printf("0");
			}
			else if(i==fy && j==fx)
				printf("/");
			else{
			  printf(" ");
		    }
		    putchar(i<N && a[i][j] ? ' ':'_');
			putchar(j<M && a[i][j] ? '_':'|');
		    
		}
		printf("\n");
	}	
	for(i=0;i<width;i++){
		printf("#");
	}
	printf("\n");
};

void input(){
  	if(_kbhit()){
  		switch(_getch()){
  			case 'a':dir=LEFT;break;
  			case 'd':dir=RIGHT;break;
  			case 'w':dir=UP;break;
  			case 's':dir=DOWN;break;
  			case 'x':game=true;break;
		  }
	  }
};

void logic(){
	switch(dir){
		case LEFT:x--;break;
		case RIGHT:x++;break;
		case UP:y--;break;
		case DOWN:y++;break;	
	}
	if(x>width||x<0||y>height||y<0){
		printf("GAME OVER \n");
		printf("LOL!!!!!");
		game=true;
	}
	if(x==fx && y==fy){
		printf("YOU WIN!!!!!!!\n\a");
		game=true;
	}
};

int main(){
	Setup();
	while(!game){
		Drow();
		input();
		logic();
	}
	getch();
}
