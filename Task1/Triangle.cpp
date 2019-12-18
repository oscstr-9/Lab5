#include "Triangle.h"
#include "SDL.h"
#include <IOstream>


Triangle::Triangle(int rgbaIn[4], int baseIn, int heightIn, Point2D positionIn):Shape(rgbaIn, positionIn){
	for (int i = 0; i < 4; i++) {
		rgba[i] = rgbaIn[i];
		std::cout << rgba[i] << ", ";

	}
	height = heightIn;
	base = baseIn;
	position = positionIn;
}

void Triangle::Render(SDL_Renderer *renderer) {
	std::cout << "Height: " << height << std::endl;
	std::cout << "Base: " << base << std::endl;
	std::cout << "Position: " << position.toString() << std::endl << std::endl;

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

	SDL_RenderDrawLine(renderer, position.getX(), position.getY() + height, position.getX() + base, position.getY() + height);
	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX(), position.getY() + height);
	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX() + base, position.getY() + height);
}

Triangle::~Triangle(){
	delete(this);
}
