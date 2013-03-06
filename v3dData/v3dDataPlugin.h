// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#pragma once

#include <dtkCore/dtkPlugin.h>

#include "v3dDataPluginExport.h"

class V3DDATAPLUGIN_EXPORT v3dDataPluginPrivate;

class V3DDATAPLUGIN_EXPORT v3dDataPlugin : public dtkPlugin
{
    Q_OBJECT
    Q_INTERFACES(dtkPlugin)

public:
     v3dDataPlugin(QObject *parent = 0);
    ~v3dDataPlugin(void);

    virtual bool initialize(void);
    virtual bool uninitialize(void);

    virtual QString name(void) const;
    virtual QString description(void) const;
    virtual QString version(void) const;

    virtual QStringList tags(void) const;
    virtual QStringList types(void) const;

private:
     v3dDataPluginPrivate *d;
};


