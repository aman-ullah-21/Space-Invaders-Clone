void draw() {
 setCursorPosition(0, 0); // Resets cursor to top-left (0,0) to redraw frame smoothly
 // Draws the top border of the board
 for (int i = 0; i < WIDTH + 2; i++) printf("#");
 printf("\n");
 // Draws the inner playfield area
 for (int y = 0; y < HEIGHT; y++) {
 printf("#"); // Left border wall
 for (int x = 0; x < WIDTH; x++) {
 // Draws player symbol '^' at the bottom row
 if (y == HEIGHT - 1 && x == playerX) {
 printf("^");
 }
 // Draws active bullet symbol '|'
 else if (bulletActive && x == bulletX && y == bulletY) {
printf("|");
 }
 else {
 // Checks and draws active aliens represented by 'M'
 bool isAlien = false;
 for (int k = 0; k < NUM_ALIENS; k++) {
 if (aliens[k].active && aliens[k].x == x && aliens[k].y == y) {
 printf("M"); // Alien representation
 isAlien = true;
 break;
 }
 }
 // Prints empty space if no object is present
 if (!isAlien) {
 printf(" ");
 }
 }
 }
 printf("#\n"); // Right border wall
 }
 // Draws the bottom border of the board
 for (int i = 0; i < WIDTH + 2; i++) printf("#");
 printf("\n");
 // Displays real-time score and lives HUD
 printf(" Score: %d | Lives: %d \n", score, lives);
 printf(" Controls: 'A' (Left), 'D' (Right), 'SPACE' (Shoot), 'Q' (Quit)\n");
 }
 
