mod myModule;

fn main() {
    //let result = double(32);
    //blocks();
    //scope();
    //visibility();
    //ownership();
    reference();
    //variables();
    //mut_reference();
    //macros();
    //attributes();
}

fn double(num: u128) -> u128 {
    num * 2
}

fn blocks() {
    let sum: i32 = {
        let num1 = 20;
        let num2 = 30;
        num1 + num2
    };
    fn sum_fn() -> i32 {
        let num1 = 20;
        let num2 = 30;
        num1 + num2
    }
    let res = sum_fn();
    println!("{res},{sum}");
}

fn scope() {
    let number = 10;
    {
        let number = 20;
        println!("{number}");
    }
    println!("{number}");
}

//modules for visibility
mod nums {
    pub const ZERO: i32 = 0;
}
mod more_nums {
    pub const ONE: i32 = 1;
    use super::nums::ZERO;
    pub fn print_nums() {
        println!("{ZERO},{ONE}");
    }
}

//struct for visibility
pub struct Number {
    value: i32,
    struct_type: String,
}

fn visibility() {
    more_nums::print_nums();
    let mut number = Number {
        value: 0,
        struct_type: String::from("num"),
    };
    number.value = 2;
    println!(
        "value is: {}, type is: {}",
        number.value, number.struct_type
    )
}

fn ownership() {
    //stackbased values like i32 will be copied
    let stack_num1 = 10;
    let stack_num2 = 20;
    println!("num1: {stack_num1}, num2: {stack_num2}");

    let heap_str1 = String::from("i have one owner");
    let heap_str2 = heap_str1;
    let heap_str3 = heap_str2.clone();
    //println!("{}", heap_str1); will not work since heap_str2 now owns the string
    println!("{}", heap_str2);
    //since we use .clone() we copy the heap value as well
    println!("{}", heap_str3);
}

fn reference() {
    let owner_variable: String = String::from("foo");
    //to borrow we use a reference to that variable we want to borrow
    let borrower: &String = &owner_variable;

    //to access the underlying data we need to dereference the reference with *
    let mut owner_num1 = 10;
    let borrow_num1 = &mut owner_num1;

    let new_value = *borrow_num1 * 2;
    *borrow_num1 = *borrow_num1 + 1; //since it borrwos the value, owner will also change
    println!("{new_value}");
    println!("{borrow_num1}");

    //now the borrow is over
    owner_num1 += 1;
    println!("{owner_num1}");
}

fn variables() {
    let var1 = 3;
    //we can assign varaibles to expressions
    let tripple = |d| d * 3;
    let var2 = tripple(var1);
    let doubblevar = var2;
    println!("{}", doubblevar);

    let (_a, _b) = ("foo", "bar");
    let [_a, _b, _c] = ["foo", "bar", "foo"];
    //to not get waring for unused varaibles we use _ infront of the variable name
}

fn mut_reference() {
    fn make_question(s: &mut String) {
        s.push('?');
    }
    let mut sentence = String::from("BarFooBarFoo");
    make_question(&mut sentence);
    println!("{}", sentence);

    //we can only have one mutable reference to a value at any given time
    let mut first = String::from("foo");
    let secound = &mut first;
    println!("{}", secound);
    println!("{}", first);
    //here if we chage the prints the code will not compile
}

fn macros() {
    //macros are denoted with a ! at the end
    //or as an attribute like #[derive()]

    //we can use () {} and [] interchangeably
    println! {"test"};
}

fn attributes() {
    // we can declare an inner attribute with #![attribute] placed in the first item
    // declared in the scope
    fn warnings() {
        let another_unused = 20;
    }

    fn no_warnings() {
        #![allow(warnings)]
        let unused = 10;
    }

    //we can declare an outer attribute wiht a #[attribute] before the item we
    //would like it to apply to
    #[test]
    pub fn test_true() {
        assert!(true, "the test failed");
        assert!(!true, "the test failed")
    }
}
