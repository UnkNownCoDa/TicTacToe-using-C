#include <stdio.h>

int played[3][3] = {{2, 2, 2},{2, 2, 2},{2, 2, 2},};

char symbols[] = "XO ";

void print_board(){
    printf(" %c | %c | %c\n", symbols[played[0][0]],symbols[played[0][1]],symbols[played[0][2]]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",symbols[played[1][0]],symbols[played[1][1]],symbols[played[1][2]]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",symbols[played[2][0]],symbols[played[2][1]],symbols[played[2][2]]);

}
int play_round(int r, int c, int player){
    printf("%d %d\n", r, c);
    if (r < 0 || r > 2 || c < 0 || c > 2){
        printf("Invalid input\n");
        return 0;
    }
    if (played[r][c] != 2){
        printf("Position already played\n");
        return 0;
    }
    played[r][c] = player;
    return 1;
}
int check_win(int player){
    for (int i = 0; i < 3; ++i){
        if (played[i][0] == player && played[i][0] == played[i][1] && played[i][1] == played[i][2]){
            return player;
        }
        if (played[0][i] == player && played[1][i] == player &&  played[2][i] == player){
            return player;
        }
    }
    if (played[0][0] == player && played[1][1] == player && played[2][2] == player){
        return player;
    }
    if (played[0][2] == player && played[1][1] == player && played[2][0] == player){
        return player;
    }
    
    return 2; 
}

int main(){
    int current_player = 0;
    int round = 0;
    int r, c;

    print_board();
    while (round < 10){
        printf("Enter row: ");
        scanf("%d", &r);
        printf("Enter column: ");
        scanf("%d", &c);
        play_round(r, c, current_player);
        print_board();
        if (check_win(current_player) != 2){
            printf("%c is the winner\n", symbols[current_player]);
            return 0;
        }
        current_player = (current_player + 1) % 2;
        round++;
    }
}