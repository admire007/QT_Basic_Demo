#ifndef CWEBVIEW_H
#define CWEBVIEW_H

#include <QWebEngineView>

class CWebView : public QWebEngineView
{
public:
    CWebView(QWidget *parent = nullptr);
};

#endif // CWEBVIEW_H
