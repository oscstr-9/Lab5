#include "Rectangle.h"
#include "SDL.h"
#include <Iostream>

Rectangle::Rectangle(int rgbaIn[4], int widthIn, int heightIn, Point2D positionIn):Shape(rgbaIn, positionIn) {
	for (int i = 0; i < 4; i++) {
		rgba[i] = rgbaIn[i];
	}
	width = widthIn;
	height = heightIn;
	position = positionIn;
}

void Rectangle::Render(SDL_Renderer *renderer){
	std::cout << "Height: " << height << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Position: " << position.toString() << std::endl << std::endl;

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX() + width, position.getY());
	SDL_RenderDrawLine(renderer, position.getX(), position.getY() + height, position.getX() + width, position.getY() + height);
	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX(), position.getY() + height);
	SDL_RenderDrawLine(renderer, position.getX() + width, position.getY(), position.getX() + width, position.getY() + height);
}

Rectangle::~Rectangle(){
	delete(this);
}
