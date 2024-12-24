fn main() {
    //use_struct();
    use_enum();
}

//stucts is a way to grouping related data of differing types, mush like tuple. the main difference
//is that a struct allows ut to provide names to the fields
struct Guest {
    name: &'static str,
    rsvp: bool,
    costume: bool,
}
impl Guest {
    pub fn greet(&self) {
        println!("hello");
    }
    pub fn change_name(&mut self, new_name: &'static str) {
        self.name = new_name;
    }
    pub fn change_rsvp(&mut self, new_rsvp: bool) {
        self.rsvp = new_rsvp;
    }
    pub fn show_name(&self) {
        println!("{}", self.name);
    }
}

fn use_struct() {
    let name = "Thomas";
    let rsvp = true;
    let costume = false;

    let mut thomas = Guest {
        name,
        rsvp,
        costume,
    };

    thomas.change_name("Thomas Barth");
    thomas.show_name();

    let mut mark = Guest {
        name: "mark",
        ..thomas //rsvp and costume will now be the same as thomas
                 //so after decalring all the unique fields we put ..var to autofill the rest
    };
    mark.change_rsvp(false);
    println!("{},{}", mark.rsvp, thomas.rsvp);
    Guest::show_name(&mark);
}

enum Planets {
    Earth,
    Mercury,
    Venus,
}
//enums in rust can also contain values, this is possible since enum variants in rust is
//actually structs
enum Meal {
    Pasta, //unit struct
    StirFry(Vec<&'static str>),
    Burrito { beans: bool, rice: bool },
}

fn use_enum() {
    let home = Planets::Earth;

    match home {
        Planets::Venus => println!("venus"),
        Planets::Mercury => println!("mercury"),
        Planets::Earth => println!("HOMMMMEEE"),
    }

    let dinner = Meal::Burrito {
        beans: false,
        rice: true,
    };

    let dinner = Meal::StirFry(vec!["s", "t", "r"]);

    match dinner {
        Meal::Burrito { beans, rice } => {
            println!("beans: {beans}, rice: {rice}");
        }
        Meal::StirFry(veggies) => println!("{veggies:?}"),
        _ => println!("not burrito"),
    }
}
