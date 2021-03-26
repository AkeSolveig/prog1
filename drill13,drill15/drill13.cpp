#include "Graph.h"
#include "Simple_window.h"

int main()
try
{
	constexpr int x_max = 1000;
	constexpr int y_max = 800;

	Point s(300,50);
	Simple_window win(s,x_max,y_max,"");

	Lines grid;
	int x_size=800;
	int y_size=800;
	int grid_size=100;

	for(int i = grid_size; i <=x_size; i += grid_size )
	{
		grid.add(Point(i,0), Point(i,y_size));
		grid.add(Point(0,i), Point(x_size,i));
	}

	win.attach(grid);

	Vector_ref<Rectangle> vr;
	for(int i=0; i<8; ++i)
	{
		vr.push_back(new Rectangle(Point(i*grid_size, i*grid_size), grid_size, grid_size));
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}

	

	Vector_ref<Image> vi;
	for(int i=200, j=0;i<=600 && j<3;i+=200,++j)
	{
		vi.push_back(new Image(Point{0,i}, "badge.jpg"));
		vi[j].set_mask(Point(100,100),200,200);
		win.attach(vi[j]);
	}

	Image logo(Point(0,0), "badge.jpg");
	logo.set_mask(Point(150,150),100,100);
	win.attach(logo);

	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
		{
			win.wait_for_button();
			if(j<7) logo.move(100,0);
			else logo.move(-700,100);
		}


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