#include "GUI.h"

GUI::GUI(QWidget* parent)
    : QMainWindow(parent)


{

    ui.setupUi(this);

    connect(ui.Aa, &QPushButton::clicked, this, [this]() { onDigitClicked('1'); });
    connect(ui.Bb, &QPushButton::clicked, this, [this]() { onDigitClicked('2'); });
    connect(ui.pushButton_7, &QPushButton::clicked, this, [this]() { onDigitClicked('3'); });
    connect(ui.pushButton, &QPushButton::clicked, this, [this]() { onDigitClicked('4'); });
    connect(ui.pushButton_2, &QPushButton::clicked, this, [this]() { onDigitClicked('5'); });
    connect(ui.pushButton_8, &QPushButton::clicked, this, [this]() { onDigitClicked('6'); });
    connect(ui.pushButton_3, &QPushButton::clicked, this, [this]() { onDigitClicked('7'); });
    connect(ui.pushButton_4, &QPushButton::clicked, this, [this]() { onDigitClicked('8'); });
    connect(ui.pushButton_9, &QPushButton::clicked, this, [this]() { onDigitClicked('9'); });
    connect(ui.pushButton_6, &QPushButton::clicked, this, [this]() { onDigitClicked('0'); });

    connect(ui.pushButton_13, &QPushButton::clicked, this, [this]() { onOperatorClicked('+'); });
    connect(ui.pushButton_14, &QPushButton::clicked, this, [this]() { onOperatorClicked('-'); });
    connect(ui.pushButton_12, &QPushButton::clicked, this, [this]() { onOperatorClicked('*'); });
    connect(ui.pushButton_11, &QPushButton::clicked, this, [this]() { onOperatorClicked('/'); });

    connect(ui.pushButton_24, &QPushButton::clicked, this, &GUI::onEqualsClicked);
    connect(ui.pushButton_16, &QPushButton::clicked, this, &GUI::onClearClicked);
    connect(ui.pushButton_17, &QPushButton::clicked, this, &GUI::onClearClicked);
    connect(ui.pushButton_5, &QPushButton::clicked, this, &GUI::onToggleSignClicked);
    connect(ui.pushButton_10, &QPushButton::clicked, this, &GUI::onCommaClicked);

}



GUI::~GUI()


{
}



double GUI::getDisplayValue()


{

    QString text = ui.Display->text();
    text.replace(",", ".");
    return text.toDouble();

}



void GUI::setDisplayValue(double value)


{

    std::string formatted = calc.formatNumber(value);
    QString text = QString::fromStdString(formatted);
    text.replace(".", ",");
    ui.Display->setText(text);

}



void GUI::onDigitClicked(char digit)


{

    QString current = ui.Display->text();

    if (waitingForSecondOperand)

    {

        current = "";
        waitingForSecondOperand = false;

    }

    if (current == "0")

    {

        current = "";

    }

    current += QChar(digit);
    ui.Display->setText(current);

}



void GUI::onOperatorClicked(char operation)


{

    firstOperand = getDisplayValue();
    pendingOperation = operation;
    waitingForSecondOperand = true;

}



void GUI::onEqualsClicked()


{

    if (pendingOperation == 0)

    {
        return;
    }

    double secondOperand = getDisplayValue();
    bool validOperation = true;
    double result = calc.calculate(firstOperand, secondOperand, pendingOperation, validOperation);

    if (validOperation)

    {
        setDisplayValue(result);
    }

    else

    {
        ui.Display->setText("Ошибка");
    }

    pendingOperation = 0;
    waitingForSecondOperand = true;

}



void GUI::onClearClicked()


{

    ui.Display->setText("0");
    firstOperand = 0;
    pendingOperation = 0;
    waitingForSecondOperand = false;

}



void GUI::onToggleSignClicked()


{

    double value = getDisplayValue();
    setDisplayValue(-value);

}



void GUI::onCommaClicked()


{

    QString current = ui.Display->text();

    if (!current.contains(","))

    {
        current += ",";
        ui.Display->setText(current);

    }

}