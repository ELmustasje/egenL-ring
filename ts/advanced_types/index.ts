type Employee = {
  id: number,
  name: string,
  age: number
}

let emp1: Employee = {
  id: 1,
  name: "thomas",
  age: 20
}

function kgToLbs(w: number | string): number {
  if (typeof w === 'string') {
    w = parseFloat(w);
  }
  return (w * 2.2);
}
