fn main() {
    fn double(num: u128) -> u128 {
        num * 2
    }
    let my_int = 32;
    let result = double(my_int);

    println!("{result}");
}
