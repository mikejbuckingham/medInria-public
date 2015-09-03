/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <dtkComposer>

class medSubtractImageProcessNodePrivate;

// ///////////////////////////////////////////////////////////////////
//
// ///////////////////////////////////////////////////////////////////
template <class T>
class medProcessNode : public dtkComposerNodeObject<T>
{
public:
    medProcessNode(void);
    virtual ~medProcessNode(void);

public:
    void run(void);
};
