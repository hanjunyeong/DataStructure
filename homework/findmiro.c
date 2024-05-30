#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    int ve;
    int ho;
} offsets;

typedef struct {
    short row;
    short col;
    short dir;
} element;

int n, m;
offsets move[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
char maze_size[1234567] = { 0, };
int maze[1234][1234];
int check[1234][1234] = { 0, };

element* stack;
int stack_capacity = 100;

void push(int* top, element posi) {
    (*top)++;
    stack[*top] = posi;
    if (*top >= stack_capacity) {
        stack_capacity *= 2;
        stack = (element*)realloc(stack, stack_capacity * sizeof(element));
    }
}

element pop(int* top) {
    element result = { -1, -1, -1 };
    if (*top >= 0) {
        result = stack[*top];
        (*top)--;
    }
    return result;
}

void path(void) {
    int row, col, next_row, next_col, dir;
    int clear = FALSE;
    element posi;
    int top = -1;

    posi.row = 0;
    posi.col = 0;
    posi.dir = 0;
    push(&top, posi);
    check[0][0] = 1;

    while (top > -1 && !clear) {
        posi = pop(&top);
        row = posi.row;
        col = posi.col;
        dir = posi.dir;

        while (dir < 8 && !clear) {
            next_row = row + move[dir].ve;
            next_col = col + move[dir].ho;
            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
                if (next_row == n - 1 && next_col == m - 1) {
                    clear = TRUE;
                    check[next_row][next_col] = 1;
                    push(&top, (element){next_row, next_col, 0}); // 목적지 추가
                } else if (!maze[next_row][next_col] && !check[next_row][next_col]) {
                    check[next_row][next_col] = 1;
                    posi.row = row;
                    posi.col = col;
                    posi.dir = dir + 1;
                    push(&top, posi);
                    row = next_row;
                    col = next_col;
                    dir = 0;
                } else {
                    ++dir;
                }
            } else {
                ++dir;
            }
        }


    }

    if (clear) {

        printf("<SOLUTION>\n");
        printf("\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(check[i][j] == 1 ) {
                    printf("%d", maze[i][j]);
                }
                else {
                    printf("1");
                }
            }
            printf("\n");
            
        }
    } else {
        printf("No solution found.\n");
    }
}

int main() {
    FILE* fp;
    stack = (element*)malloc(stack_capacity * sizeof(element));
    fp = fopen("maze.txt", "r");
    n = 0;
    while (fgets(maze_size, sizeof(maze_size), fp) != NULL) {
        n++;
    }
    fclose(fp);
    
    m = strlen(maze_size) - 1; // '\n' 제거
    
    fp = fopen("maze.txt", "r");
    for (int i = 0; i < n; i++) {
        fgets(maze_size, sizeof(maze_size), fp);
        for (int j = 0; j < m; j++) {
            maze[i][j] = maze_size[j] - '0';
        }
    }
    fclose(fp);
    
    path();
    free(stack);

    return 0;
}
