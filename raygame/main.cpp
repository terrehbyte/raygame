/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <cstdio>

#include "tools.h"
#include "raylib.h"
#include "raymath.h"

void DrawArrow(int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    DrawLine(startPosX, startPosY, endPosX, endPosY, color);
    DrawCircleLines(endPosX, endPosY, 5.0f, color);
}

void DrawArrowEx(Vector2 startPos, Vector2 endPos, float thick, Color color)
{
    DrawLineEx(startPos, endPos, thick, color);
    DrawCircleV(endPos, thick * 1.25f, color);
}

Vector2 Vector2FromVector3(Vector3 vec)
{
    return {vec.x, vec.y};
}

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = sum(450, 50);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Vector2 origin = {float(screenWidth / 2), float(screenHeight / 2)};
    Vector2 vecA = {0, 1};
    Vector2 vecB = {1, 0};
    float arrowLength = float((screenHeight < screenHeight ? screenHeight : screenWidth) / 4);
    float arrowThick = 10.0f;
    float rotationSpeed = 1.0f;

    const size_t TEXT_BUFFER_SIZE = 30;
    char vecAtext[TEXT_BUFFER_SIZE];
    char vecBtext[TEXT_BUFFER_SIZE];
    char dotText[TEXT_BUFFER_SIZE];

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        float aAxis = IsKeyDown('Q') ? -1.0f : 0.0f + IsKeyDown('E') ? 1.0f : 0.0f;
        float bAxis = IsKeyDown('A') ? -1.0f : 0.0f + IsKeyDown('D') ? 1.0f : 0.0f;

        float rotDelta = rotationSpeed * GetFrameTime();

        vecA = Vector2FromVector3(Vector3Transform({vecA.x, vecA.y, 0.0f}, MatrixRotateZ(-aAxis * rotDelta)));
        vecB = Vector2FromVector3(Vector3Transform({vecB.x, vecB.y, 0.0f}, MatrixRotateZ(-bAxis * rotDelta)));

        float dot = Vector2DotProduct(vecA, vecB);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawArrowEx(origin, Vector2Add(origin, Vector2Scale(vecA, arrowLength)), arrowThick, RED);
        DrawArrowEx(origin, Vector2Add(origin, Vector2Scale(vecB, arrowLength)), arrowThick, BLUE);

        sprintf_s(vecAtext, TEXT_BUFFER_SIZE, "%f , %f", vecA.x, vecA.y);
        sprintf_s(vecBtext, TEXT_BUFFER_SIZE, "%f , %f", vecB.x, vecB.y);
        sprintf_s(dotText, TEXT_BUFFER_SIZE, "%f", dot);

        DrawText(vecAtext, 10, 10, 20, BLUE);
        DrawText(vecBtext, 10, 40, 20, RED);
        DrawText(dotText, 10, 70, 20, GREEN);

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}