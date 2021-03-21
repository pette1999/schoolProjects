//
//  StorageHandler.swift
//  HChen_357_Project03
//
//  Created by peter on 3/21/21.
//

import Foundation

struct StorageHandler {
    static var defaultStorage: UserDefaults = UserDefaults.standard
    static let defaultKey = "BasicStringStorage"
    
    static func setStorage(input: [String:String]) {
        defaultStorage.set(input, forKey: self.defaultKey)
    }
    
    static func getStorage() -> [String: String] {
        if let storedWords = defaultStorage.object(forKey: defaultKey) as? [String: String]? ?? [String: String]() {
            return storedWords
        } else {
            return [:]
        }
    }
    
    static func getKeys() -> [String] {
        if let storedWords = defaultStorage.object(forKey: defaultKey) as? [String: String]? ?? [String: String]() {
            var passwordKey: [String] = []
            storedWords.keys.forEach { key in
                passwordKey.append(key)
            }
            return passwordKey
        } else {
            return []
        }
    }
}
