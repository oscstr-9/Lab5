#include "Circle.h"
#include "SDL.h"
#include <IOstream>
#include <math.h>

Circle::Circle(int rgbaIn[4], int radiusIn, Point2D positionIn):Shape(rgbaIn, positionIn){
	for (int i = 0; i < 4; i++) {
		rgba[i] = rgbaIn[i];
	}
	radius = radiusIn;
	position = positionIn;
}

void Circle::Render(SDL_Renderer *renderer) {
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Position: " << position.toString() << std::endl << std::endl;

	SDL_SetRenderDrawColor(renderer, rgba[0], rgba[1], rgba[2], rgba[3]);

	for (int i = 0; i <= 360; i++) {
		SDL_RenderDrawLine(renderer, position.getX() + radius * cos((2 * M_PI / 360)*i), position.getY() + radius * sin((2 * M_PI / 360)*i),
		position.getX() + radius * cos((2 * M_PI / 360)*(i + 1)), position.getY() + radius * sin((2 * M_PI / 360)*(i + 1)));
		
	}
}

Circle::~Circle(){
	delete(this);
}
