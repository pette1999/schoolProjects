//
//  ContentView.swift
//  HChen_357_Project03
//
//  Created by peter on 3/21/21.
//

import SwiftUI

struct ContentView: View {
    @State var masterPassword = ""
    @State var passwords = StorageHandler.getStorage()
    @State private var passwordKey: [String] = StorageHandler.getKeys()
    @State private var mPass: String = ""
    @State private var key: String = ""
    @State private var password: String = ""
    @State private var identifier: String = ""
    @State private var showingDetail = false
    @State private var showingError = false
    @State private var hiddenmasterpassword = ""
    @State private var hidemasterpassword = true
    
    var body: some View {
        VStack {
            NavigationView {
                List {
                    ForEach(self.passwordKey, id: \.self) {
                        item in
                        Button(
                            action: {
                                showingDetail.toggle()
                            },
                            label: {
                                Text(item)
                                    .frame(maxWidth: .infinity, alignment: .leading)
                        })
                        .sheet(isPresented: $showingDetail) {
                            DetailView(key: item, passwordList: passwords)
                        }
                    }
                    .onDelete(perform: delete)
                }
                .navigationBarTitle(Text("Key List"))
            }
            TextField("Enter a key", text: $key)
                .padding()
            TextField("Enter a password", text: $password)
                .padding()
            TextField("Enter an identifier", text: $identifier)
                .padding()
            Button(
                action: {
                    if self.key != "" && password != "" && identifier != ""{
                        showingError = false
                        addSingle(key: key, pwd: password, phrase: identifier)
                        StorageHandler.setStorage(input: passwords)
                        passwordKey = StorageHandler.getKeys()
                        self.key = ""
                        self.password = ""
                        self.identifier = ""
                    } else {
                        showingError = true
                    }
                },
                label: {
                    Text("Add a Password")
                        .padding(.horizontal, 12)
                        .padding(.vertical, 5)
                        .border(Color.black, width: 1)
                        .foregroundColor(.black)
            })
            SheetView(btnTitle: "Reset Passcode", showTrigger: false)
                .padding(.horizontal, 12)
                .padding(.vertical, 5)
                .border(Color.black, width: 1)
                .foregroundColor(.black)
            SheetView(btnTitle: "Sign Out", showTrigger: true)
                .padding(.horizontal, 12)
                .padding(.vertical, 5)
                .border(Color.black, width: 1)
                .foregroundColor(.black)
            if(showingError) {
                Text("Missing input man!")
                    .foregroundColor(.red)
                    .font(.system(size: 18, weight: .heavy, design: .default))
            }
           
        }
    }

    func delete(at offsets: IndexSet) {
        passwordKey.remove(atOffsets: offsets)
        let tempArr = StorageHandler.getKeys()
        
        for i in tempArr {
            if(passwordKey.contains(i)) {
                continue
            } else {
                passwords.removeValue(forKey: i)
            }
        }
        StorageHandler.setStorage(input: passwords)
    }
    
    func showMasterPassword() -> String {
        return MasterPasswordHandler.getStorage(key: "pass")
    }
    
    // add single password
    func addSingle(key:String, pwd:String, phrase:String) {
        let originalPwd = pwd + phrase
        let encryptedPWD = encrypt(strForward: originalPwd)
        // add the key and password to the dictionary
        passwords[key] = encryptedPWD
    }
    
    func encrypt(strForward:String) -> String {
        // reverse the string
        let reversedString = String(strForward.reversed())
        var strShift:String = ""
        // do the caesar cipher
        for letter in reversedString {
            strShift += String(translate(l: letter, trans: reversedString.count))
        }
        return strShift
    }
    
    // caesar cipher
    func translate(l: Character, trans: Int) -> Character {
        if let ascii = l.asciiValue
        {
            var outputInt = ascii
            if (ascii >= 97 && ascii <= 122) {
                // a = 97
                //97 - 97 = 0
                //0+27 = 27
                //27 % 26 = 1
                //1 + 97 = 98
                //98 = b
                outputInt = ((ascii-97+UInt8(trans))%26)+97
            } else if (ascii >= 65 && ascii <= 90) {
                outputInt = ((ascii-65+UInt8(trans))%26)+65
            }
            
            //65 -> 65 the Character value -> "A"
            return Character(UnicodeScalar(outputInt))
        }
        
        return Character("")
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

struct SheetView: View {
    @State var btnTitle:String
    @State var showTrigger = true
    
    var body: some View {
        VStack {
            Button(self.btnTitle) {
                self.showTrigger = true
                if self.btnTitle == "Reset Passcode" {
                    MasterPasswordHandler.setKeyPass(input: "")
                    MasterPasswordHandler.setTitle(input: "Create New Passcode")
                }
            }
        }.sheet(isPresented: $showTrigger, onDismiss: {
        })
        {
            LockView()
        }
    }
}

struct LockView: View {
    @State private var text: String = ""
    @State private var titleMessage = MasterPasswordHandler.getTitleMessave()
    @State private var keyPass = MasterPasswordHandler.getKeyPass()
    @State var errorMessage = ""
    
    var body: some View{
        VStack{
            Spacer()
            
            Text(self.titleMessage).font(.system(size: 22, weight: .semibold, design: .default))
            TextField("Password Here", text: $text).textFieldStyle(RoundedBorderTextFieldStyle())
                .font(.system(size: 20, weight: .medium, design: .default))
            Text(self.errorMessage).foregroundColor(.red).font(.system(size: 15, weight: .semibold, design: .default))
            
            Button(action: {
                if self.keyPass == self.text {
                    UIApplication.shared.windows[0].rootViewController?.dismiss(animated: false, completion: {})
                } else if self.keyPass == "" {
                    MasterPasswordHandler.setKeyPass(input: self.text)
                    MasterPasswordHandler.setTitle(input: "Input the passcode")
                    
                    UIApplication.shared.windows[0].rootViewController?.dismiss(animated: false, completion: {})
                }else{
                    self.errorMessage = "Incorrect Passcode"
                }
            }) {
                Text("Done")
                    .padding(.horizontal, 12)
                    .padding(.vertical, 5)
                    .border(Color.black, width: 1)
                    .foregroundColor(.black)
                    .font(.system(size: 18, design: .default))
            }
            Spacer()
        }.font(.custom("SFProText-Bold", size: 25))
    }
}
