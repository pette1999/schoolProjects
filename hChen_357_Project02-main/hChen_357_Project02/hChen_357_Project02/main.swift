import Foundation

class Program {
    var password = Dictionary<String,String>()
    
    init() {
        var reply = ""
        var keepRunning = true
        
//        Pass.writeToJson(dictionary: passwordDic)
        password = File.readJSONFromFile()

        while(keepRunning) {
            menu()
            // Ask a question
            reply = Ask.AskQuestion(questionText: "Which function do you want to run?", acceptableReplies: ["1", "2", "3", "4", "5"])
            // Act on a question
            if (reply == "1") {
                //1. View all password
                var count = 1
                print("Here are all the keys of your password: ")
                password.keys.forEach { key in
                     print("\t\(count). \(key)")
                    count += 1
                }
            } else if (reply == "2") {
                //2. View single password
                reply = Ask.AskQuestion(questionText: "Please enter a key to the password.", acceptableReplies: [])
                viewSingle(key: reply)
            } else if (reply == "3") {
                //3. Delete single password
                reply = Ask.AskQuestion(questionText: "Please enter a key to the password.", acceptableReplies: [])
                // Delete the password from the key inputed
                deleteSingle(key: reply)
                // update the json file
                File.writeToJson(dictionary: password)
            } else if (reply == "4") {
                //4. Add single password
                let addkey:String = Ask.AskQuestion(questionText: "Please enter a key to the password.", acceptableReplies: [])
                let addPwd:String = Ask.AskQuestion(questionText: "Please enter your password.", acceptableReplies: [])
                let addPhrase:String = Ask.AskQuestion(questionText: "Please enter your phrase to your password.", acceptableReplies: [])
                addSingle(key: addkey, pwd: addPwd, phrase: addPhrase)
            }
            else {
                print("Thank you. Goodbye.")
                break
            }
            // Check if keep running
            reply = Ask.AskQuestion(questionText: "Do you want to keep running the app?", acceptableReplies: ["yes", "no"])
            // if not, change keepRunning=false
            if(reply == "yes") {
                continue
            } else {
                print("Thank you. Goodbye.")
                keepRunning = false
            }
            // Application will end
        }
    }
    
    func menu() {
        print("1. View all password")
        print("2. View single password")
        print("3. Delete single password")
        print("4. Add single password")
        print("5. Exit")
    }
    
    func deleteSingle(key:String) {
        // check if the key exists
        if let pass = password.removeValue(forKey: key) {
            // password exists
            print("The password '\(pass)' with key '\(key)' has been removed")
        } else {
            // Password does not exist
            print("No password found for key: \(key)")
        }
    }
    
    func encrypt(strForward:String) -> String {
        // reverse the string
        let reversedString = String(strForward.reversed())
        var strShift:String = ""
        // do the caesar cipher
        for letter in reversedString {
            strShift += String(Pass.translate(l: letter, trans: reversedString.count))
        }
        return strShift
    }
    
    func decrypt(key:String, passphrase:String) -> String {
        let strBackword = password[key]
        var strShift:String = ""
        // do the de-caesar cipher
        for letter in strBackword! {
            strShift += String(Pass.deTranslate(l: letter, trans: strBackword!.count))
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
    
    func viewSingle(key:String) {
        // check if the key exists
        if password[key] != nil {
            // password exists
            let reply = Ask.AskQuestion(questionText: "What's the phrase for the password", acceptableReplies: [])
            let finalPass = decrypt(key: key, passphrase: reply)
            print("Your password is: '\(finalPass)'")
        } else {
            // password does not exist
            print("Please go back to the main menu.")
        }
    }
    
    func addSingle(key:String, pwd:String, phrase:String) {
        let originalPwd = pwd + phrase
        let encryptedPWD = encrypt(strForward: originalPwd)
        // add the key and password to the dictionary
        password[key] = encryptedPWD
        // update the json file
        File.writeToJson(dictionary: password)
    }
}

class Ask
{
    static func AskQuestion(questionText output: String, acceptableReplies inputArr: [String], caseSensitive: Bool = false) -> String {
        print(output) //output is the questionText ask our question
        //handle response
        guard let response = readLine() else {
            //they didn't have a valid answer
            print("Invalid input")
            return AskQuestion(questionText: output, acceptableReplies: inputArr)
        }
        //they typed in a valid answer
        //verify response is acceptable
        //OR we don't care what the response is
        if(inputArr.contains(response) || inputArr.isEmpty) {
            return response
        }
        else
        {
            print("Invalid input")
            return AskQuestion(questionText: output, acceptableReplies: inputArr)
        }
    }
}

class Pass
{
    static func AskPass(passwordQuestion output: String, passwordReplies input: [String], caseSensitive: Bool = false)-> String
    {
        print(output)
        guard let response = readLine() else
        {
            print("Invalid input")
            return AskPass(passwordQuestion: output, passwordReplies: input)
            
        }
        if(input.contains(response))
        {
            return response
        }
        else
        {
            print("Invalid input")
            return AskPass(passwordQuestion: output, passwordReplies: input)
        }
    }
    
    // caesar cipher
    static func translate(l: Character, trans: Int) -> Character {
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
                outputInt = ((ascii-5+UInt8(trans))%26)+65
            }
            
            //65 -> 65 the Character value -> "A"
            return Character(UnicodeScalar(outputInt))
        }
        
        return Character("")
    }
    
    // reverse caesar cipher
    static func deTranslate(l: Character, trans: Int) -> Character {
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

class File {
    static func writeToJson(dictionary: [String:String]) {
        do {
            let fileURL = try FileManager.default
                .url(for: .desktopDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
                .appendingPathComponent("passwords.json")
            
            try JSONSerialization.data(withJSONObject: dictionary).write(to: fileURL)
        } catch {
            print(error)
        }
    }
    
    static func readJSONFromFile() -> Dictionary<String,String>
      {
        var passwords = Dictionary<String,String>()
        do {
            let fileURL = try FileManager.default
                .url(for: .desktopDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
                .appendingPathComponent("passwords.json")
            let josnData = try Data(contentsOf: fileURL)
            passwords = try JSONSerialization.jsonObject(with: josnData) as! Dictionary<String,String>
        } catch {
            print(error)
            
        }
        return passwords
      }
}

let p = Program()
