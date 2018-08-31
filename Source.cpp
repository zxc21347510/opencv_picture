//#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv2/stitching.hpp>

using namespace cv;
using namespace std;

/*
	img.cols 寬 w
	img.rows 高 h
	x->水平 往右+
	y->垂直 往下+
*/

/*
vector<Mat> imgs;		//保存拼接的原始圖像向量
Mat picture;			//保存切割後的圖像
Mat cut;				//

//導入所有原始拼接圖像函數
void parseCmdArgs(int number, string *array);
void cutPicture(string name);
void resizePicture(string name);*/

int main()
{
	//導入拼接圖像
	int number;
	string *array;
	cout << "please inout number of picuture" << endl;
	cin >> number;

	/*string tmp[14] =
	{
		"/home/project108/opencv_picture/1.JPG","/home/project108/opencv_picture/2.JPG",
		"/home/project108/opencv_picture/3.JPG","/home/project108/opencv_picture/4.JPG",
		"/home/project108/opencv_picture/5.JPG","/home/project108/opencv_picture/6.JPG",
		"/home/project108/opencv_picture/7.JPG","/home/project108/opencv_picture/8.JPG",
		"/home/project108/opencv_picture/9.JPG","/home/project108/opencv_picture/10.JPG",
		"/home/project108/opencv_picture/11.JPG","/home/project108/opencv_picture/12.JPG",
		"/home/project108/opencv_picture/13.JPG","/home/project108/opencv_picture/14.JPG"
	};*/
	
	string tmp[14] =
	{
		"1.JPG","2.JPG",
		"3.JPG","4.JPG",
		"5.JPG","6.JPG",
		"7.JPG","8.JPG",
		"9.JPG","10.JPG",
		"11.JPG","12.JPG",
		"13.JPG","14.JPG"
	};

	array = new string[number];

	for (int i = 0;i < number;i++)
	{
		array[i] = tmp[i];
	}

	for (int i = 0;i < number;i++)
	{
		cout << array[i] << endl;
	}

	/*parseCmdArgs(number, array);
	Mat pano;
	Stitcher stitcher = Stitcher::createDefault(false);
	Stitcher::Status status = stitcher.stitch(imgs, pano);//拼接 
	if (status != Stitcher::OK) //判斷拼接是否成功
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return -1;
	}
	//namedWindow("全景拼接", 0);
	//imshow("全景拼接", pano);
	/*imwrite("/home/project108/opencv_picture/result1.jpg", pano);
	cout << "合成結束" << endl;
	cutPicture("/home/project108/opencv_picture/result1.jpg");
	imwrite("/home/project108/opencv_picture/result2.jpg", picture);
	cout << "切割結束" << endl;
	resizePicture("home/project108/opencv_picture/result2.jpg");
	imwrite("/home/project108/opencv_picture/result3.jpg", cut);
	cout << "resize結束" << endl;*/
	
	/*imwrite("result1.jpg", pano);
	cout << "合成結束" << endl;
	/*cutPicture("result1.jpg");
	imwrite("result2.jpg", picture);
	cout << "切割結束" << endl;
	resizePicture("result2.jpg");
	imwrite("result3.jpg", cut);
	cout << "resize結束" << endl;*/
	//system("pause");
	return 0;
}

//導入所有原始拼接圖像函數
/*void parseCmdArgs(int number, string* array)
{
	for (int i = 0;i<number;i++)
	{
		Mat img = imread(array[i]);
		if (img.empty())
		{
			cout << "Can't read image '" << array[i] << "'\n";
		}
		imgs.push_back(img);
	}
}

void cutPicture(string name)
{
	Mat tmp = imread(name);
	//Mat img = imread("/home/project108/opencv_picture/result.jpg");

	//裁切區域的 x 與 y 座標（左上角）
	int x = 0;
	int y = tmp.rows/2-img.rows/2;
	//cout << x << endl << y << endl;

	//裁切區域的寬度與高度
	int w = tmp.cols;
	int h = img.rows;

	//裁切圖片
	Rect rect(x, y, w, h);					 //創建一個Rect框，屬於cv中的類，四個參數代表x,y,width,height
	Mat image_cut = Mat(tmp, rect);			 //從img中按照rect進行切割，此時修改image_cut時image中對應部分也會修改，因此需要copy
	picture = image_cut.clone();			 //clone函數創建新的圖片
}

void resizePicture(string name)
{
	/*
	//尺寸調整
	resize(source ,dstination ,Size(temImage.cols/2,temImage.rows/2),0,0,CV_INTER_LINEAR);
	resize(tmp, cut, Size(tmp.cols / 2, tmp.rows / 2), 0, 0, CV_INTER_LINEAR);
	Size(round(fxsrc.cols), round(fysrc.rows));
 
	imshow("縮小",dstImage1);
	imshow("放大",dstImage2);
	*/

	/*Mat tmp = imread(name);
	resize(tmp, cut, Size(tmp.cols/2, tmp.rows/2), 0, 0, CV_INTER_LINEAR);
}
