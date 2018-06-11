#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QFile>
#include <gl/glut.h>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <util.h>
#include <QTimer>
using namespace std;

static const float c_JointThickness = 3.0f;
static const float c_TrackedBoneThickness = 6.0f;
static const float c_InferredBoneThickness = 1.0f;

class GLwidget :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:

    QTimer *timer;
    explicit GLwidget(QWidget *parent = 0);
	void reset();
    void setPp(const vector<vector<Point> > &value);
	void setPp(const vector<vector<Point> > &s1, const vector<vector<Point> > &s2);
    vector<Point> p;
    int a = -1;
    void drawLine(int i);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	
signals:
    void send(QString str);
public slots:
    void updatePoint();
	void pause();
	void start();
private:
	int m_xRot;
	int m_yRot;
	int m_zRot;
	QPoint m_lastPos;
	GLfloat sca[3];//Ëõ·Å
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    vector<vector<Point>> pp;
	vector<vector<Point>> s1;
	vector<vector<Point>> s2;
};

#endif // GLWIDGET_H
