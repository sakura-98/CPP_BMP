# CPP_BMP
a class named BMP to draw *.bmp by draw each point
## construct function

BMP(int biWidth,int biHeight,bool colors=true)

At least, you should give the scale of the BMP file, which means biWidth and biHeight

We offer two modes: RGB colors and Black-White two colors.If the third argument "colors" is "true" or by default, you need three integers (0~255) to describe one point's color. Or you need a boolean to do, true for white and false for black.

If you do not describe some points,they are white by default


## edit points :

set_at(int x,int y,bool white)          //for colors == false 

set_at(int x,int y,int r,int g,int b)   //for colors == true

If colors == true but choosing the first set_at,it will choose the second set_at.

If colors == false but choosing the second set_at,it also will choose the first set_at. The easiest way is regarding a point with r+g+b>(255+255+255)/2 as white, else as black

If the x or y out of the picture,choose the closest point

If the r or g or b not in (0,255), choose the closet number as well

## save and show :

save(char* name='temp.bmp')

show()

easy to see their usage.
