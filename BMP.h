#ifndef BMP_H
#define BMP_H

inline void d2h(char* head,int n,int size);

class BMP{
public:
        BMP(int biWidth,int biHeight,bool colors=true);
        ~BMP();
        
        void set_at(int x,int y,int r,int g,int b);
        void set_at(int x,int y,bool white);
        void show();
        void save(const char* c=0);

private:
        void set_fhead(int RGBQUAD);
        void set_ihead(int biBitCount);
        void set_chead();
        void set_pic(int biSizeImage);

        char* fhead;
        char* ihead;
        char* chead;
        char* pic;

        bool colors;
        int biWidth,biHeight;
        int biRealWidth;
        int biSizeImage;
};

#endif //BMP
