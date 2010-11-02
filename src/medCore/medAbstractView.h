/* medAbstractView.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Thu Oct 21 19:54:36 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Oct 26 10:46:04 2010 (+0200)
 *           By: Julien Wintz
 *     Update #: 9
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef MEDABSTRACTVIEW_H
#define MEDABSTRACTVIEW_H

#include <dtkCore/dtkAbstractView.h>

#include "medCoreExport.h"

class MEDCORE_EXPORT medAbstractView: public dtkAbstractView
{
    Q_OBJECT

public:
             medAbstractView(medAbstractView * parent = 0);
             medAbstractView(const medAbstractView& view);
    virtual ~medAbstractView(void){}

    virtual void setColorLookupTable(int min_range,
                                     int max_range,
                                     int size,
                                     const int & table);

    virtual void setColorLookupTable(QList<double>scalars,QList<QColor>colors);

    virtual QWidget *receiverWidget(void);
};

#endif