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
		当你在 QAction 或菜单项的文本前面加上& 并跟一个字母（如& Hello world），Qt 会将& 后面的字母（这里是 H）作为助记符。
		在图形界面中，这个字母通常会显示为下划线（例如，菜单项显示为 Hello world，H 带有下划线）。
		用户可以通过按下 Alt 键加上该字母（例如 Alt + H）来快速触发该菜单项或动作。
	*/
	hello_world_action_ = new QAction(tr("&Hello world"), this);
	connect(hello_world_action_, &QAction::triggered, this, &MainWindow::HelloWorld);
	main_menu_ = menuBar()->addMenu(tr("&Main"));
	main_menu_->addAction(hello_world_action_);
	main_toolbar_ = addToolBar(tr("&Main"));
	main_toolbar_->addAction(hello_world_action_);
}
