#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include"util.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	Util util;
	vector<vector<Point>> s1;
	vector<vector<Point>> s2;
	vector<vector<Point>> fusions;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

private slots:
    void fileOpenActionSlot();//打开文件动作对应的槽函数
    void on_pushButton_clicked();
	void onClickedPauseBtn();
	void onLoadBtn();
    void setLabel(QString str);
	void fusion();
	void reset();
private:
	bool clicked = false;
    Ui::MainWindow *ui;
protected:
	
};

#endif // MAINWINDOW_H
