#include<iostream>
#include<graphics.h>

using namespace std;

class ludo {
    public:

        ludo();
        void cir(int x, int y, int c);
        void star(int x, int y);
        void flood_fill(int x, int y, int new_color, int old_color);
        void fill_horizotal_path(int x, int y, int c);
        void fill_vertical_path(int x, int y, int c);
        void fill_color();
};


// Function to draw circle
void ludo::cir(int x,int y,int c){
    int r=13;

    circle(x+28,y+28,r);
    circle(x+28,y+28+55,r);
    circle(x+28+55,y+28,r);
    circle(x+28+55,y+28+55,r);
    return;
}

// Function to draw star
void ludo::star(int x,int y){
    line(x-7, y-7, x, y+10);
    line(x, y+10, x+7, y-7);
    line(x+7, y-7, x-7, y-7);
    line(x-7, y+7, x+7, y+7);
    line(x+7, y+7, x, y-10);
    line(x, y-10, x-7, y+7);

    return;
}


// Costructor
ludo::ludo(){
    int i=0,x,y,j;
    setcolor(12);
    rectangle(20, 20, 470, 470);
    line(200, 20, 200, 470);
    line(230, 20, 230, 200);
    line(230, 290, 230, 470);
    line(290, 230, 470, 230);
    line(260, 20, 260, 200);
    line(260, 290, 260, 470);
    line(290, 20, 290, 470);
    line(20, 200, 470, 200);
    line(20, 230, 200, 230);
    line(290, 230, 470, 230);
    line(20, 260, 200, 260);
    line(290, 260, 470, 260);
    line(20, 290, 470, 290);
    line(200, 200, 290, 290);
    line(200, 290, 290, 200);
    star(65, 215);
    star(215, 95);
    star(275, 65);
    star(395, 215);
    star(425, 275);
    star(275, 395);
    star(215, 425);
    star(95, 275);
    rectangle(50, 50, 170, 170);
    rectangle(55, 55, 165, 165);
    rectangle(320, 50, 440, 170);
    rectangle(325, 55, 435, 165);
    rectangle(50, 320, 170, 440);
    rectangle(55, 325, 165, 435);
    rectangle(320, 320, 440, 440);
    rectangle(325, 325, 435, 435);
    for(i = 0; i < 15; i++){
        if(i >= 6 && i <= 9)
            continue;
        line(20+i*30, 200, 20+i*30, 290);
    }
    for(i = 0; i < 15; i++){
        if(i >= 6 && i <= 9)
            continue;
        line(200,20+i*30,290,20+i*30);
    }
    x=55,y=55;
    cir(x, y, 4);
    cir(x+270, y, 2);
    cir(x, y+270, 1);
    cir(x+270, y+270, 14);

    return;
}

void ludo::flood_fill(int x, int y, int new_color, int old_color){

    int c;
    c=getpixel(x,y);
    if(c==old_color){
        setcolor(new_color);
        putpixel (x, y, new_color);
        flood_fill(x+1, y, new_color, old_color);
        flood_fill(x, y+1, new_color, old_color);
        flood_fill(x-1, y, new_color, old_color);
        flood_fill(x, y-1, new_color, old_color);
    }
    return;
}

// Function to fill color in horizontal path
void ludo::fill_horizotal_path(int x, int y, int c){

    int i = 0;
    for(i = 0; i < 5; i++){
        flood_fill(x+i*30, y, c, 0);
    }
    return;
}

// Function to fill color in vertical path
void ludo::fill_vertical_path(int x, int y, int c){

    int i=0;
    for(i = 0; i < 5; i++){
        flood_fill(x, y+i*30, c, 0);
    }
    return;
}

// Function to fill color in the layout
void ludo::fill_color(){

    flood_fill(235,245,4,0);
    flood_fill(245,235,2,0);
    flood_fill(245,275,1,0);
    flood_fill(275,245,14,0);
    flood_fill(21,21,4,0);
    flood_fill(291,21,2,0);
    flood_fill(21,291,1,0);
    flood_fill(291,291,14,0);
    flood_fill(56,56,15,0);
    flood_fill(56,326,15,0);
    flood_fill(326,56,15,0);
    flood_fill(326,326,15,0);
    flood_fill(51,201,11,0);
    flood_fill(201,81,11,0);
    flood_fill(261,51,11,0);
    flood_fill(381,201,11,0);
    flood_fill(411,261,11,0);
    flood_fill(261,381,11,0);
    flood_fill(201,411,11,0);
    flood_fill(81,261,11,0);

    fill_horizotal_path(55,245,4);
    fill_horizotal_path(305,245,14);
    fill_vertical_path(245,55,2);
    fill_vertical_path(245,305,1);
}

// Driver code
int main(){

    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,NULL);
    ludo L;
    L.fill_color();
    getch();
    closegraph();
    return 0;
}
