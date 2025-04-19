#include "example.h"

example::example(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	// ����һ�� QAction ���󣬱�ʾһ�����Դ����Ķ���������Ϊ "&hello"�������丸��������Ϊ��ǰ����
	pAction = new QAction(tr("&hello"),this);
	pAction1 = new QAction(tr("&hello1"), this);
	pActionExit = new QAction(tr("&Exit"), this);

	// �ڲ˵��������һ����Ϊ "&Test" �Ĳ˵��������ö�����ӵ��˵���
	pMenutest = menuBar()->addMenu(tr("&Test"));
	pMenutest->addAction(pAction);
	pMenutest->addAction(pActionExit);

	// ���һ���µĲ˵� "&Menu1"
	pMenu1 = menuBar()->addMenu(tr("&Menu1"));  // ����һ���²˵�
	pMenu1->addAction(pAction1);  // ��������ӵ��²˵���

	// ����һ���������������ö�����ӵ���������
	main_toolbar_ = addToolBar(tr("&Main"));
	main_toolbar_->addAction(pAction);
	main_toolbar_->addAction(pAction1);
	
	// �����źźͲۣ��� pAction ������ʱ������ example ��� hello() ����
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
	// ��ʾһ����Ϣ����ʾ�û��Ƿ�ȷ���˳�
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(
		this,
		tr("Exit"),
		tr("Are you sure you want to exit?"),
		QMessageBox::Yes | QMessageBox::No
	);

	// ����û�ѡ��Yes�������˳�Ӧ�ó���
	if (reply == QMessageBox::Yes) {
		QApplication::quit();  // �˳�Ӧ�ó���
	}
}
