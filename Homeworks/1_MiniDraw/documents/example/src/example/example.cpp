#include "example.h"

example::example(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// 创建一个 QAction 对象，表示一个可以触发的动作，名称为 "&hello"，并将其父对象设置为当前窗口
	pAction = new QAction(tr("&hello"),this);
	pAction1 = new QAction(tr("&hello1"), this);
	pActionExit = new QAction(tr("&Exit"), this);

	// 在菜单栏中添加一个名为 "&Test" 的菜单，并将该动作添加到菜单中
	pMenutest = menuBar()->addMenu(tr("&Test"));
	pMenutest->addAction(pAction);
	pMenutest->addAction(pActionExit);

	// 添加一个新的菜单 "&Menu1"
	pMenu1 = menuBar()->addMenu(tr("&Menu1"));  // 创建一个新菜单
	pMenu1->addAction(pAction1);  // 将动作添加到新菜单中

	// 创建一个工具栏，并将该动作添加到工具栏中
	main_toolbar_ = addToolBar(tr("&Main"));
	main_toolbar_->addAction(pAction);
	main_toolbar_->addAction(pAction1);
	
	// 连接信号和槽：当 pAction 被触发时，调用 example 类的 hello() 方法
	connect(pAction, &QAction::triggered, this, &example::hello);
	connect(pAction1, &QAction::triggered, this, &example::compliment);
	connect(pActionExit, &QAction::triggered, this, &example::exit);
}

example::~example()
{

}

void example::hello()
{
	QMessageBox::information(NULL, "Hello", "Hello, Qt", QMessageBox::Yes);
}

void example::compliment()
{
	QMessageBox::information(NULL, "compliment", "u haobangbang", QMessageBox::Yes);
}

void example::exit()
{
	// 显示一个消息框，提示用户是否确认退出
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(
		this,
		tr("Exit"),
		tr("Are you sure you want to exit?"),
		QMessageBox::Yes | QMessageBox::No
	);

	// 如果用户选择“Yes”，则退出应用程序
	if (reply == QMessageBox::Yes) {
		QApplication::quit();  // 退出应用程序
	}
}
