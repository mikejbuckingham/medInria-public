#pragma once

#include <dtkCore/dtkAbstractDataWriter.h>

#include "v3dDataPluginExport.h"

class v3dDataFibersWriterPrivate;

class V3DDATAPLUGIN_EXPORT v3dDataFibersWriter : public dtkAbstractDataWriter
{
    Q_OBJECT

public:
             v3dDataFibersWriter(void);
    virtual ~v3dDataFibersWriter(void);

    virtual QStringList handled(void) const;
    
    virtual QString identifier(void)  const;
    virtual QString description(void) const;

    static bool registered(void);

    /** Override base class */
    virtual QStringList supportedFileExtensions(void) const;

public slots:
    bool write    (const QString& path);
    bool canWrite (const QString& path);

 private:
    v3dDataFibersWriterPrivate *d;
};


dtkAbstractDataWriter *createV3dDataFibersWriter(void);


