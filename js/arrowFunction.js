var magic = function() {
  return new Date();
};

var moreMagic = () => {
  return new Date();
}

var evenMoreMagic = () => new Date();

var myConcat = (arr1, arr2) => arr1.concat(arr2);
console.log(myConcat([1, 2, 3], [4, 5, 6]));
console.log(myConcat);

myArr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
myFilteredArr = myArr.filter(num => num % 2 == 0)

function isEven(num) {
  return num % 2 == 0
}

myFilteredArr2 = myArr.filter(isEven)
console.log(myFilteredArr);
console.log(myFilteredArr2);
myMappedArr = myArr.map((num, index, a) => a);
console.log(myMappedArr);
