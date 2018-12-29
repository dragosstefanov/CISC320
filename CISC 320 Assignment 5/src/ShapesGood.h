// Dragos Stefanov
// 15ds73

#include <string>

using namespace std;

// Base class that all other classes will inherit from
class Shape {
public:
	Shape(int length, int width, string borderColor);  // Constructor
	virtual ~Shape() {};  // Destructor
	int getLength() { return length; }
	int getWidth() { return width; }
	string getBorderColor() { return borderColor; }
	virtual void draw() = 0;

private:
	int length;
	int width;
	string borderColor;

protected:
	virtual void drawShape() = 0;
};


class Fill {
public:
	Fill(string fillColor);
	virtual ~Fill() {};
	string getFillColor() { return fillColor; }

private:
	string fillColor;

protected:
	virtual void drawFill() = 0;
};


class Label {
public:
	Label(string label);
	virtual ~Label() {};
	string getLabel() { return label; }

private:
	string label;

protected:
	virtual void drawLabel() = 0;
};


class Square : public Shape {
public:
	Square(int length, int width, string borderColor);
	virtual void draw() {
		drawShape();
	}

protected:
	virtual void drawShape();
};


class FilledSquare : public Square, Fill {
public:
	FilledSquare(int length, int width, string borderColor, string fillColor);
	virtual void draw() {
		drawShape();
		drawFill();
	}

protected:
	virtual void drawFill();
};



class FilledTextSquare : public FilledSquare, Label {
public:
	FilledTextSquare(int length, int width, string borderColor, string fillColor, string label);
	virtual void draw() {
		drawShape();
		drawFill();
		drawLabel();
	}

protected:
	virtual void drawLabel();
};


class Circle : public Shape {
public:
	Circle(int length, int width, string borderColor);
	virtual void draw() {
		drawShape();
	}

protected:
	virtual void drawShape();
};


class FilledCircle : public Circle, Fill {
public:
	FilledCircle(int length, int width, string borderColor, string fillColor);
	virtual void draw() {
		drawShape();
		drawFill();
	}

protected:
	virtual void drawFill();
};


class Arc : public Shape {
public:
	Arc(int length, int width, string borderColor);
	virtual void draw() {
		drawShape();
	}

protected:
	virtual void drawShape();
};





