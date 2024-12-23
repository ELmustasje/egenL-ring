//js types = number, string, boolean, null, undefined, object
//ts = js +, any, unknown, never, enum, tuple
let sales: number = 123_456_789;
let message: string = "Hello World";
let is_sendt: boolean = false;
let random: any = "a";
random = 1;

function render(doc) {//should always have a type, so the compiler dont have to guess
  console.log(doc);

}
