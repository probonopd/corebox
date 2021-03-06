/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QMIMEDATABASE_P_H
#define QMIMEDATABASE_P_H

#include <QHash>
#include <QMutex>

#include <NBMimeType.hpp>
#include <NBMimeType_p.hpp>
#include <NBMimeGlobPattern_p.hpp>

class QMimeDatabase;
class QMimeProviderBase;

class QMimeDatabasePrivate
{
public:
    Q_DISABLE_COPY(QMimeDatabasePrivate)

    QMimeDatabasePrivate();
    ~QMimeDatabasePrivate();

    static QMimeDatabasePrivate *instance();

    QMimeProviderBase *provider();
    void setProvider(QMimeProviderBase *theProvider);

    inline QString defaultMimeType() const { return m_defaultMimeType; }

    bool inherits(const QString &mime, const QString &parent);

    QList<QMimeType> allMimeTypes();


    QMimeType mimeTypeForName(const QString &nameOrAlias);
    QMimeType mimeTypeForNameAndData(const QString &fileName, QIODevice *device, int *priorityPtr);
    QMimeType findByData(const QByteArray &data, int *priorityPtr);
    QStringList mimeTypeForFileName(const QString &fileName, QString *foundSuffix = 0);

    mutable QMimeProviderBase *m_provider;
    const QString m_defaultMimeType;
    QMutex mutex;
};

QT_END_NAMESPACE

#endif   // QMIMEDATABASE_P_H
