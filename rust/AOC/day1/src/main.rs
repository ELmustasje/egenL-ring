use core::panic;
use std::fs::File;
use std::io::Read;
use std::path::Path;

fn main() {
    println!("Hello, world!");
    get_input_parts(String::from("aaaaaaaaa \n b \n c \n d"));
}

fn open_file(path: &Path) -> String {
    let mut file = match File::open(path) {
        Err(why) => panic!("{why}"),
        Ok(file) => file,
    };

    let mut str = String::new();
    match file.read_to_string(&mut str) {
        Err(why) => panic!("{why}"),
        Ok(_) => {}
    }
    str
}

fn get_input_parts(str: String) -> (Vec<String>, Vec<String>) {
    let mut lines: Vec<&str> = Vec::new();
    let mut right = Vec::new();
    let mut left = Vec::new();
    lines = str.split('\n').collect();

    for line in lines {
        let temp: Vec<&str> = line.split(' ').collect();
        if let Some(r) = temp.get(0) {
            right.push(r.to_string());
        }
        if let Some(l) = temp.get(1) {
            left.push(l.to_string());
        }
    }
    (left, right)
}
