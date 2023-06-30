#include "raylib.h"
#include "raymath.h"

// const int gridSize      = 100;
// const float gridSpacing = 1.0f;

// void DrawInfiniteGrid(Vector3 cameraPosition, float gridSize,
//     float gridSpacing);

// int main() {
//     // Initialization
//     const int screenWidth  = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth, screenHeight, "Infinite Grid");

//     // Define the camera to look into our 3D world
//     Camera camera     = { 0 };
//     camera.position   = { 10.0f, 10.0f, 10.0f };
//     camera.target     = { 0.0f, 0.0f, 0.0f };
//     camera.up         = { 0.0f, 1.0f, 0.0f };
//     camera.fovy       = 45.0f;
//     camera.projection = CAMERA_PERSPECTIVE;
//     // camera.type = CAMERA_PERSPECTIVE;

//     DisableCursor();
//     SetTargetFPS(60); // Set our game to run at 60 frames-per-second

//     // Main game loop
//     while (!WindowShouldClose()) // Detect window close button or ESC key
//     {
//         // Update
//         UpdateCamera(&camera, CAMERA_FREE);

//         // Draw
//         BeginDrawing();

//         ClearBackground(GRAY);

//         BeginMode3D(camera);

//         DrawInfiniteGrid(camera.position, gridSize, gridSpacing);

//         EndMode3D();

//         DrawFPS(10, 10);

//         EndDrawing();
//     }

//     // De-Initialization
//     CloseWindow(); // Close window and OpenGL context

//     return 0;
// }

// void DrawInfiniteGrid(Vector3 cameraPosition, float gridSize,
//     float gridSpacing) {
//     // Calculate the nearest grid lines to the camera
//     int xStart = (int)(roundf(cameraPosition.x / gridSpacing) - gridSize / 2);
//     int zStart = (int)(roundf(cameraPosition.z / gridSpacing) - gridSize / 2);

//     // Draw horizontal lines
//     for (int i = 0; i < gridSize + 1; ++i) {
//         float x       = xStart * gridSpacing + i * gridSpacing;
//         Vector3 start = { x, 0.0f, zStart * gridSpacing };
//         Vector3 end   = { x, 0.0f, (zStart + gridSize) * gridSpacing };
//         DrawLine3D(start, end, DARKGRAY);
//     }

//     // Draw vertical lines
//     for (int i = 0; i < gridSize + 1; ++i) {
//         float z       = zStart * gridSpacing + i * gridSpacing;
//         Vector3 start = { xStart * gridSpacing, 0.0f, z };
//         Vector3 end   = { (xStart + gridSize) * gridSpacing, 0.0f, z };
//         DrawLine3D(start, end, DARKGRAY);
//     }
// }