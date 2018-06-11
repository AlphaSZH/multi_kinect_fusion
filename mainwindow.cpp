#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "QDebug"
#include "sacsvstream.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->c1btn,SIGNAL(clicked()),this,SLOT(fileOpenActionSlot()));
    connect(ui->c2btn,SIGNAL(clicked()),this,SLOT(fileOpenActionSlot()));
    connect(ui->c3btn,SIGNAL(clicked()),this,SLOT(fileOpenActionSlot()));
    connect(ui->camera1gl,SIGNAL(send(QString)),this,SLOT(setLabel(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileOpenActionSlot()
{
    QPushButton *ccc  = (QPushButton*) sender();


    //定义文件对话框类
    QFileDialog *fileDialog = new QFileDialog(this);
    //定义文件对话框标题
    fileDialog->setWindowTitle(tr("打开文件"));
    //设置默认文件路径
    fileDialog->setDirectory(".");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("file(*.csv)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
        if(ccc->objectName() == "c1btn")
        {
            ui->camera1->setText(fileNames[0]);
            ui->log->appendPlainText("camera1 opened");
        }
        if(ccc->objectName() == "c2btn")
        {
            ui->camera2->setText(fileNames[0]);
            ui->log->appendPlainText("camera2 opened");
        }
        if(ccc->objectName() == "c3btn")
        {
            ui->camera3->setText(fileNames[0]);
            ui->log->appendPlainText("camera3 opened");
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->camera1gl->setPp(s1);
    ui->camera2gl->setPp(s2);
	ui->camera3gl->setPp(fusions);
	//ui->camera4gl->setPp(fusions);
}

void MainWindow::onClickedPauseBtn()
{//暂停按钮
	if (!clicked)
	{
		clicked = true;
		ui->pausebtn->setText(tr("continue"));
		ui->camera1gl->pause();
		ui->camera2gl->pause();
		ui->camera3gl->pause();
	}
	else
	{
		clicked = false;
		ui->camera1gl->start();
		ui->camera2gl->start();
		ui->camera3gl->start();
		ui->pausebtn->setText(tr("pause"));
	}
	
	
}

void MainWindow::onLoadBtn()
{//加载数据
	s1=util.getpoint(ui->camera1->text());
	s2=util.getpoint(ui->camera2->text());
	fusion();
	on_pushButton_clicked();
}

void MainWindow::setLabel(QString str)
{
    ui->label->setText(str);
}

void MainWindow::fusion()
{//对数据进行融合
	fusions=util.fusion(s1,s2);
}

void MainWindow::reset()
{
	ui->camera1gl->reset();
	ui->camera2gl->reset();
	ui->camera3gl->reset();
}


