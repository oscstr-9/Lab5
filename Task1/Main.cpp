#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "SDL.h"

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void testRendering(vector<Shape*> shapes, SDL_Renderer *renderer) {
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->Render(renderer);
	}
}
//Task 1

//void main() {
//	vector<Shape*> shapes;
//	Point2D recPoint(6, 8);
//	Point2D triPoint(9, 3);
//	Point2D cirPoint(2, 1);
//
//	int GrgbArr[] = { 0,255,0,180 };
//	int LrgbArr[] = { 90,0,200,200 };
//	int BrgbArr[] = { 0,50,255,255 };
//
//	Triangle tri(GrgbArr,1, 10, triPoint);
//	Circle cir(LrgbArr, 8, cirPoint);
//	Rectangle rec(BrgbArr,12, 7, recPoint);
//
//	shapes.push_back(&rec);
//	shapes.push_back(&cir);
//	shapes.push_back(&tri);
//	
//	testRendering(shapes);
//}


//Task 2
int main(int argc, char *argv[]) {
	vector<Shape*> shapes;
	srand((unsigned int)time(NULL));
	SDL_Event event;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("This is window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);
	SDL_Delay(3000);

	while (true) {
		Point2D position(rand() % 500, rand() % 300);
		int rgbArr[] = { rand() % 255,rand() % 255,rand() % 255,rand() % 255 };

		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_t: {
					Triangle *tri = new Triangle(rgbArr, rand() % 100, rand() % 100, position);
					shapes.push_back(tri);
					testRendering(shapes, renderer);
					break;
				}
				case SDLK_r: {
					Rectangle *rec = new Rectangle(rgbArr, rand() % 100, rand() % 100, position);
					shapes.push_back(rec);
					testRendering(shapes, renderer);
					break; 
				}
							 
				case SDLK_c: {
					Circle *cir = new Circle(rgbArr, rand() % 100, position);
					shapes.push_back(cir);
					testRendering(shapes, renderer);
					break;
				}
				case SDLK_q: {
					return 0;
				}
				case SDLK_x: {
					SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
					SDL_RenderClear(renderer);
					shapes.clear();
					break;
				}
				default:
					cout << "That is not a valid command!" << endl;
					break;
				}
				break;
		default:
			break;
		}
		
		SDL_RenderPresent(renderer);
	}

	return 0;
}