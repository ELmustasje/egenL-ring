//handlers

import { useState } from "react";


const Button = () => {
  let [count, setCount] = useState(0);
  const handleOnClick = () => {
    setCount(count + 1);
    return console.log(count);
  }
  return (
    <button onClick={handleOnClick} type="button" className="btn btn-primary">{count}</button>
  )
}

export default Button
