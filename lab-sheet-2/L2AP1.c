#include<stdio.h>
 
int m[3][3], header[3], i, j, ch, ch2;
 
char** sprite(int n) {
    if(n == 1) return "  O  ";
    else if(n == 2) return " OOO ";
    else if(n == 3) return "OOOOO";
    else return "";
}
 
void draw_board() {
    for(j = 2; j >= 0; j--) {
        printf("%s\t%s\t%s\n", sprite(m[0][j]), sprite(m[1][j]), sprite(m[2][j]));
    }
}

void loop() {
	draw_board();
        printf("========================\n");
        printf("1\t2\t3\n");
 
        printf("Which column do you want to pop?\n");
        scanf("%d", &ch);
 
        printf("Which column do you want to place it in?\n");
        scanf("%d", &ch2);
 
        if((header[ch2-1] != 0 && (m[ch-1][header[ch-1]] > m[ch2-1][header[ch2-1]])) || ch == ch2) {
            printf("Not possible!\n");
            return loop();
        }
 
        m[ch2-1][header[ch2-1]++] = m[ch-1][--header[ch-1]];
        m[ch-1][header[ch-1]] = 0;
	loop();
}
 
int main() {
    // Empty the board
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            m[i][j] = 0;
        }
    }
 
    m[0][0] = 3; // place the largest disk is at the bottom of the first column
    m[0][1] = 2; // place the medium disk is at the middle of the first column
    m[0][2] = 1; // place the smallest disk is at the top of the first column
 
    header[0] = 3;
    header[1] = header[2] = 0;
 
    loop();
 
    return 0;
}
