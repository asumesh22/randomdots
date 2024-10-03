//
// *** replace "7" with your Student ID number ***
//
// this seeds the state of the random number generator
//
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//
#include <time.h>
#include <iostream>
//
using namespace std ;
using namespace cv  ;
//
int main( int argc , char* argv[] )
{
    Mat img( 480 , 640 ,    CV_8UC3    , Scalar(0,0,0) ); // black
    Point2d p1(160,0) , p2(160,480) ;
    Point2d p3(320,0), p4(320,480) ;
    Point2d p5(480,0), p6(480,480) ;
    //
    MatIterator_<Vec3b> it ;
    //
    RNG rng(1617620) ;
    //
    int black = 0 ;
    int white = 0 ;
    for ( int row = 0 ; row < img.rows ; row++ )
    {
        for ( int col = 0 ; col < img.cols / 4 ; col++ )
        {
            unsigned int x = rng . next() ;
            for (int i = 0 ; i < 4 ; i++ )
            {
                Vec3b pixel = img . at<Vec3b>( row , col + i * 160) ;
                double y = x * 1.0 / UINT_MAX ;
                if ( y > 0.5 ) {
                    pixel[0] = 255 ;
                    pixel[1] = 255 ;
                    pixel[2] = 255 ;
                    white++;
                } else {
                    black++;
                }            
                img . at<Vec3b>( row , col + i * 160 ) = pixel ;
            }
        }
    }
    cout << black << endl ;
    cout << white << endl ;
        
    //
    line( img , p1 , p2 , Scalar(0,0,255) , 2 , LINE_AA ) ;   // red, 2-pixels thick, anti-aliasing
    line( img , p3 , p4 , Scalar(0,0,255) , 2 , LINE_AA ) ;   // red, 2-pixels thick, anti-aliasing
    line( img , p5 , p6 , Scalar(0,0,255) , 2 , LINE_AA ) ;   // red, 2-pixels thick, anti-aliasing
    //
    //
    //
    imwrite( "step02_rng.jpg" , img ) ;
    //
    return 0 ;
}
//
// end
//
