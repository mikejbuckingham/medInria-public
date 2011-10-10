/* medToolBoxFactory.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Wed Nov 10 11:34:40 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Nov 10 16:05:16 2010 (+0100)
 *           By: Julien Wintz
 *     Update #: 27
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef MEDTOOLBOXFACTORY_H
#define MEDTOOLBOXFACTORY_H

#include "medGuiExport.h"

#include <dtkCore/dtkAbstractFactory.h>

#include <QtCore>

class medToolBox;
class medToolBoxFactoryPrivate;
class medToolBoxRegistrationCustom;
class medToolBoxDiffusionCustom;
class medToolBoxCompositeDataSetImporterCustom;
class medToolBoxFilteringCustom;

class MEDGUI_EXPORT medToolBoxFactory : public dtkAbstractFactory
{
    Q_OBJECT

public:
    typedef medToolBoxRegistrationCustom *(*medToolBoxRegistrationCustomCreator)(QWidget *parent);
    typedef medToolBoxDiffusionCustom    *(*medToolBoxDiffusionCustomCreator)(QWidget *parent);
    typedef medToolBoxFilteringCustom *(*medToolBoxFilteringCustomCreator)(QWidget *parent);
    typedef medToolBoxCompositeDataSetImporterCustom    *(*medToolBoxCompositeDataSetImporterCustomCreator)(QWidget *parent);


public:
    static medToolBoxFactory *instance(void);

    bool registerCustomRegistrationToolBox(QString identifier,
                                           QString name,
                                           QString description,
                                           medToolBoxRegistrationCustomCreator func);
    bool registerCustomDiffusionToolBox(QString identifier,
                                        QString name,
                                        QString description,
                                        medToolBoxDiffusionCustomCreator func);
    bool registerCustomFilteringToolBox(QString identifier,
                                        QString name,
                                        QString description,
                                        medToolBoxFilteringCustomCreator func);
    bool registerCustomCompositeDataSetImporterToolBox(QString identifier,
                                                       QString name,
                                                       QString description,
                                                       medToolBoxCompositeDataSetImporterCustomCreator func);

    QList<QString> registrationToolBoxes(void);
    QList<QString> diffusionToolBoxes(void);
    QList<QString> filteringToolBoxes(void);
    QList<QString> compositeDataSetImporterToolBoxes(void);

public slots:
    medToolBoxRegistrationCustom *createCustomRegistrationToolBox(QString identifier, QWidget *parent=0);
    medToolBoxDiffusionCustom *createCustomDiffusionToolBox(QString identifier, QWidget *parent=0);
    medToolBoxFilteringCustom *createCustomFilteringToolBox(QString identifier, QWidget *parent=0);
    medToolBoxCompositeDataSetImporterCustom *createCustomCompositeDataSetImporterToolBox(QString identifier, QWidget *parent=0);

protected:
     medToolBoxFactory(void);
    ~medToolBoxFactory(void);

private:
    static medToolBoxFactory *s_instance;

private:
    medToolBoxFactoryPrivate *d;
};

#endif
