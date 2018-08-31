#include <fstream> 
#include <iostream> 
#include <opencv2/opencv.hpp>
#include <opencv2/stitching.hpp>

using namespace cv;
using namespace std;

/*
	img.cols 寬 w
	img.rows 高 h
	x->水平 往右+
	y->垂直 往下+
*/


vector<Mat> imgs;		//保存拼接的原始圖像向量 
Mat picture;			//保存切割後的圖像
Mat cut;				//

//導入所有原始拼接圖像函數
void parseCmdArgs(int number, string *array);
void cutPicture(string name);
void resizePicture(string name);

int main(int argc, char* argv[])
{
	//導入拼接圖像 
	int number;
	string *array;
	cout << "please inout number of picuture" << endl;
	cin >> number;

	string tmp[9] =
	{
		"C:\\Users\\User\\Desktop\\tests\\DSC_0039.jpg","C:\\Users\\User\\Desktop\\tests\\DSC_0040.jpg",
		"C:\\Users\\User\\Desktop\\tests\\DSC_0041.jpg","C:\\Users\\User\\Desktop\\tests\\DSC_0042.jpg",
		"C:\\Users\\User\\Desktop\\tests\\DSC_0043.jpg","C:\\Users\\User\\Desktop\\tests\\DSC_0044.jpg",
		"C:\\Users\\User\\Desktop\\tests\\DSC_0045.jpg","C:\\Users\\User\\Desktop\\tests\\DSC_0046.jpg",
		"C:\\Users\\User\\Desktop\\tests\\DSC_0047.jpg"
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

	parseCmdArgs(number, array);
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
	imwrite("C:\\Users\\User\\Desktop\\全景拼接.jpg", pano);
	cout << "合成結束" << endl;
	cutPicture("C:\\Users\\User\\Desktop\\全景拼接.jpg");
	imwrite("C:\\Users\\User\\Desktop\\全景拼接2.jpg", picture);
	cout << "切割結束" << endl;
	resizePicture("C:\\Users\\User\\Desktop\\全景拼接2.jpg");
	imwrite("C:\\Users\\User\\Desktop\\全景拼接3.jpg", cut);
	cout << "resize結束" << endl;
	system("pause");
	return 0;
}

//導入所有原始拼接圖像函數
void parseCmdArgs(int number, string* array)
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
	Mat img = imread("C:\\Users\\User\\Desktop\\tests\\DSC_0039.jpg");

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

	Mat tmp = imread(name);
	resize(tmp, cut, Size(tmp.cols/2, tmp.rows/2), 0, 0, CV_INTER_LINEAR);
}