import React, { RefObject } from "react";

interface InputProps {
  placeholder: string;
  refs: RefObject<HTMLInputElement>;
}

const Input = (props: InputProps) => {
  return (
    <input
      ref={props.refs}
      placeholder={props.placeholder}
      className="bg-stone-700 text-gray-200 h-[40px] outline-none rounded pl-2"
    />
  );
};

export default Input;
