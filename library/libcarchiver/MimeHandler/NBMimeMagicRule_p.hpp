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

#ifndef QMIMEMAGICRULE_P_H
#define QMIMEMAGICRULE_P_H

#include <QByteArray>
#include <QScopedPointer>
#include <QList>

class QMimeMagicRulePrivate;
class QMimeMagicRule
{
public:
    enum Type { Invalid = 0, String, Host16, Host32, Big16, Big32, Little16, Little32, Byte };

    QMimeMagicRule(Type type, const QByteArray &value, int startPos, int endPos, const QByteArray &mask = QByteArray());
    QMimeMagicRule(const QMimeMagicRule &other);
    ~QMimeMagicRule();

    QMimeMagicRule &operator=(const QMimeMagicRule &other);

    bool operator==(const QMimeMagicRule &other) const;

    Type type() const;
    QByteArray value() const;
    int startPos() const;
    int endPos() const;
    QByteArray mask() const;

    bool isValid() const;

    bool matches(const QByteArray &data) const;

    QList<QMimeMagicRule> m_subMatches;

    static Type type(const QByteArray &type);
    static QByteArray typeName(Type type);

    static bool matchSubstring(const char *dataPtr, int dataSize, int rangeStart, int rangeLength, int valueLength, const char *valueData, const char *mask);

private:
    const QScopedPointer<QMimeMagicRulePrivate> d;
};
Q_DECLARE_TYPEINFO(QMimeMagicRule, Q_MOVABLE_TYPE);

QT_END_NAMESPACE

#endif // QMIMEMAGICRULE_H
