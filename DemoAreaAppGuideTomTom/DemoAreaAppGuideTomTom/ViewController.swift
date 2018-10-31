//
//  ViewController.swift
//  DemoAreaAppGuideTomTom
//
//  Created by Mac on 27/10/18.
//  Copyright © 2018 Mac software. All rights reserved.
//

import UIKit
import CoreLocation

class ViewController: UIViewController {
    @IBOutlet weak var searchButton: UIButton!
    
    @IBOutlet weak var searchAreaTextField: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        //self.navigationController?.navigationBar.isHidden = true
        var navigationBarAppearace = UINavigationBar.appearance()
        navigationBarAppearace.tintColor = UIColor.init(displayP3Red: 225/255.0, green: 102/255.0, blue: 102/255.0, alpha: 1.0)
        navigationBarAppearace.barTintColor = UIColor.init(displayP3Red: 225/255.0, green: 102/255.0, blue: 102/255.0, alpha: 1.0)
        let locationManager = LocationManager.sharedInstance()
        locationManager?.startService()
        // Do any additional setup after loading the view, typically from a nib.
    }

    @IBAction func searchButtonTapped(_ sender: Any) {
        print("button clicked")
        if let searchText =  searchAreaTextField.text {
            if searchText.count > 0 {
                if let viewController = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(withIdentifier: "SearchAlongTheRouteViewController") as? SearchAlongTheRouteViewController {
                    //viewController.newsObj = newsObj
                    let geocoder = CLGeocoder()
                    geocoder.geocodeAddressString(searchText) { (placemarks, error) in
                        if error == nil {
                            if let placemark = placemarks?[0] {
                                let location = placemark.location!
                                if let navigator = self.navigationController {
                                    print("location \(location)")
                                    viewController.destinationLocation = location
                                    navigator.pushViewController(viewController, animated: true)
                                }
                                
                            }
                        }
                        
                    }
                }

            } else {
                let alert = UIAlertController(title: "Search", message: "Search should be not blank.", preferredStyle: .alert)
                let OKAction = UIAlertAction(title: "OK", style: .default) { (action) in
                    // do something
                    self.dismiss(animated: true, completion: nil)
                }
                alert.addAction(OKAction)
                self.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    func getCoordinate( addressString : String,
                        completionHandler: @escaping(CLLocationCoordinate2D, NSError?) -> Void ) {
        let geocoder = CLGeocoder()
        geocoder.geocodeAddressString(addressString) { (placemarks, error) in
            if error == nil {
                if let placemark = placemarks?[0] {
                    let location = placemark.location!
                    
                    completionHandler(location.coordinate, nil)
                    return
                }
            }
            
            completionHandler(kCLLocationCoordinate2DInvalid, error as NSError?)
        }
    }
    
}
extension ViewController: UITextFieldDelegate {
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        return true
    }
}

