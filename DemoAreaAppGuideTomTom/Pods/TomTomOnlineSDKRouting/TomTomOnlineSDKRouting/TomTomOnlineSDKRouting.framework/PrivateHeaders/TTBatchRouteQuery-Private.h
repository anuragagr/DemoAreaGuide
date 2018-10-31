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

#ifndef TTBatchRouteQuery_Private_h
#define TTBatchRouteQuery_Private_h

#include "tomtom/utils/batch/Batch.h"

@interface TTBatchRouteQuery()

@property (nonatomic) std::shared_ptr<tomtom::BatchQuery> cpp;

-(instancetype _Nonnull)initWithCpp:(std::shared_ptr<tomtom::BatchQuery>)cpp;

@end

#endif /* TTBatchRouteQuery_Private_h */
