#include "BMP.h"
#define SIZE 500
#define EDAG 100

int main(){
        BMP pic(SIZE,SIZE/*,true*/);
        //draw red
        for (int i=0;i<EDAG;i++)
                for(int j=0;j<SIZE;j++)
                        pic.set_at(i,j,255,0,0);
        //mix red and blue
        for (int i=EDAG;i<SIZE-EDAG;i++)
                for(int j=0;j<SIZE;j++)
                        if((i+j)%2) pic.set_at(i,j,0,0,255);
                        else pic.set_at(i,j,255,0,0);
        //draw blue
        for(int i=SIZE-EDAG;i<SIZE;i++)
                for(int j=0;j<SIZE;j++)
                        pic.set_at(i,j,0,0,255);
        
        pic.show();
        return 0;
}
