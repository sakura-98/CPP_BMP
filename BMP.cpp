#include "BMP.h"
#include <stdio.h>
#include <stdlib.h>
inline void d2h(char* head,int n,int size){
        for(int i=0;i<size;i++){
                head[i]=char(n&255);
                n=n>>8;
        }
}

BMP::BMP(int biWidth,int biHeight,bool colors){
        int biBitCount=1+23*colors;
        int RGBQUAD=2*!colors;
        
        this->biWidth=biWidth;this->biHeight=biHeight;
        this->biRealWidth=(biWidth*biBitCount+31)/32*4;
        this->biSizeImage=biHeight*biRealWidth;
        this->colors=colors;

        set_fhead(RGBQUAD);
        set_ihead(biBitCount);
        set_chead();
        set_pic(biSizeImage);
}

BMP::~BMP(){
        delete[] fhead;
        delete[] ihead;
        delete[] chead;
        delete[] pic;
}

void BMP::set_fhead(int RGBQUAD){
        fhead=new char[14];
        fhead[0]='B';fhead[1]='M';
        d2h(&(fhead[2]),54+4*RGBQUAD+biSizeImage,4);
        d2h(&(fhead[6]),0,4);
        d2h(&(fhead[10]),54+4*RGBQUAD,4);
}

void BMP::set_ihead(int biBitCount){
        ihead=new char[40];
        d2h(&(ihead[0]),40,4);
        d2h(&(ihead[4]),biWidth,4);d2h(&(ihead[8]),biHeight,4);
        d2h(&(ihead[12]),1,2);
        d2h(&(ihead[14]),biBitCount,2);
        d2h(&(ihead[16]),0,4);
        d2h(&(ihead[20]),biSizeImage,4);
        d2h(&(ihead[24]),0,4);d2h(&(ihead[28]),0,4);
        d2h(&(ihead[32]),0,4);d2h(&(ihead[36]),0,4);
}

void BMP::set_chead(){
        if(!colors){
                chead=new char[8];
                chead[0]=chead[1]=chead[2]=chead[3]=0;
                chead[4]=chead[5]=chead[6]=chead[7]=255;
        }
        else chead=new char[0];
}

void BMP::set_pic(int biSizeImage){
        pic=new char[biSizeImage];
        for(int i=0;i<biSizeImage;i++)
                pic[i]=255;
}

void BMP::set_at(int x,int y,int r,int g,int b){
        //make the function reasonable
        if(!colors) set_at(x,y,r+g+b>382);
        //make the statics reasonable
        if(x<0)x=0;if(x>=biWidth)x=biWidth-1;
        if(y<0)y=0;if(y>=biWidth)y=biWidth-1;
        if(r<0)r=0;if(r>255)r=255;
        if(g<0)g=0;if(g>255)g=255;
        if(b<0)b=0;if(b>255)b=255;
        x=biWidth-x-1;
        //draw
        int pos=x*biRealWidth+3*y;
        pic[pos]=b;pic[pos+1]=g;pic[pos+2]=r;
}

void BMP::set_at(int x,int y,bool white){
        //make the function reasonable
        if(colors) set_at(x,y,255*white,255*white,255*white);
        //make the statics reasonable
        if(x<0)x=0;if(x>=biWidth)x=biWidth-1;
        if(y<0)y=0;if(y>=biWidth)y=biWidth-1;
        x=biWidth-x-1;//y=biHeight-y-1;
        
        //draw
        int pos=x*biRealWidth+y/8,div=7-y%8;
        pic[pos]=(pic[pos]&(255-(1<<div)))|(white<<div);
}

void BMP::save(const char* c){
        FILE* file;
        if(c) file=fopen(c,"wb");
        else file=fopen("temp.bmp","wb");
        for(int i=0;i<14;i++)
            fputc(fhead[i],file);
        for(int i=0;i<40;i++)
            fputc(ihead[i],file);
        if(!colors)
            for(int i=0;i<8;i++)
                fputc(chead[i],file);
        for(int i=0;i<biSizeImage;i++)
            fputc(pic[i],file);
        fclose(file);
}

void BMP::show(){
        save();
        system("xdg-open temp.bmp");
}
