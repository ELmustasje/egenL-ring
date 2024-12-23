var myString = "Jello world"
myString[0] = "H"
console.log(myString)//no change, strings are immutable
myString = "Hello world"
console.log(myString)
result = myString.replace("H", "J")
console.log(result)

console.log(result.length)

