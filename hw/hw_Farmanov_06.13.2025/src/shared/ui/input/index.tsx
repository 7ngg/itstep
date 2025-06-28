import Ionicons from "@expo/vector-icons/Ionicons";
import { JSX, useState } from "react";
import { TextInput, TextInputProps, View } from "react-native";

const Input = ({
  placeholder,
  secureTextEntry = false,
  icon,
  ...props
}: TextInputProps & { icon: JSX.Element }) => {
  const [focus, setFocus] = useState(false);
  const [shown, setShown] = useState(!secureTextEntry);

  return (
    <View
      className={`flex-row items-center  px-4 gap-2
        ${focus ? "border-2 border-[#fb9401] rounded-2xl" : ""}`}
    >
      {icon}
      <TextInput
        placeholder={placeholder}
        className="h-16 flex-1"
        onFocus={() => setFocus(true)}
        onBlur={() => setFocus(false)}
        secureTextEntry={!shown}
        {...props}
      />
      {secureTextEntry && (
        <Ionicons
          name={shown ? "eye" : "eye-off"}
          size={20}
          color="gray"
          className="place-self-end"
          onPress={() => setShown(!shown)}
        />
      )}
    </View>
  );
};

export default Input;
