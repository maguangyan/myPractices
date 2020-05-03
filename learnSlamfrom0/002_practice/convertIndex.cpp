#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main (int argc, char** argv)
{
    if (argc!=3)
    {
        cout<<"usage: convertIndex filepath newfilepath"<<endl;
        return 1;
    }
    Mat img;
    String filepath = argv[1], new_filepath = argv[2];
    vector<String> filenames;
    glob(filepath,filenames, false);
    cout<<"filenames size is :"<<filenames.size()<<endl;
    for (int i =0; i < filenames.size(); i++)
    {
        char new_name[10];
        img = imread(filenames[i], CV_LOAD_IMAGE_UNCHANGED);
        sprintf(new_name, "%04d.png", i);
        imwrite(new_filepath + new_name, img);
        cout<<new_filepath + new_name<<endl;
    }

    return 0;
}




