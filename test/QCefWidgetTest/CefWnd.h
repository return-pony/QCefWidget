#pragma once
#include <QWidget>
#include <QString>
#include <QSize>
#include <QDebug>

class QCefWidget;
class QCefOpenGLWidget;

class CefWnd : public QWidget {
  Q_OBJECT
public:
  CefWnd(QWidget *parent = nullptr);
  virtual ~CefWnd();

  void setupUi();

  bool usingGLWidget();
  void setUsingGLWidget(bool b);

  bool framelessWindow();
  void setFramelessWindow(bool b);

  bool translucentWindowBackground();
  void setTranslucentWindowBackground(bool b);

  bool osrEnabled();
  void setOsrEnabled(bool b);

  bool contextMenuEnabled();
  void setContextMenuEnabled(bool b);

  bool autoAddDevToolsContextMenu();
  void setAutoAddDevToolsContextMenu(bool b);

  QSize initSize();
  void setInitSize(QSize s);

  QString initUrl();
  void setInitUrl(QString u);

  int maximumFps();
  void setMaximumFps(int f);

  QColor windowBkColor();
  void setWindowBkColor(QColor c);

  QColor browserBkColor();
  void setBrowserBkColor(QColor c);

protected:
  QSize sizeHint() const override;
protected slots:
  virtual void onNavigateToUrl(QString url);
  virtual void onReload();
  virtual void onShowDevTools();
  virtual void onCloseDevTools();
  virtual void onInvokeMethodNotify(int browserId, int frameId, const QString &method, const QVariantList &arguments);

protected:
  bool usingGLWidget_;
  bool framelessWindow_;
  bool translucentWindowBackground_;
  QSize initSize_;
  QString initUrl_;
  QColor windowBkColor_;
  QColor browserBkColor_;
  bool contextMenuEnabled_;
  bool autoAddDevToolsContextMenu_;
  bool osrEnabled_;
  int maximumFps_;

  QCefWidget *pCefWidget_;
  QCefOpenGLWidget *pCefGLWidget_;
};