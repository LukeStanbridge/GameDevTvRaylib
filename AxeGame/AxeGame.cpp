#include "raylib.h"

int main()
{
    // window dimensions
    int width = 800;
    int height = 450;
    InitWindow(width, height, "Axe Game");

    // circle coordinmates
    int circleX = 200;
    int circleY = 200;
    int circleRadius = 25;
    // circle edges
    int leftCircleX = circleX - circleRadius;
    int rightCircleX = circleX + circleRadius;
    int upCircleY = circleY - circleRadius;
    int bottomCircleY = circleY + circleRadius;

    //axe coordinates
    int axeX = 400;
    int axeY = 0;
    int axeLength = 50;
    // axe edges
    int lAxeX = axeX;
    int rAxeX = axeX + axeLength;
    int uAxeY = axeY;
    int bAxeY = axeY + axeLength;

    int direction = 10;

    // check for collisons
    bool collisionWithAxe = (bAxeY >= upCircleY) && 
                            (uAxeY <= bottomCircleY) && 
                            (lAxeX <= rightCircleX) && 
                            (rAxeX >= leftCircleX);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        if (collisionWithAxe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins

            // update edges
            leftCircleX = circleX - circleRadius;
            rightCircleX = circleX + circleRadius;
            upCircleY = circleY - circleRadius;
            bottomCircleY = circleY + circleRadius;
            lAxeX = axeX;
            rAxeX = axeX + axeLength;
            uAxeY = axeY;
            bAxeY = axeY + axeLength;
            // update collison with axe
            collisionWithAxe = (bAxeY >= upCircleY) &&
                               (uAxeY <= bottomCircleY) &&
                               (lAxeX <= rightCircleX) &&
                               (rAxeX >= leftCircleX);

            // draw objects
            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);

            // move the axe
            axeY += direction;
            if (axeY > height || axeY < 0)
            {
                direction = -direction;
            }

            // move the circle
            if (IsKeyDown(KEY_D) && circleX < width)
            {
                circleX += 10;
            }

            if (IsKeyDown(KEY_A) && circleX > 0)
            {
                circleX -= 10;
            }
        }

        // Game logic ends
        EndDrawing();
    }
}

