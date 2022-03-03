#include "Simple_window.h"
#include "Graph.h"

int main(){

    using namespace Graph_lib;

    Point x {100, 100};
    Simple_window win {x, 800, 1000, "Canvas"};
    
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for(int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});    
    for(int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});

    grid.set_color(Color::red);
    
    Vector_ref<Rectangle> vr;
    for(int i = 0; i < x_size; i += x_grid){
        vr.push_back(new Rectangle{Point{i,i},Point{i+100,i+100}});
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }

    Image im1 {Point{100,300}, "gif1.gif"};
    Image im2 {Point{200,500}, "image1.jpg"};
    Image im3 {Point{500,100}, "image2.jpg"};
    Image im4 {Point{0,0}, "image3.jpg"};
    
    win.attach(im1);
    win.attach(im2);
    win.attach(im3);
    win.attach(im4);
    win.attach(grid);
    win.wait_for_button();

    for (int i = 0; i <7; ++i) {
        for (int j = 0; j <7; ++j) {
            im4.move(100, 0);
            win.wait_for_button();
        }
        im4.move(-700, 100);         
        win.wait_for_button();
    }
}


