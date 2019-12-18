#pragma once
#include "Point2D.h"
#include "Shape.h"
#include "SDL.h"


class Circle:public Shape{
	Point2D position;
	int radius;
	int rgba[4];

public:
	Circle(int rgbaIn[4], int radiusIn, Point2D positionIn);
	virtual ~Circle();
	void Render(SDL_Renderer *renderer);

};

