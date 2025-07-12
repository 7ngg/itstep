import { Stack, Tabs } from "expo-router";
import React from "react";
import { StyleSheet } from "react-native";

const IntroLayout = () => {
  return (
    <Tabs
      initialRouteName=""
      screenOptions={{
        headerShown: false,
      }}
    >
      <Tabs.Screen name="index" />
    </Tabs>
  );
};

export default IntroLayout;

const styles = StyleSheet.create({});
