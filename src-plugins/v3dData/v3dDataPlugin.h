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
    ~v3dDataPlugin();

    virtual bool initialize();
    virtual bool uninitialize();

    virtual QString name() const;
    virtual QString description() const;
    virtual QString version() const;

    virtual QStringList tags() const;
    virtual QStringList types() const;

private:
     v3dDataPluginPrivate *d;
};


