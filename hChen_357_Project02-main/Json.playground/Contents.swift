import Foundation

var dictionary: [String:String] =
    [
        "Twitter":"iDkWha7mYPa33!s",
        "Facebook" : "WJS13FLI3$29",
        "Instagram" : "SwiftUI14ED!"
    ]

do{
    let fileURL = try FileManager.default
        .url(for: .desktopDirectory, in: .userDomainMask, appropriateFor: nil, create: true)
        .appendingPathComponent("passwords.json")
    
    try JSONSerialization.data(withJSONObject: dictionary).write(to: fileURL)
}
catch
{
    print(error)
    
}
