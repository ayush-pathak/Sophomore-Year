#include<iostream>
#include<fstream>
using namespace std;

int main(){
float imageX, imageY, paperX, paperY;//needs to be floats so that the scaleX/Y are floats
float scaleX, scaleY;
int scale;  //this is so that it will truncate the floating points to just the integer part
cin>> imageX>>imageY>>paperX>>paperY;
	while (imageX != 0){
	if(imageX>imageY){
	  int temp = imageX;
	  imageX = imageY;
	  imageY = temp;
	}
	if (paperX>paperY){
	  int temp = paperX;
	  paperX = paperY;
	  paperY = temp;
	}
	scaleX = paperX/imageX;
	scaleY = paperY/imageY;
	
	if(scaleX<scaleY){
	  scale = scaleX*100;
	}
	else{
	  scale = scaleY*100;
	}
	if(scale>100){
	  scale = 100;
	}	
	cout << scale <<"%" << endl;
	cin >> imageX>>imageY>>paperX>>paperY;
	}
}

