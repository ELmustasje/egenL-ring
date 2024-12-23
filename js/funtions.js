let scopeTest = 5;
function myFunc() {
  let scopeTest = 2;
  console.log(scopeTest);
  console.log("hello world");
}
console.log(scopeTest);
myFunc();

function rm5(num) {
  return num - 5;
}

var a = rm5(10);

function increment(base, increment = 1) {
  return base + increment;
}
console.log(increment(6));

function sum(...args) {
  let sum = 0;
  for (let elem of args) {
    sum += elem
  }
  return sum
}

