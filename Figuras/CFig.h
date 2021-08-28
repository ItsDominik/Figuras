#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include<math.h>
#define PI 3.14159265
using namespace System::Drawing;
class CFig
{
public:
	CFig();
	CFig(Graphics^ g);
	void dibujaMapa(Graphics^ g);
	void dibujaLineas(Graphics^ g);
	void dibujarFigura(Graphics^ g);
	void reflejoEnX();
	void reflejoEnY();
	void reflejoEnOrigen();
	void rotacion(int angulo);
	~CFig();

private:
	int a, b, c, d;
	std::vector<int> puntos;
};

CFig::CFig()
{
}

CFig::CFig(Graphics^ g)
{
	a = g->VisibleClipBounds.Width / 2;
	b = g->VisibleClipBounds.Height / 2;
	c = g->VisibleClipBounds.Bottom;
	d = g->VisibleClipBounds.Right;
	std::ifstream archivo("puntos.txt");
	int x;
	while (archivo >> x) { puntos.push_back(x); }
	archivo.close();
}

void CFig::dibujaMapa(Graphics^ g)
{
	g->DrawLine(Pens::Blue, a, 0, a, c);
	g->DrawLine(Pens::Blue, 0, b, d, b);
}

void CFig::dibujaLineas(Graphics^ g)
{
	g->DrawLine(Pens::Red, a, b, 200 + a, b - 100);
	g->DrawLine(Pens::Red, a, b, 30 + a, b - 50);
	g->DrawLine(Pens::Red, 200 + a, b - 100, 30 + a, b - 50);
}

void CFig::dibujarFigura(Graphics^ g)
{
	array<Point>^ arr = { Point(puntos.at(0) + a, b - puntos.at(1)), Point(puntos.at(2) + a, b - puntos.at(3)),
		Point(puntos.at(4) + a, b - puntos.at(5)), Point(puntos.at(6) + a, b - puntos.at(7)) };
	g->DrawPolygon(Pens::Red, arr);
}
void CFig::reflejoEnX()
{
	for (int i = 1; i < puntos.size(); i+= 2)
		puntos.at(i) *= -1;
}
void CFig::reflejoEnY()
{
	for (int i = 0; i < puntos.size(); i += 2)
		puntos.at(i) *= -1;
}
void CFig::reflejoEnOrigen()
{
	for (int i = 0; i < puntos.size(); i++)
		puntos.at(i) *= -1;
}
void CFig::rotacion(int angulo)
{
	for (int i = 0; i < puntos.size()-2; i += 2)
	{
		puntos.at(i) = puntos.at(i) * cos(angulo * PI / 180) - puntos.at(i + 1) * sin(angulo * PI / 180);
		puntos.at(i + 1) = puntos.at(i) * sin(angulo * PI / 180) + puntos.at(i + 1) * cos(angulo * PI / 180);
	}
}
CFig::~CFig()
{
}