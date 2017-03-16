/*
 * Copyright (c) 2015-2017, Parallels International GmbH
 *
 * This file is part of Virtuozzo Core. Virtuozzo Core is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * Our contact details: Parallels International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */


#include "CDspHandlerRegistrator.h"
#include "CDspRouter.h"
#include <prlcommon/Interfaces/ParallelsNamespace.h>
#include <prlcommon/Std/PrlAssert.h>

DSP_ROUTE_TABLE_BEGIN

 DSP_ROUTE_BEGIN( IOSender::Client )
   //TODO: DispatcherHandler should include all tasks
   //DSP_ROUTE( PVE::DspClientToDispatcherCommandRangeStart,
   //     PVE::DspClientToDispatcherCommandRangeEnd,
   //	  "DispatcherHandler" )

   DSP_ROUTE( PVE::DspClientToVmCommandRangeStart,
			  PVE::DspClientToVmCommandRangeEnd,
			  "VmHandler" )

//   Route CLIENT -> CLIENT is not implemented yet!
//   DSP_ROUTE( PVE::ClientTypeStart,
//	            PVE::ClientTypeEnd,
//	            "ClientHandler" )

 DSP_ROUTE_END

DSP_ROUTE_TABLE_END
