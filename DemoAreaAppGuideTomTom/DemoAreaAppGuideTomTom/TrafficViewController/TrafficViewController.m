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

#import "TrafficViewController.h"
#import <TomTomOnlineSDKTraffic/TomTomOnlineSDKTraffic.h>
#import "FormatUtils.h"

@interface TrafficTableViewCell: UITableViewCell

@property (weak, nonatomic) IBOutlet UIImageView *trafficImageView;
@property (weak, nonatomic) IBOutlet UILabel *descriptionTextField;
@property (weak, nonatomic) IBOutlet UILabel *delayTextField;
@property (weak, nonatomic) IBOutlet UILabel *lengthTextField;

@end

@implementation TrafficTableViewCell

@end

@interface TrafficViewController () <UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UITableView *trafficTableView;
@property (strong, nonatomic) NSArray<TTTrafficDetailBase *>* incidents;

@end

@implementation TrafficViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self buildHeader:@"Traffic incident list" and:@"London"];

    TTLatLngBounds bounds = TTLatLngBoundsMake(CLLocationCoordinate2DMake(51.544300, -0.176267), CLLocationCoordinate2DMake(51.465582, -0.071777));
    TTIncidentDetailsQuery *query = [[TTIncidentDetailsQueryBuilder createWithStyle:TTTrafficIncidentStyleTypeS1 withBoundingBox:bounds withZoom:12 withTrafficModelID:@"-1"] build];

    [[TTTrafficIncidents new] incidentDetailsWithQuery:query completionHandler:^(TTIncidentDetailsResponse * _Nullable response, TTResponseError * _Nullable error) {
        self.incidents = [response incidents];
        [self.trafficTableView reloadData];
    }];
}

#pragma mark - Traffic Table View
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.incidents count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    TrafficTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"TrafficTableViewCell" forIndexPath:indexPath];

    TTTrafficDetailBase *incident = [self.incidents objectAtIndex:indexPath.row];
    if ([incident isKindOfClass:[TTTrafficDetail class]]) {
        TTTrafficDetail *trafficDetail = (TTTrafficDetail *)incident;
        cell.trafficImageView.image = [[TTTrafficDetailImage createWithTraffic:trafficDetail] medium];
        cell.descriptionTextField.text = [NSString stringWithFormat:@"%@ / %@", trafficDetail.from, trafficDetail.to];
        cell.delayTextField.text = trafficDetail.delay == -1 ? @"---" : [FormatUtils formatTimeDelay:(int)trafficDetail.delay];
        cell.lengthTextField.text = [FormatUtils formatDistance:(int)trafficDetail.length imperial:false];
    } else {
        TTTrafficDetailCluster *trafficDetailCluster = (TTTrafficDetailCluster *)incident;
        cell.trafficImageView.image = [[TTTrafficDetailImage createWithTraffic:trafficDetailCluster] medium];
        cell.descriptionTextField.text = @"Multiple incidents";
        cell.lengthTextField.text = [FormatUtils formatDistance:(int)trafficDetailCluster.length imperial:false];
    }

    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 70.0;
}

- (nullable UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    UIView *tableViewCell = [tableView dequeueReusableCellWithIdentifier:@"TrafficSectionTableViewCell"];
    return tableViewCell;
}

@end
