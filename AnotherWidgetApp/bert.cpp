#include "bert.h"
#include "ui_bert.h"
//#include "stdafx.h" // microsoft ... not used
#include <vector>
#include <string>
using namespace std;




void showbits(unsigned int x, char *arr, int arrSize)
{
	int i;
	i = 0;
	int offSet = 2;
//	for (i = (sizeof(int) * 8) - offSet; i >= 0; i--)
//		(x & (1u << i)) ? putchar('1') : putchar('0');
//	for (i = arrSize - 2; i>=0; i--)
//		(x & (1u << i)) ? arr[i] = '1' : arr[i] = '0';	\\ this is backwards
	for (i = arrSize - 2; i>=0; i--)
		(x & (1u << i)) ? arr[(arrSize - offSet) - i] = '1' : arr[(arrSize - offSet) - i] = '0';

	arr[arrSize - 1]='\0';
}

inline int factorial(int n) {return ((n == 1) ? 1 : (factorial(n - 1) * n)); }
// Think of above as     n! = (((((1)*2)*3)*4)*5) for n=5, 1st stage
//		is all about filling up the '* n' expressions as it telescopes
//		out (expands), 2nd stage collapses as it calculates n!  Wonder
//		if n could have been passed by reference (&n).

Bert::Bert(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Bert)
{
	ui->setupUi(this);
}

Bert::~Bert()
{
	delete ui;
}

void Bert::on_pushButton_clicked()
{
	ui->lineEdit->setText("Fuck You...");
}

void Bert::on_pushButton_2_clicked()
{
	ui->lineEdit->setText("Asshole!");
}

void Bert::on_dial_valueChanged(int value)
{
	ui->progressBar->setValue(value);
}

void Bert::on_radioButton_3_clicked()
{
	ui->label_4->setText("LIB");
	ui->label->setText("Dodgy");
	ui->verticalSlider->setValue(5);
	ui->lineEdit_2->setText("Worx");

}

void Bert::on_pushButton_3_clicked()
{
	ui->label_5->setText("Assknocker");
	ui->lcdNumber->setDigitCount(6);

}

void Bert::on_pushButton_4_clicked()
{
	char arr[sizeof(int) * 8 + 1];
	char arr2[] = {'a','s','s',' ','H','o','l','e',' ','F','u','c','k','e','r','\0'};
//	QString string(arr2);
	int arrSiz = sizeof(int);
	int arrSiz2 = sizeof(arr);
	ui->label_6->setText(QVariant(arrSiz).toString());
	ui->label_7->setText(QVariant(arrSiz2).toString());

//	ui->label_8->setText(QVariant(ui->dial_2->value()).toString());	//worx okay
//	ui->label_8->setText(QVariant(*arr2).toString());	//no error but not what expct
	ui->label_10->setText(arr2);
//	ui->label_9->setText(string(arrSiz));	//error
	showbits(ui->dial_2->value(), arr, arrSiz2);
	ui->label_8->setText(arr);
}

typedef enum{A,B,C,D,E}Letter;	// This and the next lines are both typedefs
enum suit {CLUBS = 3, DIAMONDS = 6, HEARTS = 7, SPADES = 26, JACKS, JILLS};
const double PI = 3.141592653589792;
const double myPI = 3.141592653589792;
// enums are really just a different way of dealing with integer
//		constants, although as a type (like suit above) they strictly
//		limit you to the enumerated choices.
float coords[2][3] = {{1,2,3},{4,5,6}};


void Bert::on_dial_2_valueChanged(int value)
{
	int num=0;
	while (num<10)
	{
		num++;
		if (num==5) continue;
		// The above will ensure the #5 does NOT show up in list
		//		as it will skip the rest of the loop & start next iteration

/*		ui->textEdit->append(QVariant(num).toString());
		ui->textEdit->moveCursor(QTextCursor::End);
		ui->textEdit->append(",   ");
		ui->textEdit->moveCursor(QTextCursor::End);
*/
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
//	QString MyStr = "x = Clubs = " + x + ", y = C = " + y;
//	QString MyStr("x = Clubs = %`, y = C = %2");
//	QString MyStr;  // THIS FUCKING BULLSHIT DOESNT WORK!
//	MyStr = "x = Clubs = %1, y = C = %2";
//	MyStr.arg(int(5));
//	MyStr.arg(int(y));
//	MyStr.arg(5).arg(88);
//	using namespace string;
	int x1 = 5, y1=88;
	string MyStr = "x = Clubs = " + to_string(x) + ", y = C = " + to_string(y);
//	string MyStr2 = "x1 = 5 = " + (string)x1 + ", y1 = 88 = " + (string)y1;
	float yy = (float) y1 + 1.25;
	x1 += yy;
	string Sx1;
//	Sx1 = (string) x1;
//	string Sy1 = (string) y1;
	Sx1 = to_string(x1);
	string Sy1 = to_string(y1);
	string MyStr2 = "x1 = 5 = " + Sx1 + ", y1 = 88 = " + Sy1;
	QString qSx = "I dont Know ";
	QString qSy = " but Fuck 8 of you!";
	QString qSS = qSx + qSy + " Bout Time" + to_string(y1).c_str();

	ui->textEdit->append(qSS);
//	ui->label_10->setText(QVariant(MyStr).toString());
	ui->label_10->setText(MyStr.c_str());
	ui->lineEdit->setText(MyStr2.c_str());

	ui->label_9->setText(QVariant(value).toString());
// The MyStr.find(substring,0); MyStr.swap(Str2); MyStr.insert(10,substring);
//		are interesting also.
}

void Bert::on_checkBox_3_stateChanged(int arg1)
{
	ui->textEdit->setText("ui->textEdit-> doesnt seem to work since there is no text property");
}

void Bert::on_pushButton_5_clicked()
{
	ui->textEdit->clear();
}

void Bert::on_pushButton_7_clicked()
{
	ui->textEdit->undo();
}

void Bert::on_pushButton_6_clicked()
{
	ui->textEdit->redo();
}

void Bert::on_pushButton_8_clicked()
{
	ui->textEdit->append(ui->lineEdit_2->text());
}

void Bert::on_pushButton_9_clicked()
{
	ui->textEdit->append(QString("Constants include PI: %1 and Spades: %2, Jacks: %3 and Jills: %4.").arg(PI,SPADES,JACKS,JILLS));
}

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
	setTemp(float tempTemp) {fTemperature = tempTemp;}
	setCity(string tmpCity) {sCity = tmpCity;}
	setPlace(string tmpPlace) {sPlace = tmpPlace;}
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
//	string stDerived = "Derived Class \"Robert\" Variable";
	string stDerived = "Derived Class Robert Variable";
};

void Bert::on_pushButton_10_clicked()
{
	ui->textEdit->append(QString("Constants include myPI: %1 and Spades: %2, Jacks: %3 and Jills: %4.").arg(QString::number(myPI),QString::number(SPADES),QString::number(JACKS),QString::number(JILLS)));
	ui->label->setText(QVariant(factorial(ui->verticalSlider->value())).toString());
	cRobert NuClass;
	QString tmpStr = "\n===============\nValue of stDerived: \n";
	tmpStr.append(NuClass.stDerived.c_str());
	tmpStr.append("\n==================\n");
	ui->textEdit->append(tmpStr);
}

static int stTimesPressed; // Times button pressed

void Bert::on_pushButton_11_clicked()
{
	string sTemp;
	stTimesPressed++;
	sTemp = "Times: " + to_string(stTimesPressed);
	ui->label_12->setText(sTemp.c_str());

	cBert BertClass;
	BertClass.setCity("Broken Arrow");
	BertClass.setPlace("Bedroom");
	BertClass.setTemp(57.8);
	ui->pushButton_11->setText(BertClass.sAlert.c_str());
	sTemp = "Changing Age from " + to_string(BertClass.iAge) +
			" to 51, \n Also, Protected Variable = " +
			to_string(BertClass.getProtected());
	ui->textEdit->append(sTemp.c_str());
	BertClass.iAge=51;
	BertClass.sYear = 2019;
	BertClass.sName = "Robert P";
	double dTemp = 0;
	if (ui->pushButton_12->isChecked()) {
		dTemp = BertClass.Calculate(ui->spinBox->value());
		ui->pushButton_11->setText(BertClass.sAlert.c_str());
		sTemp = "\n===> Static Alert Member = " + to_string(BertClass.iAlert)
				+ "\nAlert Status: " + BertClass.sAlert
				+ "\nCalc Result (protected): "
				+ to_string(BertClass.getProtected())
				+ "\nResult (return): " + to_string(dTemp);
		ui->textEdit->append(sTemp.c_str());
	}

	sTemp = "\nClass BertClass DATA \nName: " + BertClass.sName
			+ "\nAge: " + to_string(BertClass.iAge)
			+ " Years Old";
	ui->textEdit->append(sTemp.c_str());
	sTemp = "Year is: " + to_string(BertClass.sYear);
	ui->textEdit->append(sTemp.c_str());
	sTemp = "------------\nAlert Status: " + BertClass.sAlert;
	ui->textEdit->append(sTemp.c_str());
	if (BertClass.sAlert != "green") {
		sTemp = "Calculation Result: " + to_string(dTemp);
	}
	sTemp = "\nTemperature: " + to_string(BertClass.getTemp())
			+ "\nCity: " + BertClass.getCity();
	ui->textEdit->append(sTemp.c_str());
	sTemp = "Place: " + BertClass.getPlace()
			+ "\nStatic Member: " + to_string(BertClass.iAlert)
			+ "\n\nThanks!";
	ui->textEdit->append(QString(sTemp.c_str()));

}

void Bert::on_dial_2_actionTriggered(int action)
{
	ui->checkBox->setText(QVariant(action).toString());
}

void Bert::MiscFunction (int &a, int &b, int &c)
{	//NOTE: I HAD TO ADD THE "Bert::" TO THIS IN ORDER TO
	//   ACCESS THE Controls (like textEdit)
	string sTmpP;
	char cTmp[150]; // = (char)&a;
	int xx=0;
	while (xx < 150)
	{
		xx++;
		cTmp[xx] = '\0';
	}
	// Pointer array
	int *ptrArr[3] = {&a, &b, &c};
//	string sTmp = "Pointer index 1: " + to_string(*ptrArr[0])
//			+ "\nAddress: " + to_string(ptrArr[0]);
//	int pArr[3] = {4,55,21};
	int pArr[3] = {a,b,c};
	string sTmp = "\nPointer index 1: " + to_string(pArr[0])
			+ "\nAddress: " + to_string(pArr[1]);
	ui->textEdit->append(sTmp.c_str());
//	QString qTmp;
//	qTmp.append(QVariant(%a).toString());
//	sTmpP = &b; //(ptrArr[0]);
/*
 * ********************************************************************************************
 * ********************************************************************************************
 * ********************** MEMORY TO STRING CONVERSION BULLSHIT     ****************************
 * ********************************************************************************************
 * ********************************************************************************************
 */
	//QString p = QString::number(&a,16);
//	sprintf(cTmp, "Formatted data: %ulld", &a);
//	sprintf(cTmp, "%ulld", &a);  // this basically works
	sprintf(cTmp, "%ulld", ptrArr[0]);
	sTmp = "\nPointer index 1: " + to_string(*ptrArr[0])
			+ "\nAddress: " + cTmp;// + to_string(cTmp); // to_string((int)ptrArr[0]);
	ui->textEdit->append(sTmp.c_str());
//	ui->textEdit->append(cTmp);
	sprintf(cTmp, "%u", ptrArr[1]);
	sTmp = "\nPointer index 1: " + to_string(*ptrArr[1])
			+ "\nAddress: " + cTmp;
	ui->textEdit->append(sTmp.c_str());
	sprintf(cTmp, "%u", ptrArr[2]);
	sTmp = "\nPointer index 1: " + to_string(*ptrArr[2])
			+ "\nAddress: " + cTmp;
	ui->textEdit->append(sTmp.c_str());
//	ui->textEdit->selectAll();

}
void Bert::on_pushButton_13_clicked()
{
	int A,B,C;
	A=4; B=332; C=26;
	MiscFunction(A,B,C);
}

void Bert::on_pushButton_14_clicked()
{
	// StringStream
int iA = 42;
float fA = 2.71828182935;
double dA = 44993;
string sA = "My string";
float *ptrA = &fA;
int mArray[25];
for (int i=0;i<25;i++){mArray[i]=i * i;}
//ostringstream myList;		// ostringstream & istringstream are just specific input/output versions of stringstream (which is bidirectional)
stringstream myList;
myList << "Buy " << iA << " tomatoes and " << fA << " milk and " << fA * 2.3
	   << " tacos " << sA << " is the thought of the day.  \nI ran this " << dA
	   << " times so far.  \n\nPointer A = " << *ptrA << ", address: " << ptrA
		<< "\n&dA = " << &dA << ", &sA = " << &sA << "\n mArray[16] = " << mArray[16];

//ui->textEdit->append(to_string(myList).c_str());
string sTmp;
sTmp = myList.str();		// NOTICE:  the .str() does NOT show up in intellisense!!!
ui->textEdit->append(sTmp.c_str());

}

void Bert::on_pushButton_15_clicked()
{
	// LOAD
	stringstream filedata;
	string sTmp;
//	ofstream myFile;
//	myFile.open("example.txt", ios::in); // can combine flags ,ios::out | ios::binary | ios::ate | ios::app | ios::trunc) etc.
	string line;
	ifstream myfile ("example.txt");
	if (myfile.is_open())
	{
		while (getline (myfile,line))
		{
			filedata << line << '\n';
		}
		myfile.close();
	}
	else
	{
		filedata << "Unable to open file";
		sTmp = filedata.str();
		QMessageBox msgBox;
		msgBox.setText(sTmp.c_str());
		msgBox.exec();

	}
	sTmp = filedata.str();
	ui->textEdit->append(sTmp.c_str());
}

void Bert::on_pushButton_16_clicked()
{
	// SAVE 1
	fstream myFile; // could use ifstream for input by default, fstream is both i & o
	myFile.open("example.txt");
	myFile << "Writing this to a file.\n";
	myFile.close();

}

void Bert::on_pushButton_17_clicked()
{
	// SAVE 2
	ofstream myfile ("example.txt");
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

void Bert::on_pushButton_18_clicked()
{
	myself(1);
}

void Bert::myself(int n){
	stringstream myString;
	myString << "Iteration " << n;
	string sTmp = myString.str();
	n++;
	ui->textEdit->append(sTmp.c_str());
	if (n >= 8) return;
	else myself(n);
}
