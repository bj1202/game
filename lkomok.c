#include <stdio.h>

#define PAN_SIZE 8
#define BLACK 1
#define WHITE 2

int pan[PAN_SIZE][PAN_SIZE];

void initgame(void);
void displayPan(void);
int check(int player, int x, int y);
int _check_horizontal(int player);
int _check_vertical(int player);
int _check_diagonal(int player);

int main(void){
	int x = 0, y = 0, player = 1;
	int sel, hor, ver, dia;
	initgame();
	displayPan();
	do{	
		check(player, x, y);
		displayPan();

		hor = _check_horizontal(player);
		ver = _check_vertical(player);
		dia = _check_diagonal(player);

		if(player == 1){
			player = 2;
		}else if(player == 2){
			player = 1;
		}
		
		if(hor == 1 || ver == 1 || dia == 1){
			printf("1.재시작 2.프로그램 종료\n");
			scanf("%d",&sel);
			while(sel != 1 && sel != 2){
				printf("다시입력\n");
				scanf("%d",&sel);
			}
			if(sel == 1){
				initgame();
				displayPan();
				player = 1;
			}
		}	
	}while(sel != 2);
	
	return 0;
}

void initgame(void){
	int i,j;
	for(i = 0 ; i < PAN_SIZE; i++){
		for(j = 0; j < PAN_SIZE; j++){
			pan[i][j] = 0;
		}
	}
	printf("게임시작!\n");
}

void displayPan(void){
	int i, j;
	
	for(i = 0 ; i < PAN_SIZE ; i++){
		for(j = 0 ; j < PAN_SIZE ; j++){
			if(pan[i][j] == 0){
				printf("+ ");
			}if(pan[i][j] == 1){
				printf("● ");
			}if(pan[i][j] == 2){
				printf("○ ");
			}
		}
		printf("\n");
	}
}

int check(int player, int x, int y){
	if(player == 1){
		printf("흑돌 : ");
	}else {
		printf("백돌 : ");
	}
	printf("(x,y)의 좌표 입력 : ");
	scanf("%d %d", &x, &y);
	if(pan[x][y] == 0){
		if(player == 1){
			pan[x][y] = player;
		}else if(player == 2){
			pan[x][y] = player;
		}
	}else{
		printf("돌이 이미 놓여있습니다.\n");
		return check(player,x,y);
	}
}
int _check_horizontal(int player){
	int i, j;
	
	for(i = 0; i < PAN_SIZE; i++){		
		for(j = 0; j < PAN_SIZE; j++){
			if(pan[i][j]==pan[i][j+1] && pan[i][j+1]==pan[i][j+2] && pan[i][j+2]==pan[i][j+3] && pan[i][j+3]==pan[i][j+4] && pan[i][j]==player){
				if(player == 1){
					printf("흑돌 승리 !\n\n");
				}else if(player == 2){
					printf("백돌 승리 !\n\n");
				}
				return 1;
			}
		}
	}
	return 0;
}

int _check_vertical(int player){
	int i, j;
	
	for(i = 0; i < PAN_SIZE; i++){		
		for(j = 0; j < PAN_SIZE; j++){
			if(pan[i][j]==pan[i+1][j] && pan[i+1][j]==pan[i+2][j] && pan[i+2][j]==pan[i+3][j] && pan[i+3][j]==pan[i+4][j] && pan[i][j]==player){
				if(player == 1){
					printf("흑돌 승리 !\n\n");
				}else if(player == 2){
					printf("백돌 승리 !\n\n");
				}
				return 1;
			}
		}
	}
	return 0;

}

int _check_diagonal(int player){
	int i, j;
	
	for(i = 0; i < PAN_SIZE; i++){
		for(j = 0 ; j < PAN_SIZE; j++){
			if(pan[i][j]==pan[i+1][j+1] && pan[i+1][j+1]==pan[i+2][j+2] && pan[i+2][j+2]==pan[i+3][j+3] && pan[i+3][j+3]==pan[i+4][j+4] && pan[i][j]==player){
				if(player == 1){
					printf("흑돌 승리 !\n\n");
				}else if(player == 2){
					printf("백돌 승리 !\n\n");
				}
				return 1;
			}else if(pan[i][j]==pan[i-1][j+1] && pan[i-1][j+1]==pan[i-2][j+2] && pan[i-2][j+2]==pan[i-3][j+3] && pan[i-3][j+3]==pan[i-4][j+4] && pan[i][j]==player){
				if(player == 1){
					printf("흑돌 승리 !\n\n");
				}else if(player == 2){
					printf("백돌 승리 !\n\n");
				}
				return 1;
			}	
		}
	}
}
