#include "raylib.h"

struct DrawSprite
{
    void Draw(Texture2D texture, Vector2 texturePos, float rot, float scale, Color color) {
        DrawTextureEx(texture, texturePos, rot, scale, color);
    }
};