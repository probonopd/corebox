#ifndef QTERMWIDGET_GLOBAL_H
#define QTERMWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTERMWIDGET_LIBRARY)
#  define QTERMWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTERMWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTERMWIDGET_GLOBAL_H
