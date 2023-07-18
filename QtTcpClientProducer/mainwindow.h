#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void putData();

  void tcpConnect();
  void tcpDisconnect();

  void valorMin(int);
  void valorMax(int);
  void valorInterv(int);
  void timerEvent();
  void timerStop();

private:
  int min;
  int max;
  int seg;
  QTimer *Timer;
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
