//
//  CartViewModel.swift
//  Cart
//
//  Created by Balaji on 10/10/20.
//

import SwiftUI

class CartViewModel: ObservableObject{
    
    // cart Items....
    
    @Published var items = [

        Item(name: "Asian Pear", details: "Very Big Asian Pears", image: "pear", price: 20.99, quantity: 3,
             offset: 0, isSwiped: false),
        Item(name: "Tomatos", details: "Very red tomatos", image: "tomatoe", price: 25.69, quantity: 2, offset: 0, isSwiped: false),
        
        Item(name: "Lemon", details: "Very yellow lemon", image: "r5", price: 22.99, quantity: 1, offset: 0, isSwiped: false),
        
        Item(name: "Fresh Bread", details: "Very fresh bread", image: "r3", price: 15.2, quantity: 1, offset: 0, isSwiped: false),
        
        Item(name: "Potatoes", details: "IN-N-OUT potatoes", image: "r1", price: 29.02, quantity: 1, offset: 0, isSwiped: false),
        
    ]
}
