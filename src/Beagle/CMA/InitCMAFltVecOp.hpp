/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   beagle/GA/InitCMAFltVecOp.hpp
 *  \brief  Definition of the class GA::InitCMAFltVecOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.4 $
 *  $Date: 2007/08/08 19:26:34 $
 */

#ifndef Beagle_CMA_InitCMAFltVecOp_hpp
#define Beagle_CMA_InitCMAFltVecOp_hpp

#include <string>

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/Core/AllocatorT.hpp"
#include "Beagle/Core/PointerT.hpp"
#include "Beagle/Core/ContainerT.hpp"
#include "Beagle/EC/InitializationOp.hpp"
#include "Beagle/FltVec.hpp"
#include "Beagle/CMA/InitCMAFltVecOp.hpp"


namespace Beagle
{
namespace CMA
{

/*!
 *  \class InitCMAFltVecOp beagle/GA/InitCMAFltVecOp.hpp "beagle/GA/InitCMAFltVecOp.hpp"
 *  \brief Real-valued GA genotype uniformly initialization for CMA-ES operator class.
 *  \ingroup GAF
 *  \ingroup GAFV
 *
 *  This operator does the same thing than the GA::InitFltVecOp except that initialize
 *  only one individual in the population, nowithstanding of the population size given.
 *  This approach is suitable to the CMA-ES algorithm, which start from only one initial
 *  random point.
 */
class InitCMAFltVecOp : public FltVec::InitGaussianOp
{

public:

	//! GA::InitCMAFltVecOp allocator type.
	typedef AllocatorT<InitCMAFltVecOp,FltVec::InitGaussianOp::Alloc>
	Alloc;
	//! GA::InitCMAFltVecOp handle type.
	typedef PointerT<InitCMAFltVecOp,FltVec::InitGaussianOp::Handle>
	Handle;
	//! GA::InitCMAFltVecOp bag type.
	typedef ContainerT<InitCMAFltVecOp,FltVec::InitGaussianOp::Bag>
	Bag;

	explicit InitCMAFltVecOp(unsigned int inFloatVectorSize=0,
	                         std::string inReproProbaName="ec.repro.prob",
	                         std::string inName="CMA-InitCMAFltVecOp");
	virtual ~InitCMAFltVecOp()
	{ }

	virtual void operate(Beagle::Deme& ioDeme, Beagle::Context& ioContext);


};

}
}

#endif // Beagle_GA_InitCMAFltVecOp_hpp
