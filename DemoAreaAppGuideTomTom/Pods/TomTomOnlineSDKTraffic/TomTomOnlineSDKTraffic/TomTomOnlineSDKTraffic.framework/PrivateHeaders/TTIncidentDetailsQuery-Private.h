/**
 * Copyright (c) 2017 TomTom N.V. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom N.V. and its subsidiaries and may be used
 * for internal evaluation purposes or commercial use strictly subject to separate licensee
 * agreement between you and TomTom. If you are the licensee, you are only permitted to use
 * this Software in accordance with the terms of your license agreement. If you are not the
 * licensee then you are not authorised to use this software in any manner and should
 * immediately return it to TomTom N.V.
 */

#ifndef TTIncidentDetailsQuery_Private_h
#define TTIncidentDetailsQuery_Private_h
#include "TTIncidentDetailsQuery.h"
#include "tomtom/traffic/incidents/incident_details_query.hpp"
#include "tomtom/traffic/incidents/incident_details_query_builder.hpp"

@interface TTIncidentDetailsQuery ()

-(id)initWithCppShared:(std::shared_ptr<tomtom::traffic::IncidentDetailsQuery>) cpp;

@property (nonatomic) std::shared_ptr<tomtom::traffic::IncidentDetailsQuery> cpp;

@end


#endif /* TTIncidentDetailsQuery_Private_h */
