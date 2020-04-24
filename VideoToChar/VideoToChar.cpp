#include "VideoToChar.h"

using namespace std;
using namespace cv;

int main()
{
	Mat frame, gray;
	VideoCapture video("./test.mp4");
	if (!video.isOpened())
	{
		cout << "视频未成功打开" << endl;
		return -1;
	}
	int cols = video.get(CAP_PROP_FRAME_WIDTH);
	int rows = video.get(CAP_PROP_FRAME_HEIGHT);
	int frame_count = video.get(CAP_PROP_FRAME_COUNT);
	int fps = video.get(CAP_PROP_FPS);
	float speed = 1;  // 播放倍速
	int delty = 20;
	int deltx = 10;
	int value = 0;
	int n = 0;
	char c[] = ".,_-=+*`^~:!1&%@#$";
	vector<string> v;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 0 };
	system("cls");
	while (n < frame_count)
	{
		video.read(frame);
		
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		string s = "";
		for (int row = 0; row < rows - delty; row += delty)
		{
			for (int col = 0; col < cols - deltx; col += deltx)
			{
				value = gray.at<uchar>(row, col);
				s = s + c[int(value / 15)];
			}
			s = s + "\n";
		}
		v.push_back(s);
		SetConsoleCursorPosition(h, pos);
		printf("正在读取 %d/%d", n, frame_count);
		n++;
	}
	// -- play
	for (int i = 0; i < v.size(); i++){
		SetConsoleCursorPosition(h, pos);
		cout << v[i];
		waitKey(1000 / fps / speed);
	}
	return 0;
}
