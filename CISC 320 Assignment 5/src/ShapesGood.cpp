// Dragos Stefanov
// 15ds73

#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;


Shape::Shape(int length, int width, string borderColor) {
	this->length = length;
	this->width = width;
	this->borderColor = borderColor;
}


Label::Label(string label) {
	this->label = label;
}


Fill::Fill(string fillColor) {
	this->fillColor = fillColor;
}


Square::Square(int length, int width, string borderColor) : Shape(length, width, borderColor) {}

void Square::drawShape() {
	cout << "\nDrawing a " << getBorderColor() << " square. ";
}


FilledSquare::FilledSquare(int length, int width, string borderColor, string fillColor) : Square(length, width, borderColor), Fill(fillColor) {}

void FilledSquare::drawFill() {
	cout << "With " << getFillColor() << " fill. ";
}


FilledTextSquare::FilledTextSquare(int length, int width, string borderColor, string fillColor, string label) : FilledSquare(length, width, borderColor, fillColor), Label(label) {}

void FilledTextSquare::drawLabel() {
	cout << "Containing the text: " << "\""<< getLabel() << "\""<< ". ";
}


Circle::Circle(int length, int width, string borderColor) : Shape(length, width, borderColor) {}

void Circle::drawShape() {
	cout << "\nDrawing a " << getBorderColor() << " circle. ";
}


FilledCircle::FilledCircle(int length, int width, string borderColor, string fillColor) : Circle(length, width, borderColor), Fill(fillColor) {}

void FilledCircle::drawFill() {
	cout << "With " << getFillColor() << " fill.";
}


Arc::Arc(int length, int width, string borderColor) : Shape(length, width, borderColor) {}

void Arc::drawShape() {
	cout << "\nDrawing a " << getBorderColor() << " arc.";
}
