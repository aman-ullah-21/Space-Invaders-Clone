

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
    info.bVisible = FALSE;                                    // Sets cursor visibility to false (hidden) 

    SetConsoleCursorInfo(consoleHandle, &info);               // Applies the console cursor setting 
} 
 
// Function to reset cursor position to top-left to avoid screen flickering 
void setCursorPosition(int x, int y) 
{ 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD Coord = { (SHORT)x, (SHORT)y }; 
    SetConsoleCursorPosition(hOut, Coord);                    // Moves cursor to specified (x,y) coordinates

}
