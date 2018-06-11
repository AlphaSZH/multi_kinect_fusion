#include "glwidget.h"
#include<QMouseEvent>

GLwidget::GLwidget(QWidget *parent) : QOpenGLWidget(parent),
m_xRot(0),
m_yRot(0),
m_zRot(0)
{
	for (int i = 0; i < 3; i++)
	{
		sca[i] = 1;
	}
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePoint()));//刷新骨骼点数据jpp
    timer->start(30);
}


void GLwidget::resizeGL(int w, int h)
{

}

void GLwidget::drawLine(int i)
{//定义点，以第0个点为中心
	glVertex3f(p[i].x - p[0].x, p[i].y - p[0].y, -(p[i].z - p[0].z));
	//glVertex3f(p[i].x, p[i].y, p[i].z);
}

void GLwidget::mousePressEvent(QMouseEvent * event)
{
	m_lastPos = event->pos();
}

void GLwidget::mouseMoveEvent(QMouseEvent * event)
{
	int dx = event->x() - m_lastPos.x();
	int dy = event->y() - m_lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		//m_xRot += 1.1 * dy;
		m_yRot += 1.1 * dx;
	}
	else if (event->buttons() & Qt::RightButton) {
		m_xRot += 1.1 * dy;
		//m_zRot += 1.1 * dx;
	}
	m_lastPos = event->pos();
	update();
}

void GLwidget::wheelEvent(QWheelEvent * event)
{
	if (event->delta()>0) {//鼠标向上滚
		for (int i = 0; i < 3; i++)
		{
			sca[i] += 0.1;

		}
		update();
	}
	else {//鼠标向下滚
		for (int i = 0; i < 3; i++)
		{
			sca[i] -= 0.1;
			if (sca[i] <= 0.1)
			{
				sca[i] = 0.1;
			}
		}
		update();
	}
}

void GLwidget::reset()
{
	m_yRot = 0;
	m_xRot = 0;
	for (int i = 0; i < 3; i++)
	{
		sca[i] = 1;
	}
}

void GLwidget::pause()
{
	
	timer->stop();
}

void GLwidget::start()
{

	timer->start();
}

void GLwidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//清除颜色缓冲区
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glMatrixMode(GL_PROJECTION);//投影矩阵
	glLoadIdentity();
	gluPerspective(45, 1.0f, 0.0f, 500.0f);
	gluLookAt(0, 0, 2.5,
		0, 0, 0,
		0, 1.0, 0);
}

void GLwidget::paintGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	//旋转加缩放
	glRotatef(m_xRot, 1.0, 0.0, 0.0);
	glRotatef(m_yRot, 0.0, 1.0, 0.0);
	glRotatef(m_zRot, 0.0, 0.0, 1.0);
	glScalef(sca[0], sca[1], sca[2]);

    if (p.size() == 0) {
        glVertex3f(0, 0, 0);
    }
    else {
        glColor3f(1, 1, 1);
        glLineWidth(2);
        //    /*中线*/
        glBegin(GL_LINE_STRIP);
        drawLine(0);
        drawLine(1);
        drawLine(20);
        drawLine(2);
        drawLine(3);
        glEnd();
        //    /*左右胳膊*/
        glBegin(GL_LINE_STRIP);
		drawLine(21);
        drawLine(7);
        drawLine(6);
        drawLine(5);
        drawLine(4);
        drawLine(20);
        drawLine(8);
        drawLine(9);
        drawLine(10);
        drawLine(11);
		drawLine(23);
        glEnd();
		///*左右大拇指*/
		glBegin(GL_LINE_STRIP);
		drawLine(6);
		drawLine(22);
		glEnd();
		glBegin(GL_LINE_STRIP);
		drawLine(10);
		drawLine(24);
		glEnd();
        //    /*左右腿*/
        glBegin(GL_LINE_STRIP);
        drawLine(15);
        drawLine(14);
        drawLine(13);
        drawLine(12);
        drawLine(0);
        drawLine(16);
        drawLine(17);
        drawLine(18);
        drawLine(19);
        glEnd();

        //画点
        glColor3f(1, 0, 0);
        glPointSize(6);
        glBegin(GL_POINTS);
        for (int i = 0; i < p.size(); ++i) {
			switch (p[i].state)
			{
			case 0://未捕获
				glColor3f(1.0, 0.0, 0.0);
				break;
			case 1://预测
				glColor3f(1.0, 1.0, 0.0);
				break;
			case 2://捕获
				glColor3f(0, 1, 0);
				break;
			case 4://要1这个点
				glColor3f(0, 0, 1);
				break;
			case 5://要2这个点
				glColor3f(0.8, 0.0, 0.8);
				break;
			default:
				break;
			}
			drawLine(i);
        }
        glEnd();
    }
	//glutSwapBuffers();
}

void GLwidget::setPp(const vector<vector<Point> > &value)
{
    pp = value;
}

void GLwidget::setPp(const vector<vector<Point>>& s1v, const vector<vector<Point>>& s2v)
{
	s1 = s1v;
	s2 = s2v;
}

void GLwidget::updatePoint()
{
    if (pp.size()!=0) {
        a++;
        p = pp[a];
        QString str= "now:" + QString::number(a+1) +" total:" + QString::number(pp.size());
        emit(send(str));
        if (a==pp.size()-1) {
            a=0;
        }
    }
    update();
}
