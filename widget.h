#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QVector>
#include "qcustomplot.h"
#include "gdal_priv.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_load_pb_clicked();

    void on_buildProfile_pb_clicked();

private:
    Ui::Widget *ui;

    // Данные рельефа
    QVector<double> distances;
    QVector<double> heights;

    // Приватные методы для логики
    bool loadElevationData(const QString &filePath);
    void setupProfilePlot();

    // Структура для хранения координат (Lon/Lat)
    struct GeoPoint {
        double lon;
        double lat;
    };

    // Константа, определяющая детализацию профиля
    const int INTERPOLATION_POINTS = 500;
};
#endif // WIDGET_H
