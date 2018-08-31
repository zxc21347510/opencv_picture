#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) 
{

  // 檢查是否有指定輸入影像檔案
  if ( argc != 2 ) {
    printf("usage: DisplayImage.out <Image_Path>\n");
    return -1;
  }

  // 讀取影像檔案
  Mat image;
  image = imread( argv[1], 1 );

  // 檢查影像是否正確讀入
  if ( !image.data ) {
    printf("No image data \n");
    return -1;
  }

  imwrite("test.jpg",image);

  return 0;
}
