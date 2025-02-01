// #if defined(_MSC_VER) && (_MSC_VER >= 1600)
// QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
// #endif
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
