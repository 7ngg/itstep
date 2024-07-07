import { FormEventHandler } from "react";

interface ButtonProps {
  text: string;
  type: string;
}

const Button: React.FC<ButtonProps> = (props: ButtonProps) => {
  return (
    <button
      className="bg-blue-500 w-24 h-7 flex items-center justify-center rounded-md text-white active:scale-[0.95] hover:bg-blue-600"
      type={"submit" || props.type}
    >
      {props.text}
    </button>
  );
};

export default Button;
