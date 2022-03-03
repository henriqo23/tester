#include "Simple_window.h"
#include "Graph.h"

int main()
{

	using namespace Graph_lib;

	Point tl{100,100}; //define a point that we will use as the top left corner of our window

	Simple_window win{tl,600,400,"MY window"}; //make a simple window (point to be used, width, length, name)

	Axis xa {Axis::x, Point{20,300},280,10, "x axis"};
	
	Axis ya {Axis::y, Point{20,300},280,10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::red);

	Function sine{sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::black);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::dark_red);
	poly.set_style(Line_style::dash);

	Rectangle r {Point{200,200},100,50};

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::blue);

	Text t{Point{150,150}, "Hello, graphical world!"};
	//t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{400,30}, "image1.jpg"};
	
	Circle c{Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::yellow);
	Mark m{Point{100,200}, 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{Point{100,20},oss.str()};

	Image cal{Point{225,225}, "gif1.gif"};
	cal.set_mask(Point{20,50},200,150);

	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);

	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(ii);

	win.wait_for_button(); //give control to the display engine




}