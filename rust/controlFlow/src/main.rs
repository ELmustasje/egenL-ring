use core::time;

fn main() {
    //if_else();
    //else_if();
    //let color: Colors = Colors::GREEN;
    //check_color(color);
    //if_let();
    //matching();
    loops();
}

fn if_else() {
    let control_bool = false;
    if control_bool {
        println!("active");
    } else {
        println!("deactivated");
    };
}

fn else_if() {
    let control_value = 1;
    if control_value == 1 {
        println!("active");
    } else if control_value == 0 {
        println!("deactivated");
    } else {
        println!("not accepted");
    }
}

#[derive(PartialEq, Eq)]
enum Colors {
    RED,
    BLUE,
    GREEN,
}

fn check_color(color: Colors) {
    if color == Colors::RED {
        println!("RED");
    } else if color == Colors::GREEN {
        println!("GREEN");
    } else if color == Colors::BLUE {
        println!("BLUE");
    } else {
        println!("Not a color");
    };
}

fn if_let() {
    let mut vault = Some("fooBarr");
    let mut vault2: Option<&str> = None;
    if let Some(secret) = vault {
        println!("the secret is {secret}");
    }

    if vault.is_some() {
        println!("the secret is {}", vault.unwrap());
    }

    match vault {
        Some(secret) => println!("the secret is {secret}"),
        _ => {}
    }
}

fn matching() {
    let count = 21;
    match count {
        0 => println!("Count is ZERO"),
        1..=20 => {
            println!("the count is not known");
            println!("buts its between 1 and 20");
        }
        n @ 21..40 => println!("the count in {n}"),
        _ => println!("too high"),
    }

    let guess = Some(5);
    match guess {
        Some(x) if x == 5 => println!("Correct"),
        Some(x) => println!("Wrong"),
        _ => println!("You have no guess"),
    }
}

fn loops() {
    let mut count = 0;
    loop {
        println!("{count}");
        count += 1;
        if count == 5 {
            break;
        }
    }
    count = 0;
    loop {
        count += 1;
        if count == 5 {
            break;
        }
        if count == 2 {
            continue;
        }
        println!("{count}");
    }

    'first: loop {
        println!("entering first loop");
        'secount: loop {
            println!("entering secound loop");
            break 'secount;
        }
        break 'first;
    }

    count = 0;
    while count < 5 {
        println!("{count}");
        count += 1;
    }

    let mut timer: Option<i32> = None;

    while let Some(secounds_left) = timer {
        if secounds_left == 0 {
            println!("done");
            timer = None
        } else {
            println!("secounds left: {secounds_left}");
            timer = Some(secounds_left - 1);
            std::thread::sleep(time::Duration::from_secs(1));
        }
    }

    let numbers = [1, 2, 3, 4, 5, 6];
    for n in numbers {
        println!("{n}");
    }
}
