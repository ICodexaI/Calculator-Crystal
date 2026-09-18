#pragma once
//#inlude "All In.h" - ошибка слепых глаз и дырявой клавы от "panteon"
#include "All In.h" //Этот из GUI\All In.h

class GUI : public QMainWindow


{

    Q_OBJECT

public:
    GUI(QWidget* parent = nullptr);
    ~GUI();

private:
    Ui::GUIClass ui;
    Calculator calc;

    double firstOperand = 0;
    char pendingOperation = 0;
    bool waitingForSecondOperand = false;

    void onDigitClicked(char digit);
    void onOperatorClicked(char operation);
    void onEqualsClicked();
    void onClearClicked();
    void onToggleSignClicked();
    void onCommaClicked();

    double getDisplayValue();
    void setDisplayValue(double value);

};