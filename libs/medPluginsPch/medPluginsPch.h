/* medPluginsPch.h ---
 *
 * Author: John Stark
 * Copyright (C) 2011 - John Stark, Inria.
 * Created: August 2011
 * Version: $Id$
 * Last-Updated:
 *           By: John Stark
 *     Update #: 1
 */

/* Commentary:
 * Precompiled header file
 */

/* Change log:
 *
 */


#pragma once

#include <QtCore>
#include <QtDebug>
#include <QtGui>

#include <dtkCore/dtkAbstractData.h>
#include <dtkCore/dtkAbstractDataFactory.h>
#include <dtkCore/dtkAbstractDataReader.h>
#include <dtkCore/dtkAbstractDataWriter.h>
#include <dtkCore/dtkAbstractProcess.h>
#include <dtkCore/dtkAbstractProcessFactory.h>
#include <dtkCore/dtkAbstractViewFactory.h>
#include <dtkCore/dtkSmartPointer.h>

#ifdef MEDINRIA_PLUGINS_PCH_USE_VTK
//VTK
#include <vtkActor.h>
#include <vtkActor2D.h>
#include <vtkCamera.h>
#include <vtkCommand.h>
#include <vtkgl.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkMath.h>
#include <vtkMatrix4x4.h>
#include <vtkObject.h>
#include <vtkPolyDataMapper2D.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkTransform.h>
#endif // MEDINRIA_PLUGINS_PCH_USE_VTK

#ifdef MEDINRIA_PLUGINS_PCH_USE_ITK
//ITK
#include <itkConstNeighborhoodIterator.h>
#include <itkExtractImageFilter.h>
#include <itkGreyColormapFunctor.h>
#include <itkImage.h>
#include <itkImageIOBase.h>
#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>
#include <itkImageToImageFilter.h>
#include <itkMinimumMaximumImageCalculator.h>
#include <itkObjectFactory.h>
#include <itkRecursiveGaussianImageFilter.h>
#include <itkRegionOfInterestImageFilter.h>
#include <itkResampleImageFilter.h>
#include <itkRGBAPixel.h>
#include <itkRGBPixel.h>
#include <itkScalarImageToHistogramGenerator.h>
#include <itkScalarToRGBColormapImageFilter.h>
#include <itkShrinkImageFilter.h>
#include <itkVector.h>
#endif // MEDINRIA_PLUGINS_PCH_USE_ITK

//STL / C++ bindings for C
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>


