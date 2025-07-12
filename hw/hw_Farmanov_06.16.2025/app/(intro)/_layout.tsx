import { router, Stack } from "expo-router";
import React from "react";
import { StyleSheet } from "react-native";

const IntroLayout = () => {
  return (
    <Stack
      initialRouteName="carousel"
      screenOptions={{
        headerShown: false,
      }}
    >
      <Stack.Screen name="index" />
      <Stack.Screen name="carousel" />
    </Stack>
  );
};

export default IntroLayout;

const styles = StyleSheet.create({});
