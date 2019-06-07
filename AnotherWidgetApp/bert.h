#ifndef BERT_H
#define BERT_H

#include <QMainWindow>
#include <sstream>
#include <iostream>
#include <fstream>
#include <QMessageBox>

namespace Ui {
class Bert;
}

class Bert : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bert(QWidget *parent = nullptr);
    ~Bert();
	void MiscFunction (int &, int &, int &);
	void myself(int n);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_dial_valueChanged(int value);

    void on_radioButton_3_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_dial_2_valueChanged(int value);

	void on_checkBox_3_stateChanged(int arg1);

	void on_pushButton_5_clicked();

	void on_pushButton_7_clicked();

	void on_pushButton_6_clicked();

	void on_pushButton_8_clicked();

	void on_pushButton_9_clicked();

	void on_pushButton_10_clicked();

	void on_pushButton_11_clicked();

	void on_dial_2_actionTriggered(int action);

	void on_pushButton_13_clicked();

	void on_pushButton_14_clicked();

	void on_pushButton_15_clicked();

	void on_pushButton_16_clicked();

	void on_pushButton_17_clicked();

	void on_pushButton_18_clicked();

private:
    Ui::Bert *ui;
};

#endif // BERT_H
