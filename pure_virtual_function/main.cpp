#include <iostream>
#include <vector>

class Shape {
	private:
		// stuff
	public:
		// can't instanciate Shape objects
		virtual void draw() = 0;	// pure virtual function
		virtual void rotate() = 0;	// pure virtual function
		virtual ~Shape(){}
};


// did not override the pure virtual functions so these classes
// will be abstract classes
class Open_Shape: public Shape {
	public:
		virtual ~Open_Shape(){}
};

class Closed_Shape: public Shape {
	public:
		virtual ~Closed_Shape(){}
};

// concrete classes
class Line: public Open_Shape {
	public:
		virtual void draw() override {
			std::cout << "Draw Line\n";
		}
		virtual void rotate() override {
			std::cout << "Rotate Line\n";
		}
		virtual ~Line(){}
};

class Circle: public Closed_Shape {
	public:
		virtual void draw() override {
			std::cout << "Draw Circle\n";
		}
		virtual void rotate() override {
			std::cout << "Rotate Circle\n";
		}
		virtual ~Circle(){}
};

class Square: public Closed_Shape {
	public:
		virtual void draw() override {
			std::cout << "Draw Square\n";
		}
		virtual void rotate() override {
			std::cout << "Rotate Square\n";
		}
		virtual ~Square(){}
};

void screen_refresh(const std::vector<Shape *> &shapes) {
	std::cout << "Refreshing\n";
	for(const auto p: shapes){
		p->draw();
	}
}

int main(){
	// can't do this
	// Shape s;
	// Shape *ptr = new Shape();

	Shape *ptr = new Circle();
	ptr->draw();
	ptr->rotate();

	delete ptr;

	Shape *circle = new Circle();
	Shape *line = new Line();
	Shape *square = new Square();

	std::vector<Shape *> shapes {circle, line, square};
	/*
	for (const auto p: shapes){
		p->draw();
	}
	*/
	screen_refresh(shapes);

	delete circle;
	delete line;
	delete square;
	
	return 0;
}
