#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;

int main(int, char **)
{
    std::string filename = "data/test_video.mp4";

    VideoCapture cap;
    Mat frame;

    cap.open(filename);

    if (!cap.isOpened())
    {
        std::cerr << "no video is opened\n";
        return -1;
    }

    namedWindow("frame", 1);
    while (1)
    {
        cap.read(frame);
        if (frame.empty())
        {
            std::cerr << "frame is empty\n";
            break;
        }

        imshow("Live", frame);
        waitKey(20);
    }

    waitKey(0);
    return 0;
}
