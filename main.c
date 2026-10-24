
/*
=============================================
            Space Invanders Clone             
=============================================
*/

#include<stdio.h>        // Required for standard input/output functons [example: prinft()]
#include<stdlib.h>       // Required for general utilities [example: system("cls")]
#include<conio.h>        // Required for direct console keyboard input [example: _kbhit(), _getch()]
#include<windows.h>      // Required for Windows console manipulation and delays [example: Sleep()]
#include<stdbool.h>      // Required for boolean data types [true/false]

#define WIDTH 40         // Defines the width of the game board
#define HEIGHT 20        // Defines the height of the game board
#define NUM_ALIENS 10    // Defines the total number of aliens in the game

// Player variables
int playerX;             // Horizontal position (X-axis) of the player
int score;               // Stores the player's current score
int lives;               // Tracks the remaining lives of the player

// Bullet variables
int bulletX, bulletY;    // Current X and Y coordinates of the bullet
bool bulletActive;       // Flag to check if a bullet is currently active on screen

// Alien structure definition
typedef struct 
{
  int x;                 // X-cordinate of the alien
  int y;                 // Y-cordinate of the alien
  bool active;           // Flag to check if the alien is active (true) or destroyed (false)
} Alien;

Alien aliens[NUM_ALIENS];    // Array to hold all aliens
int alienDirection = 1;      // Direction of alien movement (1 for right and -1 for left)

// Function prototypes declaration 
void setup();                            // Initializes game variables and positions
void draw();                             // Renders the game elements on the screen
void input();                            // Handles player keyboard inputs
void logic();                            // Handles game physics, movement and collision detection
void setCursorPosition(int x, int y);    // Sets console cursor position to preventscreen flickering
void hidecursor();                       // Hides the blinking console cursor


int main()
{
  hideCursor();                          // Hides the annoying blinking cursor
  setup();                               // Initializes the initial game state

  while (lives > 0)                      // Game loop runs as long as the player has lives remaining
  {
    draw();                              // Renders the current state of the game
    input();                             // Checks for user input
    logic();                             // Updates game logic and collisions
    Sleep(50);                           // Adds a small delay (50ms) to control game speed
  }

  // Game Over screen display
  system("cls");                         // Clears the console screen
  printf("\n\n");
  printf(" =================================================\n");
  printf("                     GAME OVER                    \n");
  printf(" =================================================\n");
  printf("                  Final score: %d\n", score);          // Display the final score
  printf(" =================================================\n\n");
  printf("  Press any key to exit...");     // Prompt to exit
  _getch();                                 // Waits for user key press before exiting

  return 0;                                 // Successfull program termination

}


// Rakin's part: 
// Function to initialize game settings 
void setup() { 
playerX = WIDTH / 2;                                          // Places the player at the center of the board   
score = 0;                                                    // Sets initial score to 0
lives = 3;                                                    // Gives the player 3 lives 
bulletActive = false;                                         // Ensures no bullet is active initially
                                          
  
// Positions the aliens neatly in two rows 
for (int i = 0; i < NUM_ALIENS; i++)
{ 
aliens[i].x = (i % 5) * 6 + 5;                    // Spreads 5 aliens horizontally per row 
aliens[i].y = (i / 5) * 2 + 2;                    // Sets vertical gap between rows 
aliens[i].active = true;                          // Sets all aliens as active/alive initially 
} 
} 
                                                              
// Function to hide the console cursor 
void hideCursor() 

{ 
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);       // Gets console handle 
  CONSOLE_CURSOR_INFO info;                                     
  info.dwSize = 100; 
  info.bVisible = FALSE;                                        // Sets cursor visibility to false (hidden)                               
  SetConsoleCursorInfo(consoleHandle, &info);                   // Applies the console cursor setting 
} 
 
// Function to reset cursor position to top-left to avoid screen flickering 
void setCursorPosition(int x, int y) 
{ 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD Coord = { (SHORT)x, (SHORT)y }; 
    SetConsoleCursorPosition(hOut, Coord);                     // Moves cursor to specified (x,y) coordinates

}


// Aysha's part
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
 
