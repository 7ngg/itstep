import { Stack } from "expo-router";
import React from "react";
import { StyleSheet, Text } from "react-native";

const IntroLayout = () => {
  return (
    <>
      <Stack
        screenOptions={{
          headerShown: false,
        }}
      >
        <Stack.Screen name="index" />
        <Stack.Screen name="register" />
        <Stack.Screen name="login" />
      </Stack>
    </>
  );
};

export default IntroLayout;

const styles = StyleSheet.create({});
