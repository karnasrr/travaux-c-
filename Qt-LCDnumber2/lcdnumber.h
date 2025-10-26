#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#pragma once
#include <QFont>
#include <QFrame>
#include <QLCDNumber>
#include <QMainWindow>
#include <QDoubleSpinBox>

namespace Examples {
class Window1 : public QMainWindow {
    Q_OBJECT
public:
    Window1() {
        doubleSpinBox.move(10, 10);
        doubleSpinBox.setDecimals(2);
        doubleSpinBox.setRange(0, 15000000);
        doubleSpinBox.setSingleStep(0.01);
        doubleSpinBox.setValue(12345678.90);
        connect(&doubleSpinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), [&] {
            lcdNumber.display(QString::number(doubleSpinBox.value(), 'f', 2));
        });

        //ajout d'un deuxieme doubleSpinBox
        //doubleSpinBox.move(90, 90);
        //doubleSpinBox.setDecimals(2);
        //doubleSpinBox.setRange(0, 15000000);
        //doubleSpinBox.setSingleStep(0.01);
        //doubleSpinBox.setValue(12345678.90);
        //connect(&doubleSpinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), [&] {
        //    lcdNumber.display(QString::number(doubleSpinBox.value(), 'f', 2));
        //});



        lcdNumber.setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        lcdNumber.setDigitCount(11);
        lcdNumber.display("12345678.90");
        lcdNumber.move(10, 50);
        lcdNumber.setFrameStyle(QFrame::NoFrame);

        setCentralWidget(&frame);
        setWindowTitle("LCD number example1");
        resize(300, 300);


    }

private:
    QFrame frame;
    QDoubleSpinBox doubleSpinBox {&frame};
    QLCDNumber lcdNumber {&frame};
};

//class window2
class Window2 : public QMainWindow {
    Q_OBJECT
public:
    Window2() {
        doubleSpinBox.move(10, 10);
        doubleSpinBox.setDecimals(2);
        doubleSpinBox.setRange(0, 15000000);
        doubleSpinBox.setSingleStep(0.01);
        doubleSpinBox.setValue(12345678.90);
        connect(&doubleSpinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), [&] {
            lcdNumber.display(QString::number(doubleSpinBox.value(), 'f', 2));
        });

        //ajout d'un deuxieme doubleSpinBox
        //doubleSpinBox.move(90, 90);
        //doubleSpinBox.setDecimals(2);
        //doubleSpinBox.setRange(0, 15000000);
        //doubleSpinBox.setSingleStep(0.01);
        //doubleSpinBox.setValue(12345678.90);
        //connect(&doubleSpinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), [&] {
        //    lcdNumber.display(QString::number(doubleSpinBox.value(), 'f', 2));
        //});



        lcdNumber.setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        lcdNumber.setDigitCount(11);
        lcdNumber.display("12345678.90");
        lcdNumber.move(10, 50);
        lcdNumber.setFrameStyle(QFrame::NoFrame);

        setCentralWidget(&frame2);
        setWindowTitle("LCD number example2");
        resize(300, 300);


    }

private:
    QFrame frame2;
    QDoubleSpinBox doubleSpinBox {&frame2};
    QLCDNumber lcdNumber {&frame2};
};




}
#endif // LCDNUMBER_H
