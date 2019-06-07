#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include <iostream>
#include <fstream>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_btnShowBits_clicked();

	void on_dial_2_valueChanged(int value);

	void on_btnMisc_clicked();

	void on_btnClass_clicked();

	void on_btnFileSave_clicked();

	void on_btnFileSave_2_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
