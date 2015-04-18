//
//  ThirdViewController.swift
//  Rush Appli
//
//  Created by swift on 20/12/14.
//  Copyright (c) 2014 swift. All rights reserved.
//

import UIKit
import MapKit

class Item {
    var name: String
    var description: String
    var location: CLLocationCoordinate2D
    
    init(nam:String, des:String, lat:CLLocationDegrees, long:CLLocationDegrees) {
        self.name = nam
        self.description = des
        self.location = CLLocationCoordinate2DMake(lat, long)
    }
}

var point1 = Item(nam: "Tour Eiffel", des: "5 Avenue Anatole France, 75007 Paris", lat:48.85837, long:2.294481)
var point2 = Item(nam: "Tour Montparnasse", des: "33 Avenue du Maine, 75015 Paris", lat:48.842138, long:2.321951)
var point3 = Item(nam: "Arc de Triomphe", des: "Place Charles de Gaulle, 75008 Paris", lat:48.873792, long:2.295028)
var test: [Item] = [point1, point2, point3]

class ThirdViewController: UIViewController, UITableViewDelegate, UITableViewDataSource
{
    @IBOutlet
    var tableView: UITableView!
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return test.count;
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
         var cell: UITableViewCell = self.tableView.dequeueReusableCellWithIdentifier("cell") as UITableViewCell
        
        cell.textLabel.text = test[indexPath.row].name
        
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        var zone = test[indexPath.row].location
        // MapViewController.zoomon(zone)
        var x = self.tabBarController?.viewControllers![1] as SecondViewController
        x.receivedLocation = zone
        self.tabBarController?.selectedIndex = 1
        x.zoomon(zone)
        println("You selected cell #\(indexPath.row)!")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.tableView.registerClass(UITableViewCell.self, forCellReuseIdentifier: "cell")
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}
