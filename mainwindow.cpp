//! [0]
#include <QtWidgets>
#ifndef QT_NO_PRINTDIALOG
#include <QtPrintSupport>
#endif

#include "mainwindow.h"

#include <opencv2\opencv.hpp>
//! [0]

//! [1]
MainWindow::MainWindow()
	: textEdit(new QTextEdit)
{
	myWidget = new MyTestWidget(this);

	wgt = new VideoWidget(this);
	wgt->setMinimumSize(200, 200);

	setCentralWidget(wgt);
	//setCentralWidget(textEdit);

	setMinimumSize(400, 400);

	createActions();
	createStatusBar();
	createDockWindows();

	setWindowTitle(tr("NFC Video Anayser"));

	newLetter();
}
//! [1]

//! [2]
void MainWindow::newLetter()
{
	cv::Mat img = cv::imread("E:\\6.Testdata\\Bilder\\fruits.jpg");
	//cv::Mat img = cv::imread("C:\\2.Testdata\\Bilder\\fruits.jpg");

	wgt->showImage(img);

}
//! [2]

//! [3]
void MainWindow::print()
{
	QDockWidget *dock = new QDockWidget(tr("Video"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	VideoWidget* vv = new VideoWidget(dock);
	dock->setWidget(vv);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	statusBar()->showMessage(tr("Created video dockwidget"), 2000);
}
//! [3]

//! [4]
void MainWindow::save()
{
	ww = new VideoWidget(NULL);
	ww->show();
}
//! [4]

//! [5]
void MainWindow::undo()
{
	ww->close();
	QWidget* savedWidget = centralWidget();
	savedWidget->setParent(0);//now it is saved
	setCentralWidget(myWidget);
}
//! [5]

//! [6]
void MainWindow::selectionChanged()
{
	//if (customer.isEmpty())
	//	return;
	//QStringList customerList = customer.split(", ");
	//QTextDocument *document = textEdit->document();
	//QTextCursor cursor = document->find("NAME");
	//if (!cursor.isNull()) {
	//	cursor.beginEditBlock();
	//	cursor.insertText(customerList.at(0));
	//	QTextCursor oldcursor = cursor;
	//	cursor = document->find("ADDRESS");
	//	if (!cursor.isNull()) {
	//		for (int i = 1; i < customerList.size(); ++i) {
	//			cursor.insertBlock();
	//			cursor.insertText(customerList.at(i));
	//		}
	//		cursor.endEditBlock();
	//	}
	//	else
	//		oldcursor.endEditBlock();
	//}
}
//! [6]

//! [7]
void MainWindow::addParagraph(const QString &paragraph)
{
	if (paragraph.isEmpty())
		return;
	QTextDocument *document = textEdit->document();
	QTextCursor cursor = document->find(tr("Yours sincerely,"));
	if (cursor.isNull())
		return;
	cursor.beginEditBlock();
	cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 2);
	cursor.insertBlock();
	cursor.insertText(paragraph);
	cursor.insertBlock();
	cursor.endEditBlock();

}
//! [7]

void MainWindow::about()
{
	QWidget* savedWidget = centralWidget();
	savedWidget->setParent(0);//now it is saved
	setCentralWidget(wgt);
}

void MainWindow::createActions()
{
	QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
	QToolBar *fileToolBar = addToolBar(tr("File"));

	const QIcon newIcon = QIcon::fromTheme("document-new", QIcon("C:/Users/NIAP/Documents/GitHub/NFCVideo/images/new.png"));
	QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
	newLetterAct->setShortcuts(QKeySequence::New);
	newLetterAct->setStatusTip(tr("Create a new form letter"));
	connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
	fileMenu->addAction(newLetterAct);
	fileToolBar->addAction(newLetterAct);

	const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon("C:/Users/NIAP/Documents/GitHub/NFCVideo/images/save.png"));
	QAction *saveAct = new QAction(saveIcon, tr("&Save..."), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the current form letter"));
	connect(saveAct, &QAction::triggered, this, &MainWindow::save);
	fileMenu->addAction(saveAct);
	fileToolBar->addAction(saveAct);

	const QIcon printIcon = QIcon::fromTheme("document-print", QIcon("C:/Users/NIAP/Documents/GitHub/NFCVideo/images/print.png"));
	QAction *printAct = new QAction(printIcon, tr("&Print..."), this);
	printAct->setShortcuts(QKeySequence::Print);
	printAct->setStatusTip(tr("Print the current form letter"));
	connect(printAct, &QAction::triggered, this, &MainWindow::print);
	fileMenu->addAction(printAct);
	fileToolBar->addAction(printAct);

	fileMenu->addSeparator();

	QAction *quitAct = fileMenu->addAction(tr("&Quit"), this, &QWidget::close);
	quitAct->setShortcuts(QKeySequence::Quit);
	quitAct->setStatusTip(tr("Quit the application"));

	QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
	QToolBar *editToolBar = addToolBar(tr("Edit"));
	const QIcon undoIcon = QIcon::fromTheme("edit-undo", QIcon("C:/Users/NIAP/Documents/GitHub/NFCVideo/images/undo.png"));
	QAction *undoAct = new QAction(undoIcon, tr("&Undo"), this);
	undoAct->setShortcuts(QKeySequence::Undo);
	undoAct->setStatusTip(tr("Undo the last editing action"));
	connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
	editMenu->addAction(undoAct);
	editToolBar->addAction(undoAct);

	viewMenu = menuBar()->addMenu(tr("&View"));

	menuBar()->addSeparator();

	QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

	QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
	aboutAct->setStatusTip(tr("Show the application's About box"));

	QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
	aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

	//showFullScreen();
	//resize(QGuiApplication::primaryScreen()->availableSize() );
}

//! [8]
void MainWindow::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}
//! [8]

//! [9]
void MainWindow::createDockWindows()
{
	QDockWidget *dock = new QDockWidget(tr("Project"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	projectTree = new QTreeWidget(dock);
	QTreeWidgetItem *parentItem = new QTreeWidgetItem();
	parentItem->setText(0, "E:\\7.DEP\\Icons1\\1471538888_video.png");
	parentItem->setIcon(0, *(new QIcon("E:\\7.DEP\\Icons1\\1471538888_video.png")));
	projectTree->addTopLevelItem(parentItem);
	projectTree->setIconSize(QSize(50, 50));

	QTreeWidgetItem *child1 = new QTreeWidgetItem();
	child1->setText(0,"Motion detection");
	child1->setIcon(0, *(new QIcon("E:\\7.DEP\\Icons1\\1471538879_search.png")));
	parentItem->addChild(child1);

	child1 = new QTreeWidgetItem();
	child1->setText(0, "Motion detection2");
	cv::VideoCapture cap("E:\\6.Testdata\\SL\\FHP-P112.avi");
	cv::Mat frame;
	cap >> frame;
	QImage qimage = QImage(frame.data, frame.cols, frame.rows, frame.cols * 3, QImage::Format_RGB888);
	QPixmap pix;
	pix.convertFromImage(qimage);
	QIcon ico(pix);

	child1->setIcon(0, ico);
	//child1->setIcon(0, *(new QIcon(pix)));
	parentItem->addChild(child1);

	dock->setWidget(projectTree);
	addDockWidget(Qt::LeftDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());

	dock = new QDockWidget(tr("Paragraphs"), this);
	paragraphsList = new QListWidget(dock);
	paragraphsList->addItems(QStringList()
		<< "Thank you for your payment which we have received today."
		<< "Your order has been dispatched and should be with you "
		"within 28 days."
		<< "We have dispatched those items that were in stock. The "
		"rest of your order will be dispatched once all the "
		"remaining items have arrived at our warehouse. No "
		"additional shipping charges will be made."
		<< "You made a small overpayment (less than $5) which we "
		"will keep on account for you, or return at your request."
		<< "You made a small underpayment (less than $1), but we have "
		"sent your order anyway. We'll add this underpayment to "
		"your next bill."
		<< "Unfortunately you did not send enough money. Please remit "
		"an additional $. Your order will be dispatched as soon as "
		"the complete amount has been received."
		<< "You made an overpayment (more than $5). Do you wish to "
		"buy more items, or should we return the excess to you?");
	dock->setWidget(paragraphsList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	viewMenu->addAction(dock->toggleViewAction());

	connect(projectTree, &QTreeWidget::currentItemChanged,
		this, &MainWindow::selectionChanged);
	connect(paragraphsList, &QListWidget::currentTextChanged,
		this, &MainWindow::addParagraph);
}
//! [9]

void MainWindow::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

}