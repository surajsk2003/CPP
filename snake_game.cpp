#include <iostream>
#include <unistd.h> // For usleep
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <algorithm> // For std::max
#include <termios.h>
#include <fcntl.h>

using namespace std;

// Directions
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// Game settings
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, highScore;
bool gameOver;
Direction dir;
vector<pair<int, int>> snake; // To store the position of the snake
vector<pair<int, int>> obstacles; // To store obstacles

// Function prototypes
void Setup();
void Draw();
void Input();
void Logic();
void GenerateFruit();
void GenerateObstacles();
bool CheckCollision(int x, int y);
bool kbhit(); // Check if a key has been pressed
char getch(); // Get character input

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000 - score * 1000); // Increase speed based on score
    }
    cout << "Game Over! Your score: " << score << endl;
    cout << "High Score: " << highScore << endl;
    return 0;
}

void Setup() {
    gameOver = false;
    dir = RIGHT; // Start moving to the right
    x = width / 2; // Center start position
    y = height / 2; // Center start position
    score = 0;
    highScore = 0;
    snake.push_back(make_pair(x, y)); // Initial position of the snake
    GenerateFruit();
    GenerateObstacles();
}

void Draw() {
    system("clear"); // Clear the console
    for (int i = 0; i < width + 2; i++)
        cout << "#"; // Draw top wall
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Draw left wall
            if (i == y && j == x) cout << "O"; // Draw snake head
            else if (i == fruitY && j == fruitX) cout << "F"; // Draw fruit
            else {
                bool isSnakePart = false;
                for (auto &s : snake) {
                    if (s.first == j && s.second == i) {
                        cout << "o"; // Draw snake body
                        isSnakePart = true;
                        break;
                    }
                }
                if (!isSnakePart) {
                    bool isObstacle = false;
                    for (auto &obs : obstacles) {
                        if (obs.first == j && obs.second == i) {
                            cout << "#"; // Draw obstacle
                            isObstacle = true;
                            break;
                        }
                    }
                    if (!isObstacle) cout << " "; // Empty space
                }
            }
            if (j == width - 1) cout << "#"; // Draw right wall
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#"; // Draw bottom wall
    cout << endl;

    cout << "Score: " << score << endl;
    cout << "High Score: " << highScore << endl;
}

void Input() {
    if (kbhit()) { // Check if a key has been pressed
        switch (getch()) {
            case 'a':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true; // Exit the game
                break;
        }
    }
}

void Logic() {
    // Store the current head position
    int prevX = snake[0].first;
    int prevY = snake[0].second;
    int prev2X, prev2Y;
    snake[0].first = x; // Update head position

    // Update snake position
    for (int i = 1; i < snake.size(); i++) {
        prev2X = snake[i].first;
        prev2Y = snake[i].second;
        snake[i].first = prevX;
        snake[i].second = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Update head position based on direction
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // Check for collision with walls or obstacles
    if (CheckCollision(x, y)) {
        gameOver = true; // End game if collision occurs
    }

    // Check for fruit collision
    if (x == fruitX && y == fruitY) {
        score += 10;
        highScore = max(highScore, score); // Update high score
        snake.push_back(make_pair(-1, -1)); // Add new segment to the snake
        GenerateFruit();
    }
}

bool CheckCollision(int x, int y) {
    // Check if the snake collides with walls
    if (x >= width || x < 0 || y >= height || y < 0) return true;

    // Check if the snake collides with itself
    for (int i = 1; i < snake.size(); i++)
        if (snake[i].first == x && snake[i].second == y)
            return true;

    // Check if the snake collides with obstacles
    for (auto &obs : obstacles)
        if (obs.first == x && obs.second == y)
            return true;

    return false; // No collision
}

void GenerateFruit() {
    fruitX = rand() % width; // Generate random fruit position
    fruitY = rand() % height;

    // Check if the fruit spawns on the snake or obstacles
    for (auto &s : snake) {
        if (s.first == fruitX && s.second == fruitY) {
            GenerateFruit(); // Regenerate fruit if it spawns on the snake
            return;
        }
    }
    for (auto &obs : obstacles) {
        if (obs.first == fruitX && obs.second == fruitY) {
            GenerateFruit(); // Regenerate fruit if it spawns on an obstacle
            return;
        }
    }
}

void GenerateObstacles() {
    // Randomly generate obstacles
    int numObstacles = 5; // Number of obstacles
    srand(time(0)); // Seed random number generator
    for (int i = 0; i < numObstacles; i++) {
        int obsX = rand() % width;
        int obsY = rand() % height;

        // Avoid placing obstacles on the snake
        if (!CheckCollision(obsX, obsY)) {
            obstacles.push_back(make_pair(obsX, obsY));
        } else {
            i--; // Retry generating this obstacle
        }
    }
}

// Function to check if a key has been pressed
bool kbhit() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, ch | O_NONBLOCK);
    bool hit = getchar() != EOF;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return hit;
}

// Function to get a character input without waiting for enter
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror ("tcsetattr()");
    old.c_lflag &= ~ICANON; // Disable canonical mode
    old.c_lflag &= ~ECHO; // Disable echo
    tcsetattr(0, TCSANOW, &old);
    if (read(0, &buf, 1) < 0) perror ("read()");
    old.c_lflag |= ICANON; // Re-enable canonical mode
    old.c_lflag |= ECHO; // Re-enable echo
    tcsetattr(0, TCSANOW, &old);
    return (buf);
}