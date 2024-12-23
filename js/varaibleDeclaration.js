//let = local variable 
//var = global variable
//const = constant variable, only avalible inside scope
const pi = 3.14;
{

  let foo = "Foo";
  var bar = "Bar";

  console.log("inside scope", foo);
  console.log("inside scope", bar);
  console.log("inside scope", pi);
}
//console.log(foo) = error
console.log("outside scope", bar);
bar = "BARRRRR";
console.log("changed bar", bar);
//pi = 2 = error

//declaration vs assignment
var a; //declared
var b = 10; //assigned

console.log("a =", a);
console.log("b =", b);
a = 7;//assigned
a++;
console.log("a =", a);


