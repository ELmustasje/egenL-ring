use core::panic;
use std::fs::File;
use std::io::Write;
use std::io::{self, Read};
use std::path::Path;
use std::ptr::null;

fn main() {
    //Reading a single line from standard input
    println!("whats ur name? ");
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    //writing to standard Output
    println!("Hello, {}", input.trim());

    //Open a file in readmode
    let mut path = Path::new("./input.txt");
    let mut file = match File::open(&path) {
        Err(why) => panic!("error: {why}"),
        Ok(file) => file,
    };

    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(why) => panic!("error"),
        Ok(_) => print!("{s}"),
    }

    //creating a file
    path = Path::new("./res.txt");
    let mut outFile = match File::create(&path) {
        Err(why) => panic!("error"),
        Ok(outFile) => outFile,
    };

    //write to file
    let buff = "writing";
    match outFile.write_all(buff.as_bytes()) {
        Err(why) => panic!("Error"),
        Ok(_) => print!("test"),
    }
}
