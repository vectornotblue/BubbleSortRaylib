#include <raylib.h>

#include <time.h>


int main() 
{
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int barCount = 100;
    const Color darkBlue = {25,25,100,255};
    int array[barCount] = {0};
    int barWidth = (int)(screenWidth/barCount);
    for(int i = 0; i < barCount; i++){
        array[i] = GetRandomValue(0,screenHeight);
    }

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0; i < barCount; i++){
            DrawRectangle(i*barWidth, 0, barWidth, array[i], WHITE);
        }
        for(int i = 0; i < barCount; i++){
            for(int j = 0; j < barCount -i; j++){
                DrawRectangle(i*barWidth, 0, barWidth, array[i], darkBlue);
                WaitTime(.1);
                if(array[j] > array[j+1]){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
                DrawRectangle(i*barWidth, 0, barWidth, array[i], WHITE);
            }
        }
        EndDrawing();
    }
    
    CloseWindow();
}

