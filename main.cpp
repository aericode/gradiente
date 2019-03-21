#include <iostream>
#include <fstream>

using namespace std;

class Color{
public:
	int r;
	int g;
	int b;

	Color(){}
	Color(int r_, int g_, int b_){
		r = r_;
		g = g_;
		b = b_;
	}

};

class Location{
public:
	int x;
	int y;

	Location(){}
	Location(int x_,int y_){
		x = x_;
		y = y_;
	}
};


Color gradient(Location location, float xMax, float yMax){
	float rPercent = location.x/xMax;
	float gPercent = location.y/yMax;
	float bPercent = 0.2;

	int r = int(255.99*rPercent);
	int g = int(255.99*gPercent);
	int b = int(255.99*bPercent);

	return Color(r,g,b);
}


int main(){

	ofstream myfile;
	myfile.open ("image.ppm");
	
	int nx = 200;
	int ny = 100;

	myfile<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
	for (int j = ny - 1;j >= 0; j--){
		for (int i = 0; i < nx ; i++){

			Color nextColor = gradient(Location(i,j),nx,ny);

			myfile<<nextColor.r<<" "<<nextColor.g<<" "<<nextColor.b<<endl;
		}
	}

	myfile.close();
	return 0;
}