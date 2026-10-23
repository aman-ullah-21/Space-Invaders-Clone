
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

