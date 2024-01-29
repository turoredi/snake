#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define HEIGHT 10
#define WIDTH 20
#define snake_row 9
#define snake_col 2
#define alma 10
void init_field(char matrix[HEIGHT][WIDTH],int a){
    for (int i=0;i<HEIGHT;i++) {
        for (int j = 0;j<WIDTH;j++) {
            matrix[i][j] = ' ';
        }
    }
    srand(time(NULL));
    int rand_row;
    int rand_col;
    int counter = 0;
    while(counter<alma){
        rand_col = rand() % WIDTH;
        rand_row = rand() % HEIGHT;
        if (matrix[rand_row][rand_col] == ' ') {
            matrix[rand_row][rand_col] = 'a';
            counter++;
        }

}
}
void init_snake(int matrix[199][2]){
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    for (int i = 1;i<9;i++){
         matrix[i][0] = i+1;
         matrix[i][1] = 0;
    }
}
void print_game(char matrix[HEIGHT][WIDTH],int snake[snake_row][snake_col]) {
    char munka_matrix[HEIGHT][WIDTH];
    for (int i=0;i<HEIGHT;i++) {
        for (int j = 0;j<WIDTH;j++) {
            
            munka_matrix[i][j] = matrix[i][j];
        }
        
    }
    munka_matrix[snake[0][0]][snake[0][1]] = '8';
    for (int i = 1;i<9;i++){
        munka_matrix[snake[i][0]][snake[i][1]] = '0';
    }
    for (int i = 0;i<WIDTH+2;i++){
        if (i==WIDTH+1){printf("#\n");}else{printf("#");}
    }
    for (int i=0;i<HEIGHT;i++) {
        for (int j = 0;j<WIDTH+2;j++) {
                if (j == 0){
                    printf("#");
                } else if (j==WIDTH+1)
                {
                    printf("#\n");
                } else{printf("%c",munka_matrix[i][j-1]);} 
        }

    }
    for (int i = 0;i<WIDTH+2;i++){
        if (i==WIDTH+1){printf("#\n");}else{printf("#");}
    }
}
int update_snake(char matrix[HEIGHT][WIDTH],int snake[snake_row][snake_col],char direction,int snake_hossz) {
    int new_head[1][2];
    switch (direction)
    {
    case 'w':
        
        new_head[0][0] = snake[0][0]-1;
        new_head[0][1] = snake[0][1];
        //palya szele
        if (new_head[0][0]==-1){
            
            return -1;}
        //önmaga
        bool hit = false;
        
        for (int i = 1;i<9;i++){
            if (new_head[0][0] == snake[i][0] && new_head[0][1] == snake[i][1]){
                hit = true;
            }
        }
        if (hit) {return -2;}

        break;
    case 'a':
        
        new_head[0][0] = snake[0][0];
        new_head[0][1] = snake[0][1]-1;
        if (new_head[0][1]==-1){
           
            return -1;}
        hit = false;
        
        for (int i = 1;i<9;i++){
            
            if (new_head[0][0] == snake[i][0] && new_head[0][1] == snake[i][1]){
                hit = true;
            }
        }
        if (hit) {
            
            return -2;}
        break;
    case 's':
        hit = false;
    
        new_head[0][0] = snake[0][0]+1;
        new_head[0][1] = snake[0][1];
        if (new_head[0][0]==HEIGHT){
           
            return -1;}
        for (int i = 1;i<9;i++){
            
            if (new_head[0][0] == snake[i][0] && new_head[0][1] == snake[i][1]){
                hit = true;
            }
        }
        if (hit) {
            
            return -2;}

        break;
    case 'd':
        hit = false;
        
        new_head[0][0] = snake[0][0];
        new_head[0][1] = snake[0][1]+1;
        if (new_head[0][1]==WIDTH){
           
            return -1;}
        for (int i = 1;i<9;i++){
            
            if (new_head[0][0] == snake[i][0] && new_head[0][1] == snake[i][1]){
                hit = true;
            }
        }
        if (hit) {
            
            return -2;}
        break;
    }
    snake_hossz--;
    for (int i=snake_hossz;i>0;i--){
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    snake[0][0]=new_head[0][0];
    snake[0][1]=new_head[0][1];
    if (matrix[new_head[0][0]][new_head[0][1]] == 'a') {
        matrix[new_head[0][0]][new_head[0][1]] = ' ';
        return 1;
    }
}
int main() {
    int rows = 199;
    int cols = 2;
    int **snake_tabla = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        snake_tabla[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill the matrix with -1
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            snake_tabla[i][j] = -1;
        }
    }

    int snake_hossz = 1;
    int tabla[HEIGHT][WIDTH];
    
    init_field(tabla,alma);
    init_snake(snake_tabla);
    int alma_count = alma;
    bool hiba = false;
    printf("Ez egy snake jatek.\nirányitas: a s w d\n");
    char direction;
    print_game(tabla,snake_tabla);
    while (!hiba && alma_count >0 && direction != EOF)
    {   
        scanf("%c",&direction);
        print_game(tabla,snake_tabla);
        if (direction == 'a' || direction == 's' || direction == 'd' || direction == 'w') {
            int update = update_snake(tabla,snake_tabla,direction,snake_hossz);
            if ( update == -1 || update == -2) {hiba = true;}
            else if (update == 1)
        {
                alma_count--;
                snake_hossz++;
        }
        }   
        
    }
    
    if (alma_count==0){
        print_game(tabla,snake_tabla);
        printf("gratulalok");}
    else {printf( "hiba/leállitás történt.");}
    for(int i = 0; i < rows; i++) {
        free(snake_tabla[i]);
    }
    free(snake_tabla);
    
    return 0;
}