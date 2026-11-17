// Function to initialize game settings
void setup() {
    playerX = WIDTH / 2;                          // Places the player at the center of the board
    score = 0;                                    // Sets initial score to 0
    lives = 3;                                    // Gives the player 3 lives
    bulletActive = false;                         // Ensures no bullet is active initially

    // Positions the aliens neatly in two rows
    for (int i = 0; i < NUM_ALIENS; i++) {
        aliens[i].x = (i % 5) * 6 + 5;            // Spreads 5 aliens horizontally per row
        aliens[i].y = (i / 5) * 2 + 2;            // Sets vertical gap between rows
        aliens[i].active = true;                  // Sets all aliens as active/alive initially
    }
}

// Function to hide the console cursor
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);             // Gets console handle
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;                                              // Sets cursor visibility to false (hidden)
    SetConsoleCursorInfo(consoleHandle, &info);                         // Applies the console cursor setting

}

// Function to reset cursor position to top-left to avoid screen flickering


void setCursorPosition(int x, int y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, Coord);                              // Moves cursor to specified (x,y) coordinates
}

// Function to draw the game board and characters

void draw() {
    setCursorPosition(0, 0);                                            // Resets cursor to top-left (0,0) to redraw frame smoothly

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
        printf("#\n");                        // Right border wall
    }

    // Draws the bottom border of the board
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    // Displays real-time score and lives HUD
    printf(" Score: %d   |   Lives: %d   \n", score, lives);
    printf(" Controls: 'A' (Left), 'D' (Right), 'SPACE' (Shoot), 'Q' (Quit)\n");
}
