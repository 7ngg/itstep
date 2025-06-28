import { Pressable, PressableProps } from "react-native";

const Button = ({ children, disabled, ...props }: PressableProps) => {
  return (
    <Pressable
      className={`bg-[#fb9401] h-16 flex w-full items-center justify-center 
      rounded-full`}
      disabled={disabled}
      style={{ opacity: disabled ? 0.5 : 1 }}
      {...props}
    >
      {children}
    </Pressable>
  );
};

export default Button;
