#include "widget.h"
#include "ui_widget.h"
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // Инициализация GDAL
    GDALAllRegister();

    // Создание всех виджетов из .ui файла
    ui->setupUi(this);

    setWindowTitle("Профиль Рельефа");
    resize(800, 600);

    // Начальная настройка элементов
    ui->buildProfile_pb->setEnabled(false);

    // Настройка виджета QCustomPlot (должен быть назван 'customPlot' в .ui)
    // Доступ к QCustomPlot осуществляется через ui->customPlot
    if (ui->customPlot_widget) {
        ui->customPlot_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->customPlot_widget->xAxis->setLabel("Расстояние (м)");
        ui->customPlot_widget->yAxis->setLabel("Высота (м)");
    }


}

Widget::~Widget()
{
    delete ui;
    GDALDestroyDriverManager();
}



void Widget::on_load_pb_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Открыть файл ЦМР"),"", tr("DEM Files (*.tif *.tiff *.hgt);;All Files (*.*)"));
    if (filePath.isEmpty()) return;

    if (loadElevationData(filePath)) {
        QMessageBox::information(this, "Успех", "Данные ЦМР успешно загружены! Нажмите 'Построить профиль");
        ui->buildProfile_pb->setEnabled(true);
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить данные ЦМР.");
        ui->buildProfile_pb->setEnabled(false);
    }
}


void Widget::on_buildProfile_pb_clicked()
{
    if (distances.isEmpty() || heights.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Сначала загрузите данные ЦМР.");
        return;
    }

    setupProfilePlot();
}

bool Widget::loadElevationData(const QString &filePath)
{
    // Очищаем старые данные
    distances.clear();
    heights.clear();

    GDALDataset *poDataset = (GDALDataset *) GDALOpen(filePath.toLocal8Bit().constData(), GA_ReadOnly);

    if (poDataset == nullptr) {
        return false;
    }

    // ***************************************************************
    // >>> Скелет: Генерация тестовых данных (ЗАМЕНИТЬ РЕАЛЬНОЙ ЛОГИКОЙ GDAL)
    int count = 100;
    for (int i = 0; i < count; ++i) {
        double dist = i * 10.0;
        double height = 1000 + (double)i * 0.5 + 50.0 * qSin(dist / 500.0);
        distances.append(dist);
        heights.append(height);
    }
    // ***************************************************************

    GDALClose(poDataset);
    return true;
}

void Widget::setupProfilePlot()
{
    if (!ui->customPlot_widget) return;

    ui->customPlot_widget->clearGraphs();

    // Создаем новый график
    ui->customPlot_widget->addGraph();
    ui->customPlot_widget->graph(0)->setData(distances, heights);

    // Настраиваем внешний вид
    ui->customPlot_widget->graph(0)->setPen(QPen(Qt::blue, 2));
    ui->customPlot_widget->graph(0)->setName("Профиль рельефа");

    // Автоматическое масштабирование
    ui->customPlot_widget->rescaleAxes();

    // Перерисовка
    ui->customPlot_widget->replot();
}

