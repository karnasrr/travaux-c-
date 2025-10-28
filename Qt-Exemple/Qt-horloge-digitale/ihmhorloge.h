#ifndef IHMHORLOGE_H
#define IHMHORLOGE_H

#include <qglobal.h>
#if QT_VERSION >= 0x050100
#include <QtWidgets> /* tous les widgets de Qt5 */
#else
#include <QtGui> /* tous les widgets de Qt4 */
#endif

class HorlogeDigitale;

class IHMHorloge : public QWidget
{
    Q_OBJECT

    private:
        // les widgets
        QPushButton     *boutonReglage;
        HorlogeDigitale *horloge;
        QTimeEdit       *editionHeure;

    public:
        IHMHorloge(QWidget *parent=0);
        ~IHMHorloge();

    private slots:
        void regler();
        void quitter();

   signals:
        void depart(int);
        void arret();
};

#endif // IHMHORLOGE_H
