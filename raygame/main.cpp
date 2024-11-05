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

#include "raylib-cpp.hpp"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int ScreenWidth = 800;
	const int ScreenHeight = 450;

	raylib::Window GameWindow(ScreenWidth, ScreenHeight, "raylib [core] example - basic window");
	
	GameWindow.SetTargetFPS(60);
	
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!GameWindow.ShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		GameWindow.BeginDrawing();

		GameWindow.ClearBackground(RAYWHITE);

		raylib::DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		GameWindow.EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	GameWindow.Close();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
