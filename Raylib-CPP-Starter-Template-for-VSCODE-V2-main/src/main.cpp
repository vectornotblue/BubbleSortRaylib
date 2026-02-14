#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>


class BubbleSort{
    private:
        int i = 0;
        int j = 0;
    public: 
        int GetSortingIndex(){
            return j;
        }
        bool sorted = false;

        bool GetIsSorted(){return sorted;}
        void BubbleStep(int array[], int arraySize){
            if(i >= arraySize){
                sorted = true;
            }
            if (sorted) return;

            if( i < arraySize - 1){
                if(j < arraySize -i - 1){
                    if(array[j] > array[j+1])
                    {
                        int temp = array[j];
                        array[j] = array[j+1];
                    array[j+1] = temp; 
                    }
                    j++;
                } else{
                    i ++;
                    j = 0;
                }
            }
        }
};

void RandomiseArray(int barCount, int array[], int screenHeight){
    for(int i = 0; i < barCount; i++){
        array[i] = GetRandomValue(0,screenHeight);
    }
}

int main() 
{
    
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int barCount = 480;
    const Color lightBlue = {150,150,255,255};
    bool start = false;
    int array[barCount] = {0};
    int barWidth = (int)(screenWidth/barCount);
    Color barColor;
    srand(time(NULL));
    

    RandomiseArray(barCount, array, screenHeight);
    
    InitWindow(screenWidth, screenHeight, "Bubble Sort Visualiser");
    
    BubbleSort bubbleSort;

    while (!WindowShouldClose() && !start){
        BeginDrawing();
        if(IsKeyPressed(KEY_SPACE)){
            start = true;
        }
        for(int i = 0; i < barCount; i++){
            DrawRectangle(i*barWidth, screenHeight-array[i], barWidth, array[i], WHITE);
        }
        EndDrawing();
    }
    while (!WindowShouldClose())
    {
        bubbleSort.BubbleStep(array, barCount);
        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0; i < barCount; i++){
            double hue = ((array[i])/((double)screenHeight))*360;
            barColor = ColorFromHSV(hue, 1, 1);
            DrawRectangle(i*barWidth, screenHeight/3.0, barWidth, screenHeight/3.0, barColor);
            DrawRectangle(i*barWidth, screenHeight-array[i]/3.0, barWidth, array[i]/3.0, WHITE);
            double angle = (140.0-(array[i]/(double)screenHeight*100.0))/180.0*PI;
            double lineLenght = screenHeight/3.0;
            double x1 = i*barWidth;
            double y1 = 0;
            double x2 = x1 +cos(angle)*lineLenght;
            double y2 = sin(angle)*lineLenght;
            DrawLine(x1,y1,x2,y2, WHITE);

        }
        int blueIndex = bubbleSort.GetSortingIndex();
        DrawRectangle(blueIndex*barWidth, 0, barWidth*2, screenHeight, lightBlue);
        std::string fps = std::to_string(GetFPS());
        DrawText(fps.c_str(), 0,0,20,lightBlue);
        EndDrawing();
        
    }
    
    CloseWindow();
}



