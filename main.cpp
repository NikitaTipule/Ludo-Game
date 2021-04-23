#include<iostream>
#include<graphics.h>

using namespace std;

// Structure for Pawns
struct pawns
{
    int pos;  // position
    int  status; // status is 1 if it is not come out from source
    int sum; // required to move the pawns
};

// Structure for user
struct user
{
    struct pawns g[4];  // created pawns
    int def;    //starting position
    int color;  // for the color of pawns
    int win;    // for how many pawns reached to the home
};


int color_g[4]={4,2,14,1};
int ary[2][52]={0};
int red_hm[2][6];
int grn_hm[2][6];
int blu_hm[2][6];
int ylw_hm[2][6];

// Class ludo
class ludo {
    public:

        ludo();
        void cir(int x, int y, int c);
        void star(int x, int y);
        void flood_fill(int x, int y, int new_color, int old_color);
        void flood_fill1(int x, int y, int new_color, int old_color);
        void fill_horizotal_path(int x, int y, int c);
        void fill_vertical_path(int x, int y, int c);
        void fill_color();
        void dice(int curr, int prev);
        void path_init();
        void home_assgn();
        int home(int clr,int first,int pos);
        void play();
        int movement(int first,int last,int clr);
        int diamond(int x);
};


// Function to draw circle
void ludo::cir(int x,int y,int c){
    int r=13;

    circle(x+28,y+28,r);
    circle(x+28,y+28+55,r);
    circle(x+28+55,y+28,r);
    circle(x+28+55,y+28+55,r);
    flood_fill(x+28,y+28,c,0);
    flood_fill(x+28,y+28+55,c,0);int ary[2][15]={0};
    flood_fill(x+28+55,y+28,c,0);
    flood_fill(x+28+55,y+28+55,c,0);
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
    setcolor(12);
    rectangle(550 ,210, 610, 270);
    flood_fill(551, 211, 15, 0);
    dice(1, 0);
    dice(2, 1);
    dice(3, 2);
    dice(4, 3);
    dice(5, 4);
    dice(6, 5);
    dice(0, 6);

    return;
}

// Function to fill the color into the layout
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

// Functinon to return the coordinate of the home of given color
int ludo::diamond(int x)
{
    int a;
    if(x == 4)
        a = 51;
    else if( x == 2)
        a = 12;
    else if(x == 14)
        a = 25;
    else if (x == 1)
        a == 38;
    return a;
}


// Function to draw dice and fill it with appropriate color
void ludo::dice(int curr, int prev){

    setcolor(12);

    // to fill circle with color
    switch(prev){

        case 1:
            flood_fill(580, 240, 15, 0);
            break;

        case 2:
            flood_fill(565, 240, 15, 0);
            flood_fill(595, 240, 15, 0);
            break;

        case 3:
            flood_fill(580, 225, 15, 0);
            flood_fill(565, 255, 15, 0);
            flood_fill(595, 255, 15, 0);
            break;

        case 4:
            flood_fill(565, 255, 15, 0);
            flood_fill(595, 255, 15, 0);
            flood_fill(565, 225, 15, 0);
            flood_fill(595, 225, 15, 0);
            break;

        case 5:
            flood_fill(565, 255, 15, 0);
            flood_fill(595, 255, 15, 0);
            flood_fill(565, 225, 15, 0);
            flood_fill(595, 225, 15, 0);
            flood_fill(580, 240, 15, 0);
            break;

        case 6:
            flood_fill(565, 255, 15, 0);
            flood_fill(595, 255, 15, 0);
            flood_fill(565, 225, 15, 0);
            flood_fill(595, 225, 15, 0);
            flood_fill(580, 225, 15, 0);
            flood_fill(580, 255, 15, 0);
 
            break;
    }

    // to draw circle with appropriate color
    switch(curr){

        case 1:
            setcolor(0);
            circle(580, 240, 5);
            flood_fill(580, 240, 0, 15);
            break;

        case 2:
            setcolor(0);
            circle(565, 240, 5);
            circle(595, 240, 5);
            flood_fill(565, 240, 0, 15);
            flood_fill(595, 240, 0, 15);
            break;

        case 3:
            setcolor(0);
            circle(580, 225, 5);
            circle(565, 255, 5);
            circle(595, 255, 5);
            flood_fill(580, 225, 0, 15);
            flood_fill(565, 255, 0, 15);
            flood_fill(595, 255, 0, 15);
            break;

        case 4:
            setcolor(0);
            circle(565, 255, 5);
            circle(595, 255, 5);
            circle(565, 225, 5);
            circle(595, 225, 5);
            flood_fill(565, 255, 0, 15);
            flood_fill(595, 255, 0, 15);
            flood_fill(565, 225, 0, 15);
            flood_fill(595, 225, 0, 15);
            break;

        case 5:
            setcolor(0);
            circle(565, 255, 5);
            circle(595, 255, 5);
            circle(565, 225, 5);
            circle(595, 225, 5);
            circle(580, 240, 5);
            flood_fill(565, 255, 0, 15);
            flood_fill(595, 255, 0, 15);
            flood_fill(565, 225, 0, 15);
            flood_fill(595, 225, 0, 15);
            flood_fill(580, 240, 0, 15);
            break;

        case 6:
            setcolor(0);
            circle(565, 255, 5);
            circle(595, 255, 5);
            circle(565, 225, 5);
            circle(595, 225, 5);
            circle(580, 225, 5);
            circle(580, 255, 5);
            flood_fill(565, 255, 0, 15);
            flood_fill(595, 255, 0, 15);
            flood_fill(565, 225, 0, 15);
            flood_fill(595, 225, 0, 15);
            flood_fill(580, 225, 0, 15);
            flood_fill(580, 255, 0, 15);
            break;
    }


}

// Function to initialize the path of pawns i.e it stores the x and y co-ordinates of path into an array ( a[2][52] )
void ludo::path_init()
        {

            int i=0,j,k=0;

            for( j=0;j<=15;j++)
            {

                if(j==6)
                {
                    int m=0,p=0;
                    for(int l=6;l<19;l++)
                    {
                        if(l<=11)
                        {
                            ary[i][l]=215;
                            ary[i+1][l]=185-m*30;
                            ary[i][l+26]=275;
                            ary[i+1][l+26]=305+m*30;
                            m++;
                        }

                        else if(l==12)
                        {
                            ary[i][l]=245;
                            ary[i+1][l]=35;
                            ary[i][38]=245;
                            ary[i+1][38]=455;
                            ary[i][51]=35;
                            ary[i+1][51]=245;
                        }

                        else
                            {
                            ary[i][l]=275;
                            ary[i+1][l]=35+p*30;
                            ary[i][l+26]=215;
                            ary[i+1][l+26]=455-p*30;
                            p++;
                            }

                    }
                    j+=2;
                    k+=13;
                }
                else
                    {
                        if(j==15)
                        {
                            ary[i][j+10]=455;
                            ary[i+1][j+10]=245;
                        }

                        else
                        {
                            ary[i][k]=35+j*30;
                            ary[i+1][k] = 215;
                            ary[i][50-k]=35+j*30;
                            ary[i+1][50-k]=275;
                            k++;
                        }
                    }
            }

        }


// Function to assign home to all pawns according to their color
void ludo::home_assgn(){

    //for thr red pawns
   for(int i=0;i<6;i++) {
       // x co-ordinate is varing
       red_hm[0][i]=65+30*i; // for x co ordinate
       red_hm[1][i]=245; // for y co ordinate
   }

    //for the green pawns
   for(int i=0;i<6;i++) {

       grn_hm[0][i]=245; // x co ordinate
       grn_hm[1][i]=65+30*i; // y co-ordinate

   }

    // for the blue pawns
   for(int i=0;i<6;i++) {

       blu_hm[0][i]=245; // x co-ordinate
       blu_hm[1][i]=425-30*i; // y co-ordinate
   }

    //for the yellow pawns
   for(int i=0;i<6;i++) {

       ylw_hm[0][i]=425-30*i;  // x co-ordinate
       ylw_hm[1][i]=245;  // y co-ordinate

   }

}

// Function to move the pawns .
// In this function we have to give argument :first for the initial position of pawn and
// last means till where we have to move that pawn
int ludo::movement(int first,int last,int clr) {

    int num=6,temp=0,q,rx,ry,prev,prs=0,t1,t2;


    //update play
    // move the graph
    // end of function
    // new turn to player

    for(q=first;q<=last;q++) {

        if(q==52) {

            last=last-52;
            movement(0,last,clr);
            q=0;
            return 0;
        }

        prs=getpixel(ary[0][q],ary[1][q]);

        // It will create a cicle as pawn of the given color and fill it with delay so that we can see the animations
        setcolor(clr);
        rx=ary[0][q];
        ry=ary[1][q];
        delay(200);
        circle(rx,ry,12);
        flood_fill(rx,ry,clr,0);
        delay(200);
        if(prs!=clr||q==first){
            setcolor(0);
            circle(rx,ry,12);

            flood_fill(rx,ry,0,clr);
        }
    }

    // When it reaches to the destination then it only draw circle and keep it
    setcolor(clr);
    circle(rx,ry,12);
    flood_fill(rx,ry,clr,0);
}

// Function to move the pawn into its home area .
int ludo::home(int clr,int first,int pos) {

    int ab,remn,tmp,rx,ry;
    int bdb;
    tmp=diamond(clr);

    if(first > 5) {
        movement(first,tmp,clr);
        bdb=0;
        remn=pos-tmp;
        flood_fill(ary[0][tmp],ary[1][tmp],0,clr);
    }
    else {
        if(pos > 6) {
            return first;
        }
        bdb=first;
        remn=pos;
    }
   //printf(" bdb %d remn %d",bdb,remn);

    switch(clr)
    {
        // for blue pawn
        case 1:
            if(bdb > 0){
                setcolor(1);
                rx=blu_hm[0][bdb-1];
                ry=blu_hm[1][bdb-1];
                circle(rx,ry,12);
                flood_fill(rx,ry,1,3);
            }
            for(ab=bdb;ab<remn;ab++){
                clr=3;
                setcolor(clr);
                rx=blu_hm[0][ab];
                ry=blu_hm[1][ab];
                delay(200);
                circle(rx,ry,12);
                flood_fill(rx,ry,clr,1);
                delay(200);
                setcolor(1);
                circle(rx,ry,12);
                flood_fill(rx,ry,1,clr);
            }
            setcolor(clr);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,1);
            break;

        // for green pawn
        case 2:
            if(bdb > 0){
                setcolor(2);
                rx=grn_hm[0][bdb-1];
                ry=grn_hm[1][bdb-1];
                circle(rx,ry,12);
                flood_fill(rx,ry,2,3);
            }
            for(ab=bdb;ab<remn;ab++){
                clr=3;
                setcolor(clr);
                rx=grn_hm[0][ab];
                ry=grn_hm[1][ab];
                delay(200);
                circle(rx,ry,12);
                flood_fill(rx,ry,clr,2);
                delay(200);
                setcolor(2);
                circle(rx,ry,12);
                flood_fill(rx,ry,2,clr);
            }
            setcolor(clr);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,2);
            break;

        // for red pawn
        case 4:
            if(bdb > 0){
                setcolor(4);
                rx=red_hm[0][bdb-1];
                ry=red_hm[1][bdb-1];
                circle(rx,ry,12);
                flood_fill(rx,ry,4,3);
            }
            for(ab=bdb;ab<remn;ab++){
                clr=3;
                setcolor(clr);
                rx=red_hm[0][ab];
                ry=red_hm[1][ab];
                delay(200);
                circle(rx,ry,12);
                flood_fill(rx,ry,clr,4);
                delay(200);
                setcolor(4);
                circle(rx,ry,12);
                flood_fill(rx,ry,4,clr);
            }
            setcolor(clr);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,4);
            break;


        // for yellow pawns
        case 14:
            if(bdb > 0){
                setcolor(14);
                rx=ylw_hm[0][bdb-1];
                ry=ylw_hm[1][bdb-1];
                circle(rx,ry,12);
                flood_fill(rx,ry,14,3);
            }
            for(ab=bdb;ab<remn;ab++){
                clr=3;
                setcolor(clr);
                rx=ylw_hm[0][ab];
                ry=ylw_hm[1][ab];
                delay(200);
                circle(rx,ry,12);
                flood_fill(rx,ry,clr,14);
                delay(200);
                setcolor(14);
                circle(rx,ry,12);
                flood_fill(rx,ry,14,clr);
            }
            setcolor(clr);
            circle(rx,ry,12);
            flood_fill(rx,ry,clr,14);
            break;

    }

    return ab;

}




void ludo::play(){

    struct user  *student;
    int n,k=1;

    int num;
    printf("\n HOW MANY PLAYERS : ");
    scanf("%d",&n);
    student = (struct user *)malloc(n*sizeof(struct user));

    // intialise the users
    for(int i =0;i< n;i++) {

        for(int j=0;j<4;j++){
            student[i].g[j].pos=-1;
            student[i].g[j].sum=0;
            student[i].g[j].status=1;
        }
        student[i].win=0;
        student[i].def=k;
        k+=13;
    }
     //gameplaye and movement
    int i=0, prev=0;
    printf ("GAME STARTED ");

    while(1) {

       printf ("\nplayer-%d ::",i);
       int num,run,first,getcl,safejone;
      //generate random number and get it in pos
      // and give again chance to same user
       //num
       // find which one user want to play in   run
       //give the extra conditionsssss
        while(1) {

            //generated dice number using rand function
            num = (rand() % 6 ) +1;
            printf("\tDICE : %d :",num);
            dice(num, prev);
            prev = num;
            printf("\n\tTO MOVE : (0,1,2,3)  ::");
            scanf("%d",&run);                     // which pawns to move

            // check if the pawn has reached home or not
            if( student[i].g[run].status==0) {
               cout<<"it already reached home "<<endl;
               break;
            }

            if(num == 6) {

               // function to check if the pawn is come out or not
               // this function will take the pawn out
                if(student[i].g[run].pos== -1) {

                    student[i].g[run].pos = student[i].def;
                    student[i].g[run].sum=0;
                }

                else{

                    student[i].g[run].sum+=num;
                    first = student[i].g[run].pos;

                    getcl=getpixel(ary[0][first+num],ary[1][first+num]);

                    if(getcl != 0 && getcl != color_g[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  ) {
                        // eat the other player
                        int l,m;
                        for( l=0;l<n;l++)   //get the player
                            {
                                if(student[l].color == getcl)
                                break;
                            }
                        printf(" :: m %d  :",m);
                        for( m=0 ; m<4;m++)  // get the particular player
                            { if( student[l].g[m].pos == first+num)
                                    break;
                            }
                            student[l].g[m].pos =-1;  //  intial stage set
                            printf("pawns number %d %d",m,l);
                            flood_fill(ary[0][first+num],ary[1][first+num],0,getcl);
                    }

                     printf("sum :%d\n",student[i].g[run].sum);
                     if(student[i].g[run].sum > 50)
                     {
                            student[i].g[run].pos=home(color_g[i],first,first+num);
                              if(  student[i].g[run].pos == 6)
                                    {cout<<"\t\t\tFINISHED"<<endl;    student[i].g[run].status=0;
                                        student[i].win+=1;
                                      }
                           break;
                     }

                    movement(first,(first+num),color_g[i]);
                    student[i].g[run].pos = (student[i].g[run].pos+num)%52;

                 }
                continue;
            }
            else{
                    // check if it is not came out
                    if(student[i].g[run].pos==-1){
                        printf(" \n\t\t::CANNOT MOVE ::");
                        break;
                    }

                    student[i].g[run].sum+=num;
                    first = student[i].g[run].pos;
                    getcl=getpixel(ary[0][first+num],ary[1][first+num]);

                    if(getcl != 0 && getcl != color_g[i] && first+num != 1 && first+num != 9 && first+num != 14 && first+num != 22 && first+num != 27 && first+num != 35 && first+num != 40 && first+num !=48  ) {
                        // eat other pawn
                        int l=0,m=0;
                        for( l=0;l<n;l++) {
                            if(color_g[l] == getcl)
                                break;
                        }

                        for( m=0 ; m<4;m++) {
                            if( student[l].g[m].pos == first+num)
                                break;
                        }

                        student[l].g[m].pos =-1;
                        flood_fill(ary[0][first+num],ary[1][first+num],0,getcl);
                    }

                    // if the pawn is in home area
                    if( student[i].g[run].sum >50) {

                        printf("  \t \t HOME TIME ");

                        student[i].g[run].pos= home(color_g[i],first,first+num);
                            if(student[i].g[run].pos == 6) {
                                cout<<"\t\t\t FINISHED"<<endl;   student[i].g[run].status=0;
                                    student[i].win+=1;
                                    if(student[i].win==4) {
                                        cout<<"\t\t\t\t*******WINNER IS :"<<i<<"  ******"<<endl;
                                        return;
                                    }
                            }

                        break;
                    }

                    movement(first,(first+num),color_g[i]);
                    student[i].g[run].pos=(student[i].g[run].pos+num)%52;
                    break;
                }

          }
            i=(i+1)%n;
        }

    }



// Driver code
int main(){

    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,NULL);
    ludo L;

    L.fill_color();
    L.path_init();
    L.home_assgn();
    L.play();
    getch();
    closegraph();
    return 0;
}
