#pragma once
#include "Point2D.h"
#include "Shape.h"
#include "SDL.h"


class Rectangle:public Shape{
	Point2D position;
	int height;
	int width;
	int rgba[4];

public:
	Rectangle(int rgbaIn[4], int widthIn, int heightIn,Point2D positionIn);
	virtual ~Rectangle();
	void Render(SDL_Renderer *renderer);

};

