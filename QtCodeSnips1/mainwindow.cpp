/*
 * NOTE most of these code snips are from "AnotherWIdgetApp, bert.cpp & bert.h"
 * in "C:\Users\frig\OneDrive\Documents\Qt Projects" on new i3.  See this file
 * for complete versions including ways things DIDNT work properly in comments.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
// See header file for additional includes (like stringstream, etc)...how they got there???
using namespace std;

typedef enum{A,B,C,D,E}Letter;	// This and the next lines are both typedefs
enum suit {CLUBS = 3, DIAMONDS = 6, HEARTS = 7, SPADES = 26, JACKS, JILLS};
const double myPI = 3.141592653589792;  // PI 'seems' to already be defined in QT as 'PI'...or maybe not????
const double PI = 3.141592653589792;
// enums are really just a different way of dealing with integer constants, although
//  as a type (like suit above) they strictly limit you to the enumerated choices.
float coords[2][3] = {{1,2,3},{4,5,6}};  // out of function array def


void showbits(unsigned int x, char *arr, int arrSize)	// integer to binary cvrtr
{
	int i = 0;		//This is a Much better version of this
	int offSet = 2;
	for (i = arrSize - 2; i>=0; i--)
		(x & (1u << i)) ? arr[(arrSize - offSet) - i] = '1' : arr[(arrSize - offSet) - i] = '0';
	arr[arrSize - 1]='\0';
}

inline int factorial(int n) {return ((n == 1) ? 1 : (factorial(n - 1) * n)); }
// Think of above as     n! = (((((1)*2)*3)*4)*5) for n=5, 1st stage
//		is all about filling up the '* n' expressions as it telescopes
//		out (expands), 2nd stage collapses as it calculates n!  Wonder
//		if n could have been passed by reference (&n).


class cBert {
protected:
	double dProtectedVariable = 999;
public:
	cBert() {sYear = 2019;}
	~cBert() {}
	enum {GREEN = 1, RED, BLUE};
	// ////// Variables
	int iAge = 15;
	int sYear;
	string sName;
	static int iAlert; // init to = GREEN outside main class def;
	string sAlert = "green";  // A single static variable is shared with ALL instances of this object
		// Static vairables allow object instances to communicate with each other.  You dont even need an instance of it to access vairable (hint Bert::sAlert = 55;)
	// ////// Functions
	// setters
	void setTemp(float tempTemp) {fTemperature = tempTemp;}
	void setCity(string tmpCity) {sCity = tmpCity;}
	void setPlace(string tmpPlace) {sPlace = tmpPlace;}
	// getters
	double getProtected() {return dProtectedVariable;}
	float getTemp() {return fTemperature;}
	string getCity() {return sCity;}
	string getPlace() {return sPlace;}
	double Calculate(int Multiplier);
private:
	string sPlace;
	string sCity = "tulsa";
	float fTemperature;
};

int cBert::iAlert = GREEN;  // Initialize static variable

double cBert::Calculate(int Multiplier) {
	double i;
	for(int n = 0; n <= 100; n++) {
		i += this->iAge * Multiplier + n;
		if (i > 100000) {
			this->iAlert = RED;
			this->sAlert = "red";
			this->dProtectedVariable = i * 7.433;
			return i + n;
		}
	}
	this->iAlert = BLUE;
	sAlert = "Blue";
	this->dProtectedVariable = i;
	return i * Multiplier;
}

class cRobert: public cBert {
public:
	string stDerived = "Derived Class Robert Variable";
};


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);	// Constructor
}

MainWindow::~MainWindow()
{
	delete ui;			// Destructor
}

void MainWindow::on_btnShowBits_clicked()	//'ShowBits'f(x) button
{
	char arr[sizeof(int) * 8 + 1]; // also:	char arr2[] = {'a','s','s',' ','H','o','l','e',' ','F','u','c','k','e','r','\0'};
	int arrSiz = sizeof(arr);
	ui->lblArrSiz->setText(QVariant(arrSiz).toString());
	showbits(ui->dial_2->value(), arr, arrSiz);
	ui->tbShowBits->setText(arr);	// char arrays need no conversion
}

void MainWindow::on_dial_2_valueChanged(int value)
{
	ui->tbShowBits->setText(QVariant(value).toString());
}

void MainWindow::on_btnMisc_clicked()
{
	int num=0;
	while (num<10)
	{
		num++;
		if (num==5) continue;	// This will ensure the #5 does NOT show up in list as it will skip the rest of the loop & start next iteration
		// ========================= WORKS !!  No Newline on edit box ========
		ui->textEdit->textCursor().insertText(QVariant(num).toString());
		ui->textEdit->textCursor().insertText(",   ");
		// ===================================================================
	}
	ui->textEdit->append("\n\n");
	suit x;
	x = CLUBS;
//	x = 5;		// Gives an error and rightly so!
	Letter y;
	y = C;
	int x1 = 5, y1 = 88;
	string MyStr = "x = Clubs = " + to_string(x) + ", y = C = " + to_string(y);
	float yy = (float)y1 + 1.25;
	x1 += yy;
	string Sx1;
	Sx1 = to_string(x1);
	string Sy1 = to_string(y1);
	string MyStr2 = "x1 = 5 = " + Sx1 + ", y1 = 88 = " + Sy1;
	QString qSx = "I dont Know ";
	QString qSy = " but Fuck 8 of you!";
	QString qSS = qSx + qSy + " Bout Time" + to_string(y1).c_str();

	ui->textEdit->append(qSS);
	ui->lblMisc->setText(MyStr.c_str());
	ui->tbMisc->setText(MyStr2.c_str());
// The MyStr.find(substring,0); MyStr.swap(Str2); MyStr.insert(10,substring);
//		are interesting also.
	ui->textEdit->append(QString("Constants include PI: %1 and Spades: %2, Jacks: %3 and Jills: %4.").arg(PI,SPADES,JACKS,JILLS));
	ui->textEdit->append(QString("Constants include myPI: %1 and Spades: %2, Jacks: %3 and Jills: %4.").arg(QString::number(myPI),QString::number(SPADES),QString::number(JACKS),QString::number(JILLS)));

}

void MainWindow::on_btnClass_clicked()
{
	ui->lblClass1->setText(QVariant(factorial(ui->verticalSlider->value())).toString());
	cRobert NuClass;
	QString tmpStr = "\n===============\nValue of stDerived: \n";
	tmpStr.append(NuClass.stDerived.c_str());
	tmpStr.append("\n==================\n");
	ui->textEdit->append(tmpStr);
}

void MainWindow::on_btnFileSave_clicked()
{
	// SAVE 2
	ofstream myfile ("example.txt");	// this should create a file if none exists, the simpler one in the other project does
	if (myfile.is_open())
	{
		myfile << "This is a line. \n";
		myfile << "This is another line. \n";
		myfile.close();
	}
	else {
		QMessageBox msgbox;
		msgbox.setText("File not openable\nFor some reason...");
	}
}

void MainWindow::on_btnFileSave_2_clicked()
{
	// StringStream
	int iA = 42;
	float fA = 2.71828182935;
	double dA = 44993;
	string sA = "My string";
	float *ptrA = &fA;
	int mArray[25];
	for (int i=0;i<25;i++){mArray[i]=i * i;}	// Quickly pop an array
	stringstream myList;	// ostringstream & istringstream are just specific input/output versions of stringstream (which is bidirectional)
	myList << "Buy " << iA << " tomatoes and " << fA << " milk and " << fA * 2.3
		   << " tacos " << sA << " is the thought of the day.  \nI ran this " << dA
		   << " times so far.  \n\nPointer A = " << *ptrA << ", address: " << ptrA
			<< "\n&dA = " << &dA << ", &sA = " << &sA << "\n mArray[16] = " << mArray[16];
	string sTmp;
	sTmp = myList.str();		// NOTICE:  the .str() does NOT show up in intellisense!!!
	ui->textEdit->append(sTmp.c_str());

}
