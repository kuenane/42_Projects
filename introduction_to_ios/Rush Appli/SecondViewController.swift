//
//  SecondViewController.swift
//  Rush Appli
//
//  Created by swift on 20/12/14.
//  Copyright (c) 2014 swift. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class SecondViewController: UIViewController, MKMapViewDelegate, CLLocationManagerDelegate {

    let locationManager = CLLocationManager()
    @IBOutlet weak var Map_Reference: MKMapView!
    @IBOutlet weak var Choice_Reference: UISegmentedControl!
    @IBOutlet weak var Geoloc_Reference: UIButton!
    var manager:CLLocationManager!
    var annotation = MKPointAnnotation()
    var receivedLocation: CLLocationCoordinate2D?
    override func viewDidLoad() {
        super.viewDidLoad()
        //0
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()
        
        
        // 1
        let location = CLLocationCoordinate2D(
            latitude: 48.896684,
            longitude: 2.318376
        )
        // 2
        zoomon(receivedLocation ?? location)

       // let span = MKCoordinateSpanMake(0.0042, 0.0042)
//let region = MKCoordinateRegion(center: location, span: span)
        //Map_Reference.setRegion(region, animated: true)
        
        //3
        annotation.setCoordinate(location)
        annotation.title = "Ecole 42"
        annotation.subtitle = "42 Born2Code"
        Map_Reference.addAnnotation(annotation)
        
        //boutons de la liste
        for var index = 0; index < test.count; ++index {
            // ajouter pin sur loc
            annotation = MKPointAnnotation()
            annotation.setCoordinate(test[index].location)
            annotation.title = test[index].name
            annotation.subtitle = test[index].description
            Map_Reference.addAnnotation(annotation)
        }
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func Change_Type(sender: AnyObject) {
        switch (Choice_Reference.selectedSegmentIndex) {
        case 0:
            Map_Reference.mapType = MKMapType.Standard
            break
        case 1:
            Map_Reference.mapType = MKMapType.Satellite
            break
        case 2:
            Map_Reference.mapType = MKMapType.Hybrid
            break
            
        default:
            break
    }
    }
    
    @IBAction func putGeoloc(sender: AnyObject) {
        manager = CLLocationManager()
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestAlwaysAuthorization()
        manager.startUpdatingLocation()
        
        // 1
        let currentLocation: CLLocationCoordinate2D = CLLocationCoordinate2DMake(locationManager.location.coordinate.latitude, locationManager.location.coordinate.longitude)
        // 2
        let span = MKCoordinateSpanMake(0.0042, 0.0042)
        let region = MKCoordinateRegion(center: currentLocation, span: span)
        Map_Reference.setRegion(region, animated: true)
        
        //3
        let annotation = MKPointAnnotation()
        annotation.setCoordinate(currentLocation)
        annotation.title = "Current Location"
        Map_Reference.addAnnotation(annotation)
    }
    func zoomon(zone: CLLocationCoordinate2D) {
        
        
        let span = MKCoordinateSpanMake(0.0042, 0.0042)
        let region = MKCoordinateRegion(center: zone, span: span)
        Map_Reference.setRegion(region, animated: true)
    }
}