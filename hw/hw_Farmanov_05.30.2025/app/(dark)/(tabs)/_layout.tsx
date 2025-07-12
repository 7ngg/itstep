import { Tabs } from "expo-router";

import { View, Platform, useWindowDimensions } from "react-native";
import { useLinkBuilder, useTheme } from "@react-navigation/native";
import { Text, PlatformPressable } from "@react-navigation/elements";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";

import type { BottomTabBarProps } from "@react-navigation/bottom-tabs";
import {
  Calendar,
  Home,
  NotificationBing,
  NotificationStatus,
  Setting,
  Setting2,
} from "iconsax-react-native";

function MyTabBar({ state, descriptors, navigation }: BottomTabBarProps) {
  const { colors } = useTheme();
  const { buildHref } = useLinkBuilder();
  const { width } = useWindowDimensions();

  return (
    <View
      style={{
        position: "absolute",
        bottom: 0,
        left: "50%",
        transform: [{ translateX: "-50%" }],
        flexDirection: "row",
        height: 90,
        borderTopLeftRadius: 16,
        borderTopRightRadius: 16,
        width: width - 24,
        paddingHorizontal: 25,
        paddingVertical: 20,
        backgroundColor: "#151A28",
      }}
    >
      {state.routes.map((route, index) => {
        const { options } = descriptors[route.key];
        let label: React.ReactNode;

        if (options.tabBarLabel !== undefined) {
          if (typeof options.tabBarLabel === "function") {
            label = options.tabBarLabel({
              focused: state.index === index,
              color: state.index === index ? colors.primary : colors.text,
              position: "below-icon",
              children: route.name,
            });
          } else {
            label = options.tabBarLabel;
          }
        } else if (options.title !== undefined) {
          label = options.title;
        } else {
          label = route.name;
        }

        const isFocused = state.index === index;

        const onPress = () => {
          const event = navigation.emit({
            type: "tabPress",
            target: route.key,
            canPreventDefault: true,
          });

          if (!isFocused && !event.defaultPrevented) {
            navigation.navigate(route.name, route.params);
          }
        };

        const onLongPress = () => {
          navigation.emit({
            type: "tabLongPress",
            target: route.key,
          });
        };

        return (
          <PlatformPressable
            key={route.key}
            href={buildHref(route.name, route.params)}
            accessibilityState={isFocused ? { selected: true } : {}}
            accessibilityLabel={options.tabBarAccessibilityLabel}
            testID={options.tabBarButtonTestID}
            onPress={onPress}
            onLongPress={onLongPress}
            style={{ flex: 1, gap: 8, alignItems: "center" }}
          >
            {options.tabBarIcon &&
              options.tabBarIcon({
                color: isFocused ? "#fff" : "#8C8BA7",
                size: 24,
                focused: isFocused,
              })}
            <Text style={{ color: isFocused ? "#fff" : "#8C8BA7", fontSize: 12 }}>
              {label as any}
            </Text>
          </PlatformPressable>
        );
      })}
    </View>
  );
}

const TabsLayout = () => {
  return (
    <Tabs
      tabBar={(props) => <MyTabBar {...props} />}
      screenOptions={{
        sceneStyle: {
          backgroundColor: "#0A0F1D",
        },
        headerShown: false,
      }}
    >
      <Tabs.Screen
        name="index"
        options={{
          tabBarIcon: ({ color }) => (
            <Home fontWeight={"bold"} color={color} size={24} />
          ),
          title: "Home",
        }}
      />
      <Tabs.Screen
        name="notifications"
        options={{
          tabBarIcon: ({ color }) => (
            <NotificationBing fontWeight={"bold"} color={color} size={24} />
          ),
          title: "Notifications",
        }}
      />
      <Tabs.Screen
        name="bookings"
        options={{
          tabBarIcon: ({ color }) => (
            <Calendar fontWeight={"bold"} color={color} size={24} />
          ),
          title: "Bookings",
        }}
      />
      <Tabs.Screen
        name="settings"
        options={{
          tabBarIcon: ({ color }) => (
            <Setting2 fontWeight={"bold"} color={color} size={24} />
          ),
          title: "Settings",
        }}
      />
    </Tabs>
  );
};

export default TabsLayout;
