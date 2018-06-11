#include "util.h"
#include<QFile>
#include<QDebug>
#define PI 3.14159265358979323846
Util::Util()
{

}
enum Util::JointType
{
	JointType_SpineBase = 0,
	JointType_SpineMid = 1,
	JointType_Neck = 2,
	JointType_Head = 3,
	JointType_ShoulderLeft = 4,
	JointType_ElbowLeft = 5,
	JointType_WristLeft = 6,
	JointType_HandLeft = 7,
	JointType_ShoulderRight = 8,
	JointType_ElbowRight = 9,
	JointType_WristRight = 10,
	JointType_HandRight = 11,
	JointType_HipLeft = 12,
	JointType_KneeLeft = 13,
	JointType_AnkleLeft = 14,
	JointType_FootLeft = 15,
	JointType_HipRight = 16,
	JointType_KneeRight = 17,
	JointType_AnkleRight = 18,
	JointType_FootRight = 19,
	JointType_SpineShoulder = 20,
	JointType_HandTipLeft = 21,
	JointType_ThumbLeft = 22,
	JointType_HandTipRight = 23,
	JointType_ThumbRight = 24
};
vector<vector<Point>> Util::getpoint(const QString &value)
{
	path = value;
    vector<vector<Point>> pp;
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return pp;
    }
    SACsvStream csv(&file);
    while(!csv.atEnd())
    {
        vector<Point> p;
        QStringList res = csv.readCsvLine();
        for (int i = 0; i < res.size()-1; ++i) {
            Point point;
            QStringList ql = res[i].split(",");
            point.x = QString2double(ql[0]);
            point.y = QString2double(ql[1]);
            point.z = QString2double(ql[2]);
			point.state = QString2double(ql[3]);
			qDebug() << point.state;
            p.push_back(point);
        }
        pp.push_back(p);
    }
    qDebug()<< pp.size();
    file.close();
    return pp;
}


double Util::QString2double(QString str)
{
    return str.toDouble();
}

vector<vector<Point>> Util::fusion(vector<vector<Point>> s1, vector<vector<Point>> s2)
{//s1为基准骨架，s2为待融合骨架
    //对齐
	//double dis1,dis2 = 999;//极小化距离
	//double radiany, radianz = 0;//旋转弧度
	//double v1x, v1y, v1z, v2x, v2y, v2z, v3x, v3y, v3z;//基准数据（hipleft，hipright，spinemid）
	//double v1_x, v1_y, v1_z, v2_x, v2_y, v2_z, v3_x, v3_y, v3_z;
	//Point hipleft_true, hipright_true ,spinemid_true;//基准点
	//Point hipleft_temp, hipright_temp, spinemid_temp;//待融合点
	//vector<vector<Point>> fusion;//融合后的数据
	///*第一步，将两个骨架都选取hip center关节点作为局部坐标原点，以使得两幅骨架原点对齐*/
	///*qDebug() << s1.size();
	//qDebug() << s2.size();*/
	//for (int i = 0; i < s1.size(); i++)
	//{//每一帧
	//	
	//	for (int j = 1; j < s1[i].size(); j++)
	//	{//一帧中骨骼点数量
	//		s1[i][j].x -= s1[i][0].x;
	//		s1[i][j].y -= s1[i][0].y;
	//		s1[i][j].z -= s1[i][0].z;
	//	}
	//	s1[i][0].x = 0;
	//	s1[i][0].y = 0;
	//	s1[i][0].z = 0;
	//	
	//	for (int k = 1; k < s2[i].size(); k++)
	//	{//一帧中骨骼点数量
	//		s2[i][k].x -= s2[i][0].x;
	//		s2[i][k].y -= s2[i][0].y;
	//		s2[i][k].z -= s2[i][0].z;
	//	}
	//	s2[i][0].x = 0;
	//	s2[i][0].y = 0;
	//	s2[i][0].z = 0;
	//}

	///*第二步，通过旋转hip right和hip left关节点与基准骨架的相应两个关节点尽量对齐，先y后z,以求得旋转角度*/
	//for (int i = 0; i < s1.size(); i++)
	//{//每一帧
	//	/*得到两个基准点坐标*/
	//	hipleft_true = s1[i][12];
	//	v1x = hipleft_true.x;
	//	v1y = hipleft_true.y;
	//	v1z = hipleft_true.z;

	//	hipright_true = s1[i][16];
	//	v2x = hipright_true.x;
	//	v2y = hipright_true.y;
	//	v2z = hipright_true.z;

	//	spinemid_true = s1[i][1];
	//	v3x = spinemid_true.x;
	//	v3y = spinemid_true.y;
	//	v3z = spinemid_true.z;
	//	/*------------------*/

	//	/*得到两个临时点坐标*/
	//	hipleft_temp = s2[i][12];
	//	v1_x = hipleft_temp.x;
	//	v1_y = hipleft_temp.y;
	//	v1_z = hipleft_temp.z;
	//	
	//	hipright_temp = s2[i][16];
	//	v2_x = hipright_temp.x;
	//	v2_y = hipright_temp.y;
	//	v2_z = hipright_temp.z;

	//	hipright_true = s1[i][1];
	//	v3_x = spinemid_true.x;
	//	v3_y = spinemid_true.y;
	//	v3_z = spinemid_true.z;
	//	/*------------------*/

	//	/*计算基准点和临时点对齐时旋转的角度*/
	//	/*先绕y轴旋转*/
	//	radiany = atan(v1x * v1_z + v2x * v2_z - v1_x * v1z - v2_x * v2z + v3x * v3_z - v3_x * v3z) / (v1_x * v1x + v2_x * v2x + v1_z * v1z + v2_z * v2z + v3_x * v3x + v3_z * v3z);
	//	
	//	hipleft_temp = rotate(hipleft_temp, radiany, 0);
	//	hipright_temp = rotate(hipright_temp, radiany, 0);
	//	
	//	v1_x = hipleft_temp.x;
	//	v1_y = hipleft_temp.y;
	//	v1_z = hipleft_temp.z;

	//	v2_x = hipright_temp.x;
	//	v2_y = hipright_temp.y;
	//	v2_z = hipright_temp.z;
	//	/*----------*/
	//	dis1 = sqrt(pow(v1x - v1_x, 2) + pow(v1z - v1_z, 2)) + sqrt(pow(v2x - v2_x, 2) + pow(v2z - v2_z, 2));//初始距离
	//	/*再绕z轴旋转*/
	//	radianz = atan(v1x * v1_y + v2x * v2_y - v1_x * v1y - v2_x * v2y + v3x * v3_y - v3_x * v3y) / (v1_x * v1x + v2_x * v2x + v1_y * v1y + v2_y * v2y + v3_x * v3x + v3_y * v3y);

	//	hipleft_temp = rotate(hipleft_temp, 0, radianz);
	//	hipright_temp = rotate(hipright_temp, 0, radianz);

	//	v1_x = hipleft_temp.x;
	//	v1_y = hipleft_temp.y;
	//	v1_z = hipleft_temp.z;

	//	v2_x = hipright_temp.x;
	//	v2_y = hipright_temp.y;
	//	v2_z = hipright_temp.z;
	//	/*----------*/
	//	/*----------------------------------------------------*/
	//	/*开始融合*/
	//	vector<Point> p;
	//	for (int j = 0; j < s2[i].size(); j++)
	//	{//一帧中骨骼点数量
	//		Point temp = rotate(s2[i][j], radiany, radianz);
	//		p.push_back(temp);
	//	}
	//	fusion.push_back(p);
	//	/*--------------------------融合结束---------------------*/
	//	dis2 = sqrt(pow(v1x - v1_x, 2) + pow(v1z - v1_z, 2)) + sqrt(pow(v2x - v2_x, 2) + pow(v2z - v2_z, 2));//最小距离
	//	//qDebug() << radiany << radianz << dis1 << dis2;
	//}

	//for (int i = 0; i < s1.size(); i++)
	//{//每一帧
	//	for (int j = 0; j < s1[i].size(); j++)
	//	{//一帧中骨骼点数量
	//		
	//		if ((s1[i][j].state==2&&fusion[i][j].state == 2))
	//		{
	//			fusion[i][j].x = (s1[i][j].x+ fusion[i][j].x)/2;
	//			fusion[i][j].y = (s1[i][j].y + fusion[i][j].y) / 2;
	//			fusion[i][j].z = (s1[i][j].z + fusion[i][j].z) / 2;
	//			fusion[i][j].state = 2;
	//		}
	//		else if ((s1[i][j].state == 1 || s1[i][j].state == 3) && fusion[i][j].state == 2) {

	//			//               tempp.x=s1[i][j].x;
	//			//               tempp.y=s1[i][j].y;
	//			//               tempp.z=s1[i][j].z;


	//			fusion[i][j].x = (fusion[i][j].x*0.5 + s1[i][j].x*1.5) / 2;
	//			fusion[i][j].y= (fusion[i][j].y*0.5 + s1[i][j].y*1.5) / 2;

	//			fusion[i][j].z = (fusion[i][j].z*0.5 + s1[i][j].z*1.5) / 2;
	//			//fusion[i][j].state = 4;

	//		}
	//		else if ((fusion[i][j].state == 1 || fusion[i][j].state == 3) && s1[i][j].state == 2) {
	//			//                   tempp.x=s2[i][j].x;
	//			//                   tempp.y=s2[i][j].y;
	//			//                   tempp.z=s2[i][j].z;
	//			fusion[i][j].x = (s1[i][j].x*0.5 + fusion[i][j].x*1.5) / 2;
	//			fusion[i][j].y = (s1[i][j].y*0.5 + fusion[i][j].y*1.5) / 2;

	//			fusion[i][j].z = (s1[i][j].z*0.5 + fusion[i][j].z*1.5) / 2;
	//			fusion[i][j].state = 5;
	//		}

	//		else {
	//			fusion[i][j].x = (fusion[i][j].x + s1[i][j].x) / 2;
	//			fusion[i][j].y = (fusion[i][j].y + s1[i][j].y) / 2;

	//			fusion[i][j].z = (fusion[i][j].z + s1[i][j].z) / 2;
	//			fusion[i][j].state = 1;

	//		}
	//	}
	//}
	//qDebug() << fusion[23][0].x;
	//return fusion;
	//对齐
double dis = 999;

//绕Y轴
vector<Point>  p1 = s1[0];
vector<Point>  p2 = s2[0];
int size = 1;
size = p1.size();
vector<vector<Point>> fusion;
for (int i = 0; i<s1.size(); i++) {


	for (int j = 1; j<p1.size(); j++) {
		s1[i][j].x -= s1[i][0].x;
		s1[i][j].y -= s1[i][0].y;
		s1[i][j].z -= s1[i][0].z;
		s2[i][j].x -= s2[i][0].x;
		s2[i][j].y -= s2[i][0].y;
		s2[i][j].z -= s2[i][0].z;


	}
	s2[i][0].x = 0;
	s2[i][0].y = 0;
	s2[i][0].z = 0;
	s1[i][0].x = 0;
	s1[i][0].y = 0;
	s1[i][0].z = 0;
}
int theta[999] = { 0 };
for (int frame = 0; frame<p1.size(); frame++)
	for (double i = 0; i <= 360; i++) {

		double tempdis = sqrt(pow((s2[frame][12].x*sin(i*PI / 180) + s2[frame][12].x*cos(i*PI / 180) - s1[frame][12].x), 2) + pow(s2[frame][12].y, 2) + pow((-s2[frame][12].z*sin(i*3.14159265358979323846 / 180) + s2[frame][12].z*cos(i*3.14159265358979323846 / 180) - s1[frame][12].z), 2))
			+ sqrt(pow((s2[frame][16].x*sin(i*PI / 180) + s2[frame][16].x*cos(i*3.14159265358979323846 / 180) - s1[frame][16].x), 2) + pow(s2[frame][16].y, 2) + pow((-s2[frame][16].z*sin(i*3.14159265358979323846 / 180) + s2[frame][16].z*cos(i*3.14159265358979323846 / 180) - s1[frame][16].z), 2));
		tempdis += sqrt(pow((s2[frame][1].x*sin(i*3.14159265358979323846 / 180) + s2[frame][1].x*cos(i*3.14159265358979323846 / 180) - s1[frame][1].x), 2) + pow(s2[frame][1].y, 2) + pow((-s2[frame][1].z*sin(i*3.14159265358979323846 / 180) + s2[frame][1].z*cos(i*3.14159265358979323846 / 180) - s1[frame][1].z), 2));
		if (dis>tempdis) {
			dis = tempdis;
			theta[frame] = i;
		}

	}
int theta2[999] = { 0 };
//绕z轴
for (int frame = 0; frame<p1.size(); frame++) {
	double newx12 = (s2[frame][12].x*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][12].x*cos(theta[frame] * 3.14159265358979323846 / 180));
	double newy12 = s2[frame][12].y;
	double newz12 = -s2[frame][12].z*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][12].z*cos(theta[frame] * 3.14159265358979323846 / 180);
	double newx16 = s2[frame][16].x*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][16].x*cos(theta[frame] * 3.14159265358979323846 / 180);
	double newy16 = s2[frame][16].y;
	double newz16 = (-s2[frame][16].z*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][16].z*cos(theta[frame] * 3.14159265358979323846 / 180));

	double newx1 = (s2[frame][1].x*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][1].x*cos(theta[frame] * 3.14159265358979323846 / 180));
	double newy1 = s2[frame][1].y;
	double newz1 = -s2[frame][1].z*sin(theta[frame] * 3.14159265358979323846 / 180) + s2[frame][1].z*cos(theta[frame] * 3.14159265358979323846 / 180);
	double dis2 = 999;

	for (double i = 0; i <= 360; i++) {
		double tempdis = sqrt(pow(newx12*cos(i*3.14159265358979323846 / 180) - newx12*sin(i*3.14159265358979323846 / 180) - s1[0][12].x, 2) + pow(newy12*sin(i*3.14159265358979323846 / 180) + newy12*cos(i*3.14159265358979323846 / 180) - s1[0][12].y, 2) + pow(newz12 - s1[0][12].z, 2))
			+ sqrt(pow(newx16*cos(i*3.14159265358979323846 / 180) - newx16*sin(i*3.14159265358979323846 / 180) - s1[0][16].x, 2) + pow(newy16*sin(i*3.14159265358979323846 / 180) + newy16*cos(i*3.14159265358979323846 / 180) - s1[0][16].y, 2) + pow(newz16 - s1[0][16].z, 2));
		tempdis += sqrt(pow(newx1*cos(i*3.14159265358979323846 / 180) - newx1*sin(i*3.14159265358979323846 / 180) - s1[0][1].x, 2) + pow(newy1*sin(i*3.14159265358979323846 / 180) + newy1*cos(i*3.14159265358979323846 / 180) - s1[0][1].y, 2) + pow(newz1 - s1[0][1].z, 2));
		if (dis2>tempdis) {
			dis2 = tempdis;
			theta2[frame] = i;

		}

	}
}

for (int i = 0; i<s1.size(); i++) {
	vector<Point> temppp;

	for (int j = 0; j<p1.size(); j++) {
		int ffs = 4;
		int err = 1;

		if (i>ffs) {
			int num1 = 0; int num2 = 0;
			for (int x = 1; x <= ffs; x++) {
				if (s2[i - x][j].state == 1 | s2[i - x][j].state == 0)
					num1++;
				if (s1[i - x][j].state == 1 | s1[i - x][j].state == 0)
					num2++;
			}
			if (num1 >= err) {
				//cout<<"4    "<<j<<endl;
				s2[i][j].state = 3;
			}
			if (num2 >= err) {
				//cout<<"3    "<<j<<endl;
				s1[i][j].state = 3;
			}

		}
	}  if (s1[i][14].state == 1 || s1[i][14].state == 3) {
		s1[i][15].state = 3;
		s1[i][13].state = 3;

	}
	if (s2[i][14].state == 1 || s2[i][14].state == 3) {
		s2[i][15].state = 3;
		s2[i][13].state = 3;
	}
	if (s1[i][18].state == 1 || s1[i][18].state == 3) {
		s1[i][19].state = 3;
		s1[i][17].state = 3;
	}
	if (s2[i][18].state == 1 || s2[i][18].state == 3) {
		s2[i][19].state = 3;
		s2[i][17].state = 3;
	}

	for (int j = 0; j<p1.size(); j++) {
		s2[i][j].x = s2[i][j].x*sin(theta[i] * 3.14159265358979323846 / 180) + s2[i][j].x*cos(theta[i] * 3.14159265358979323846 / 180);
		s2[i][j].x = s2[i][j].x*cos(theta2[i] * 3.14159265358979323846 / 180) - s2[i][j].x*sin(theta2[i] * 3.14159265358979323846 / 180);
		s2[i][j].y = s2[i][j].y*sin(theta2[i] * 3.14159265358979323846 / 180) + s2[i][j].y*cos(theta2[i] * 3.14159265358979323846 / 180);
		s2[i][j].z = (-1 * s2[i][j].z*sin(theta[i] * 3.14159265358979323846 / 180)) + s2[i][j].z*cos(theta[i] * 3.14159265358979323846 / 180);



		Point tempp;
		if (s2[i][j].state == 2 && s1[i][j].state == 2) {

			tempp.x = (s2[i][j].x + s1[i][j].x) / 2;
			tempp.y = (s2[i][j].y + s1[i][j].y) / 2;

			tempp.z = (s2[i][j].z + s1[i][j].z) / 2;
			tempp.state = 2;
		}
		else if ((s2[i][j].state == 1 || s2[i][j].state == 3) && s1[i][j].state == 2) {

			tempp.x = (s2[i][j].x*0.5 + s1[i][j].x*1.5) / 2;
			tempp.y = (s2[i][j].y*0.5 + s1[i][j].y*1.5) / 2;

			tempp.z = (s2[i][j].z*0.5 + s1[i][j].z*1.5) / 2;
			tempp.state = 4;

		}
		else if ((s1[i][j].state == 1 || s1[i][j].state == 3) && s2[i][j].state == 2) {

			tempp.x = (s1[i][j].x*0.5 + s2[i][j].x*1.5) / 2;
			tempp.y = (s1[i][j].y*0.5 + s2[i][j].y*1.5) / 2;

			tempp.z = (s1[i][j].z*0.5 + s2[i][j].z*1.5) / 2;
			tempp.state = 5;
		}

		else {
			tempp.x = (s2[i][j].x + s1[i][j].x) / 2;
			tempp.y = (s2[i][j].y + s1[i][j].y) / 2;

			tempp.z = (s2[i][j].z + s1[i][j].z) / 2;
			tempp.state = 1;

		}

		temppp.push_back(tempp);
	}

	fusion.push_back(temppp);
}
return fusion;
}

Point Util::rotate(Point p, double radiany, double radianz)
{
	Point p1;
	p1.state = p.state;
	p1.x = cos(radianz)*(p.x*cos(radiany) - p.z*sin(radiany)) + p.y*sin(radianz);
	p1.y = sin(radianz)*(p.z*sin(radiany) - p.x*cos(radiany)) + p.y*cos(radianz);
	p1.z = p.x*sin(radiany) + p.z*cos(radiany);
	return p1;
}


