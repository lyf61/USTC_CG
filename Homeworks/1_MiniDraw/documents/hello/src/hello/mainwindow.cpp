#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	CreateButtons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HelloWorld() {
	QMessageBox::about(this, tr("Hello world"),
		tr("Well done! Go ahead."));
}

void MainWindow::CreateButtons()
{
	/*
		������ QAction ��˵�����ı�ǰ�����& ����һ����ĸ����& Hello world����Qt �Ὣ& �������ĸ�������� H����Ϊ���Ƿ���
		��ͼ�ν����У������ĸͨ������ʾΪ�»��ߣ����磬�˵�����ʾΪ Hello world��H �����»��ߣ���
		�û�����ͨ������ Alt �����ϸ���ĸ������ Alt + H�������ٴ����ò˵��������
	*/
	hello_world_action_ = new QAction(tr("&Hello world"), this);
	connect(hello_world_action_, &QAction::triggered, this, &MainWindow::HelloWorld);
	main_menu_ = menuBar()->addMenu(tr("&Main"));
	main_menu_->addAction(hello_world_action_);
	main_toolbar_ = addToolBar(tr("&Main"));
	main_toolbar_->addAction(hello_world_action_);
}
