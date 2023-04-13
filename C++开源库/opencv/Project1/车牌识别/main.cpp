#include<iostream>
#include<opencv2/opencv.hpp>
#include<fstream>   //�ı���д
#include<Windows.h> //����̨�����������

using namespace std;
using namespace cv;

//�Զ��峵�ƽṹ��
struct License
{
	Mat mat;  //ROIͼƬ
	Rect rect; //ROI���ھ���
};

//��ȡ��������ROI����--���ƶ�λ
bool Get_License_ROI(Mat src, License& License_ROI)
{
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	Mat thresh;
	threshold(gray, thresh, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

	//ʹ����̬ѧ������ȥ��һЩС����
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat open;
	morphologyEx(thresh, open, MORPH_OPEN, kernel);

	//ʹ�� RETR_EXTERNAL �ҵ���������
	vector<vector<Point>>contours;
	findContours(open, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>>conPoly(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		double peri = arcLength(contours[i], true);
		//�������ɸѡ���������ڳ������������

		if (area > 1000)
		{
			//ʹ�ö���ν��ƣ���һ��ȷ��������������
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			if (conPoly[i].size() == 4)
			{
				//������������߱�
				Rect box = boundingRect(contours[i]);
				double ratio = double(box.width) / double(box.height);
				if (ratio > 2 && ratio < 4)
				{
					//��ȡROI����
					Rect rect = boundingRect(contours[i]);
					License_ROI = { src(rect),rect };
				}
			}
		}
	}

	if (License_ROI.mat.empty())
	{
		return false;
	}
	return true;
}


//��ȡ����ÿһ���ַ�ROI����
bool Get_Character_ROI(License& License_ROI, vector<License>& Character_ROI)
{
	Mat gray;
	cvtColor(License_ROI.mat, gray, COLOR_BGR2GRAY);

	Mat thresh;
	threshold(gray, thresh, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat close;
	morphologyEx(thresh, close, MORPH_CLOSE, kernel);

	vector<vector<Point>>contours;
	findContours(close, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		//��������ɸѡ����������������ģ��ʺ���������Ҫ���ַ���������
		if (area > 200)
		{
			Rect rect = boundingRect(contours[i]);
			//������Ӿ��ο�߱�
			double ratio = double(rect.height) / double(rect.width);
			if (ratio > 1)
			{
				Mat roi = License_ROI.mat(rect);
				resize(roi, roi, Size(50, 100), 1, 1, INTER_LINEAR);
				Character_ROI.push_back({ roi ,rect });
			}
		}
	}

	//��ɸѡ�������ַ����� ���������Ͻǵ��������������˳������
	//ð������
	for (int i = 0; i < Character_ROI.size() - 1; i++)
	{
		for (int j = 0; j < Character_ROI.size() - 1 - i; j++)
		{
			if (Character_ROI[j].rect.x > Character_ROI[j + 1].rect.x)
			{
				License temp = Character_ROI[j];
				Character_ROI[j] = Character_ROI[j + 1];
				Character_ROI[j + 1] = temp;
			}
		}
	}

	if (Character_ROI.size() != 7)
	{
		return false;
	}
	return true;
}


//��txt�ļ��ж�ȡ���ģ���ֹ����
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

//��ȡ�ļ�  ͼƬ
bool Read_Data(string filename, vector<Mat>& dataset)
{
	vector<String>imagePathList;
	glob(filename, imagePathList);
	if (imagePathList.empty())return false;

	for (int i = 0; i < imagePathList.size(); i++)
	{
		Mat image = imread(imagePathList[i]);
		resize(image, image, Size(50, 100), 1, 1, INTER_LINEAR);
		dataset.push_back(image);
	}

	return true;
}

//��ȡ�ļ� ��ǩ
bool Read_Data(string filename, vector<string>& data_name)
{
	fstream fin;
	fin.open(filename, ios::in);
	if (!fin.is_open())
	{
		cout << "can not open the file!" << endl;
		return false;
	}

	string s;
	while (std::getline(fin, s))
	{
		string str = UTF8ToGB(s.c_str()).c_str();
		data_name.push_back(str);
	}
	fin.close();

	return true;
}



//�������ص����
int pixCount(Mat image)
{
	int count = 0;
	if (image.channels() == 1)
	{
		for (int i = 0; i < image.rows; i++)
		{
			for (int j = 0; j < image.cols; j++)
			{
				if (image.at<uchar>(i, j) == 0)
				{
					count++;
				}
			}
		}

		return count;
	}
	else
	{
		return -1;
	}
}

//ʶ�����ַ�
bool License_Recognition(vector<License>& Character_ROI, vector<int>& result_index)
{
	string filename = "data/";
	vector<Mat>dataset;
	if (!Read_Data(filename, dataset)) return false;

	for (int i = 0; i < Character_ROI.size(); i++)
	{
		Mat roi_gray;
		cvtColor(Character_ROI[i].mat, roi_gray, COLOR_BGR2GRAY);

		Mat roi_thresh;
		threshold(roi_gray, roi_thresh, 0, 255, THRESH_BINARY | THRESH_OTSU);

		int minCount = 1000000;
		int index = 0;
		for (int j = 0; j < dataset.size(); j++)
		{
			Mat temp_gray;
			cvtColor(dataset[j], temp_gray, COLOR_BGR2GRAY);

			Mat temp_thresh;
			threshold(temp_gray, temp_thresh, 0, 255, THRESH_BINARY | THRESH_OTSU);

			//��������ͼƬ�����ز�Դ��ж�����ͼƬ�Ƿ���ͬ
			Mat dst;
			absdiff(roi_thresh, temp_thresh, dst);

			int count = pixCount(dst);
			if (count < minCount)
			{
				minCount = count;
				index = j;
			}
		}

		result_index.push_back(index);
	}

	return true;
}

//��ʾ����Ч��
bool Draw_Result(Mat src, License& License_ROI, vector<License>& Character_ROI, vector<int>& result_index)
{
	rectangle(src, License_ROI.rect, Scalar(0, 255, 0), 2);

	vector<string>data_name;
	if (!Read_Data("data_name.txt", data_name))return false;

	for (int i = 0; i < Character_ROI.size(); i++)
	{
		//putText ������ʾ�����룬������������ʾ
		string str = data_name[result_index[i]];  //string ת char
		cout << str << " ";
		putText(src, str, Point(License_ROI.rect.x + Character_ROI[i].rect.x, License_ROI.rect.y + Character_ROI[i].rect.y), 3, FONT_HERSHEY_PLAIN, Scalar(0, 0, 255), 2);
	}

	return true;
}


int main()
{

	Mat src = imread("car.jpg");
	if (src.empty())
	{
		cout << "No image!" << endl;
		system("pause");
		return -1;
	}

	License License_ROI;
	if (Get_License_ROI(src, License_ROI))
	{
		vector<License>Character_ROI;
		if (Get_Character_ROI(License_ROI, Character_ROI))
		{
			vector<int>result_index;
			if (License_Recognition(Character_ROI, result_index))
			{
				Draw_Result(src, License_ROI, Character_ROI, result_index);
			}
			else
			{
				cout << "δ��ʶ���ַ���" << endl;
				system("pause");
				return -1;
			}
		}
		else
		{
			cout << "δ���и���ַ���" << endl;
			system("pause");
			return -1;
		}
	}
	else
	{
		cout << "δ��λ������λ�ã�" << endl;
		system("pause");
		return -1;
	}

	imshow("src", src);
	waitKey(0);
	system("pause");
	return 0;
}
