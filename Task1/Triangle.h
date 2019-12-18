#pragma once
#include "Point2D.h"
#include "Shape.h"
#include "SDL.h"



class Triangle:public Shape{
	Point2D position;
	int height;
	int base;
	int rgba[4];

public:
	Triangle(int rgbaIn[4], int baseIn, int heightIn, Point2D positionIn);
	virtual ~Triangle();
	void Render(SDL_Renderer *renderer);

};