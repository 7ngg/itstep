import React from 'react'

interface IButtonProps {
  text: string
}

const Button: React.FC<IButtonProps> = (props: IButtonProps) => {
  return(
    <a className='cursor-pointer w-full h-[50px] shadow-md rounded-3xl bg-blue-300 flex justify-center items-center text-2xl'>{props.text}</a>
  );
}

export default Button;
