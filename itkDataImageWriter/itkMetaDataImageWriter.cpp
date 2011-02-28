#include "itkMetaDataImageWriter.h"

#include <dtkCore/dtkAbstractData.h>
#include <dtkCore/dtkAbstractDataFactory.h>

#include <itkMetaImageIO.h>


itkMetaDataImageWriter::itkMetaDataImageWriter(void) : itkDataImageWriterBase()
{
    this->io = itk::MetaImageIO::New();
}


itkMetaDataImageWriter::~itkMetaDataImageWriter(void)
{
}

QStringList itkMetaDataImageWriter::handled(void) const
{
    return s_handled();
}

QStringList itkMetaDataImageWriter::s_handled(void)
{
    return QStringList()  << "itkDataImageChar3" << "itkDataImageChar4"
            << "itkDataImageUChar3" << "itkDataImageUChar4"
            << "itkDataImageShort3" << "itkDataImageShort4"
            << "itkDataImageUShort3" << "itkDataImageUShort4"
            << "itkDataImageInt3" << "itkDataImageInt4"
            << "itkDataImageUInt3" << "itkDataImageUInt4"
            << "itkDataImageLong3" << "itkDataImageLong4"
            << "itkDataImageULong3" << "itkDataImageULong4"
            << "itkDataImageFloat3" << "itkDataImageFloat4"
            << "itkDataImageDouble3" << "itkDataImageDouble4"
            << "itkDataImageRGB3";
}

bool itkMetaDataImageWriter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataWriterType("itkMetaDataImageWriter", s_handled(),
                                                                      createItkMetaDataImageWriter);
}


QString itkMetaDataImageWriter::description(void) const
{
    return "itkMetaDataImageWriter";
}

// /////////////////////////////////////////////////////////////////
// Type instantiation
// /////////////////////////////////////////////////////////////////

dtkAbstractDataWriter *createItkMetaDataImageWriter(void)
{
    return new itkMetaDataImageWriter;
}

