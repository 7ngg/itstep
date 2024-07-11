interface buttonProps {
  text: string;
  onClick: any;
}

const Button = (props: buttonProps) => {
  return (
    <button
      onClick={props.onClick}
      className="h-[40px] text-gray-200 w-32 bg-black rounded"
    >
      {props.text}
    </button>
  );
};

export default Button;
