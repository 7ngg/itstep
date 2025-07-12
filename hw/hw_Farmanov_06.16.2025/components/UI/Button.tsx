import { Dimensions, Pressable, StyleSheet, Text, View } from "react-native";
import React from "react";
import { colors, fonts } from "@/constants";

interface IButton {
  onPress: () => void;
  text: string;
}
const Button = ({ onPress, text }: IButton) => {
  return (
    <Pressable style={styles.button} onPress={onPress}>
      <Text style={styles.buttonText}>{text}</Text>
    </Pressable>
  );
};

export default Button;

const styles = StyleSheet.create({
  button: {
    borderRadius: 100,
    backgroundColor: colors.Primary,
    alignItems: "center",
    width: Dimensions.get("screen").width - 32,
    justifyContent: "center",
    boxShadow: "4px 8px 24px rgba(251,148,0, 0.25)",
    paddingHorizontal: 16,
    paddingVertical: 18,
  },
  buttonText: {
    fontFamily: fonts.bold,
    fontSize: 16,
    color: colors.White,
  },
});
