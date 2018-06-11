#ifndef UTIL_H
#define UTIL_H
#include<vector>
#include<sacsvstream.h>
#include<QString>
#include<math.h>
using namespace std;
typedef struct point {
    double x= 0;
    double y= 0;
    double z= 0;
	int state=1;
}Point;

class Util
{
public:
	enum JointType;
    Util();
    vector<vector<Point>> pp;
    vector<Point> p;
    vector <vector<Point>> getpoint(const QString &value);
    double QString2double(QString str);
	vector <vector<Point>> fusion(vector<vector<Point>> s1, vector<vector<Point>> s2);
	Point rotate(Point p,double radiany,double radianz);
private:
    QString path;
};

#endif // UTIL_H
