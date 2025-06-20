import React from "react";
import { Pressable, Text } from "react-native";

export default function Button({ children }: React.ButtonHTMLAttributes<HTMLButtonElement>) {
  return (
    <Pressable className="bg-[#6A53E7] w-96 h-14 flex items-center justify-center
      rounded-lg">
      {children}
    </Pressable>
  );
}
