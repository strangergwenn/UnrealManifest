/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwennaël ARBONA
 **/

#include <QApplication>
#include "umanifest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UManifest w;
    w.show();
    return a.exec();
}
