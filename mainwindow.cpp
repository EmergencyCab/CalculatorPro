#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger= false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for (int i=0; i< 10; ++i){
        QString butName = "Button" + QString::number(i); // Create button name, e.g., "Button0", "Button1"


        numButtons[i]= MainWindow::findChild<QPushButton *>(butName); // Find the button by name and store it in the array

        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed())); // Connect the button's released signal to the NumPressed slot
    }

    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    connect(ui->Substract, SIGNAL(released()), this,
           SLOT(MathButtonPressed()));

    connect(ui->Multiply, SIGNAL(released()), this,
           SLOT(MathButtonPressed()));

    connect(ui->Divide, SIGNAL(released()), this,
           SLOT(MathButtonPressed()));

    connect(ui->Equals, SIGNAL(released()), this,
           SLOT(EqualButtonPressed()));

    connect(ui->ChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));

    connect(ui->Clear, SIGNAL(released()), this, SLOT(Clear()));
    connect(ui->MemAdd, SIGNAL(released()), this, SLOT(MemAdd()));
    connect(ui->MemClear, SIGNAL(released()), this, SLOT(MemClear()));
    connect(ui->MemGet, SIGNAL(released()), this, SLOT(MemGet()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed() {
    QPushButton *button = (QPushButton *)sender(); // Get the button that was pressed
    QString butVal = button->text(); // Get the text of the pressed button
    QString displayVal = ui->Display->text(); // Get the current text in the display

    // If the display is "0" or empty, replace it with the button value
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)) {
        ui->Display->setText(butVal);
    } else {
        // Otherwise, append the button value to the current display text
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble(); // Convert the new value to double

        // Set the new value in the display
        ui->Display->setText(QString::number(dblNewVal, 'g', 15));
    }
}


void MainWindow::MathButtonPressed(){

    // Reset all triggers to false before setting the new one

    divTrigger = false;
    multTrigger= false;
    addTrigger = false;
    subTrigger = false;

    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton  *button = (QPushButton *)sender();
    QString butVal = button ->text();
    if (QString::compare(butVal, "/",Qt::CaseInsensitive)==0){
        divTrigger = true;
    } else if ((QString::compare(butVal, "*",Qt::CaseInsensitive)==0)){
        multTrigger = true;
    } else if ((QString::compare(butVal, "+",Qt::CaseInsensitive)==0)){
        addTrigger = true;
    }else {
        subTrigger = true;
    }
    ui->Display->setText("");

}

void MainWindow::EqualButtonPressed(){

    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || multTrigger || subTrigger || divTrigger){
        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if (multTrigger){
            solution = calcVal * dblDisplayVal;
        }else if (subTrigger){
            solution = calcVal - dblDisplayVal;
        }else {
            solution = calcVal / dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void MainWindow::ChangeNumberSign() {
    // Static regular expression to match a number (optional negative sign, digits, optional decimal point and more digits)
    static const QRegularExpression reg("[-]?[0-9.]*");

    // Get the current text displayed
    QString displayVal = ui->Display->text();

    // Check if the current display value matches the number pattern
    QRegularExpressionMatch match = reg.match(displayVal);
    if (match.hasMatch()) {
        // Convert the display value to double
        double dblDisplayVal = displayVal.toDouble();

        // Change the sign of the number
        double dblDisplayValSign = -1 * dblDisplayVal;

        // Set the new value with the changed sign back to the display
        ui->Display->setText(QString::number(dblDisplayValSign));
    }
}

// Clear the display and reset calcVal
void MainWindow::Clear() {
    calcVal = 0.0;
    ui->Display->setText(QString::number(calcVal));
}

// Add the current display value to memory
void MainWindow::MemAdd() {
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    memoryVal += dblDisplayVal;
    ui->Display->setText("");
}

// Clear the memory value
void MainWindow::MemClear() {
    memoryVal = 0.0;
    ui->Display->setText("");
}

// Get the value from memory and display it
void MainWindow::MemGet() {
    ui->Display->setText(QString::number(memoryVal));
}
