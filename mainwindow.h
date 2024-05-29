#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Add a variable to store memory value
    double memoryVal;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void ChangeNumberSign();
    void EqualButtonPressed();
    void Clear(); // Declare the Clear function
    void MemAdd(); // Declare the MemAdd function
    void MemClear(); // Declare the MemClear function
    void MemGet(); // Declare the MemGet function
};

#endif // MAINWINDOW_H
