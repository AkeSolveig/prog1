/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
try 
{
	using namespace Graph_lib;

	Point tl(150,150);
	Simple_window win(tl,600,400,"My window");
	win.resize(600,400);


	Axis xa(Axis::x, Point(20,330),300,10,"X axis");
	win.attach(xa);

	Axis ya(Axis::y, Point(20,330),300,10,"Y axis");
	ya.set_color(Color::green);
	win.attach(ya);

	Function sine(sin,0.7,11,Point(1,330),350,30,30);
	sine.set_color(Color::magenta);
	win.attach(sine);

	Graph_lib::Polygon poly;
	poly.add(Point(100,125));
	poly.add(Point(75,100));
	poly.add(Point(150,25));
	poly.add(Point(225,100));
	poly.add(Point(200,125));
	poly.set_style(Line_style::dot);
	win.attach(poly);

	Graph_lib::Rectangle r(Point(100,145),100,30);
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point(350,25));
	poly_rect.add(Point(450,25));
	poly_rect.add(Point(450,75));
	poly_rect.add(Point(350,75));
	win.attach(poly_rect);

	poly_rect.add(Point(300,50));

	r.set_fill_color(Color::red);
	poly.set_style(Line_style(Line_style::dashdot,4));
	poly_rect.set_style(Line_style(Line_style::dashdotdot,2));
	poly_rect.set_fill_color(Color::blue);

	Text t(Point(125,170),"Halo");
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);

	Image ii(Point(500,100),"badge.jpg");
	win.attach(ii);

	Circle c(Point(150,250),50);
	win.attach(c);

	//Graph_lib::Ellipse e(Point(100,200),75,25);
	//e.set_color(Color::red);
	Mark m(Point(150,257),'X');
	win.attach(m);



	
	win.wait_for_button();

}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}

catch (...)
{
	cerr << "exception\n";
	keep_window_open();
}