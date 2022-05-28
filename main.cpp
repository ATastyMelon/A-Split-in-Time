#include "raylib.h"
#include "spriteDrawer.cpp"

bool titleScreen = true;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "A Crack in Time PRE-ALPHA TESTING");
    
    Image image = LoadImage("resources/logo.png");
    SetWindowIcon(image);
    UnloadImage(image);

    Vector2 mousePoint = { 0.0f, 0.0f };
    Texture2D cursor = LoadTexture("resources/cursor.png");
    Texture2D logo = LoadTexture("resources/logo.png");

    DrawSprite sprite;

    double splashTimer = 0;
    bool playedSplash = false;

    bool isDebug = false;

    //Initialization Stuff
    
    InitAudioDevice();
    SetMasterVolume(0.3f);
    
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePoint = GetMousePosition();
        
        if (titleScreen) {
            if (splashTimer > 220) {
                
                titleScreen = false;

            } else {
                if (!playedSplash) {
                    BeginDrawing();
                    ClearBackground(BLACK);
        
                    sprite.Draw(logo, Vector2 { (screenWidth/2.0f) - 64, (screenHeight/2.0f) - 64}, 0, 1.0f, WHITE);

                    EndDrawing();
                    splashTimer += 1;
                }
            }
        } 
        else if (isDebug) {
            HideCursor();

            BeginDrawing();
            ClearBackground(BLACK);

            sprite.Draw(cursor, mousePoint, 0, 0.2f, SKYBLUE);
            DrawText("A Crack in Time DEBUGMODE", 0, screenHeight - 15, 15, LIME);

            EndDrawing();
        } else {
            HideCursor();
            
            if (IsKeyPressed(KEY_ENTER)) {
                isDebug = true;
            }

            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("A Crack in Time", 0, 0, 30, WHITE);
            DrawText("Main Menu", 0, 35, 25, WHITE);

            DrawText("Press SPACE to Play", 0, (screenHeight/2) - 30, 30, WHITE);
            DrawText("Press ESCAPE to close", 0, screenHeight/2, 30, WHITE);

            sprite.Draw(cursor, mousePoint, 0, 0.2f, SKYBLUE);
            DrawText("A Crack in Time PRE-ALPHA TESTING", 0, screenHeight - 15, 15, LIME);

            EndDrawing();
            
            if (IsKeyPressed(KEY_SPACE)) {
                
            }
        }
    }
    
    UnloadTexture(cursor);
    UnloadTexture(logo);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}