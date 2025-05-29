import { Tabs } from "expo-router";
import React from "react";
import { globalStyles } from "../global-styles";
import Ionicons from "@expo/vector-icons/Ionicons";

export default function MembersAreaLayout() {
  return (
    <Tabs
      backBehavior="history"
      detachInactiveScreens
      screenOptions={{
        headerShown: false,
        tabBarStyle: {
          backgroundColor: globalStyles.background,
        },
      }}
    >
      <Tabs.Screen
        name="account"
        options={{
          title: "Account",
          animation: "shift",
          tabBarIcon: () => {
            return (
              <Ionicons
                size={24}
                name="person-outline"
                color={globalStyles.foreground}
              />
            );
          },
        }}
      />
      <Tabs.Screen
        name="users"
        options={{
          title: "Users",
          animation: "shift",
          tabBarIcon: () => {
            return (
              <Ionicons
                size={24}
                name="people-outline"
                color={globalStyles.foreground}
              />
            );
          },
        }}
      />
    </Tabs>
  );
}
