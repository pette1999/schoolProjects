//
//  DetailView.swift
//  HChen_357_Project03
//
//  Created by peter on 3/21/21.
//

import SwiftUI

struct DetailView: View {
    @State private var identifier: String = ""
    var key: String
    var passwordList: [String: String]
    @State private var yourPassword: String = ""
    
    var body: some View {
        TextField("Enter an identifier", text: $identifier).textFieldStyle(RoundedBorderTextFieldStyle())
            .font(.system(size: 20, weight: .medium, design: .default))
            .padding()
        Text("Our Key is: ")
        Text(key)
            .font(.system(size: 20, weight: .semibold, design: .default))
            .foregroundColor(.blue)
        Button(
            action: {
                if self.identifier != "" {
                    yourPassword = viewSingle(key: key, identifier: identifier)
                    self.identifier = ""
                }
            },
            label: {
                Text("Get Password")
                    .padding(.horizontal, 12)
                    .padding(.vertical, 5)
                    .border(Color.black, width: 1)
                    .foregroundColor(.black)
        })
        Text(yourPassword)
            .font(.system(size: 20, weight: .semibold, design: .default))
            .foregroundColor(.blue)
    }
    
    func viewSingle(key:String, identifier:String) -> String{
        // check if the key exists
        if passwordList[key] != nil {
            let finalPass = decrypt(key: key, passphrase: identifier)
            print("Your password is: '\(finalPass)'")
            return ("Your password is: '\(finalPass)'")
        } else {
            // password does not exist
            print("Please go back to the main menu.")
            return ("Password does not exist")
        }
    }
    
    func decrypt(key:String, passphrase:String) -> String {
        let strBackword = passwordList[key]
        var strShift:String = ""
        // do the de-caesar cipher
        for letter in strBackword! {
            strShift += String(deTranslate(l: letter, trans: strBackword!.count))
        }
        // reverse back the string
        var decryptedString:String = String(strShift.reversed())
        
        // get the length of the phrase
        let phraseLength:Int = passphrase.count
        // get the phrase from decrypted message
        let phrase:String = String(decryptedString.suffix(phraseLength))
        
        if(passphrase == phrase) {
            decryptedString = String(decryptedString.prefix(decryptedString.count - phraseLength))
            return decryptedString
        } else {
            return ("Error message: passphrase does not match")
        }
    }
    
    func deTranslate(l: Character, trans: Int) -> Character {
        if let ascii = l.asciiValue {
            var outputInt = ascii
            if (ascii >= 97 && ascii <= 122) {
                let asciiNum = ascii - UInt8(trans)
                if (asciiNum < 97) {
                    outputInt = outputInt + 26
                } else if (asciiNum > 122) {
                    outputInt = outputInt - 26
                }
                outputInt = (((outputInt - 97) - UInt8(trans)) % 26) + 97
            } else if (ascii >= 65 && ascii <= 90) {
                let asciiNum = ascii - UInt8(trans)
                if(asciiNum < 65) {
                    outputInt = outputInt + 26
                } else if (asciiNum > 90) {
                    outputInt = outputInt - 26
                }
                outputInt = (((outputInt - 65) - UInt8(trans))%26) + 65
            }
            return Character(UnicodeScalar(outputInt))
        }
        return Character("")
    }
}

struct DetailView_previews: PreviewProvider {
    static var previews: some View {
        DetailView(key: "Hello", passwordList: ["hello":"what"])
    }
}
