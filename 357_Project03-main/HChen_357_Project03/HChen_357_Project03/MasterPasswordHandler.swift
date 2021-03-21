//
//  MasterPasswordHandler.swift
//  HChen_357_Project03
//
//  Created by peter on 3/21/21.
//

import Foundation

struct MasterPasswordHandler {
    static var defaultStorage: UserDefaults = UserDefaults.standard
    static let defaultKey = "DefaultPassword"
    
    static func setStorage(input: String, key: String) {
        defaultStorage.set(input, forKey: key)
    }
    
    static func setTitle(input: String) {
        defaultStorage.set(input, forKey: "message")
    }
    
    static func setKeyPass(input: String) {
        defaultStorage.set(input, forKey: "pass")
    }
    
    static func getStorage(key: String) -> String {
        if let password = defaultStorage.string(forKey: key) {
            return password
        } else {
            return ""
        }
    }
    
    static func getTitleMessave() -> String {
        if let password = defaultStorage.string(forKey: "message") {
            return password
        } else {
            return "Create New Passcode"
        }
    }
    
    static func getKeyPass() -> String {
        if let password = defaultStorage.string(forKey: "pass") {
            return password
        } else {
            return ""
        }
    }
}
