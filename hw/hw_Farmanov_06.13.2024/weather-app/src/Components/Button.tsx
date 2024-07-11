interface buttonProps {
  text: string;
}

const Button = (props: buttonProps) => {
  return (
    <button className="h-[40px] text-gray-200 w-32 bg-black rounded">
      {props.text}
    </button>
  );
};

export default Button;
