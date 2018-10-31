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

#ifndef TTTrafficUtils_Private_h
#define TTTrafficUtils_Private_h

#include "tomtom/traffic/incidents/incident_details_types.hpp"
#include "tomtom/traffic/flow/flow_segment_data_types.hpp"

@interface TTTrafficUtils()

+ (tomtom::traffic::IncidentDetailsQueryTypes::GeometryType)geometryType:(TTTrafficGeometriesType)trafficGeometriesType;

+ (tomtom::traffic::IncidentDetailsQueryTypes::Style)incidentStyleType:(TTTrafficIncidentStyleType)trafficIncidentStyleType;

+ (tomtom::traffic::FlowSegmentDataQueryTypes::Style)styleType:(TTTrafficStyleType)trafficStyleType;

+ (tomtom::traffic::FlowSegmentDataQueryTypes::SpeedUnit)unitType:(TTTrafficUnitType)unitType;

@end

#endif /* TTTrafficUtils_Private_h */
