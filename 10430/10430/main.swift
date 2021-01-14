import Foundation
let line = readLine()!
let arr = line.components(separatedBy: " ")
print(((Int(arr[0])! + Int(arr[1])!)) % (Int(arr[2])!))
print((((Int(arr[0])! % Int(arr[2])!)) + ((Int(arr[1])! % Int(arr[2])!))) % (Int(arr[2])!))
print((Int(arr[0])! * Int(arr[1])!) % (Int(arr[2])!))
print((((Int(arr[0])! % Int(arr[2])!)) * ((Int(arr[1])! % Int(arr[2])!))) % (Int(arr[2])!))

