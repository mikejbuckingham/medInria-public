#pragma once

#include <dtkCore/dtkAbstractViewInteractor.h>

#include "v3dViewPluginExport.h"

class v3dViewFuseInteractorPrivate;

class dtkAbstractData;
class dtkAbstractView;

/**
 * @deprecated Use layers instead: faster implementation.
 */
class V3DVIEWPLUGIN_EXPORT v3dViewFuseInteractor: public dtkAbstractViewInteractor
{
    Q_OBJECT

public:
    v3dViewFuseInteractor();
    virtual ~v3dViewFuseInteractor();

    virtual QString description(void) const;
    virtual QString identifier(void) const;
    virtual QStringList handled(void) const;

    static bool registered(void);

    virtual void setData(dtkAbstractData *data, int channel);
    virtual void setView(dtkAbstractView *view);

    virtual void enable(void);
    virtual void disable(void);

public slots:
    virtual void onPropertySet                       (const QString& key, const QString& value);
    virtual void onFusionStylePropertySet            (const QString& value);
    virtual void onBlendAlphaValueSet                (int value);
    virtual void onBlendAlphaValueSet                (double value);
    virtual void onCheckerboardDivisionCountValueSet (int value);
    virtual void onCheckerboardDivisionCountValueSet (double value);

private:
    v3dViewFuseInteractorPrivate *d;

};

dtkAbstractViewInteractor *createV3dViewFuseInteractor(void);


