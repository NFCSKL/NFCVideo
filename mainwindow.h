
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <videowidget.h>
#include <qtreewidget.h>

QT_BEGIN_NAMESPACE
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

	private slots:
	void newLetter();
	void save();
	void print();
	void undo();
	void about();
	void selectionChanged(void);
	void addParagraph(const QString &paragraph);

private:
	void createActions();
	void createStatusBar();
	void createDockWindows();

	void resizeEvent(QResizeEvent * event);

	QTextEdit *textEdit;
	QTreeWidget *projectTree;
	QListWidget *paragraphsList;
	VideoWidget* wgt;
	VideoWidget* ww;
	QMenu *viewMenu;
};
//! [0]

#endif
