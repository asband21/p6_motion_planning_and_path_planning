#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define GRID_WIDTH 800
#define GRID_HEIGHT 450
#define OBSTACLE_SIZE 50

Color* InitializeGrid(int width, int height) {
	Color *grid = (Color *)calloc(width * height, sizeof(Color));
	for (int i = 0; i < width * height; i++) {
		grid[i] = WHITE; // Initialize to white
	}
	return grid;
}

void DrawGrid_dd(Color *grid) {
	for (int y = 0; y < GRID_HEIGHT; y++) {
		for (int x = 0; x < GRID_WIDTH; x++) {
			DrawPixel(x, y, grid[y * GRID_WIDTH + x]);
		}
	}
}

void Draw_sqr(Color *grid, int x_start, int y_start, int x_len, int y_len, Color col) {
	for (int y = y_start; y < y_start + y_len; y++) {
		for (int x = x_start; x < x_start + x_len; x++) {
			grid[y * GRID_WIDTH + x] = col;
		}
	}
}

void distenst(Color *grid) {
    for(int i = 0; i < 255; i++) {
        for (int y = 1; y < GRID_HEIGHT-1; y++) {
            for (int x = 1; x < GRID_WIDTH-1; x++) {
            	if(grid[(y) * GRID_WIDTH + x].r == i && grid[(y) * GRID_WIDTH + x].g == i && grid[(y) * GRID_WIDTH + x].b == i)
            	{
            		if (grid[(y-1) * GRID_WIDTH + x].r == WHITE.r)
		            grid[(y-1) * GRID_WIDTH + x] = (Color){i+1, i+1, i+1, 255};
		            
		        if (grid[(y+1) * GRID_WIDTH + x].r == WHITE.r)
		            grid[(y+1) * GRID_WIDTH + x] = (Color){i+1, i+1, i+1, 255};
		            
		        if (grid[(y) * GRID_WIDTH + x+1].r == WHITE.r)
		            grid[(y) * GRID_WIDTH + x+1] = (Color){i+1, i+1, i+1, 255};
		            
		        if (grid[(y) * GRID_WIDTH + x-1].r == WHITE.r)
		            grid[(y) * GRID_WIDTH + x-1] = (Color){i+1, i+1, i+1, 255};
            	}
            }
        }
        //fprintf(stderr, "i:%d\n",i);  
    }
}

int main() {
	InitWindow(GRID_WIDTH, GRID_HEIGHT, "asbjørn Potential Field Example");
	SetTargetFPS(60);
	Color *grid = InitializeGrid(GRID_WIDTH, GRID_HEIGHT);
	fprintf(stderr,"\n\n\n\nr:%d \tg:%d \tb:%d \ta:%d",WHITE.r , WHITE.g ,WHITE.b , WHITE.a);
	fprintf(stderr,"\n\n\n\nr:%d \tg:%d \tb:%d \ta:%d",BLACK.r , BLACK.g ,BLACK.b , BLACK.a);	
	for(int i = 0; i < 50; i++)
		Draw_sqr(grid, rand() % GRID_WIDTH-10,rand() % GRID_HEIGHT-10, 10 ,10, BLACK);
	distenst(grid);
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);
		DrawGrid_dd(grid);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

