var person = {
  "name": "Thomas",
  "surname": "Barth",
  "age": 20,
  2: 3
};

console.log(person["name"])
console.log(person.name)

person.name = "Mark";
console.log(person.name);
person[2] = 2;
console.log(person[2]);
person["sport"] = "badminton";
console.log(person.sport);

delete person.surname;
console.log(person.hasOwnProperty("surname"))
