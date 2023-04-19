#include "raylib.h"

int main()
{
    // window dimensions
    const int windowWidth = 1400;
    const int windowHeight = 700;
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    //accelaeration due to gravity (pixels/frame)/frame
    const int gravity = 1;

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight / 2 - scarfyRec.height;
    
    bool isInAir = false;
    const int jumpVelocity = -22;

    //initialise starting position
    int velocity = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //perform ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            //rectangele is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            //apply gravity
            velocity += gravity;
            isInAir = true;
        }

        //jump check
        if (IsKeyPressed(KEY_SPACE) && isInAir == false)
        {
            velocity += jumpVelocity;
        }     
        
        //update position
        scarfyPos.y += velocity;

        //draw player
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();
}

